#include <iostream>
#include <thread>
#include <boost/asio.hpp>
#include <system_error>
using namespace std;

class Client {

public:
    Client(){};
    bool setEndpoint(string host, string port);
    void startClient() { reconnect(); }
    bool stopClient();
private:
    void listen();
    void setupSocket();
    void destroySocket();
    void reconnect();
    bool connect();
    int parseHeader(std::string* message) throw(boost::system::system_error);
    void readMessage(int message_length, std::string* message) throw(boost::system::system_error);
    bool checkServerDisconnected(boost::system::error_code errc);
private:
    const size_t MAX_LINESIZE = 100;
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket* socket;
    boost::asio::ip::tcp::resolver::iterator endpoint_itr;
    bool shouldReconnect;
    bool isConnected;
    std::thread* Tlisten = nullptr;
    std::thread* Tconnect = nullptr;
};