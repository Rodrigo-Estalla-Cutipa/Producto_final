#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "direccion.h"
#include <iostream>
using namespace std;

struct producto {
    int id;
    string nom;
    string descripcion;
    string categoria;
    float precio;
    int cantidad;
};

struct pedir {
    producto obj[100];
    string nombre;
    string telefono;
    direccion destino;
};

extern int numProductos;
extern int numPedidos;
extern producto item[100];
extern pedir pedido[100];

#endif