#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

void menu()
{
    cout << "***MENU***" << endl;
    cout << "1.Reservar" << endl;
    cout << "2.Eliminar reserva" << endl;
    cout << "3.Buscar reserva" << endl;
    cout << "4.Mostrar arbol de reservas" << endl;
    cout << "5.Salir" << endl;
}

void altaMesa(ArbolBinario<int> &a1)
{
    int num;
    do
    {
        try
        {
            cout << "Ingrese el numero de mesa, para terminar presione -1" << endl;
            cin >> num;
            if (num != -1)
            {
                a1.put(num);
                cout << "Cargada con exito" << endl;
            }
            
        }
        catch (int e)
        {
            if (e = 404)
            {
                cout << "La mesa ya esta reservada" << endl;
            }
        }

    } while (num != -1);
}

void eliminarMesa(ArbolBinario<int> &a1)
{
    int baja;

    try
    {
        cout << "Ingrese el numero de mesa para dar de baja" << endl;
        cin >> baja;
        a1.remove(baja);
    }
    catch (int e)
    {
        if (e == 404)
        {
            cout << "La mesa no estaba reservada" << endl;
        }
    }
}

void buscarMesa(ArbolBinario<int> &a1)
{

    int mesabuscar;

    try
    {
        cout << "Ingrese el elemento que desea buscar" << endl;
        cin >> mesabuscar;
        a1.search(mesabuscar);
        cout << "La mesa: "<<mesabuscar<<". Esta Reservada." << endl;
    }
    catch (int e)
    {
        if (e == 404)
        {
            cout << "La mesa no existe" << endl;
        }
    }
}

int main()
{

    cout << "Ejercicio N° 4" << endl;

    ArbolBinario<int> mesas;
    
        int option;

    do
    {
        menu();
        cout<<"Ingrese una opcion"<<endl;
        cin>>option;

        switch (option)
        {
        case 1:
            altaMesa(mesas);
            break;
        case 2:
            eliminarMesa(mesas);
            break;
        case 3:
            buscarMesa(mesas);
            break;
        case 4:
            mesas.print();
            break;  
        default:
            cout<<"Opcion incorrecta..."<<endl;
            break;
        }
    } while (option != 5);

    return 0;
}

