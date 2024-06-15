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

struct Pelicula
{
    std::string titulo;
    std::string tag;
    std::string sinopsis;
    // Puedes agregar más campos según los datos que contenga tu base de datos
};

// Función para calcular la similitud entre el título y la frase de búsqueda
int calcularPuntaje(const std::string& titulo, const std::string& frase);

// Función de búsqueda que retorna los títulos más similares
std::vector<Pelicula> buscarPeliculas(const std::vector<Pelicula>& baseDeDatos, const std::string& frase);

// Función para cargar la base de datos desde un archivo CSV
std::vector<Pelicula> cargarBaseDeDatos(const std::string &nombreArchivo);

#endif // SEARCH_ALGORITHM_H
