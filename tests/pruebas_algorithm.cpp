#include "../backend/include/search_algorithm.hpp"
using namespace std; 

class Nodo{
    private:
    char a;
    unordered_map <char, Nodo*> mapaNodos; //Set de nodos que van a ser pusheados por un recorrido en la base de datos.
    unordered_set <int> codigoPeliculas; 

    public:
    Nodo(char c):a(c){}
    void agregarNodo(char c){ //un nodo o un char?
        if(mapaNodos.find(c) == mapaNodos.end()){//si no lo encuentra
            Nodo* nodo = new Nodo(c);
            mapaNodos[c] = nodo;
            //Comparar con la teoria de BST y como no pushear repetido. Direcciones 
        }
    }
    void agregarcodigo(const int &codigo){ //en cada iteraciones
        codigoPeliculas.insert(codigo);
    }
    unordered_set<int> getcodigos(){
        return codigoPeliculas; 
    }
};  

class ST{ //Va a existir un ST para cada letra de abecedario (lo mas probable)
    private:
    Nodo* raiz; 

    public:
    ST(){}
    void insertarNodo(string s); //debemos tener un recuento de donde debe estar este char
    Nodo* buscarNodo(string s);
    int height();  //Lo copie de los problemas hechos en clase 
    void EliminarNodo(char c);
    unordered_set <int> retornarpeliculas(string s);//Lo podemos agregar a buscar nodo 
}; 
void ST::insertarNodo(string s){
    // Insertaremos la pelicula en cada creacion de nodo y crearemos los nodos
    
}

Nodo* ST::buscarNodo(string s){ //Vamos a encontrar conforme vayan lleyendo los chars, o se puede por string? 
    //Iteramos por medio de el string, continuamente creando nodos y agregando la pelicula
}

unordered_set <int> ST::retornarpeliculas(string s){
    Nodo* nodo = buscarNodo(s);
    return nodo->getcodigos();
}


class Admin{ //Para que quiero una instancia de una clase? 
    private:// Singleton
    Admin* ADMIN_0; 
    Admin(){} 
    vector<Pelicula> Base_de_datos; //Solo una base de datos 
    //una lista de peliculas que me gustan
    vector<Pelicula> Pelis_me_gusta; 
    //una lista de peliculas para ver mas tarde
    vector<Pelicula> Ver_mas_tarde; 
    //una set de categorias de peliculas- puede ser una clase tal que se puedan comunicar con el admin(observer) 
    map<char, ST> mapaSearchTrees; 
    //Para identificar si el caracter ingresado es nuevo o no. Y para que lo busque en su arbol determinado
    public:

    void agregar_pelicula_me_gusta(){ //builder Como se puede relacion esto? 

    }

    void agregar_pelicula_vermastarde(){

    }
    void generation(){
        if (ADMIN_0 == nullptr)
        {
            Admin* AD = new Admin();
            ADMIN_0 = AD;
        }
    }

    void Busqueda_titulos(){
        /*
        Podemos utilizar la idea del profesor de generar un puntero por cada letra y que esta apunte a un titulo o nombre
        que tenga la similitud del camino que esta formando con otros punteros junto a el. 
        */

    }
}; 