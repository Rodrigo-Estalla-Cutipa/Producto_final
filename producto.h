#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
using namespace std;

struct producto {
    int id;
    string nom;
    string descripcion;
    string categoria;
    float precio;
    int stock;
    int cantidad;
};

#endif