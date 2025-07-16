#ifndef DIRECCION_H
#define DIRECCION_H

#include <iostream>
using namespace std;

struct direccion {
    string departamento;
    string provincia;
    string distrito;
    string via;
    int manzana;
    int lote;
    string piso; // opcional
    int cod_postal;
};

#endif