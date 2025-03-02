#include "../../backend/include/protoserver.hpp"
#include "../../backend/include/builders/mensajes.hpp"
#include "../../backend/include/search_algorithm.hpp"

const int DOMINIO = AF_INET;
const int TIPO = SOCK_STREAM;
const int PROTOCOL = 0;
const std::string IP = "127.0.0.1";
const int PUERTO = 8080;

/*
Compilacion:
g++ -std=c++20 -Ibackend/include -Ibackend/SoapComm tests/comunicacion_b-f/test_backend.cpp backend/src/protoserver.cpp backend/SoapComm/sopasockets.cpp backend/src/mensajes.pb.cc backend/src/search_algorithm.cpp -L/usr/local/lib -lprotobuf -labsl_base -labsl_strings -labsl_time -labsl_log_internal_check_op -labsl_log_internal_conditions -labsl_log_internal_fnmatch -labsl_log_internal_format -labsl_log_internal_globals -labsl_log_internal_log_sink_set -labsl_log_internal_message -labsl_log_internal_nullguard -labsl_log_internal_proto -pthread -o tests/comunicacion_b-f/backend
*/

int main()
{
    ConexionBuilder estado;
    PeliculaBuilder pelibuild;
    ResultadoBusquedaBuilder resultado;

    ProtoServer server(
        DOMINIO,
        TIPO,
        PROTOCOL,
        IP,
        PUERTO);

    ifstream archivo("/Users/Tiziano/Desktop/cpp/Progra-3/Proyecto-Progra-III/backend/resources/data/base_de_datos.csv", std::ios::in);
    Admin *ADMIN = Admin::getInstance();

    // thread t1(ProcesarDatos_Aux, ref(archivo), ADMIN);
    ADMIN->ProcesarDatos(archivo);
    archivo.close();
    // t1.join();
    ADMIN->Crear_Estructura();

    server.iniciar_conexion(true);

    while (true)
    {
        if (!server.estado_conexion_fronted())
        {
            break;
        }

        mensaje::Busqueda input;
        if (!server.solicitud_busqueda(input))
        {
            break;
        }
        else
        {
            std::cout << input.texto() << std::endl;
            vector<Pelicula> busqueda_resultados = ADMIN->Busqueda_titulos(input.texto());

            for (const Pelicula &pelicula : busqueda_resultados)
            {
                pelibuild
                    .set_titulo(pelicula.titulo)
                    .set_tag(pelicula.tags)
                    .set_sinopsis(pelicula.sinopsis);
                resultado.add_pelicula(*pelibuild.build());
            }

            server.enviar_busqueda(*resultado.build());
        }
    }
    return 0;
}