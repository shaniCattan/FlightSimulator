//
// Created by shani on 1/6/20.
//

#include "SocketReader.h"

#include <iostream>

#include <cerrno>
#include <unistd.h>

SocketReader::SocketReader(int sockFd)
        : m_socket(sockFd) {

}

std::string SocketReader::readTelnetLine() {
    static constexpr auto TELNET_EOL = "\n";

    while (m_buffer.find(TELNET_EOL) == std::string::npos) {
        m_buffer += read();
    }

    auto endLinePosition = m_buffer.find(TELNET_EOL);
    auto result = m_buffer.substr(0, endLinePosition);
    m_buffer = m_buffer.substr(endLinePosition + 1);

    return result;
}

std::string SocketReader::read() {
    char buffer[BUFFER_SIZE] = {0};
    auto bytesRead = ::read(m_socket, buffer, BUFFER_SIZE);
    if (bytesRead < 0) {
        std::cerr << "Error reading from server, errno: " << errno << std::endl;
        exit(-1);
    }
    buffer[bytesRead] = '\0';

    return std::string{buffer};
}
