#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

int main()
{

    cout << "Ejercicio N° 2" << endl;

    ArbolBinario<int> arbol1;
    int eliminar, buscar;

    cout << "Agregando inventario" << endl;

    arbol1.put(4001);
    arbol1.put(2002);
    arbol1.put(6003);
    arbol1.put(1500);
    arbol1.put(3500);
    arbol1.put(5000);
    arbol1.put(7000);

    arbol1.print();

    for (int i = 0; i < 2; i++)
    {
        try
        {
            cout << "Ingrese el numero del elemento a eliminar" << endl;
            cin >> eliminar;
            arbol1.remove(eliminar);
        }
        catch (int e)
        {
            if (e == 404)
            {
                cout << "No se pudo eliminar el archivo" << endl;
            }
        }
    }

    arbol1.put(2500);

    arbol1.print();

    cout << "Ingrese el elemento que desea buscar" << endl;
    cin >> buscar;

    try
    {
        arbol1.search(buscar);
        cout << "Elemento encontrado" << endl;
    }
    catch (int e)
    {
        if (e == 404)
        {

            cout << "El elemento no se encuentra en el inventario" << endl;
        }
    }

    return 0;
}
