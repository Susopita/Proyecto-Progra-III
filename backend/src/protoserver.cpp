#include "../include/protoserver.hpp"
#include "../include/builders/mensajes.hpp"
#include "../include/mensajes.pb.h"
#include <iostream>
#include <string>
#include <cstring>
#include <chrono>

bool ProtoServer::protocolo_comunicacion_send(std::string &mensaje)
{
    // Convertir el tamaño del mensaje a network byte order
    int size_msg = mensaje.size();
    uint32_t network_number = htonl(size_msg);

    // Convertir a cadena de bytes
    std::string size_data(sizeof(network_number), 0);
    std::memcpy(&size_data[0], &network_number, sizeof(network_number));

    // Enviar el tamaño del mensaje
    int total_bytes_sent = 0;
    int bytes_sent = 0;
    while (total_bytes_sent < sizeof(network_number))
    {
        bytes_sent = this->client.send(size_data.substr(total_bytes_sent));
        if (bytes_sent < 0)
        {
            std::cerr << "Error al enviar el tamaño del mensaje" << std::endl;
            return false;
        }
        total_bytes_sent += bytes_sent;
    }

    // Enviar el mensaje
    total_bytes_sent = 0;
    while (total_bytes_sent < size_msg)
    {
        bytes_sent = this->client.send(mensaje.substr(total_bytes_sent));
        if (bytes_sent < 0)
        {
            std::cerr << "Error al enviar el mensaje" << std::endl;
            return false;
        }
        total_bytes_sent += bytes_sent;
    }
    return true;
}

bool ProtoServer::protocolo_comunicacion_recv(std::string &mensaje)
{
    // Recibir el tamaño del mensaje
    uint32_t network_number;
    std::string size_data(sizeof(network_number), 0);
    int bytes_received = 0;
    int total_bytes_received = 0;
    auto start_time = std::chrono::steady_clock::now();
    const auto timeout_duration = std::chrono::seconds(5); // Temporizador de 5 segundos

    // Recibir los bytes del tamaño del mensaje
    while (total_bytes_received < sizeof(network_number))
    {
        std::string temp_data(sizeof(network_number) - total_bytes_received, 0);
        bytes_received = this->client.recv(temp_data, sizeof(network_number) - total_bytes_received);
        if (bytes_received < 0)
        {
            std::cerr << "Error al recibir el tamaño del mensaje" << std::endl;
            return false;
        }
        size_data.replace(total_bytes_received, bytes_received, temp_data, 0, bytes_received);
        total_bytes_received += bytes_received;

        // Verificar si el tiempo ha excedido el límite
        if (std::chrono::steady_clock::now() - start_time > timeout_duration)
        {
            std::cerr << "Tiempo de espera excedido al recibir el tamaño del mensaje" << std::endl;
            return false;
        }
    }

    // Convertir el tamaño del mensaje a host byte order
    std::memcpy(&network_number, size_data.data(), sizeof(network_number));
    int size_msg = ntohl(network_number);

    // Preparar para recibir el mensaje completo
    mensaje.resize(size_msg);
    total_bytes_received = 0;
    start_time = std::chrono::steady_clock::now();

    // Recibir el mensaje en fragmentos
    while (total_bytes_received < size_msg)
    {
        std::string temp_data(size_msg - total_bytes_received, 0);
        bytes_received = this->client.recv(temp_data, size_msg - total_bytes_received);
        if (bytes_received < 0)
        {
            std::cerr << "Error al recibir el mensaje" << std::endl;
            return false;
        }
        mensaje.replace(total_bytes_received, bytes_received, temp_data, 0, bytes_received);
        total_bytes_received += bytes_received;

        // Verificar si el tiempo ha excedido el límite
        if (std::chrono::steady_clock::now() - start_time > timeout_duration)
        {
            std::cerr << "Tiempo de espera excedido al recibir el mensaje" << std::endl;
            return false;
        }
    }
    return true;
}

ProtoServer::ProtoServer(int dominio, int tipo, int protocolo, std::string ip, int puerto)
{
    if (!this->server.create(dominio, tipo, protocolo))
    {
        std::cerr << "Failed to create server socket" << std::endl;
        exit(1);
    }

    if (!this->server.bind(ip, puerto))
    {
        std::cerr << "Failed to bind server socket" << std::endl;
        exit(1);
    }

    if (!this->server.listen())
    {
        std::cerr << "Failed to listen on server socket" << std::endl;
        exit(1);
    }

    std::cout << "Server is listening on " << ip << ":" << puerto << std::endl;

    if (!this->server.accept(this->client))
    {
        std::cerr << "Failed to accept client connection" << std::endl;
        exit(1);
    }
}

ProtoServer::~ProtoServer()
{
    this->client.close();
    this->server.close();
}

bool ProtoServer::estado_conexion_fronted()
{
    std::string mensaje;
    mensaje::conexion estado;
    if (this->protocolo_comunicacion_recv(mensaje))
    {
        if (estado.ParseFromString(mensaje))
        {
            return estado.estado();
        }
        else
        {
            std::cerr << "Error al deserializar el mensaje de estado de conexion" << std::endl;
            return false;
        }
    }
    else
    {
        std::cerr << "Error al recibir el mensaje de estado de conexion" << std::endl;
        return false;
    }
}

bool ProtoServer::estado_conexion_backend(const bool &estado)
{
    this->estado_conexion.set_estado(estado);
    std::string mensaje;
    if ((*this->estado_conexion.build()).SerializeToString(&mensaje))
    {
        this->protocolo_comunicacion_send(mensaje);
        return true;
    }
    else
    {
        std::cerr << "Error al serializar el mensaje de estado de conexion" << std::endl;
        return false;
    }
}

bool ProtoServer::iniciar_conexion(const bool &estado)
{
    return this->estado_conexion_backend(estado);
}

bool ProtoServer::enviar_busqueda(const mensaje::Resultado_Busqueda &resultado)
{
    std::string mensaje;
    if (resultado.SerializeToString(&mensaje))
    {
        return this->protocolo_comunicacion_send(mensaje);
    }
    else
    {
        std::cerr << "Error al serializar el mensaje de resultado de busqueda" << std::endl;
        return false;
    }
}

bool ProtoServer::solicitud_busqueda(const mensaje::Busqueda &busqueda)
{
    std::string mensaje;
    if (this->protocolo_comunicacion_recv(mensaje))
    {
        if (busqueda.SerializeToString(&mensaje))
        {
            return this->protocolo_comunicacion_send(mensaje);
        }
        else
        {
            std::cerr << "Error al serializar el mensaje de busqueda" << std::endl;
            return false;
        }
    }
    else
    {
        std::cerr << "Error al recibir el mensaje de busqueda" << std::endl;
        return false;
    }
}