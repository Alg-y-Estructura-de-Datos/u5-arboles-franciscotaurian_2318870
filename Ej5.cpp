#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

void menu()
{
    cout << "***MENU***" << endl;
    cout << "1.Alta Paquete" << endl;
    cout << "2.Eliminar Paquete" << endl;
    cout << "3.Buscar Paquete" << endl;
    cout << "4.Mostrar arbol de Paquetes" << endl;
    cout << "5.Salir" << endl;
}

void altaPaquete(ArbolBinario<int> &a1)
{
    int num;
    do
    {
        try
        {
            cout << "Ingrese el numero de paquete, para terminar presione -1" << endl;
            cin >> num;
            if (num != -1)
            {
                a1.put(num);
                cout << "Cargada con exito" << endl;
            }
            
        }
        catch (int e)
        {
            if (e == 200)
            {
                cout << "El paquete ya esta en el sistema" << endl;
            }
        }

    } while (num != -1);
}

void bajaPaquete(ArbolBinario<int> &a1)
{
    int baja;

    try
    {
        cout << "Ingrese el numero de paquetes para dar de baja" << endl;
        cin >> baja;
        a1.remove(baja);
        cout<<"El paquete: "<<baja<<". Fue entregado"<<endl;
    }
    catch (int e)
    {
        if (e == 404)
        {
            cout << "El paquete no existe" << endl;
        }
    }
}

void BuscarPaquete(ArbolBinario<int> &a1)
{

    int paquetebuscar;

    try
    {
        cout << "Ingrese el elemento que desea buscar" << endl;
        cin >> paquetebuscar;
        a1.search(paquetebuscar);
        cout << "El paquete "<<paquetebuscar<<". Esta pendiente de entrega." << endl;
    }
    catch (int e)
    {
        if (e == 404)
        {
            cout << "El paquete no existe" << endl;
        }
    }
}

int main()
{

    cout << "Ejercicio N° 5" << endl;

    ArbolBinario<int> paquetes;
    
        int option;

    do
    {
        menu();
        cout<<"Ingrese una opcion"<<endl;
        cin>>option;

        switch (option)
        {
        case 1:
            altaPaquete(paquetes);
            break;
        case 2:
            bajaPaquete(paquetes);
            break;
        case 3:
            BuscarPaquete(paquetes);
            break;
        case 4:
            paquetes.print();
            break;  
        default:
            cout<<"Opcion incorrecta..."<<endl;
            break;
        }
    } while (option != 5);

    return 0;
}