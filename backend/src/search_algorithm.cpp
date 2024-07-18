#include "../include/search_algorithm.hpp"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdlib>
#include <thread>
#include <future>
#include <map>
using namespace std;

/*
Procedimientos planeados:

0) Metodo 'Leer Datos': Crear el metodo 'leerDatos' para que cada fila(Pelicula) se agregue como clase 'Pelicula' al vector<Pelicula>
del ADMIN(singleton administrador).

1) Limpieza de datos: Imprimir los atributos de cada pelicula(tag,ID, Titulo...) para ver si coinciden con los
del .csv, si no podemos eliminar peliculas(esto lo sugirio el profesor)

2) Procesamiento de Peliculas: Por cada pelicula del vector 'Base_de_datos', iterar en cada letra de las palabras
de su titulo, sinopsis, tags,... Por cada letra inicial se llama o crea un arbol de los atributos del ADMIN.
Luego, en las siguientes letras, se llama o crea un nodo nuevo dentro del set<Nodo*> del anterior nodo de la letra anterior.
Para asi insertar la pelicula en el set<Pelicula*> del nodo actual. Esto podriamos hacerlo paralelamente con threads.

3) Busqueda de Peliculas: Esto se puede realizar, insertando varias palabras. Por cada palabra, se llamaria a una funcion
Busqueda_Titulos de ADMIN, para que cada palabra retorne un set<Peliculas> y iteremos entre esas peliculas para retornar
las peliculas que mas se repiten en los set<Peliculas> de esas varias palabras.

*/

// Idea inicial: Va a existir un ST para cada letra que sera la raiz de este arbol. Se creara por crearRama()
// IDEA ROBUSTA: Podriamos llamar consecutivamente al metodo crearRama() en cada sub-string de cada palabra ingresada

void ST::crearRama(string s, Pelicula *P)
{ // por cada palabra, crea un camino, que tiene nodos. Y cada nodo de ese camino tiene a esa pelicula.
    // Insertaremos la pelicula en cada creacion de nodo y crearemos los nodos
    Nodo *iter = raiz;
    raiz->agregarPelicula(P);
    for (int i = 1; i < s.size(); i++)
    {
        iter->agregarNodo(s[i]);
        iter = iter->mapaNodos[s[i]];
        iter->agregarPelicula(P);
    }
}

Nodo *ST::buscarNodo(string s)
{ // Se encuentro conforme vayan leyendo los chars
    // Retorna puntero a nodo vacio si no encuentra un char en el arbol siguiendo su camino.
    if (s.empty())
    {
        return nullptr;
    }
    Nodo *nodo_final = raiz;
    for (int i = 1; i < s.size(); i++)
    {
        if (nodo_final->mapaNodos.find(s[i]) == nodo_final->mapaNodos.end())
        {
            return nodo_final;
        }
        nodo_final = nodo_final->mapaNodos[s[i]];
    }
    return nodo_final;
}

unordered_set<Pelicula *> ST::retornarpeliculas(string s)
{ // Envia o retorna las peliculas del nodo final buscado
    Nodo *nodo;
    nodo = buscarNodo(s);
    if (nodo != nullptr)
    {
        return nodo->getPeliculas();
    }
    unordered_set<Pelicula *> vacio = {};
    return vacio;
}

void ST::EliminarNodos(Nodo *padre)
{
    if (!padre->mapaNodos.empty())
    {
        for (pair<char, Nodo *> hijo : padre->mapaNodos)
        {
            EliminarNodos(hijo.second);
        }
    }
    delete padre;
}

Admin *Admin::ADMIN_0 = nullptr;

Admin *Admin::getInstance()
{
    if (ADMIN_0 == nullptr)
    {
        ADMIN_0 = new Admin();
        atexit(cleanup);
    }
    return ADMIN_0;
}

void Admin::cleanup()
{
    ADMIN_0->destruir_mapaST();
    ADMIN_0->eliminar_BD();
    delete ADMIN_0;
    ADMIN_0 = nullptr;
    cout << "Limpiado" << endl;
}

