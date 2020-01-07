//
// Created by mevaseret on 29/12/2019.
//

#include "ConnectCommand.h"

int client_socket;
#define PORT 5402

void ConnectCommand::updateSimulator(const std::string& s) {
    send(client_socket, s.c_str(), s.size(), 0);
}

//fill in fields
void ConnectCommand::parseString(std::string s) {
    //find comma:
    int indexComma = s.find(',');
    this->ip = s.substr(2, indexComma - 3);
    // check if port is always four digits number!!!!!
    this->port = static_cast<std::uint16_t>(stringToDouble(s.substr(indexComma + 1, 4)));
}

int ConnectCommand::execute(vector<string> vecOfstrings, int index) {

    //create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        exit(-1);
    }

    //We need to create a sockaddr obj to hold address of server
    auto address = sockaddr_in{}; //in means IP4
    address.sin_family = AF_INET;//IP4
    parseString(vecOfstrings[index + 1]);
    address.sin_addr.s_addr = inet_addr(this->ip.c_str());  //the localhost address
    address.sin_port = htons(this->port);
    //we need to convert our number (both port & localhost)
    // to a number that the network understands.

    // Requesting a connection with the server on local host with port 8081
    int is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
    if (is_connect == -1) {
        std::cerr << "Could not connect to host server" << std::endl;
        exit(-2);
    } else {
        std::cout << "Client is now connected to server" << std::endl;
    }

    //if here we made a connection

    return 2;
}


ConnectCommand::~ConnectCommand() {

}



