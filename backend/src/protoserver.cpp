#include "backend/include/protoserver.hpp"
#include "backend/include/mensajes.pb.h"
#include <iostream>
#include <string>

ProtoServer::ProtoServer()
{
    this->server = ServerSocket();
}