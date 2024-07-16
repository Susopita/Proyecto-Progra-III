#include "../../backend/include/protoserver.hpp"
#include "../../backend/include/builders/mensajes.hpp"
#include "../../backend/src/search_algorithm.cpp"

const int DOMINIO = AF_INET;
const int TIPO = SOCK_STREAM;
const int PROTOCOL = 0;
const std::string IP = "127.0.0.1";
const int PUERTO = 8080;

int main()
{
    ConexionBuilder estado;
    PeliculaBuilder pelibuild;
    ResultadoBusquedaBuilder resultado;

    vector<Pelicula> baseDeDatos = cargarBaseDeDatos("base_de_datos.csv");
    SearchLoggerDecorator loggerDecorator(buscarPeliculas);

    ProtoServer server(
        DOMINIO,
        TIPO,
        PROTOCOL,
        IP,
        PUERTO);
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
            vector<Pelicula> busqueda_resultados = loggerDecorator.buscar(baseDeDatos, input.texto());

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