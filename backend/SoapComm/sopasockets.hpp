#pragma once

#include <string>
#include <vector>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cerrno>
#endif

class SopaSocket
{
public:
    SopaSocket();
    ~SopaSocket();

    bool create(int domain = AF_INET, int type = SOCK_STREAM, int protocol = 0);
    bool bind(const std::string &address, int port);
    bool listen(int backlog = 5);
    bool accept(SopaSocket &new_socket);
    bool connect(const std::string &address, int port);
    int send(const std::string &data);
    int recv(std::string &data, const int &size);
    void close();

private:
    int sockfd;
#ifdef _WIN32
    static bool initialized;
    static bool initialize();
#endif
};
