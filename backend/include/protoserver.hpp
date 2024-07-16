#pragma once

#include <iostream>
#include <memory>
#include "../SoapComm/sopasockets.hpp"
#include "mensajes.pb.h"
#include "builders/mensajes.hpp"

class ProtoServer
{
    SopaSocket server;
    SopaSocket client;
    ConexionBuilder estado_conexion;

    /*
    Protocolo de comunicacion para enviar mensajes:
    1. Se envia el tamaño del mensaje en network byte order
    2. Se envia el mensaje
    */
    bool protocolo_comunicacion_send(std::string &mensaje);
    /*
    Protocolo de comunicacion para recibir mensajes:
    1. Se recibe el tamaño del mensaje en network byte order
    2. Se recibe el mensaje
    */
    bool protocolo_comunicacion_recv(std::string &mensaje);

public:
    ProtoServer(int dominio, int tipo, int protocolo, std::string ip, int puerto);
    ~ProtoServer();
    /*
    Devuelve el estado de la conexion
    */
    bool estado_conexion_fronted();
    /*

    */
    bool estado_conexion_backend(const bool &estado);
    /*
    El primer mensaje de confirmacion de conexion al frontend
    true: Conexion establecida
    false: Conexion fallida
    PD: Si algo sale mal al carga el backend marcalo como false
    */
    bool iniciar_conexion(const bool &estado);
    bool enviar_busqueda(const mensaje::Resultado_Busqueda &resultado);
    /*
    Recibe un mensaje serializado y lo deserializa
    */
    bool solicitud_busqueda(const mensaje::Busqueda &busqueda);
};