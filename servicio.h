#ifndef SERVICIO_H
#define SERVICIO_H

#include <iostream>
#include "registro.h"
using namespace std;

struct comentario {
    string usuario;
    string titulo;
    string mensaje;
};

extern comentario listaComentarios[100];
extern int nc;

void coment(registro &);
void verComentarios();

#endif