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
        cout<<"Ingrese su nombre de usuario:";cin>>listaComentarios[nc].usuario;
        cout<<"Ingrese el titulo de su comentario:";cin>>listaComentarios[nc].titulo;
        cout<<"Ingrese su mensaje:";cin>>listaComentarios[nc].mensaje;
        nc++;
        cout<<"Comentario guardado con éxito."<<endl;
    }
    else if(opcion==2){
        cout<<"Gracias por su tiempo."<<endl;
    }
    else{
        cout<<"Opción no válida."<<endl;
    }
}