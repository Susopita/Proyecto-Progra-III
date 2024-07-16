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
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <fstream>
#include <ctime>

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

struct Nodo
{

    char letra;
    unordered_map<char, Nodo *> mapaNodos; // Mapa de nodos que van a ser pusheados por un recorrido en la base de datos.
    unordered_set<Pelicula *> Peliculas;   // Peliculas que va a tener cada nodo

    Nodo(char c) : letra(c)
    {
        mapaNodos = {};
        Peliculas = {};
    }
    Nodo()
    {
        mapaNodos = {};
        Peliculas = {};
    }
    void agregarNodo(char c)
    {
        if (mapaNodos.find(c) == mapaNodos.end())
        {
            Nodo *nodo = new Nodo(c); // Asigna el char del nodo
            mapaNodos[c] = nodo;      // Lo pushea al mapa
        }
    }
    void agregarPelicula(Pelicula *Peli)
    {
        Peliculas.insert(Peli);
    }
    unordered_set<Pelicula *> getPeliculas()
    {
        return Peliculas;
    }
};

struct ST
{
    char letra_inicial;
    Nodo *raiz = nullptr;

    ST(char c) : letra_inicial(c)
    {
        raiz = new Nodo(c);
    }
    void crearRama(string s, Pelicula *);
    Nodo *buscarNodo(string s);
    unordered_set<Pelicula *> retornarpeliculas(string s);
    // El metodo para eleminar los nodos se va adescontrolar
    void EliminarNodos(Nodo *padre);
};

class Admin
{ // Clase adminitradora de toda funcion.
private:
    Admin() {}
    static Admin *ADMIN_0;
    vector<Pelicula *> Base_de_datos;
    map<char, ST *> mapaSearchTrees;

    void eliminar_BD();

    void destruir_mapaST();

    static void cleanup();

    // Prohibit copy and assignment
    Admin(const Admin &) = delete;
    Admin &operator=(const Admin &) = delete;

public:
    static Admin *getInstance();

    void ProcesarDatos(ifstream &archivo_csv);

    void Crear_Estructura();

    unordered_set<Pelicula *> RetornarPeliculas(const string s);

    vector<Pelicula> Busqueda_titulos(const string &frase);
};

// Función para calcular la similitud entre el título y la frase de búsqueda
// int calcularPuntaje(const std::string &titulo, const std::string &frase);

// Función de búsqueda que retorna los títulos más similares
// std::vector<Pelicula> buscarPeliculas(const std::vector<Pelicula> &baseDeDatos, const std::string &frase);

// Función para cargar la base de datos desde un archivo CSV
// std::vector<Pelicula> cargarBaseDeDatos(const std::string &nombreArchivo);

#endif // SEARCH_ALGORITHM_H