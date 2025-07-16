#include <iostream>
#include "menu.h"
#include "producto.h"
using namespace std;

int numProductos = 0;
int numPedidos = 0;

producto item[100];
pedir pedido[100];
void verProductos();
void modific(registro&, int);
void ppedidos(int);

void menu_u(registro &User, int &op){ //no modificar op
    producto listaProd;
    int aux, np=0;
    do{
        system("cls");
        cout << "1. Pedir Pedido" << endl;
        cout << "2. Actualizar Datos" << endl;
        cout << "0. Cerrar Sesión" << endl;
        cout << "----------------------------------" << endl;
        cout << "Elige una opcion: "; cin >> aux;

        switch (aux) {
            case 1:
                system("cls");
                cout << "Opciones--------"<< endl;
                cout << "1. Pasar pedido" << endl;
                cout << "2. Tu Saldo" << endl;
                cout << "0. Regresar" << endl;
                cin >> aux;
                ppedidos(aux);
                break;
            case 2:
                system("cls");
                cout<<"TUS DATOS DE USUARIO:----------------------------------\n\n";
                cout<<"1.Nombre: "<<User.nombre<<endl;
                cout<<"2.Usuario: "<<User.usuario<<endl;
                cout<<"3.Contrasena: "<<User.contrasena<<endl;
                cout<<"4.Email: "<<User.email<<endl;
                cout<<"5.Numero: "<<User.telefono<<endl;

                cout<<"\nQue desea modificar???(nro): "; cin>>aux;
                modific(User, aux);
                aux =-1;
                break;
            case 0:
                op = 1;
                break;
        }
    } while (aux!=0);
}

void modific(registro &u, int aux){
    registro u_m;
    system("cls");
    switch(aux){
        case 1:
            cout<<"Nombre Actual: "<<u.nombre<<endl;
            cout<<"\n\nNombre Nuevo: "; cin >> u_m.nombre;
            u = u_m;
        case 2:
            cout<<"Usuario Actual: "<<u.usuario<<endl;
            cout<<"\n\nUsuario Nuevo: "; cin >> u_m.usuario;
            u = u_m;
        case 3:
            cout<<"Clave Actual: "<<u.contrasena<<endl;
            cout<<"\n\nClave Nueva: "; cin >> u_m.contrasena;
            u = u_m;
        case 4:
            cout<<"Email Actual: "<<u.email<<endl;
            cout<<"\n\nEmail Nuevo: "; cin >> u_m.email;
            u = u_m;
        case 5:
            cout<<"Numero Actual: "<<u.telefono<<endl;
            cout<<"\n\nNumero Nuevo: "; cin >> u_m.telefono;
            u = u_m;
    }
}

void ppedidos(int aux){
    int num, p=0;
    int op=-1;
    switch (aux){
        case 1:
            for(int i=0; i<20; i++){
                cout << "Producto #" << i+1<<endl;
                cout << "\t"<<item[i].nom << endl;
                cout << "\t"<<item[i].descripcion << endl;
                cout << "\t"<<item[i].precio << endl;
                cout << "Codigo ID: " << item[i].id << "\n\n";
            }
            cout << "INGRESE 0, para finalizar el pedido\n";
            do {
                cout << "Que desear pedir(Ingresar ID): "; cin >> num;
                if (num==0){
                    op = 0;
                } else {
                    for(int i=0; i<20; i++){
                        if (num==item[i].id){
                            pedido[p].obj[i] = item[i];
                        }
                    }
                }
            } while(op!=0);
            p++;
            break;
        case 2:
            system("cls");
            cout <<"Saldo Actual: ";
            cout <<"Añadir Saldo: "; cin >> num;
            
            break;
        case 0:
            break;
    }
}

void menu_e(trabajador &Emp, int &op) {
    int tipoTrab;
    string claveExtra;

    while (true) {
        system("cls");
        cout << "Selecciona como ingresar: " << endl;
        cout << "1. Repartidor\n";
        cout << "2. Administrador\n";
        cout << "0. Volver\n ";
        cin >> tipoTrab;

        switch (tipoTrab) {
            case 1:
                menu_repar();
                return;

            case 2: {
                int intentos = 3;
                while (intentos > 0) {
                    cout << "Ingrese la contraseña de ADMIN: ";
                    cin >> claveExtra;
                    if (claveExtra == "FULL2025") {
                        menu_admin();
                        return;
                    } else {
                        intentos--;
                        cout << "Clave incorrecta. Te quedan " << intentos << " intento(s).\n";
                        if (intentos > 0) system("pause");
                    }
                }
                cout << "\nHas excedido el número de intentos";
                system("pause");
                return;
            }
            case 0:
                return;

            default:
                cout << "Opción inválida\n";
                system("pause");
        }
    }
}
///////////

