//
// Created by shani on 1/6/20.
//

#pragma once

#include <string>


class SocketReader {
    static constexpr auto BUFFER_SIZE = 1024;
public:
    explicit SocketReader(int sockFd);

    std::string readTelnetLine();
private:
    std::string read();

    std::string m_buffer;
    int m_socket;
};


