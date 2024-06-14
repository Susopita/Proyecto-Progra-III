#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

//SU COMPLEJIDAD DEBE SER MENOR QUE O(n^2). O debe soportar 10^8 operaciones como maximo

/*
Conceptos: 
Debe existir un comparador o puntaje de cada titulo de pelicula que va a determinar
que tan similar es la entrada respecto al titulo o tag de la cada pelicula. 
(Puntaje 5 >= Puntaje 4 >= Puntaje 20 >=...) 

Va ha existir un orden en el valor de cada pelicula. (Podemos crear un mapa_ordenado, 
que ordene en base a su puntaje(key) y retorne su titulo(value))

Como hallamos ese puntaje? 
    Iterativo? - Si puede ser iterativo. Nos enfocamos en el titulo o en la frase
    Es necesario iterar entre todas las peliculas? - Binary search?
    Debemos de ordenar?  

ESTRUCTURA GENERAL 1:
vector<string> data_base; 
string frase_i;
cin >> frase_i;
map<int,string> mapa; 
P(titulo_i,frase_i) = (int)
mapa.agregar(P(titulo_i), frase_i);

for(int i=0; i<5;i++){
    cout << mapa[i].value << endl; 
}

IDEA 1 [Sort, Brute force] para la funcion P() :Puede que sea en base a un contador de palabras
-Iterar en los titulos de las peliculas;
-Crear un vector de palabas de cada titulo;
-Ordenar las palabras de cada titulo;
-Dentro de cada titulo, buscar si una palabra de la frase esta presente. Suma 1 a su puntaje
-Calculado el puntaje, lo agrega a la lista(binary tree - es un algoritmo que se basa un arbol que compara entre los nodos)

IDEA 2 [Sort, Words]: Si el titulo tiene mas coincidencia de letras. 
-Que pasa si ordenas los 2? 
-Creo que no seria viable por la cantidad de iteraciones

IDEA 3 []

COMO SE VA A PRIORIZAR, IMPLEMENTAR, CREAR EL NUEVO ORDEN CUANDO UNA PELICULA ES RELACIONADA A LAS QUE TE GUSTAN? 

-Se concluye con el primer orden y luego aumentamos los puntajes de cada value?
- Podemos agregarle un +1 o +2 en la iteracion de los titulos antes de agregar la palicula a la lista?  

...
if(related(vector<string> ver_mas_tarde, titulo_i)){
    puntaje = puntaje + 2;
}
...
*/

int main(){
    
    string frase;
    while(getline(cin, frase)){

    }
    return 0;
}