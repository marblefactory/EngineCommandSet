#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
using boost::asio::ip::tcp;
using namespace std;

int serverPort = 1024;
std::string JSON = "{ \"id\": 1, \"name\": \"A green door\", \"price\": 12.50, \"tags\": [\"home\", \"green\"] }";

int main(){
    std::string message = "Content-Length: " + std::to_string(JSON.size()) + "\n" + JSON;
    try{
        boost::asio::io_service io_service;
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), serverPort));
    
        while(true){
            tcp::socket socket(io_service);
            acceptor.accept(socket);
            std::cout << message << std::endl;
            boost::asio::write(socket, boost::asio::buffer(message));
        }
    }
    catch(std::exception& e){
        std::cerr << "Error:" << e.what() << std::endl;
    }
    return 0;
}
