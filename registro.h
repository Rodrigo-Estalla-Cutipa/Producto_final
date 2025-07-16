#ifndef REGISTRO_H
#define REGISTRO_H

#include "direccion.h"
#include <iostream>
using namespace std;

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

int verificaUser(registro &, string, string);
int verificaEmp(trabajador &, string, string);

void leerUser(registro &, int &);
void leerEmp(trabajador &, int &, int &);

#endif