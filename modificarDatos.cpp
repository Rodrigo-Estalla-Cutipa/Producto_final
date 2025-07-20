#include "modificarDatos.h"
#include <iostream>
using namespace std;

void modific(registro &u, int aux){
    system("cls");
    switch(aux){
        case 1:
            cout<<"Nombre Actual: "<<u.nombre<<endl;
            cout<<"\nNombre Nuevo: "; cin >> u.nombre;
            break;
        case 2:
            cout<<"Usuario Actual: "<<u.usuario<<endl;
            cout<<"\nUsuario Nuevo: "; cin >> u.usuario;
            break;
        case 3:
            cout<<"Clave Actual: "<<u.contrasena<<endl;
            cout<<"\nClave Nueva: "; cin >> u.contrasena;
            break;
        case 4:
            cout<<"Email Actual: "<<u.email<<endl;
            cout<<"\nEmail Nuevo: "; cin >> u.email;
            break;
        case 5:
            cout<<"Numero Actual: "<<u.telefono<<endl;
            cout<<"\nNumero Nuevo: "; cin >> u.telefono;
            break;
        case 6:
            do {
                cout<<"1.Departamento: "<<u.dir.departamento<<endl;
                cout<<"2.Provincia: "<<u.dir.provincia<<endl;
                cout<<"3.Distrito: "<<u.dir.distrito<<endl;
                cout<<"4.Via: "<<u.dir.via<<endl;
                cout<<"5.Manzana: "<<u.dir.manzana<<endl;
                cout<<"6.Lote: "<<u.dir.lote<<endl;
                cout<<"7.Piso: "<<u.dir.piso<<endl;
                cout<<"8.Cod postal: "<<u.dir.cod_postal<<endl;
                cout<<"0.Regresar"<<endl;
                cout<<"\nQue desea modificar???(nro): "; cin >> aux;
                mod_dir(u, aux);
            }while(aux!=0);
            break;
        case 0:
            break;
        default:
            cout << "OPCION INVALIDA" << endl;
            system("pause");
            break;
    }
}

void mod_dir(registro &u, int aux){
    system("cls");
    switch(aux){
        case 1:
            cout << "Departamento actual: " << u.dir.departamento << endl;
            cout << "\nNuevo departamento: "; cin >> u.dir.departamento;
            break;
        case 2:
            cout << "Provincia actual: " << u.dir.provincia << endl;
            cout << "\nNueva provincia: "; cin >> u.dir.provincia;
            break;
        case 3:
            cout << "Distrito actual: " << u.dir.distrito << endl;
            cout << "\nNuevo distrito: "; cin >> u.dir.distrito;
            break;
        case 4:
            cout << "Via actual: " << u.dir.via << endl;
            cout << "\nNueva via: "; cin >> u.dir.via;
            break;
        case 5:
            cout << "Manzana actual: " << u.dir.manzana << endl;
            cout << "\nNueva manzana: "; cin >> u.dir.manzana;
            break;
        case 6:
            cout << "Lote actual: " << u.dir.lote << endl;
            cout << "\nNuevo lote: "; cin >> u.dir.lote;
            break;
        case 7:
            cout << "Piso actual: " << u.dir.piso << endl;
            cout << "\nNuevo piso: "; cin >> u.dir.piso;
            break;
        case 8:
            cout << "Cod postal actual: " << u.dir.cod_postal << endl;
            cout << "\nNuevo cod postal: "; cin >> u.dir.cod_postal;
            break;
        case 0:
            break;
        default:
            cout << "OPCION INVALIDA" << endl;
            system("pause");
            break;
    }
}

void mod_prod(producto &p){
    int aux=-1;
    do{
        system("cls");
        cout<<"\nDATOS DEL PRODUCTO:----------------------------------\n\n";
        cout<<"1.ID: "<<p.id<<endl;
        cout<<"2.Nombre"<<p.nom<<endl;
        cout<<"3.Descripcion"<<p.descripcion<<endl;
        cout<<"4.Precio"<<p.precio<<endl;
        cout<<"0.Regresar\n\n";
        cout<<"Que desea modificar?(nro): "; cin>>aux;
        system("cls");
        switch (aux){
            case 1:
                cout<<"ID actual: "<<p.id<<endl;
                cout<<"Nuevo ID: "; cin>>p.id;
                break;
            case 2:
                cout<<"Nombre actual: "<<p.nom<<endl;
                cout<<"Nuevo Nombre: "; cin>>p.nom;
                break;
            case 3:
                cout<<"Descripcion actual: "<<p.descripcion<<endl;
                cout<<"Nueva Descripcion: "; cin>>p.descripcion;
                break;
            case 4:
                cout<<"Precio actual: "<<p.precio<<endl;
                cout<<"Nuevo Precio: "; cin>>p.precio;
                break;
            case 0:
                break;
        }
    } while(aux!=0);
}