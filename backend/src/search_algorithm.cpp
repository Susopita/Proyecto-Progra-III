#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <string>
#include <thread>
#include <mutex>
using namespace std;

struct Pelicula
{
    std::string titulo;
    std::string tag;
    std::string sinopsis;
    // Puedes agregar más campos según los datos que contenga tu base de datos
};

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

int main() {
    // Cargar la base de datos desde el archivo CSV
    vector<Pelicula> baseDeDatos = cargarBaseDeDatos("base_de_datos.csv");

    // Leer la frase de búsqueda
    string frase;
    cout << "Ingrese la frase de búsqueda: ";
    getline(cin, frase);

    // Buscar películas/series similares
    vector<Pelicula> resultados = buscarPeliculas(baseDeDatos, frase);

    // Mostrar resultados
    cout << "Resultados encontrados:\n";
    for (const Pelicula& pelicula : resultados) {
        cout << "Título: " << pelicula.titulo << endl;
        cout << "Tag: " << pelicula.tag << endl;
        cout << "Sinopsis: " << pelicula.sinopsis << endl;
        cout << endl;
    }

    return 0;
}
