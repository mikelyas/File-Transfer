#include "InputHandler.h"
#include "Client.h"
#include "Server.h"
#include <iostream>
#include <string>


InputHandler::InputHandler() {

}

InputHandler::~InputHandler() {
    
}

void InputHandler::start() {
    std::cout << "File Transfer Application" << std::endl;
    std::cout << "Enter 'send' to send data or 'receive' to receive data: ";
    std::string command;
    std::getline(std::cin, command);

    if (command == "send") {
        // Handle sending a file
        std::cout << "Enter server address: ";
        std::string serverAddress;
        std::getline(std::cin, serverAddress);

        std::cout << "Enter server port: ";
        int serverPort;
        std::cin >> serverPort;

        std::cin.ignore(); // Ignore the newline character left in the input stream

        std::cout << "Enter the file or folder to send: ";
        std::string path;
        std::getline(std::cin, path);

        Client client;
        client.sendData(serverAddress, serverPort, path);
    } else if (command == "receive") {
        // Handle receiving a file
        std::cout << "Enter port to listen on: ";
        int serverPort;
        std::cin >> serverPort;

        std::cin.ignore(); // Ignore the newline character left in the input stream

        Server server;
        server.start(serverPort);
    } else {
        std::cout << "Invalid command. Please enter 'send' or 'receive'." << std::endl;
    }
}
