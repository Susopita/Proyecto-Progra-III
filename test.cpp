#include <iostream>
#include "backend/include/mensajes.pb.h"
#include "backend/include/protoserver.hpp"

using namespace std;

const int DOMINIO = AF_INET;
const int TIPO = SOCK_STREAM;
const int PROTOCOL = 0;
const std::string IP = "127.0.0.1";
const int PUERTO = 8080;

int main()
{
    ProtoServer servermini(
        DOMINIO,
        TIPO,
        PROTOCOL,
        IP,
        PUERTO);

    servermini.iniciar_conexion(true);
    mensaje::Busqueda xd;
    servermini.solicitud_busqueda(xd);
    cout << "mensaje mini client:" << endl;
    cout << xd.texto() << endl;
    mensaje::Busqueda input;
    input.set_texto("_");
    cout << input.texto() << endl;
    string inputs;
    input.SerializeToString(&inputs);
    input.ParseFromString(inputs);
    cout << input.texto() << endl;
    return 0;
}
