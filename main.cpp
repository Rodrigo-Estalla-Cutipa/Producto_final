#include <iostream>
using namespace std;

struct direccion {
    string departamento;
    string provincia;
    string distrito;
    string via;
    int manzana;
    string lote;
    string piso; // opcional
    int cod_postal;
};

struct tarjeta {
    int num;
    int CVV;
};

struct registro {
    string nombre;
    string usuario;
    string contrasena;
    string email;
    string telefono;
    direccion dir;
    tarjeta tarj;
};

struct trabajador { //repartidor, admin
    string nombre;
    string usuario;
    string contrasena;
    string email;
    string telefono;
};

struct producto {
    int id;
    string nom;
    string descripcion;
    string categoria;
    float precio;
    int stock;
    int cantidad;
};

struct comentario {
    string usuario;
    string titulo;
    string mensaje;
};

int main() {
    int op;
    char salir;

    do {
        system("cls");
        cout << "==================================" << endl;
        cout << "       BIENVENIDO A PidePE " << endl;
        cout << "==================================" << "\n" << endl;
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Registrarse" << endl;
        cout << "0. Salir" << endl;
        cout << "----------------------------------" << endl;
        cout << "Elige una opcion: "; cin >> op;
        cout << endl;

        switch(op) {
            case 1:
                cout << "Iniciandose" << endl; // Aqui haremos inicio de sesion
                system("pause");
                break;
            case 2:
                cout << ">> Registrandose" << endl; // Aqui habra una funcion de registro
                system("pause");
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
    } while(op != 0);

    return 0;
}