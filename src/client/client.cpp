#include "client.h"
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <thread>
#include "logger.h"

bool Client::setEndpoint(string host, string port){
    tcp::resolver resolver(io_service);
    tcp::resolver::query query(host, port);
    boost::system::error_code errc;
    
    this->endpoint_itr = resolver.resolve(query, errc);
    
    if(errc != boost::system::errc::success){
        Logging::logError(__LINE__, "Invalid endpoint");
        return false;
    }
    else {
        Logging::logDebug(__LINE__, "Valid endpoint");
        shouldReconnect = true;
        return true;
    }
}

void Client::setupSocket(){
    socket = new tcp::socket(io_service);
    socket->open(tcp::v4());
    socket->bind(tcp::endpoint(tcp::v4(), 1025));
}

void Client::destroySocket(){
    delete socket;
    socket = nullptr;
}

void Client::reconnect(){
    std::chrono::seconds one_sec (1);
    setupSocket();
    if(Tconnect) {
        // The destructor of Tconnect cannot be destroyed unless the thread has
        // finished. join is used to do this.
        Tconnect->join();
        delete Tconnect;
    }
    // Spawns a thread to connect to the server every second, while the client
    // hasn't been stopped using `stop_client`.
    Tconnect = new std::thread([&]() -> void {
        while(shouldReconnect && !connect()) {
            std::this_thread::sleep_for(one_sec);
        }
    });
}

// Tries to connect to the server.
// Returns whether the connection was successful.
bool Client::connect(){
    boost::system::error_code errc;
    boost::asio::connect(*socket, endpoint_itr, errc);
    if(errc != boost::system::errc::success){
        Logging::logWarning(__LINE__, "Connection failed " + errc.message());
        return false;
    }
    else {
        Logging::logDebug(__LINE__, "Connection successed");
        isConnected = true;
        if(Tlisten) {
            Tlisten->join();
            delete Tlisten;
        }
        Tlisten = new std::thread(&Client::listen, this);
        return true;
    }
}


void Client::stopClient(){
    shouldReconnect = false;
    isConnected = false;
}


void Client::listen(){
    while(isConnected){
        try {
            std::string message;
            int message_length = parseHeader(&message);
            readMessage(message_length, &message);
            std::cout << message << std::endl;
        }
        catch(boost::system::system_error& e){
            Logging::logWarning(__LINE__, " - PEER DISCONNECTED - ERROCODE:" + std::to_string(e.code().value()) + " " + std::string(e.what()));
            isConnected = false;
            destroySocket();
        }
    }
    if(shouldReconnect) reconnect();
}


int Client::parseHeader(std::string* message) throw(boost::system::system_error) {
    boost::asio::streambuf inputStream;
    inputStream.prepare(MAX_LINESIZE); //Reserve characters on the output stream
    boost::asio::read_until(*socket, inputStream, "\n");

    std::istream is(&inputStream);
    char header[MAX_LINESIZE];
    is.getline(header, MAX_LINESIZE);
    int JSON_length;
    sscanf(header, "Content-Length: %d\n", &JSON_length);
    *message += std::string(std::istreambuf_iterator<char>(is), {});
    return JSON_length - message->size();
}

void Client::readMessage(int message_length, std::string* message) throw(boost::system::system_error) {
    std::vector<char> data(message_length);
    boost::asio::read(*socket, boost::asio::buffer(data));

    *message += std::string(data.data(), data.size());
}

