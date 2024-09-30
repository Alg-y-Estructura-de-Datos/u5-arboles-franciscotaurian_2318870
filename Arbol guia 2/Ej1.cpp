#include <iostream>
#include "Arbol/ArbolBinarioAVL.h"
using namespace std;

void menu()
{
    cout << "***MENU***" << endl;
    cout << "1.Agregar Producto" << endl;
    cout << "2.Eliminar Producto" << endl;
    cout << "3.Buscar" << endl;
    cout << "4.Mostrar arbol" << endl;
    cout << "5.Salir" << endl;
}


void altaUsuario(ArbolBinarioAVL<int> &a1)
{
    int num;
    do
    {
        try
        {
            cout << "Ingrese el numero del producto, para terminar presiones -1" << endl;
            cin >> num;
            if (num != -1)
            {
                a1.put(num);
                cout << "Cargado con exito" << endl;
            }
            
        }
        catch (int e)
        {
            if (e == 200)
            {
                cout << "El elemento ya existe" << endl;
            }
        }

    } while (num != -1);
}

void bajaUsuario(ArbolBinarioAVL<int> &a1)
{
    int baja;

    try
    {
        cout << "Ingrese el numero para dar de baja" << endl;
        cin >> baja;
        a1.remove(baja);
        cout<<"Elemento eliminado"<<endl;
    }
    catch (int e)
    {
        if (e == 404)
        {
            cout << "No se pudo eliminar el usuario" << endl;
        }
    }
}

void buscarUsuario(ArbolBinarioAVL<int> &a1)
{

    int usuarioBuscar;

    try
    {
        cout << "Ingrese el elemento que desea buscar" << endl;
        cin >> usuarioBuscar;
        a1.search(usuarioBuscar);
        cout << "Elemento encontrado" << endl;
    }
    catch (int e)
    {
        if (e == 404)
        {
            cout << "Usuario no encontrado" << endl;
        }
    }
}

int main ()
{

    cout << "Ejercicio 1" << endl;

    ArbolBinarioAVL<int> arbol;
    int option;

    do
    {
        menu();
        cout << "Ingrese una opcion" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            altaUsuario(arbol);
            break;
        case 2:
            bajaUsuario(arbol);
            break;
        case 3:
            buscarUsuario(arbol);
            break;
        case 4:
            arbol.print();
            break;
        default:
            cout << "Saliendo..." << endl;
            break;
        }
    } while (option != 5);

    return 0;
}
