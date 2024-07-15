#include "C:\Users\diego\OneDrive\Escritorio\Git Proyects\Proyecto-Progra-III\backend\include\search_algorithm.hpp"
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

struct Nodo{

    char letra;
    unordered_map <char, Nodo*> mapaNodos; //Mapa de nodos que van a ser pusheados por un recorrido en la base de datos.
    unordered_set <Pelicula*> Peliculas; //Peliculas que va a tener cada nodo

    Nodo(char c):letra(c){
        mapaNodos = {};
        Peliculas = {};
    }
    Nodo(){
        mapaNodos = {};
        Peliculas = {};
    }
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
    for(int i=1;i< s.size(); i++){
        iter->agregarNodo(s[i]); 
        iter = iter->mapaNodos[s[i]];
        iter->agregarPelicula(P);
    }
}

Nodo* ST::buscarNodo(string s){ //Vamos a encontrar conforme vayan leyendo los chars 
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

void ST::EliminarNodos(Nodo* padre){ 
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
    
    public:

    static Admin* getInstance();

    void ProcesarDatos(ifstream &archivo_csv); 
    
    void Crear_Estructura(); 

    unordered_set<Pelicula*> RetornarPeliculas(const string s);
    
    vector<pair<Pelicula*,int>> Busqueda_titulos();

    void eliminar_BD();

    void destruir_mapaST();

    void prueba(){
        cout << mapaSearchTrees['b']->letra_inicial << endl;
        //cout << mapaSearchTrees['b']->raiz->mapaNodos['e']->mapaNodos['a']->mapaNodos['t']->letra << endl;
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

    if(!archivo_csv.is_open()){
        cerr << "Error al abrir el archivo." << endl;
    }
    int atributos = 0; 
    Pelicula* P = new Pelicula();
    string linea;
    vector<string> fila;
    while (getline(archivo_csv, linea, '\n')){
        string oracion;
        istringstream ss(linea);  
        while (getline(ss,oracion,',')) 
        {
            if(oracion.front()=='"'){
                
                if((oracion.back()!= '"') || (oracion.back()=='"' && oracion.substr(0,oracion.length()-1).back() == '"' && oracion.substr(0,oracion.length()-2).back() != '"')){ //Si continuas
                    string temp;
                    temp = temp +oracion;
                    bool amedias = true;
                    while (getline(ss,oracion,','))
                    {
                        temp = temp + ',' + oracion;
                        if(!((oracion.back()!= '"') || (oracion.back()=='"' && oracion.substr(0,oracion.length()-1).back() == '"' && oracion.substr(0,oracion.length()-2).back() != '"'))){
                            amedias = false;
                            break;
                        }
                    }
                    while (amedias && getline(archivo_csv,oracion,','))// Aqui, salta a la proxima fila, por el salto de linea en el getline
                    {
                        temp = temp + ',' + oracion;
                        if(!((oracion.back()!= '"') || (oracion.back()=='"' && oracion.substr(0,oracion.length()-1).back() == '"' && oracion.substr(0,oracion.length()-2).back() != '"'))){
                            break;
                        }
                    }
                    oracion = temp;
                }
            }
            if(!oracion.empty()){
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
    }
    cout << "Cantidad de peliculas: " << Base_de_datos.size() << endl;
    cout << "Cantidad de atributos en BD: " << atributos << endl; 
    cout << "Id: "<< Base_de_datos[50]->id << endl;
    cout << "Titulo: " << Base_de_datos[50]->titulo << endl; 
    cout << "Sinopsis: "<< Base_de_datos[50]->sinopsis << endl; 
    cout << "Tags: " << Base_de_datos[50]->tags << endl; 
    cout << "Split: " << Base_de_datos[50]->split << endl;
    cout << "Source: " << Base_de_datos[50]->sinop_src << endl; 
    delete P; 
}

//IDEA ROBUSTA: Aplicar ST::CrearRama(string s) por cada sub-array de s. 

void Admin::Crear_Estructura(){ //Si o si utilizar threads porque puede ser bien lento
    for (Pelicula* e: Base_de_datos){  
        istringstream ss(e->titulo); 
        string palabra; 
        while (getline(ss,palabra, ' ')) 
        {
            if(mapaSearchTrees.find(palabra[0]) == mapaSearchTrees.end()){
                ST* arbol = new ST(palabra[0]);
                mapaSearchTrees[palabra[0]] = arbol;// Aqui se crearian los arboles si no estan creados
            }
            mapaSearchTrees[palabra[0]]->crearRama(palabra,e);
        }

        istringstream s1(e->sinopsis.substr(1,e->sinopsis.length()-2));
        string palabra2;
        while (getline(s1,palabra2, ' ')){
            if(mapaSearchTrees.find(palabra2[0]) == mapaSearchTrees.end()){
                ST* arbol = new ST(palabra2[0]);
                mapaSearchTrees[palabra2[0]] = arbol;
            }
            mapaSearchTrees[palabra2[0]]->crearRama(palabra2,e);
        }
    }
}

unordered_set<Pelicula*> Admin::RetornarPeliculas(const string s){
    ST* Arbol = mapaSearchTrees[s[0]]; 
    Nodo* Nodo_final = Arbol->buscarNodo(s); 
    return Nodo_final->getPeliculas(); 
}

//FUNCION FINAL
vector<pair<Pelicula*, int>> Admin::Busqueda_titulos(){ 
        unordered_map<Pelicula*, int> apariciones; //Cono puedes ordenarlos en el mapa, si ordena en funcion del .first
        string frase; 
        cout << "Ingresar frase: "; //Debe estar aqui en GUI para insertar las frases de busqueda
        getline(cin,frase);
        istringstream ss(frase);
        string palabra;
        while (getline(ss,palabra, ' ')){
            cout << palabra << endl; 
            unordered_set<Pelicula*> Pelis_temp = RetornarPeliculas(palabra);
            if(!Pelis_temp.empty()){
                for(auto it = Pelis_temp.begin(); it != Pelis_temp.end(); it++){
                    apariciones[*it] = apariciones[*it] + 1;
                }
            }
        }
        vector<pair<Pelicula*, int>> Pelis_coincidentes(apariciones.begin(), apariciones.end());
        //Ordena el vector por apariciones
        std::sort(Pelis_coincidentes.begin(), Pelis_coincidentes.end(), [](pair<Pelicula*,int> p1, pair<Pelicula*,int> p2){
            return p1.second > p2.second;
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

void ProcesarDatos_Aux(ifstream &archivo_csv, Admin* ADMIN){
    ADMIN->ProcesarDatos(archivo_csv);
}


int main(){
    ifstream archivo("C:/Users/diego/OneDrive/Escritorio/Git Proyects/Proyecto-Progra-III/backend/resources/data/base_de_datos.csv", std::ios::in);
    Admin* ADMIN = Admin::getInstance();
    chrono::time_point<chrono::system_clock> t_init, t_fin; 
    t_init = chrono::high_resolution_clock :: now();

    thread t1(ProcesarDatos_Aux,ref(archivo),ADMIN);
    //ADMIN->ProcesarDatos(archivo);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    ADMIN->Crear_Estructura();
    t1.join();
    ADMIN->prueba();
    vector<pair<Pelicula*,int>> mejores_peliculas_de_du_mundo = ADMIN->Busqueda_titulos();

    if(mejores_peliculas_de_du_mundo.empty()){
        cout << "No se encontraron peliculas coincidentes :(" << endl;
    }
    else{
        cout << "Primeras peliculas coincidentes: "<< endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i+1 << ") Titulo: "<< mejores_peliculas_de_du_mundo[i].first->titulo << endl;
        }
    }

    for (pair<Pelicula*,int> par : mejores_peliculas_de_du_mundo)
    {
        delete par.first;
    }

    t_fin = chrono::high_resolution_clock :: now();
    chrono::duration<double,milli> t = t_fin - t_init;
    cout << "Tiempo que demora en el main: " << t.count() << " milisegundos."<< endl;

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