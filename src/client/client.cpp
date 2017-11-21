//#include "client.h"
//#include <iostream>
//#include <boost/array.hpp>
//#include <boost/asio.hpp>
//#include <thread>
//#include "logger.h"
//using boost::asio::ip::tcp;
//
//bool Client::setEndpoint(string host, string port){
//    tcp::resolver resolver(io_service);
//    tcp::resolver::query query(host, port);
//    boost::system::error_code errc;
//    endpoint_itr = resolver.resolve(query, errc);
//    if(errc != boost::system::errc::success){
//        Logging::logError(__LINE__, "Invalid endpoint");
//        return false;
//    }
//    else {
//        Logging::logDebug(__LINE__, "Valid endpoint");
//        shouldReconnect = true;
//        return true;
//    }
//}
//
//void Client::setupSocket(){
//    socket = new tcp::socket(io_service);
//    socket->open(tcp::v4());
//    socket->bind(tcp::endpoint(tcp::v4(), 1025));
//}
//
//void Client::destroySocket(){
//    delete socket;
//    socket == nullptr;
//}
//
//void Client::reconnect(){
//    std::chrono::seconds one_sec (1);
//    setupSocket();
//    if(Tconnect) {
//        Tconnect->join();
//        delete Tconnect;
//    }
//    Tconnect = new std::thread([&]() -> void{
//        while(!connect() & shouldReconnect) { std::this_thread::sleep_for(one_sec); }
//        Logging::logDebug(__LINE__, "Tconnect thread dying");
//    });
//}
//
//bool Client::connect(){
//    //Connect to server
//    boost::system::error_code errc;
//    boost::asio::connect(*socket, endpoint_itr, errc);
//    if(errc != boost::system::errc::success){
//        Logging::logWarning(__LINE__, "Connection failed " + errc.message());
//        return false;
//    }
//    else {
//        Logging::logDebug(__LINE__, "Connection successed");
//        isConnected = true;
//        if(Tlisten) {
//            Tlisten->join();
//            delete Tlisten;
//        }
//        Tlisten = new std::thread(&Client::listen, this);
//        return true;
//    }
//}
//
//
//bool Client::stopClient(){
//    shouldReconnect = false;
//    isConnected = false;
//}
//
//
//void Client::listen(){
//    while(isConnected){
//        try {
//            std::string message;
//            int message_length = parseHeader(&message);
//            readMessage(message_length, &message);
//            std::cout << message << std::endl;
//        }
//        catch(boost::system::system_error& e){
//            boost::system::error_code errc = e.code();
//            Logging::logWarning(__LINE__, " - PEER DISCONNECTED - ERROCODE:" + std::to_string(e.code().value()) + " " + std::string(e.what()));
//            isConnected = false;
//            destroySocket();
//        }
//    }
//    if(shouldReconnect) reconnect();
//}
//
//
//int Client::parseHeader(std::string* message) throw(boost::system::system_error) {
//    boost::asio::streambuf inputStream;
//    inputStream.prepare(MAX_LINESIZE); //Reserve characters on the output stream
//    boost::asio::read_until(*socket, inputStream, "\n");
//
//    std::istream is(&inputStream);
//    char header[MAX_LINESIZE];
//    is.getline(header, MAX_LINESIZE);
//    int JSON_length;
//    sscanf(header, "Content-Length: %d\n", &JSON_length);
//    *message += std::string(std::istreambuf_iterator<char>(is), {});
//    return JSON_length - message->size();
//}
//
//void Client::readMessage(int message_length, std::string* message) throw(boost::system::system_error) {
//    std::vector<char> data(message_length);
//    size_t bytesRead = boost::asio::read(*socket, boost::asio::buffer(data));
//
//    *message += std::string(data.data(), data.size());
//}
//
//
//int main(int argc, char** argv){
//    if(argc != 3){
//        std::cout << "Usage: ./client <host> <service>" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    Client client;
//    if(client.setEndpoint(argv[1], argv[2])){
//        client.startClient();
//        std::this_thread::sleep_for(std::chrono::seconds(5));
//    }
//    return EXIT_SUCCESS;
//}