/*
void Admin::ProcesarDatos(std::ifstream &archivo_csv)
{
    if (!archivo_csv.is_open())
    {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return;
    }

    std::vector<std::future<void>> futures;
    std::vector<Pelicula *> peliculas_temp;
    std::mutex mtx;

    auto procesar_linea = [&mtx, &peliculas_temp](const std::string &linea)
    {
        std::istringstream ss(linea);
        std::string oracion;
        std::vector<std::string> fila;

        while (std::getline(ss, oracion, ','))
        {
            if (oracion.front() == '"')
            {
                if ((oracion.back() != '"') || (oracion.back() == '"' && oracion.substr(0, oracion.length() - 1).back() == '"' && oracion.substr(0, oracion.length() - 2).back() != '"'))
                {
                    std::string temp = oracion;
                    bool amedias = true;
                    while (std::getline(ss, oracion, ','))
                    {
                        temp += ',' + oracion;
                        if (!((oracion.back() != '"') || (oracion.back() == '"' && oracion.substr(0, oracion.length() - 1).back() == '"' && oracion.substr(0, oracion.length() - 2).back() != '"')))
                        {
                            amedias = false;
                            break;
                        }
                    }
                    oracion = temp;
                }
            }
            fila.push_back(oracion);
        }

        if (fila.size() >= 6)
        {
            Pelicula *P = new Pelicula();
            P->id = fila[0];
            P->titulo = fila[1];
            P->sinopsis = fila[2];
            P->tags = fila[3];
            P->split = fila[4];
            P->sinop_src = fila[5];

            std::lock_guard<std::mutex> lock(mtx);
            peliculas_temp.push_back(P);
        }
    };

    std::string linea;
    while (std::getline(archivo_csv, linea))
    {
        futures.push_back(std::async(std::launch::async, procesar_linea, linea));
    }

    for (auto &fut : futures)
    {
        fut.get();
    }

    std::lock_guard<std::mutex> lock(mtx);
    this->Base_de_datos = std::move(peliculas_temp);
}
*/

void Admin::ProcesarDatos(ifstream &archivo_csv)
{
    // El algoritmo de basa en obtener los 6 atributos de cada pelicula y cada que complete 6, se agrega a la Base de Datos
    if (!archivo_csv.is_open())
    {
        cerr << "Error al abrir el archivo." << endl;
    }
    int atributos = 0;
    Pelicula *P = new Pelicula();
    string linea;
    vector<string> fila;
    while (getline(archivo_csv, linea, '\n'))
    {
        string oracion;
        istringstream ss(linea);
        while (getline(ss, oracion, ','))
        {
            if (oracion.front() == '"')
            {

                if ((oracion.back() != '"') || (oracion.back() == '"' && oracion.substr(0, oracion.length() - 1).back() == '"' && oracion.substr(0, oracion.length() - 2).back() != '"'))
                { // Si continuas
                    string temp;
                    temp = temp + oracion;
                    bool amedias = true;
                    while (getline(ss, oracion, ','))
                    {
                        temp = temp + ',' + oracion;
                        if (!((oracion.back() != '"') || (oracion.back() == '"' && oracion.substr(0, oracion.length() - 1).back() == '"' && oracion.substr(0, oracion.length() - 2).back() != '"')))
                        {
                            amedias = false;
                            break;
                        }
                    }
                    while (amedias && getline(archivo_csv, oracion, ',')) // Aqui, salta a la proxima fila, por el salto de linea en el getline
                    {
                        temp = temp + ',' + oracion;
                        if (!((oracion.back() != '"') || (oracion.back() == '"' && oracion.substr(0, oracion.length() - 1).back() == '"' && oracion.substr(0, oracion.length() - 2).back() != '"')))
                        {
                            break;
                        }
                    }
                    oracion = temp;
                }
            }
            if (!oracion.empty())
            {
                fila.push_back(oracion);
                atributos++;

                if (fila.size() >= 6)
                {
                    P->id = fila[0];
                    P->titulo = fila[1];
                    P->sinopsis = fila[2];
                    P->tags = fila[3];
                    P->split = fila[4];
                    P->sinop_src = fila[5];
                    this->Base_de_datos.push_back(P);
                    fila = {};
                    P = new Pelicula();
                }
            }
        }
    }
}

// IDEA ROBUSTA: Aplicar ST::CrearRama(string s) por cada sub-array de s.
/*
void Admin::Crear_Estructura()
{
    std::vector<std::future<void>> futures;
    std::mutex mtx;

    auto procesar_pelicula = [this, &mtx](Pelicula *e)
    {
        auto procesar_texto = [this, &mtx](const std::string &texto, Pelicula *pelicula)
        {
            std::istringstream ss(texto);
            std::string palabra;
            while (std::getline(ss, palabra, ' '))
            {
                std::lock_guard<std::mutex> lock(mtx);
                if (mapaSearchTrees.find(palabra[0]) == mapaSearchTrees.end())
                {
                    ST *arbol = new ST(palabra[0]);
                    mapaSearchTrees[palabra[0]] = arbol;
                }
                mapaSearchTrees[palabra[0]]->crearRama(palabra, pelicula);
            }
        };

        procesar_texto(e->titulo, e);
        procesar_texto(e->sinopsis.substr(1, e->sinopsis.length() - 2), e);
    };

    for (Pelicula *e : Base_de_datos)
    {
        futures.push_back(std::async(std::launch::async, procesar_pelicula, e));
    }

    for (auto &fut : futures)
    {
        fut.get();
    }
}
*/

