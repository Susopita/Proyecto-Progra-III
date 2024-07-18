#include "../../backend/include/search_algorithm.hpp"
#include "/Users/Tiziano/Desktop/cpp/scripts/resolucionEjercicios/Utilidades.cpp"
#include <iostream>
#include <fstream>
#include <vector>

/*
Compilacion:
g++ -std=c++20 tests/tiempo_carga_algoth_busqueda/test_tiempo_ADMIN.cpp backend/src/search_algorithm.cpp -pthread -o tests/tiempo_carga_algoth_busqueda/test
*/

int main()
{
    temporizador clocker;
    std::vector<Pelicula> busqueda_resultados;
    std::ifstream archivo("/Users/Tiziano/Desktop/cpp/Progra-3/Proyecto-Progra-III/backend/resources/data/base_de_datos.csv", std::ios::in);
    Admin *admin = Admin::getInstance();
    clocker.comenzar();
    admin->ProcesarDatos(archivo);
    archivo.close();
    clocker.finalizar();

    std::cout << "Tiempo de carga de la base de datos: " << clocker.observar_tiempo() << " ms" << std::endl;

    clocker.comenzar();
    admin->Crear_Estructura();
    clocker.finalizar();

    std::cout << "Tiempo de carga de la estructura: " << clocker.observar_tiempo() << " ms" << std::endl;

    clocker.comenzar();
    busqueda_resultados = admin->Busqueda_titulos("Scooby-Doo");
    clocker.finalizar();

    std::cout << "Tiempo de busqueda de la pelicula 'Scooby-Doo': " << clocker.observar_tiempo() << " ms" << std::endl;

    for (const Pelicula &pelicula : busqueda_resultados)
    {
        std::cout << "Titulo: " << pelicula.titulo << std::endl;
        std::cout << "Tags: " << pelicula.tags << std::endl;
    }
    try
    {
        busqueda_resultados = admin->Busqueda_titulos(" ");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    clocker.finalizar();

    std::cout << "Tiempo de busqueda de la pelicula ' ': " << clocker.observar_tiempo() << " ms" << std::endl;

    for (const Pelicula &pelicula : busqueda_resultados)
    {
        std::cout << "Titulo: " << pelicula.titulo << std::endl;
        std::cout << "Tags: " << pelicula.tags << std::endl;
    }
    return 0;
}