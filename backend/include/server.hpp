#pragma once

#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>

const int TIPO = AF_INET;
const int PROTO = SOCK_STREAM;
const int PUERTO = 8080;
const int MENSAJE_SIZE = 1024;

class ServerSocket
{
    int server;
    int clientSocket;

public:
    ServerSocket();
    ~ServerSocket();
    void enviar_mensaje(std::string &msg);
    void recibir_mensaje(std::string &output);
};