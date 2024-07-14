#ifndef SEARCH_ALGORITHM_H
#define SEARCH_ALGORITHM_H

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <string>
#include <thread>
#include <mutex>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
struct Pelicula
{
    std::string id;
    std::string titulo;
    std::string tags;
    std::string sinopsis;
    std::string split;
    std::string sinop_src;

    // Puedes agregar más campos según los datos que contenga tu base de datos

    Pelicula(string i, string ti, string tgs, string sin, string spl, string sin_s) : id(i), titulo(ti), tags(tgs), sinopsis(sin), split(spl), sinop_src(sin_s) {}
    Pelicula() {}
};

// Función para calcular la similitud entre el título y la frase de búsqueda
int calcularPuntaje(const std::string &titulo, const std::string &frase);

// Función de búsqueda que retorna los títulos más similares
std::vector<Pelicula> buscarPeliculas(const std::vector<Pelicula> &baseDeDatos, const std::string &frase);

// Función para cargar la base de datos desde un archivo CSV
std::vector<Pelicula> cargarBaseDeDatos(const std::string &nombreArchivo);

// Funcion para agregar a "Ver mas tarde"
void agregar_Pelicula(const Pelicula &Peli, std::vector<Pelicula> Ver_mas_tarde);

#endif // SEARCH_ALGORITHM_H
