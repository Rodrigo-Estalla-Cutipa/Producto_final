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