#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <string>
#include <thread>
#include <mutex>
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
vector<string> buscarPeliculas(const vector<string>& baseDeDatos, const string& frase) {
    map<int, vector<string>, greater<int>> mapaOrdenado;
    mutex mtx;
    vector<thread> threads;

    auto calcularYAgregar = [&](const string& titulo) {
        int puntaje = calcularPuntaje(titulo, frase);
        if (puntaje > 0) {
            lock_guard<mutex> lock(mtx);
            mapaOrdenado[puntaje].push_back(titulo);
        }
    };

    // Crear hilos para procesar en paralelo
    for (const string& titulo : baseDeDatos) {
        threads.emplace_back(calcularYAgregar, titulo);
    }

    // Unir los hilos
    for (auto& t : threads) {
        t.join();
    }

    // Recopilar los resultados ordenados por puntaje
    vector<string> resultados;
    for (const auto& par : mapaOrdenado) {
        for (const string& titulo : par.second) {
            resultados.push_back(titulo);
        }
    }

    return resultados;
}

int main() {
    // Base de datos de películas/series
    vector<string> baseDeDatos = {
        "a",
        "b",
        "c",
        "d",
        "e"
    };

    // Leer la frase de búsqueda
    string frase;
    cout << "Ingrese la Pelicula/Serie: ";
    getline(cin, frase);

    // Buscar películas/series similares
    vector<string> resultados = buscarPeliculas(baseDeDatos, frase);

    // Mostrar resultados
    cout << "Resultados encontrados:\n";
    for (const string& titulo : resultados) {
        cout << titulo << endl;
    }

    return 0;
}
