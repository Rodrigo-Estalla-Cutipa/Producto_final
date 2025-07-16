#include <iostream>
#include "menu.h"
using namespace std;

void menu_u(registro &User, int &op){ //no modificar op
    int aux;
    system("cls");
    cout << "MENU USUARIO" << endl << endl;
    cout << "1. Opcion" << endl;
    cout << "2. Opcion" << endl;

    //agregar más

    cout << "0. Salir" << endl;
    cout << "----------------------------------" << endl;
    cout << "Elige una opcion: "; cin >> aux;
    cout << endl;

    ////añadir si salir op = 1;
}

void menu_e(trabajador &Emp, int &op){
    int aux;
    system("cls");
    cout << "MENU EMPLEADO" << endl << endl;
    cout << "1. Opcion" << endl;
    cout << "2. Opcion" << endl;
    
    //agregar más

    cout << "0. Salir" << endl;
    cout << "----------------------------------" << endl;
    cout << "Elige una opcion: "; cin >> aux;
    cout << endl;

    ////añadir si salir op = 1;
};