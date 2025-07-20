#include <iostream>
#include "registro.h"
#include "direccion.h"
#include "producto.h"
#include "menu.h"
#include "servicio.h"
using namespace std;

int main() {
    int op=-1, aux, aux2, nu=0, ne=0, ingreso, p;
    registro user, listaUser[100];
    trabajador emp, listaEmp[100];
    char salir;

    do {
        if (op == -1){
            system("cls");
            cout << "==================================" << endl;
            cout << "       BIENVENIDO A PidePE " << endl;
            cout << "==================================" << endl << endl;
            cout << "1. Iniciar sesion" << endl;
            cout << "2. Registrarse" << endl;
            cout << "0. Salir" << endl;
            cout << "----------------------------------" << endl;
            cout << "Elige una opcion: "; cin >> op;
            cout << endl;
        }

        switch(op) {
            case 1:
                system("cls");
                cout << "INGRESAR COMO:" << "\n";
                cout << "1. Usuario" << endl;
                cout << "2. Trabajador" << endl;
                cout << "0. Regresar" << endl;
                cout << "----------------------------------" << endl;
                cout << "Elige una opcion: "; cin >> aux2;
                if (aux2== 1){
                    do {
                        system("cls");
                        ingreso = 0;
                        cout << "Usuario: "; cin >> user.usuario;
                        cout << "Clave: "; cin >> user.contrasena;
                        for (int i=0; i<nu; i++){
                            if (verificaUser(listaUser[i], user.usuario, user.contrasena)) {
                                ingreso = 1;
                                p = i;
                            }
                        }
                        if (ingreso==1){
                            system("cls");
                            cout << "MENU de INICIO\n\n";
                            menu_u(listaUser[p], op);
                            aux=0;
                        } else {
                            cout << "\nInformacion Incorrecta\n" << endl;
                            cout << "1. Intentar de nuevo" << endl;
                            cout << "0. Regresar" << endl;
                            cout << "----------------------------------" << endl;
                            cout << "Elige una opcion: "; cin >> aux;
                            if (aux==0){
                                op = 1;
                            }
                        }
                    } while (aux!=0);
                }
                if (aux2== 2){
                    do {
                        system("cls");
                        ingreso = 0;
                        cout << "Usuario: "; cin >> emp.usuario;
                        cout << "Clave: "; cin >> emp.contrasena;
                        for (int i=0; i<ne; i++){
                            if (verificaEmp(listaEmp[i], emp.usuario, emp.contrasena)) {
                                ingreso = 1;
                                p = i;
                            }
                        }
                        if (ingreso==1){
                            system("cls");
                            cout << "MENU DE TRABAJADOR:\n\n";
                            menu_e(listaEmp[p], op);
                            aux=0;
                        } else {
                            cout << "\nInformacion Incorrecta\n\n" << endl;
                            cout << "1. Intentar de nuevo" << endl;
                            cout << "0. Regresar" << endl;
                            cout << "----------------------------------" << endl;
                            cout << "Elige una opcion: "; cin >> aux;
                            if (aux==0){
                                op = 1;
                            }
                        }
                    } while (aux!=0);
                }
                if (aux2== 0){
                    op=-1;
                }
                aux=-1;
                break;
            case 2:
                system("cls");
                cout << "REGISTRASE COMO:" << "\n" << "\n";
                cout << "1. Registro de Usuario" << endl;
                cout << "2. Registro de Trabajador" << endl;
                cout << "0. Regresar" << endl;
                cout << "----------------------------------" << endl;
                cout << "Elige una opcion: "; cin >> aux2;
                system("cls");
                if (aux2== 1){
                    leerUser(listaUser[nu], nu);
                    op=-1;
                }
                if (aux2== 2){
                    leerEmp(listaEmp[ne], ne, op);
                }
                if (aux2== 0){
                    op=-1;
                }
                aux=-1;
                break;
            case 0:
                cout << "Esta seguro de salir? (S/n): "; cin >> salir;
                if (salir == 'N' || salir == 'n') {
                    op = -1;
                }
                break;
            default:
                cout << "OPCION NO VALIDA" << endl;
                op = -1;
                system("pause");
                break;
        }
    } while (op != 0);

    return 0;
}