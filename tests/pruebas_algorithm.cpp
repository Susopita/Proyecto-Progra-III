#include "../backend/include/search_algorithm.hpp"
using namespace std; 


class Categorias{
    private:
    int numero_de_peliculas;
    public: 
    virtual int get_cantidad(){
        return numero_de_peliculas; 
    }
};

class Nodo{
    private:
    char letra;
    unordered_map <char, Nodo*> mapaNodos; //Mapa de nodos que van a ser pusheados por un recorrido en la base de datos.
    unordered_set <Pelicula*> Peliculas;  

    public:
    Nodo(char c):letra(c){}
    void agregarNodo(char c){ //un nodo o un char?
        if(mapaNodos.find(c) == mapaNodos.end()){//si no lo encuentra
            Nodo* nodo = new Nodo(c);
            mapaNodos[c] = nodo;
            //Comparar con la teoria de BST y como no pushear repetido. Direcciones 
        }
    }
    void agregarPelicula(Pelicula* Peli){ //en cada iteraciones
        Peliculas.insert(Peli);
    }
    unordered_set <Pelicula*> getPeliculas(){
        return Peliculas; 
    }
};  

class ST{ //Va a existir un ST para cada letra de abecedario (lo mas probable)
    private:
    Nodo* raiz; 
    char letra_inicial; 

    public:
    ST(char c):letra_inicial(c){}
    //void crearRama(string s); 
    //Nodo* buscarNodo(string s); //debemos tener un recuento de donde debe estar este char
    //unordered_set <Pelicula*> retornarpeliculas(string s);//Lo podemos agregar a buscar nodo 
}; 
/*
void ST::crearRama(string s){
    // Insertaremos la pelicula en cada creacion de nodo y crearemos los nodos
    
}
*/

/*
Nodo* ST::buscarNodo(string s){ //Vamos a encontrar conforme vayan lleyendo los chars, o se puede por string? 
    // Suponemos que ya esta la estructura creada y solo profundizamos en el arbol de la primera letra de s
}*/

/*
unordered_set <Pelicula*> ST::retornarpeliculas(string s){
    Nodo* nodo; 
    nodo = buscarNodo(s); 
    return nodo->getPeliculas();
}*/

class Admin{ //Para que quiero una instancia de una clase? 
    private:// Singleton
    Admin(){} 
    static Admin* ADMIN_0; 
    vector<Pelicula*> Base_de_datos; //Solo una base de datos 
    //una lista de peliculas que me gustan
    vector<Pelicula*> Pelis_me_gusta; 
    //una lista de peliculas para ver mas tarde
    vector<Pelicula*> Ver_mas_tarde; 
    //una set de categorias de peliculas- puede ser una clase tal que se puedan comunicar con el admin(observer) 
    map<char, ST> mapaSearchTrees; 
    //Para identificar si el caracter ingresado es nuevo o no. Y para que lo busque en su arbol determinado
    
    public:

    void ProcesarDatos(ifstream &archivo_csv); //Convertir csv a vector<Pelicula>

    //void agregar_pelicula_me_gusta(); //Patron Builder: Como se puede relacion esto? 

    //void agregar_pelicula_vermastarde();

    static Admin* getInstance(){ //Patron de diseno: Singleton 
        if (ADMIN_0 == nullptr)
        {
            Admin* AD = new Admin();
            ADMIN_0 = AD;
        }
        return ADMIN_0; 
    }
    void Busqueda_titulos(string palabra){ //Que pasa si insertamos frases? los espacios contarian como una sola palabra? 
        /*
        1) Podemos utilizar la idea del profesor de generar un puntero por cada letra y que esta apunte a un titulo o nombre
        que tenga la similitud del camino que esta formando con otros punteros junto a el. 
        */
        /*
        2) Los espacio no contarian como una sola palabra, porque el usuario podria insertar palabras desordenadas.
        
        3) Entonces podriamos crear un algoritmo que junte las peliculas que esten en los nodos finales. Como que si
        encuentra la pelicula en los nodos finales. Pero si no los encuentra en todos pero en algunos si? 
        - Podemos crear un mapa global que cuente las veces que una pelicula aparece, cuando retornemos el set de peliculas 
        por cada palabra buscada. 
    
        5) Primero parceo: Tendriamos que observar cuales datos se pueden eliminar. 

        6) si insertamos rk: deberia de retornar tmb peliculas que tengan el rk y no inicien necesariamente con eso. 
        - Podriamos insertar la pelicula de cada arbol anteriormente llamado en letras anteriores. 
        */
    }
    void imprimir_BD(){
        for (Pelicula* P: Base_de_datos)
        {
            cout << "ID: " << P->id << endl;
            cout << "Titulo: " << P->titulo << endl;
            cout << "Resena muy larga para imprimirla" << endl; 
            cout << "Tags: " << P->tags << endl;
        }
        
    }
}; 

void Admin::ProcesarDatos(ifstream& archivo_csv){//queremos convertir el .csv y vector<Peliculas>
    //Podemos utilizar threads
    if(!archivo_csv.is_open()){
        cerr << "Error al abrir el archivo." << endl;
    }
    string linea; 
    while (getline(archivo_csv, linea, '\n'))
    {
        Pelicula* P = new Pelicula();
        vector<string> fila;
        istringstream ss(linea);
        string oracion;
        while(getline(ss,oracion,',')){
            fila.push_back(oracion);
        }
        if(fila.size() >= 6){
            P->id = fila[0];
            P->titulo = fila[1];
            P->sinopsis = fila[2];
            //P->tags = fila[3];
            //P->split = fila[4];
            //P->sinop_src = fila[5];
        }
        Base_de_datos.push_back(P);
    }
    cout << "Id: "<< Base_de_datos[0]->id << endl << "Titulo: "<< Base_de_datos[0]->sinopsis << endl;
}

int main(){
    ifstream archivo("backend\resources\base_de_datos.csv");
    Admin* ADMIN = Admin::getInstance();
    ADMIN->ProcesarDatos(archivo);
}