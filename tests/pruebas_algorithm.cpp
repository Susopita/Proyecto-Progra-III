#include "../backend/include/search_algorithm.hpp"
using namespace std; 

/*
class Categorias{
    private:
    int numero_de_peliculas;
    public: 
    virtual int get_cantidad(){
        return numero_de_peliculas; 
    }
};
*/

//RECORDATORIO: Implementar todos los destructores de las clases

struct Nodo{

    char letra;
    unordered_map <char, Nodo*> mapaNodos; //Mapa de nodos que van a ser pusheados por un recorrido en la base de datos.
    unordered_set <Pelicula*> Peliculas; //Peliculas que va a tener cada nodo

    Nodo(char c):letra(c){}
    Nodo(){}
    void agregarNodo(char c){ 
        if(mapaNodos.find(c) == mapaNodos.end()){
            Nodo* nodo = new Nodo(c); //Asigna el char del nodo
            mapaNodos[c] = nodo; //Lo pushea al mapa
        } // Creo que nunca accedemos al atributo char del nodo 
    }
    void agregarPelicula(Pelicula* Peli){ 
        Peliculas.insert(Peli);
    }
    unordered_set <Pelicula*> getPeliculas(){
        return Peliculas; 
    }
};  

//Idea inicial: Va a existir un ST para cada letra que sera la raiz de este arbol. Se creara por crearRama()
//IDEA ROBUSTA: Podriamos llamar consecutivamente al metodo crearRama() en cada sub-string de cada palabra ingresada

struct ST{  
    char letra_inicial;
    Nodo* raiz = nullptr;

    ST(char c):letra_inicial(c){
        raiz = new Nodo(c);
    }
    void crearRama(string s, Pelicula*); 
    Nodo* buscarNodo(string s); 
    unordered_set <Pelicula*> retornarpeliculas(string s);
    //El metodo para eleminar los nodos se va adescontrolar
    void EliminarNodos(Nodo* padre);
}; 

void ST::crearRama(string s, Pelicula* P){ // por cada palabra, crea un camino, que tiene nodos. Y cada nodo de ese camino tiene a esa pelicula.
    // Insertaremos la pelicula en cada creacion de nodo y crearemos los nodos
    Nodo* iter = raiz; 
    raiz->agregarPelicula(P);
    for(int i=1;i<s.size(); i++){
        iter->agregarNodo(s[i]); 
        iter = iter->mapaNodos[s[i]];
        iter->agregarPelicula(P);
    }
}

void Buscar_Nodo_Aux(Nodo* padre, string s, Pelicula* P){
    if(s.begin() != s.end()){
        

    }
}


//Podemos crear metodos auxiliares pero eso aumentaria el codigo
Nodo* ST::buscarNodo(string s){ //Vamos a encontrar conforme vayan leyendo los chars 
    // Suponemos que ya esta la estructura creada y solo profundizamos en el arbol de la primera letra de s
    // Retorna puntero a nodo vacio si no encuentra un char en el arbol siguiendo su camino.
    if(s.empty()){
        return nullptr;
    }
    Nodo* nodo_final = raiz; 
    for(int i=1; i<s.size(); i++){
        if(nodo_final->mapaNodos.find(s[i]) == nodo_final->mapaNodos.end()){
            return nullptr;
        }
        nodo_final= nodo_final->mapaNodos[s[i]];
    }
    return nodo_final;
}


unordered_set <Pelicula*> ST::retornarpeliculas(string s){ 
    Nodo* nodo; 
    nodo = buscarNodo(s);
    if (nodo != nullptr)
    {
        return nodo->getPeliculas();
    }
    unordered_set<Pelicula*> vacio = {};
    return vacio; 
}

void ST::EliminarNodos(Nodo* padre){ //Esto es como una funcion auxiliar- padre:raiz
    if(!padre->mapaNodos.empty()){
        for (pair<char,Nodo*> hijo : padre->mapaNodos)
        {
            EliminarNodos(hijo.second);
        }
    }
    delete padre; 
}

class Admin{  
    private:
    Admin(){} 
    static Admin* ADMIN_0;
    vector<Pelicula*> Base_de_datos; 
    //una lista de peliculas que me gustan
    //vector<Pelicula*> Pelis_me_gusta; 
    //una lista de peliculas para ver mas tarde
    //vector<Pelicula*> Ver_mas_tarde; 
    //una set de categorias de peliculas- puede ser una clase tal que se puedan comunicar con el admin(observer) 
    map<char, ST*> mapaSearchTrees; 
    //Para identificar si el caracter ingresado es nuevo o no. Y para que lo busque en su arbol determinado
    
    public:

    static Admin* getInstance();

    void ProcesarDatos(ifstream &archivo_csv); //Convertir csv a vector<Pelicula>
    
    void Crear_Estructura(); //Podria ser un functor? 

    //void agregar_pelicula_me_gusta(); //Patron Builder: Como se puede relacionar esto? 

    //void agregar_pelicula_vermastarde();

    unordered_set<Pelicula*> RetornarPeliculas(const string s);
    
    vector<pair<Pelicula*,int>> Busqueda_titulos();

    void eliminar_BD();

    void destruir_mapaST();

