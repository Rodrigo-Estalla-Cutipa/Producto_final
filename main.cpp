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