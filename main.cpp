#include <iostream>
#include "registro.h"
#include "direccion.h"
#include "producto.h"
#include "servicio.h"
using namespace std;

int main() {
    int op=-1, aux, aux2, nu=0, ne=0, ingreso;
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
                            }
                        }
                        if (ingreso==1){
                            cout << "\nINGRESASTE consumidor\n";
                            system("pause");
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
                            }
                        }
                        if (ingreso==1){
                            cout << "\nINGRESASTE trabajador\n";
                            system("pause");
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
                    cout <<"Ingrese correctamente los datos:"<<"\n\n";
                    cin.ignore();
                    cout << "Nombres Completo: "; getline(cin, user.nombre);
                    cout << "Nombre Usuario: "; cin >> user.usuario;
                    cout << "Ingrese su email: "; cin >> user.email;
                    cin.ignore();
                    cout << "Ingrese su telefono: "; getline(cin, user.telefono);
                    cout << "Ingrese su nueva clave: "; cin >> user.contrasena;
                    cout << "\nINGRESE SU DIRECCION:\n";
                    cin.ignore();
                    cout << "Departamento: "; getline(cin, user.dir.departamento);
                    cout << "Provincia: "; getline(cin, user.dir.provincia);
                    cout << "Distrito: "; getline(cin, user.dir.distrito);
                    cout << "Via (Asoc/Calle): "; getline(cin, user.dir.via);
                    cout << "Manzana: "; cin >> user.dir.manzana;
                    cout << "Lote: "; cin >> user.dir.lote;
                    cin.ignore();
                    cout << "Piso(Opcional): "; getline(cin, user.dir.piso);
                    cout << "Codigo Postal: "; cin >> user.dir.cod_postal;
                    cout << "\nRegistrandose.........\n";
                    system("pause");
                    listaUser[nu] = user;
                    nu++;
                    op=-1;
                }
                if (aux2== 2){
                    do {
                        system("cls");
                        cout << "Ingresar Codigo de Acceso: "; cin >> aux;
                        system("cls");
                        if (aux !=912){
                            cout << "CODIGO INVALIDO"<<endl;
                            cout << "1. Intentar de nuevo"<<endl;
                            cout << "0. Regresar"<<endl;
                            cout << "----------------------------------" << endl;
                            cout << "Elige una opcion: "; cin >> aux;
                        }
                    } while (aux != 912 && aux !=0);
                    system("cls");
                    if (aux==0){
                        op = 2;
                    } else {
                        cout << "CODIGO CORRECTO\n";
                        cout <<"Ingrese correctamente los datos:"<<"\n\n";
                        cin.ignore();
                        cout << "Nombres Completo: "; getline(cin, emp.nombre);
                        cout << "Nombre Usuario: "; cin >> emp.usuario;
                        cout << "Ingrese su email: "; cin >> emp.email;
                        cin.ignore();
                        cout << "Ingrese su telefono: "; getline(cin, emp.telefono);
                        cout << "Ingrese su nueva clave: "; cin >> emp.contrasena;
                        cout << "\nRegistrandose.........\n";
                        system("pause");
                        listaEmp[ne] = emp;
                        ne++;
                        op=-1;
                    }
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
                system("pause");
                break;
        }
    } while (op != 0);

    //testeo de informacion que almacena el programa
    system("cls");
    cout<<"USUARIO 0\n\n";
    cout<<"Nombre: "<<listaUser[0].nombre<<endl;
    cout<<"Usuario: "<<listaUser[0].usuario<<endl;
    cout<<"Email: "<<listaUser[0].email<<endl;
    cout<<"Numero: "<<listaUser[0].telefono<<endl;

    cout<<"\nTRABAJADOR 0\n\n";
    cout<<"Nombre: "<<listaEmp[0].nombre<<endl;
    cout<<"Usuario: "<<listaEmp[0].usuario<<endl;
    cout<<"Email: "<<listaEmp[0].email<<endl;
    cout<<"Numero: "<<listaEmp[0].telefono<<endl;

    return 0;
}