    void prueba(){
        cout << mapaSearchTrees['I']->letra_inicial << endl;
        cout << mapaSearchTrees['I']->raiz->mapaNodos['t']->mapaNodos['a']->mapaNodos['l']->mapaNodos['i']->mapaNodos['a']->mapaNodos['n']->letra << endl;
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
    vector<string> fila;
    while (getline(archivo_csv, linea, '\n')){
        string oracion;
        istringstream ss(linea); // Esto toma la linea. Y si quieres recorrer en archivo_csv, lo recorres en la siguiente linea 
        while (getline(ss,oracion,',')) 
        {
            if(oracion.front()=='"'){
                string temp;
                temp = temp +oracion;
                bool amedias = true;
                while (getline(ss,oracion,','))// Aqui, salta a la proxima fila, por el salto de linea en el getline
                {
                    temp = temp + ',' + oracion;
                    if(oracion.back()=='"'){
                        amedias = false;
                        break;
                    }
                }
                //Aqui la condicional del while siosi debe de correrse, asi que se comeria una frase en el getline(...)
                while (amedias && getline(archivo_csv,oracion,','))// Aqui, salta a la proxima fila, por el salto de linea en el getline
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
    cout << "Cantidad de peliculas: " << Base_de_datos.size() << endl;
    cout << "Cantidad de atributos en BD: " << atributos << endl; 
    cout << "Id: "<< Base_de_datos[4]->id << endl;
    cout << "Titulo: " << Base_de_datos[4]->titulo << endl; 
    cout << "Sinopsis: "<< Base_de_datos[4]->sinopsis << endl; 
    cout << "Tags: " << Base_de_datos[4]->tags << endl; 
    cout << "Split: " << Base_de_datos[4]->split << endl;
    cout << "Source: " << Base_de_datos[4]->sinop_src << endl; 
    delete P; 
}

//IDEA ROBUSTA: Aplicar ST::CrearRama(string s) por cada sub-array de s. 

void Admin::Crear_Estructura(){ //Si o si utilizar threads porque puede ser bien lento
    for (Pelicula* e: Base_de_datos){ 
        string seccion;
        seccion = e->titulo; 
        istringstream ss(seccion); 
        string palabra; 
        while (getline(ss,palabra, ' ')) // Aqui se crearian los arboles si no estan creados
        {
            if(mapaSearchTrees.find(palabra[0]) == mapaSearchTrees.end()){
                ST* arbol = new ST(palabra[0]);
                mapaSearchTrees[palabra[0]] = arbol;
            }
            mapaSearchTrees[palabra[0]]->crearRama(palabra,e);
        }

        seccion = e->sinopsis;
        seccion = seccion.substr(1,seccion.length()-2); // Porque esta entre comillas ""
        istringstream s1(seccion);
        string palabra2;
        while (getline(s1,palabra2, ' ')){
            if(mapaSearchTrees.find(palabra[0]) == mapaSearchTrees.end()){
                ST* arbol = new ST(palabra[0]);
                mapaSearchTrees[palabra[0]] = arbol;
            }
            mapaSearchTrees[palabra[0]]->crearRama(palabra,e);
        }
    }
}

unordered_set<Pelicula*> Admin::RetornarPeliculas(const string s){
    ST* Arbol = mapaSearchTrees[s[0]]; 
    Nodo* Nodo_final= Arbol->buscarNodo(s); 
    return Nodo_final->getPeliculas(); 
}

//FUNCION FINAL
vector<pair<Pelicula*, int>> Admin::Busqueda_titulos(){ 
        unordered_map<Pelicula*, int> apariciones; //Cono puedes ordenarlos en el mapa, si ordena en funcion del .first
        string palabra; 
        cout << "Ingresar frase: "; //Debe estar aqui en GUI para insertar las frases de busqueda
        while (cin >> palabra){
            unordered_set<Pelicula*> Pelis_temp = RetornarPeliculas(palabra);
            for(auto it = Pelis_temp.begin(); it != Pelis_temp.end(); it++){
                apariciones[*it] = apariciones[*it] + 1;
            }
        } 
        vector<pair<Pelicula*, int>> Pelis_coincidentes(apariciones.begin(), apariciones.end());
        //Ordena el vector por apariciones
        sort(Pelis_coincidentes.begin(), Pelis_coincidentes.end(), [](pair<Pelicula*,int> p1, pair<Pelicula*,int> p2){
            return p1.second < p2.second;
        }); 
        
        return Pelis_coincidentes;

        //Lo siguiente seria la impresion de las peliculas en el GUI. 
    }

void Admin::eliminar_BD(){
        for(auto e:Base_de_datos){
            delete e;
        }
    }

void Admin::destruir_mapaST(){
    for(pair<char,ST*> iter : mapaSearchTrees){
        iter.second->EliminarNodos(iter.second->raiz);
        delete iter.second;
    }
}


int main(){
    ifstream archivo("C:/Users/diego/OneDrive/Escritorio/Git Proyects/Proyecto-Progra-III/backend/resources/data/base_de_datos.csv", std::ios::in);
    Admin* ADMIN = Admin::getInstance();
    ADMIN->ProcesarDatos(archivo);
    ADMIN->Crear_Estructura();
    ADMIN->prueba();

    ADMIN->destruir_mapaST();
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