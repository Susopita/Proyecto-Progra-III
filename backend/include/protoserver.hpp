#pragma once

#include <iostream>
#include <memory>
#include "backend/include/server.hpp"
#include "backend/include/mensajes.pb.h"

class ProtoServer
{
    ServerSocket server;

public:
    ProtoServer();
    ~ProtoServer();
    /*
    Recibe un mensaje serializado y lo envía al cliente
    */
    bool confirmar_conexion(mensaje::initBackend &isinit);
    bool enviar_mensaje(mensaje::Resultado_Busqueda &resultado);
    /*
    Recibe un mensaje serializado y lo deserializa
    */
    bool solicitud_busqueda(mensaje::Busqueda &busqueda);
};