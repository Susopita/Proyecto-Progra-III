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
    Nodo* buscarNodo(string s); //debemos tener un recuento de donde debe estar este char
    //unordered_set <Pelicula*> retornarpeliculas(string s);//Lo podemos agregar a buscar nodo 
}; 
/*
void ST::crearRama(string s){ // por cada palabra, crea un camino, que tiene nodos. Y cada nodo de ese camino tiene a esa pelicula.
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
    unique_ptr<int> f; 
    vector<Pelicula*> Base_de_datos; //Solo una base de datos 
    //una lista de peliculas que me gustan
    vector<Pelicula*> Pelis_me_gusta; 
    //una lista de peliculas para ver mas tarde
    vector<Pelicula*> Ver_mas_tarde; 
    //una set de categorias de peliculas- puede ser una clase tal que se puedan comunicar con el admin(observer) 
    map<char, ST> mapaSearchTrees; 
    //Para identificar si el caracter ingresado es nuevo o no. Y para que lo busque en su arbol determinado
    
    public:

    static Admin* getInstance();

    void ProcesarDatos(ifstream &archivo_csv); //Convertir csv a vector<Pelicula>
    /*
    unordered_set<Pelicula*> RetornarPeliculas(const string s){
        ST Arbol = mapaSearchTrees[s[0]]; 
        Nodo* Nodo_final= Arbol.buscarNodo(s); 
        return Nodo_final->getPeliculas(); 
    }
    */
    //void agregar_pelicula_me_gusta(); //Patron Builder: Como se puede relacionar esto? 

    //void agregar_pelicula_vermastarde();
    /*
    void Busqueda_titulos(){ //Que pasa si insertamos frases? los espacios contarian como una sola palabra? 
        unordered_map<Pelicula*, int> apariciones; //Cono puedes ordenarlos en el mapa, si ordena en funcion del .first
        string palabra; 
        cout << "Ingresar frase: "; 
        while (cin >> palabra){
            unordered_set<Pelicula*> Pelis_temp = RetornarPeliculas(palabra);
            for(auto it = Pelis_temp.begin(); it != Pelis_temp.end(); it++){
                apariciones[*it] = apariciones[*it] + 1;
            }
        } 
        vector<pair<Pelicula*, int>> Pelis_coincidentes(apariciones.begin(), apariciones.end());
        sort(Pelis_coincidentes.begin(), Pelis_coincidentes.end(), [](pair<Pelicula*,int> p1, pair<Pelicula*,int> p2){
            return p1.second < p2.second;
        }); //Ordena el vector por apariciones

        //Lo siguiente seria la impresion de las peliculas en el GUI. 
        
    }*/
    
    void imprimir_BD(){
        for (Pelicula* P: Base_de_datos)
        {
            cout << "ID: " << P->id << endl;
            cout << "Titulo: " << P->titulo << endl;
            cout << "Resena muy larga para imprimirla" << endl; 
            cout << "Tags: " << P->tags << endl;
        }
    }

    void eliminar_BD(){
        for(auto e:Base_de_datos){
            delete e;
        }
    }
}; 

Admin* Admin::ADMIN_0 = nullptr; 

Admin* Admin::getInstance(){
    if(ADMIN_0==nullptr){
        ADMIN_0 = new Admin();
    }
    return ADMIN_0; 
}

void Admin::ProcesarDatos(ifstream& archivo_csv){
    //Podemos utilizar threads, dividiendo la base de datos en la cantidad de threads posibles y utilizar <future> para
    //retornar un vector<Pelicula*> que pueda ser pusheado a la base de datos. 

    if(!archivo_csv.is_open()){
        cerr << "Error al abrir el archivo." << endl;
    }
    int atributos = 0; 
    Pelicula* P = new Pelicula();
    string linea;
    while (getline(archivo_csv, linea, '\n')){
        string oracion;
        istringstream ss(linea);
        vector<string> fila;
        while (getline(ss,oracion,',')) 
        {
            if(oracion.front()=='"'){
                string temp;
                temp = temp +oracion;
                while (getline(archivo_csv,oracion,','))
                {
                    temp = temp + ',' + oracion;
                    if(oracion.back()=='"'){
                        break;
                    }
                }
                oracion = temp;
            }
            fila.push_back(oracion);
            atributos++;

            if(fila.size() >= 6){
                P->id = fila[0];
                P->titulo = fila[1];
                P->sinopsis = fila[2];
                P->tags = fila[3];
                P->split = fila[4];
                P->sinop_src = fila[5];
                Base_de_datos.push_back(P);
                fila = {}; 
                P = new Pelicula(); 
            }
        }
    }
    

    /*
    while(getline(archivo_csv,oracion,',')){
        if (oracion.front()=='"')
        {
            string temp;
            temp = temp +oracion;
            while (getline(archivo_csv,oracion,','))
            {
                temp = temp + ',' + oracion;
                if(oracion.back()=='"'){
                    break;
                }
            }
            oracion = temp;
        }
        atributos++; 
        fila.push_back(oracion);

        if(fila.size() >= 6){
            P->id = fila[0];
            P->titulo = fila[1];
            P->sinopsis = fila[2];
            P->tags = fila[3];
            P->split = fila[4];
            P->sinop_src = fila[5];
            Base_de_datos.push_back(P);
            fila = {}; 
            P = new Pelicula(); 
        }
        
    }
    */
    cout << "Cantidad de peliculas: " << Base_de_datos.size() << endl;
    cout << "Cantidad de atributos en BD: " << atributos << endl; 
    cout << "Id: "<< Base_de_datos[1]->id << endl;
    cout << "Titulo: " << Base_de_datos[1]->titulo << endl; 
    cout << "Sinopsis: "<< Base_de_datos[1]->sinopsis << endl; 
    cout << "Tags: " << Base_de_datos[0]->tags << endl; 
    cout << "Split: " << Base_de_datos[0]->split << endl;
    cout << "Source: " << Base_de_datos[0]->sinop_src << endl; 
    delete P; 
}



int main(){
    ifstream archivo("C:/Users/diego/OneDrive/Escritorio/Git Proyects/Proyecto-Progra-III/backend/resources/data/base_de_datos.csv", std::ios::in);
    Admin* ADMIN = Admin::getInstance();
    ADMIN->ProcesarDatos(archivo);
    ADMIN->eliminar_BD();
    delete ADMIN;
    archivo.close(); 
    return 0; 
}

/*
        1) Podemos utilizar la idea del profesor de generar un puntero por cada letra y que esta apunte a un titulo o nombre
        que tenga la similitud del camino que esta formando con otros punteros junto a el. 
        
        
        2) Los espacio no contarian como una sola palabra, porque el usuario podria insertar palabras desordenadas.
        
        3) Entonces podriamos crear un algoritmo que junte las peliculas que esten en los nodos finales. Como que si
        encuentra la pelicula en los nodos finales. Pero si no los encuentra en todos pero en algunos si? 
        - Podemos crear un mapa global que cuente las veces que una pelicula aparece, cuando retornemos el set de peliculas 
        por cada palabra buscada. 
    
        5) Primero parceo: Tendriamos que observar cuales datos se pueden eliminar. 

        6) si insertamos rk: deberia de retornar tmb peliculas que tengan el rk y no inicien necesariamente con eso. 
        - Podriamos insertar la pelicula de cada arbol anteriormente llamado en letras anteriores. 
        */