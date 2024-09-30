#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;


int main() {

    cout << "Ejercicio N° 1" << endl;

    ArbolBinario<int> arbol1;

    cout<<"Agregando libros"<<endl;
    cout<<""<<endl;

    arbol1.put(101);
    arbol1.put(52);
    arbol1.put(198);
    arbol1.put(36);
    arbol1.put(75);
    arbol1.put(150);
    arbol1.put(200);

    arbol1.print();

    try
    {
        int buscar;
        cout<<"Ingrese el libro que desea buscar"<<endl;
        cin>>buscar;
        arbol1.search(buscar);
        cout<<"Se encontro el libro "<<buscar<<endl;
        
    }
    catch(int e)
    {
        if(e==404){
            cout<<"Error 404"<<endl;
        }
    }
    

    

    return 0;
}
