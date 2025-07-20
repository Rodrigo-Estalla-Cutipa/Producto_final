#include "servicio.h"
#include <string>
#include <iostream>
using namespace std;

comentario listaComentarios[100];
int nc=0;

void coment(registro &User){
    system("cls");
    int op, aux=-1;
    do {
        cout<<"-----------Servicio de comentarios---------"<<endl;
        cout<<"Desea dejar un comentario?"<<endl;
        cout<<"1. Si"<<endl;
        cout<<"2. No"<<endl;
        cout<<"-----------------------" << endl;
        cout<<"Elige una opcion: "; cin>>op;

        if(op==1){
            system("cls");
            listaComentarios[nc].usuario = User.nombre;
            cout<<"Ingrese el titulo de su comentario: ";
            cin.ignore();
            getline(cin,listaComentarios[nc].titulo);
            cout<<"Ingrese su mensaje: ";
            cin.ignore();
            getline(cin,listaComentarios[nc].mensaje);
            nc++;
            cout<<"\nComentario guardado con exito"<<endl;
            aux=0;
            system("pause");
        }
        else if(op==2){
            aux=0;
        }
        else{
            cout<<"Opcion no valida."<<endl;
            system("pause");
        }
    } while(aux!=0);
}

void verComentarios() {
    system("cls");
    cout << "------------- LISTA DE COMENTARIOS -------------\n\n";
    if (nc == 0) {
        cout << "NO HAY COMENTARIOS REGISTRADOS\n";
    } else {
        for (int i = 0; i < nc; i++) {
            cout << "COMENTARIO #" << i + 1 << endl;
            cout << "Usuario: " << listaComentarios[i].usuario << endl;
            cout << "Titulo: " << listaComentarios[i].titulo << endl;
            cout << "Mensaje: " << listaComentarios[i].mensaje << endl;
            cout << "----------------------------------------\n\n";
        }
    }
    system("pause");
}