#include "backend/include/protoserver.hpp"
#include "backend/include/mensajes.pb.h"
#include "backend/include/search_algorithm.hpp"

int main()
{
    mensaje::initBackend init;
    init.set_iniciar(true);

    ProtoServer server;
    server.confirmar_conexion(init);
    while (true)
    {
        string input;
        if (!server.solicitud_busqueda(input))
        {
            break;
        }
        else
        {
            mensaje::Busqueda resultado;
            resultado.ParseFromString(input);
            
            server.enviar_mensaje();
        }
    }
    return 0;
}