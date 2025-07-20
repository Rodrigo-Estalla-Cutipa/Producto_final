#include "servicio.h"
#include <string>
#include <iostream>
using namespace std;

void coment(){
    int nc=0, opcion;
    comentario listaComentarios[100];
    cout<<"-----------Servicio de comentarios---------"<<endl;
    cout<<"¿Desea dejar un comentario?"<<endl;
    cout<<"1. Si"<<endl;
    cout<<"2. No"<<endl;
    cin>>opcion;
    if(opcion==1){
        system("cls");
        cout<<"Ingrese su nombre de usuario:";cin>>listaComentarios[nc].usuario;
        cout<<"Ingrese el titulo de su comentario:";cin>>listaComentarios[nc].titulo;
        cout<<"Ingrese su mensaje:";cin>>listaComentarios[nc].mensaje;
        nc++;
        cout<<"\nComentario guardado con exito"<<endl;
        system("pause");
    }
    else if(opcion==2){
        cout<<"/";
    }
    else{
        cout<<"Opcion no valida."<<endl;
        system("pause");
    }
}