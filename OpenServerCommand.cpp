//
// Created by shani on 12/25/19.
//
#include "OpenServerCommand.h"
#include "SocketReader.h"

#include <cerrno>

double doubleArr[DOUBLE_ARRAY_SIZE] = {};
bool programIsLive = true;
std::map<std::string, int> indexMap;


void readData(int serverSocketFd) {
    // the following part has to be in an infinity while loop
    auto reader = SocketReader{serverSocketFd};
    while (programIsLive) {
        //reading from client

        //make an array with 36 double values that were sent from the simulator
        auto s = reader.readTelnetLine();
        auto beginPosition = std::size_t{0};
        auto index = 0;

        while (index < DOUBLE_ARRAY_SIZE)
        {
            const auto commaPosition = s.find(',', beginPosition);
            if (commaPosition == std::string::npos){
                doubleArr[index++] = std::stod(s.substr(beginPosition));
                break;
            }
            doubleArr[index++] = std::stod(s.substr(beginPosition, commaPosition - beginPosition));
            beginPosition = commaPosition + 1;
        }
    }
    close(serverSocketFd); //closing the listening socket
}

void OpenServerCommand::parseString(std::string s) {
    // remove brackets
    this->port = static_cast<std::uint16_t>(stringToDouble(s.substr(1, s.length() - 2)));
}

int OpenServerCommand::execute(vector<string> v, int ind) {
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket, errno: " << errno << std::endl;
        exit(-1);
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    auto address = sockaddr_in{}; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    parseString(v[ind + 1]);
    address.sin_port = htons(this->port);
    //we need to convert our number
    // to a number that the network understands.

    auto enable = 1;
    if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
        std::cerr << "setsockopt failed" << std::endl;
        exit(-4);
    }
    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP, errno: " << errno << std::endl;
        exit(-2);
    }

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        exit(-3);
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }

    // accepting a client
    int server_socket = accept(socketfd, (struct sockaddr *) &address,
                               (socklen_t *) &address);

    if (server_socket == -1) {
        std::cerr << "Error accepting client" << std::endl;
        exit(-1);
    }

    buildMap();
    std::thread serverThread(readData, server_socket);
    serverThread.detach();
    return 2;
}

void OpenServerCommand::buildMap() {
    indexMap["/instrumentation/airspeed-indicator/indicated-speed-kt"] = {0};
    indexMap["/sim/time/warp"] = {1};
    indexMap["/controls/switches/magnetos"] = {2};
    indexMap["/instrumentation/heading-indicator/offset-deg"] = {3};
    indexMap["/instrumentation/altimeter/indicated-altitude-ft"] = {4};
    indexMap["/instrumentation/altimeter/pressure-alt-ft"] = {5};
    indexMap["/instrumentation/attitude-indicator/indicated-pitch-deg"] = {6};
    indexMap["/instrumentation/attitude-indicator/indicated-roll-deg"] = {7};
    indexMap["/instrumentation/attitude-indicator/internal-pitch-deg"] = {8};
    indexMap["/instrumentation/attitude-indicator/internal-roll-deg"] = {9};
    indexMap["/instrumentation/encoder/indicated-altitude-ft"] = {10};
    indexMap["/instrumentation/encoder/pressure-alt-ft"] = {11};
    indexMap["/instrumentation/gps/indicated-altitude-ft"] = {12};
    indexMap["/instrumentation/gps/indicated-ground-speed-kt"] = {13};
    indexMap["/instrumentation/gps/indicated-vertical-speed"] = {14};
    indexMap["/instrumentation/heading-indicator/indicated-heading-deg"] = {15};
    indexMap["/instrumentation/magnetic-compass/indicated-heading-deg"] = {16};
    indexMap["/instrumentation/slip-skid-ball/indicated-slip-skid"] = {17};
    indexMap["/instrumentation/turn-indicator/indicated-turn-rate"] = {18};
    indexMap["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = {19};
    indexMap["/controls/flight/aileron"] = {20};
    indexMap["/controls/flight/elevator"] = {21};
    indexMap["/controls/flight/rudder"] = {22};
    indexMap["/controls/flight/flaps"] = {23};
    indexMap["/controls/engines/engine/throttle"] = {24};
    indexMap["/controls/engines/current-engine/throttle"] = {25};
    indexMap["/controls/switches/master-avionics"] = {26};
    indexMap["/controls/switches/starter"] = {27};
    indexMap["/engines/active-engine/auto-start"] = {28};
    indexMap["/controls/flight/speedbrake"] = {29};
    indexMap["/sim/model/c172p/brake-parking"] = {30};
    indexMap["/controls/engines/engine/primer"] = {31};
    indexMap["/controls/engines/current-engine/mixture"] = {32};
    indexMap["/controls/switches/master-bat"] = {33};
    indexMap["/controls/switches/master-alt"] = {34};
    indexMap["/engines/engine/rpm"] = {35};
}

OpenServerCommand::~OpenServerCommand() {}








