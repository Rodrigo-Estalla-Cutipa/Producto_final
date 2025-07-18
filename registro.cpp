#include <iostream>
using namespace std;
#include "registro.h"

int verificaUser(registro &lista, string user, string c){
    int aux = 0;
    if (lista.usuario == user && lista.contrasena == c) {
        aux = 1;
    }
    return aux;
}

int verificaEmp(trabajador &lista, string user, string c){
    int aux = 0;
    if (lista.usuario == user && lista.contrasena == c) {
        aux = 1;
    }
    return aux;
}

void leerUser(registro &listaUser, int &nu){
    registro user;
    cout <<"Ingrese correctamente los datos:"<<"\n\n";
    cin.ignore();
    cout << "Nombres Completo: "; getline(cin, user.nombre);
    cout << "Nombre Usuario: "; cin >> user.usuario;
    cout << "Ingrese su email: "; cin >> user.email;
    cin.ignore();
    cout << "Ingrese su telefono: "; getline(cin, user.telefono);
    cout << "Cree su clave: "; cin >> user.contrasena;
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
    user.dinero = 0;
    system("pause");
    listaUser = user;
    nu++;
}
void leerEmp(trabajador &listaEmp, int &ne, int &op){
    int aux=-1;
    trabajador emp;
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
        listaEmp = emp;
        ne++;
        op=-1;
    }
}