void menu_admin() {
    int op;
    do {
        system("cls");
        cout << "MENU DE ADMINISTRADOR\n";
        cout << "1. Registrar producto\n";
        cout << "2. Lista de productos\n";
        cout << "3. Modificar producto\n";
        cout << "0. Salir\n\n";
        cout << "Seleccionar Opcion: "; cin >> op;

        switch (op) {
            case 1: {
                system("cls");
                if (numProductos >= 100) {
                    cout << "\nLIMITE MAXIMO ALCANZADO.\n";
                    system("pause");
                    break;
                }
                cout << "REGISTRO DE NUEVO PRODUCTO\n";
                cout << "ID: "; cin >> item[numProductos].id;
                cin.ignore();
                cout << "Nombre: "; getline(cin, item[numProductos].nom);
                cout << "Descripcion: "; getline(cin, item[numProductos].descripcion);
                cout << "Categoria: "; getline(cin, item[numProductos].categoria);
                cout << "Precio: "; cin >> item[numProductos].precio;

                numProductos++;
                cout << "\nProducto registrado correctamente.\n";
                system("pause");
                break;
            }

            case 2: {
                system("cls");
                cout << "LISTA DE PRODUCTOS\n";
                if (numProductos == 0) {
                    cout << "No hay productos registrados.\n";
                } else {
                    for (int i = 0; i < numProductos; i++) {
                        cout << "\nProducto #" << i + 1 << endl;
                        cout << "ID: " << item[i].id << endl;
                        cout << "Nombre: " << item[i].nom << endl;
                        cout << "Descripcion: " << item[i].descripcion << endl;
                        cout << "Categoria: " << item[i].categoria << endl;
                        cout << "Cantidad: " << item[i].cantidad << endl;
                        cout << "------------------------------" << endl;
                    }
                }
                system("pause");
                break;
            }

            case 3: {
                system("cls");
                if (numProductos == 0) {
                    cout << "No hay productos para modificar.\n";
                    system("pause");
                    break;
                }

                int idBuscar;
                cout << "Ingrese el ID del producto a modificar: ";
                cin >> idBuscar;
                cin.ignore();

                bool encontrado = false;
                for (int i = 0; i < numProductos; i++) {
                    if (item[i].id == idBuscar) {
                        encontrado = true;
                        cout << "Nuevo nombre: "; getline(cin, item[i].nom);
                        cout << "Nueva descripcion: "; getline(cin, item[i].descripcion);
                        cout << "Nueva categoria: "; getline(cin, item[i].categoria);
                        cout << "Nueva cantidad: "; cin >> item[i].cantidad;
                        cout << "\nProducto modificado.\n";
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "\nProducto no encontrado.\n";
                }
                system("pause");
                break;
            }

            case 0:
                cout << "Saliendo del menu administrador...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
                system("pause");
        }

    } while (op != 0);
}
void menu_repar() {
    int op;
    do {
        system("cls");
        cout << "MENU DE REPARTIDOR\n";
        cout << "1. Ver lista de pedidos\n";
        cout << "2. Ver detalle de un pedido\n";
        cout << "0. Volver\nOpcion: ";
        cin >> op;

        switch (op) {
            case 1: {
                system("cls");
                if (numPedidos == 0) {
                    cout << "No hay pedidos registrados.\n";
                } else {
                    cout << "LISTA DE PEDIDOS\n";
                    for (int i = 0; i < numPedidos; i++) {
                        cout << "Pedido para: " << ///// << endl;
                        cout << "Lista:"<<endl;
                        for (int i=0;)
                    }
                }
                system("pause");
                break;
            }

            case 2: {
                system("cls");
                if (numPedidos == 0) {
                    cout << "No hay pedidos registrados.\n";
                    system("pause");
                    break;
                }

                int index;
                cout << "Ingrese el numero de pedido: ";
                cin >> index;

                if (index < 1 || index > numPedidos) {
                    cout << "Numero de pedido invalido.\n";
                } else {
                    int i = index - 1;
                    cout << "\nDETALLE DEL PEDIDO\n";
                    cout << "Cliente: " << pedidos[i].usuario << endl;
                    cout << "Telefono: " << pedidos[i].telefono << endl;
                    cout << "Direccion: "
                         << pedidos[i].dir.via << ", Mz " << pedidos[i].dir.manzana
                         << ", Lote " << pedidos[i].dir.lote << ", Piso " << pedidos[i].dir.piso
                         << ", " << pedidos[i].dir.distrito << ", "
                         << pedidos[i].dir.provincia << ", " << pedidos[i].dir.departamento
                         << ", CP " << pedidos[i].dir.cod_postal << endl;

                    cout << "\nProductos solicitados:\n";
                    for (int j = 0; j < pedidos[i].numProductos; j++) {
                        cout << "- " << pedidos[i].obj[j].nom << " x" << pedidos[i].obj[j].cantidad << endl;
                    }
                }
                system("pause");
                break;
            }

            case 0:
                break;

            default:
                cout << "Opcion invalida.\n";
                system("pause");
        }
    } while (op != 0);
}  

    void verPedidos() {
    system("cls");
    if (numPedidos == 0) {
        cout << "No hay pedidos disponibles.\n";
        system("pause");
        return;
    }

    for (int i = 0; i < numPedidos; i++) {
        cout << "=========== PEDIDO #" << (i + 1) << " ===========" << endl;
        cout << "Cliente: " << pedidos[i].usuario << endl;
        cout << "Teléfono: " << pedidos[i].telefono << endl;

        cout << "Dirección: " 
             << pedidos[i].dir.via << ", Mz " << pedidos[i].dir.manzana 
             << ", Lote " << pedidos[i].dir.lote << ", Piso " << pedidos[i].dir.piso 
             << ", " << pedidos[i].dir.distrito << ", " 
             << pedidos[i].dir.provincia << ", " << pedidos[i].dir.departamento 
             << ", CP " << pedidos[i].dir.cod_postal << endl;

        cout << "\n Productos solicitados:\n";
        for (int j = 0; j < pedidos[i].numProductos; j++) {
            cout << "- " << pedidos[i].obj[j].nom << " (S/ " << pedidos[i].obj[j].precio << ")\n";
        }

        cout << "================================\n\n";
    }

    system("pause");
}