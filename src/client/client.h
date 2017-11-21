#include <iostream>
#include <thread>
#include <boost/asio.hpp>
#include <system_error>

using std::string;
using std::thread;
using boost::asio::io_service;
using boost::asio::ip::tcp;

class Client {
private:
    const size_t MAX_LINESIZE = 100;
    io_service io_service;
    tcp::socket* socket;
    tcp::resolver::iterator endpoint_itr;
    bool shouldReconnect;
    bool isConnected;
    thread* Tlisten = nullptr;
    thread* Tconnect = nullptr;

public:
    Client(){};
    
    // Sets the endpoint of the server. Returns whether the IP address and host are valid.
    bool setEndpoint(string host, string port);
    
    void startClient() { reconnect(); }
    void stopClient();

private:
    void listen();
    void setupSocket();
    void destroySocket();
    void reconnect();
    bool connect();
    int parseHeader(std::string* message) throw(boost::system::system_error);
    void readMessage(int message_length, std::string* message) throw(boost::system::system_error);
    bool checkServerDisconnected(boost::system::error_code errc);
};

