#ifndef MENU_H
#define MENU_H

#include "registro.h"
#include <iostream>
using namespace std;

void menu_u(registro &, int &);
void menu_e(trabajador &, int &);

void menu_admin();
void menu_repar();

void ppedidos(registro&, int);

#endif