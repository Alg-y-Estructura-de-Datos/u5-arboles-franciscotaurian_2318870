#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

void menu()
{
    cout << "***MENU***" << endl;
    cout << "1.Dar de alta" << endl;
    cout << "2.Dar de baja" << endl;
    cout << "3.Buscar" << endl;
    cout << "4.Mostrar arbol" << endl;
    cout << "5.Salir" << endl;
}

void altaUsuario(ArbolBinario<int> &a1)
{
    int num;
    do
    {
        try
        {
            cout << "Ingrese el numero del usuario" << endl;
            cin >> num;
            if (num != -1)
            {
                a1.put(num);
                cout << "Cargado con exito" << endl;
            }
            
        }
        catch (int e)
        {
            if (e = 404)
            {
                cout << "El elemento ya existe" << endl;
            }
        }

    } while (num != -1);
}

void bajaUsuario(ArbolBinario<int> &a1)
{
    int baja;

    try
    {
        cout << "Ingrese el numero para dar de baja" << endl;
        cin>>baja;
        a1.remove(baja);
    }
    catch (int e)
    {
        if (e==404)
        {
            cout<<"No se pudo eliminar el usuario"<<endl;
        }
        
    }
}

void buscarUsuario(ArbolBinario<int> &a1){

    int usuarioBuscar;

    try
    {
        cout<<"Ingrese el elemento que desea buscar"<<endl;
        cin>>usuarioBuscar;
        a1.search(usuarioBuscar);
        cout<<"Usuario encontrado"<<endl;
    }
    catch(int e)
    {
        if (e==404)
        {
            cout<<"Usuario no encontrado"<<endl;
        }
        
    }
    

}

int main()
{

    cout << "Ejercicio N° 3" << endl;

    ArbolBinario<int> arbol;
    int option;

    do
    {
        menu();
        cout<<"Ingrese una opcion"<<endl;
        cin>>option;

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
            cout<<"Opcion Incorrecta..."<<endl;
            break;
        }
    } while (option != 5);

    return 0;
}
