//
//  test_client.cpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 21/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#include "catch.hpp"
#include "client.h"
#include <string>
#include <iostream>


using boost::asio::ip::tcp;
using namespace std;

// A simple server used for testing.
class Server {
private:
    int port;

public:
    Server(int port): port(port) {
    }

    void send_message(string message) {
        boost::asio::io_service io_service;
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), port));
        
        tcp::socket socket(io_service);
        acceptor.accept(socket);
        boost::asio::write(socket, boost::asio::buffer(message));
    }
};

SCENARIO("Communicating with a server via the Client") {
    Server server(1024);
    Client client;
    
    client.setEndpoint("127.0.0.1", "1024");
    client.startClient();
    
    server.send_message("Hello");
}
