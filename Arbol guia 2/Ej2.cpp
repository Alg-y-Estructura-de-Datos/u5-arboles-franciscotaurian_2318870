#include <iostream>
#include "Arbol/ArbolBinarioAVL.h"
using namespace std;

void menu()
{

    cout << "*****MENU******" << endl;
    cout << "1.Agregar producto." << endl;
    cout << "2.Eliminar producto." << endl;
    cout << "3.Buscar producto." << endl;
    cout << "4.Mostrar Inventario." << endl;
    cout << "5.Salir." << endl;
}

void AgregarProducto(ArbolBinarioAVL<int> &inventario)
{

    int id;

    cout << "Ingrese el numero de inventario" << endl;
    cin >> id;

    try
    {

        inventario.put(id);
        cout << "Elemento cargado con exito" << endl;
    }
    catch (int e)
    {
        if (e == 200)
        {
            cout << "El elemento ya existe" << endl;
        }
    }
}

void EliminarProducto(ArbolBinarioAVL<int> &inventario)
{
    int id;
    cout << "Ingrese el numero de inventario que desea eliminar" << endl;
    cin >> id;

    if (inventario.esVacio())
    {
        cout << "El inventario esta vacio" << endl;
    }
    else
    {
        inventario.remove(id);
        cout << "Elemento eliminado" << endl;
    }
}

void BuscarProducto(ArbolBinarioAVL<int> &inventario)
{
    int id;
    cout << "Ingrese el numero de inventario que desea buscar" << endl;
    cin >> id;

    if (inventario.esVacio())
    {
        cout << "El inventario esta vacio" << endl;
    }
    else
    {
        try
        {
            inventario.search(id);
            cout << "Elemento encontrado" << endl;
        }
        catch (int e)
        {
            if (e == 404)
            {
                cout << "El elemento no existe" << endl;
            }
        }
    }
}

int main()
{
    int option;
    ArbolBinarioAVL<int> inventario;
    do
    {
        menu();
        cin >> option;

        switch (option)
        {
        case 1:
            AgregarProducto(inventario);
            break;
        case 2:
            EliminarProducto(inventario);
            break;
        case 3:
            BuscarProducto(inventario);
            break;
        case 4:
            if (inventario.esVacio())
            {
                cout << "El inventario esta vacio" << endl;
            }
            else
            {
                inventario.print();
            }
            break;
        case 5:
            cout << "Saliendo" << endl;
            break;

        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }

    } while (option != 5);
}