void Admin::Crear_Estructura()
{ // Si o si utilizar threads porque puede ser bien lento
    for (Pelicula *e : Base_de_datos)
    {
        istringstream ss(e->titulo);
        string palabra;
        while (getline(ss, palabra, ' '))
        {
            if (mapaSearchTrees.find(palabra[0]) == mapaSearchTrees.end())
            {
                ST *arbol = new ST(palabra[0]);
                mapaSearchTrees[palabra[0]] = arbol; // Aqui se crearian los arboles si no estan creados
            }
            mapaSearchTrees[palabra[0]]->crearRama(palabra, e); // Creacion de la rama en un arbol en especifico
        }

        istringstream s1(e->sinopsis.substr(1, e->sinopsis.length() - 2));
        string palabra2;
        while (getline(s1, palabra2, ' '))
        {
            if (mapaSearchTrees.find(palabra2[0]) == mapaSearchTrees.end())
            {
                ST *arbol = new ST(palabra2[0]);
                mapaSearchTrees[palabra2[0]] = arbol;
            }
            mapaSearchTrees[palabra2[0]]->crearRama(palabra2, e);
        }
    }
}

unordered_set<Pelicula *> Admin::RetornarPeliculas(const string s)
{ // Obtiene las peliculas del nodo final buscado
    if (s.size() != 0 and mapaSearchTrees.find(s[0]) != mapaSearchTrees.end())
    {
        ST *Arbol = mapaSearchTrees[s[0]];
        Nodo *Nodo_final = Arbol->buscarNodo(s);
        return Nodo_final->getPeliculas();
    }
    else
    {
        unordered_set<Pelicula *> vacio = {};
        return vacio;
    }
}

// FUNCION FINAL
vector<Pelicula> Admin::Busqueda_titulos(const string &frase)
{                                               // Va a constituir espacio y letras
    unordered_map<Pelicula *, int> apariciones; // Debe estar aqui en GUI para insertar las frases de busqueda
    istringstream ss(frase);
    string palabra;
    while (getline(ss, palabra, ' '))
    {
        unordered_set<Pelicula *> Pelis_temp = RetornarPeliculas(palabra);
        if (!Pelis_temp.empty())
        {
            for (auto it = Pelis_temp.begin(); it != Pelis_temp.end(); it++)
            {
                apariciones[*it] = apariciones[*it] + 1;
            }
        }
    }
    vector<pair<Pelicula *, int>> Pelis_coincidentes(apariciones.begin(), apariciones.end());
    // Ordena el vector por apariciones
    std::sort(Pelis_coincidentes.begin(), Pelis_coincidentes.end(), [](pair<Pelicula *, int> p1, pair<Pelicula *, int> p2)
              { return p1.second > p2.second; });
    // No alteraria el orden
    vector<Pelicula> Pelis_definitivas;
    int peliculas_max_mostrar = 20;
    for (auto iter = Pelis_coincidentes.begin(); iter != Pelis_coincidentes.end(); iter++)
    {
        if (!peliculas_max_mostrar--)
        {
            break;
        }
        Pelis_definitivas.push_back(*((*iter).first));
    }
    return Pelis_definitivas;

    // Lo siguiente seria la impresion de las peliculas en el GUI.
}

void Admin::eliminar_BD()
{
    for (auto e : Base_de_datos)
    {
        delete e;
    }
    Base_de_datos.clear();
}

void Admin::destruir_mapaST()
{
    for (pair<char, ST *> iter : mapaSearchTrees)
    {
        iter.second->EliminarNodos(iter.second->raiz);
        delete iter.second;
    }
    mapaSearchTrees.clear();
}

void ProcesarDatos_Aux(ifstream &archivo_csv, Admin *ADMIN)
{
    ADMIN->ProcesarDatos(archivo_csv);
}

/*
// Decorator para agregar logueo de búsqueda
class SearchAlgorithmDecorator
{
protected:
    vector<pair<Pelicula *, int>> (*searchFunction)(Admin *);

public:
    SearchAlgorithmDecorator(vector<pair<Pelicula *, int>> (*searchFunction)(Admin *))
        : searchFunction(searchFunction) {}

    virtual vector<pair<Pelicula *, int>> buscar(Admin *admin)
    {
        return searchFunction(admin);
    }
};

class SearchLoggerDecorator : public SearchAlgorithmDecorator
{
public:
    SearchLoggerDecorator(vector<pair<Pelicula *, int>> (*searchFunction)(Admin *))
        : SearchAlgorithmDecorator(searchFunction) {}

    vector<pair<Pelicula *, int>> buscar(Admin *admin) override
    {
        auto resultados = SearchAlgorithmDecorator::buscar(admin);
        logSearch(resultados);
        return resultados;
    }

private:
    void logSearch(const vector<pair<Pelicula *, int>> &resultados)
    {
        ofstream logFile("search_log.txt", ios::app);
        logFile << "Busqueda realizada" << endl;
        logFile << "Resultados:" << endl;
        for (const auto &resultado : resultados)
        {
            logFile << " - " << resultado.first->titulo << endl;
        }
        logFile << "----------------------------------------" << endl;
        logFile.close();
    }
};

vector<pair<Pelicula *, int>> buscarConDecorador(Admin *admin)
{
    return admin->Busqueda_titulos();
}
*/