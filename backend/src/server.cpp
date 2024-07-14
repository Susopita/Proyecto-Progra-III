#include "backend/include/server.hpp"
#include <iostream>

ServerSocket::ServerSocket()
{
    this->server = socket(TIPO, PROTO, 0);
    if (this->server == -1)
    {
        std::cerr << "Error al crear socket" << std::endl;
        exit(1);
    }

    struct sockaddr_in serverAddr;

    serverAddr.sin_family = TIPO;
    serverAddr.sin_addr.s_addr = PROTO;
    serverAddr.sin_port = PUERTO;

    if (bind(this->server, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        std::cerr << "Error al enlazar el socket al puerto" << std::endl;
        close(server);
        exit(1);
    }

    if (listen(this->server, 1) == -1)
    {
        std::cerr << "Error al escuchar conexiones entrantes" << std::endl;
        perror("Error con perror");
        close(server);
        exit(1);
    }
    std::cout << "Servidor escuchando en el puerto 8080..." << std::endl;

    this->clientSocket = accept(this->server, nullptr, nullptr);

    if (this->clientSocket == -1)
    {
        std::cerr << "Error al aceptar la conexion entrante" << std::endl;
        close(server);
        exit(1);
    }

    std::cout << "Cliente conectado" << std::endl;
}

ServerSocket::~ServerSocket()
{
    close(clientSocket);
    close(server);
}

void ServerSocket::enviar_mensaje(std::string &msg)

{
    send(clientSocket, msg, msg.size(), 0);
}

void ServerSocket::recibir_mensaje(std::string &output)
{
    char *msg[MENSAJE_SIZE];
    int valread = recv(clientSocket, msg, size, 0);

    if (valread == -1)
    {
        std::cerr << "Error al recibir mensaje" << std::endl;
        close(clientSocket);
        close(server);
        exit(1);
    }
}