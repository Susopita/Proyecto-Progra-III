#include "sopasockets.hpp"
#include <iostream>

#ifdef _WIN32
bool SopaSocket::initialized = false;

bool SopaSocket::initialize()
{
    if (!initialized)
    {
        WSADATA wsaData;
        int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (iResult != 0)
        {
            std::cerr << "WSAStartup failed: " << iResult << std::endl;
            return false;
        }
        initialized = true;
    }
    return true;
}
#endif

SopaSocket::SopaSocket() : sockfd(-1)
{
#ifdef _WIN32
    if (!initialize())
    {
        throw std::runtime_error("Failed to initialize Winsock");
    }
#endif
}

SopaSocket::~SopaSocket()
{
    close();
}

bool SopaSocket::create(int domain, int type, int protocol)
{
    sockfd = socket(domain, type, protocol);
    if (sockfd < 0)
    {
#ifdef _WIN32
        std::cerr << "Socket creation failed: " << WSAGetLastError() << std::endl;
#else
        perror("Socket creation failed");
#endif
        return false;
    }
    return true;
}

bool SopaSocket::bind(const std::string &address, int port)
{
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(address.c_str());

    int result = ::bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (result < 0)
    {
#ifdef _WIN32
        std::cerr << "Bind failed: " << WSAGetLastError() << std::endl;
#else
        perror("Bind failed");
#endif
        return false;
    }
    return true;
}

bool SopaSocket::listen(int backlog)
{
    int result = ::listen(sockfd, backlog);
    if (result < 0)
    {
#ifdef _WIN32
        std::cerr << "Listen failed: " << WSAGetLastError() << std::endl;
#else
        perror("Listen failed");
#endif
        return false;
    }
    return true;
}

bool SopaSocket::accept(SopaSocket &new_socket)
{
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    int new_sockfd = ::accept(sockfd, (struct sockaddr *)&addr, &addr_len);
    if (new_sockfd < 0)
    {
#ifdef _WIN32
        std::cerr << "Accept failed: " << WSAGetLastError() << std::endl;
#else
        perror("Accept failed");
#endif
        return false;
    }
    new_socket.sockfd = new_sockfd;
    return true;
}

bool SopaSocket::connect(const std::string &address, int port)
{
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(address.c_str());

    int result = ::connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (result < 0)
    {
#ifdef _WIN32
        std::cerr << "Connect failed: " << WSAGetLastError() << std::endl;
#else
        perror("Connect failed");
#endif
        return false;
    }
    return true;
}

int SopaSocket::send(const std::string &data)
{
    int bytes_sent = ::send(sockfd, data.data(), data.size(), 0);
    if (bytes_sent < 0)
    {
#ifdef _WIN32
        std::cerr << "Send failed: " << WSAGetLastError() << std::endl;
#else
        perror("Send failed");
#endif
    }
    return bytes_sent;
}

int SopaSocket::recv(std::string &data, const int &size_data)
{
    char buffer[size_data];
    int bytes_received = ::recv(sockfd, buffer, size_data, 0);
    if (bytes_received < 0)
    {
#ifdef _WIN32
        std::cerr << "Recv failed: " << WSAGetLastError() << std::endl;
#else
        perror("Recv failed");
#endif
        return -1;
    }
    data.assign(buffer, bytes_received);
    return bytes_received;
}

void SopaSocket::close()
{
    if (sockfd >= 0)
    {
#ifdef _WIN32
        closesocket(sockfd);
#else
        ::close(sockfd);
#endif
        sockfd = -1;
    }
#ifdef _WIN32
    WSACleanup();
#endif
}
