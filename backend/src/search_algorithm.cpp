#include "search_algorithm.h"
using namespace std;

// Función para calcular la similitud entre el título y la frase de búsqueda
int calcularPuntaje(const string& titulo, const string& frase) {
    istringstream tituloStream(titulo);
    istringstream fraseStream(frase);
    string palabraTitulo, palabraFrase;
    map<string, int> frecuenciaTitulo, frecuenciaFrase;

    // Contar la frecuencia de cada palabra en el título
    while (tituloStream >> palabraTitulo) {
        frecuenciaTitulo[palabraTitulo]++;
    }

    // Contar la frecuencia de cada palabra en la frase de búsqueda
    while (fraseStream >> palabraFrase) {
        frecuenciaFrase[palabraFrase]++;
    }

    int puntaje = 0;

    // Calcular el puntaje basado en la coincidencia de palabras
    for (const auto& par : frecuenciaFrase) {
        if (frecuenciaTitulo.find(par.first) != frecuenciaTitulo.end()) {
            puntaje += min(par.second, frecuenciaTitulo[par.first]);
        }
    }

    return puntaje;
}

// Función de búsqueda que retorna los títulos más similares
vector<Pelicula> buscarPeliculas(const vector<Pelicula>& baseDeDatos, const string& frase) {
    map<int, vector<Pelicula>, greater<int>> mapaOrdenado;
    mutex mtx;
    vector<thread> threads;

    auto calcularYAgregar = [&](const Pelicula& pelicula) {
        int puntaje = calcularPuntaje(pelicula.titulo, frase);
        if (puntaje > 0) {
            lock_guard<mutex> lock(mtx);
            mapaOrdenado[puntaje].push_back(pelicula);
        }
    };

    // Crear hilos para procesar en paralelo
    for (const Pelicula& pelicula : baseDeDatos) {
        threads.emplace_back(calcularYAgregar, pelicula);
    }

    // Unir los hilos
    for (auto& t : threads) {
        t.join();
    }

    // Recopilar los resultados ordenados por puntaje
    vector<Pelicula> resultados;
    for (const auto& par : mapaOrdenado) {
        for (const Pelicula& pelicula : par.second) {
            resultados.push_back(pelicula);
        }
    }

    return resultados;
}
