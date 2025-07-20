#include <iostream>
#include "menu.h"
#include "modificarDatos.h"
#include "producto.h"
#include "servicio.h"
using namespace std;

void menu_u(registro &User, int &op){
    int aux;
    do{
        system("cls");
        cout << "1. Pedir Pedido" << endl;
        cout << "2. Actualizar Datos" << endl;
        cout << "3. Dejar Comentario" << endl;
        cout << "0. Cerrar Sesion" << endl;
        cout << "----------------------------------" << endl;
        cout << "Elige una opcion: "; cin >> aux;

        switch (aux) {
            case 1:
                system("cls");
                cout << "Opciones--------"<< endl;
                cout << "1. Pasar pedido" << endl;
                cout << "2. Tu Saldo" << endl;
                cout << "0. Regresar" << endl;
                cout << "----------------------------------" << endl;
                cout << "Elige una opcion: "; cin >> aux;
                ppedidos(User, aux);
                break;
            case 2:
                do {
                    system("cls");
                    cout<<"TUS DATOS DE USUARIO:----------------------------------\n\n";
                    cout<<"1.Nombre"<<endl;
                    cout<<"2.Usuario"<<endl;
                    cout<<"3.Contrasena"<<endl;
                    cout<<"4.Email"<<endl;
                    cout<<"5.Numero"<<endl;
                    cout<<"6.Direccion"<<endl;
                    cout<<"0.Regresar\n\n";
                    cout<<"Que desea modificar?(nro): "; cin>>aux;
                    modific(User, aux);
                } while(aux!=0);
                aux =-1;
                break;
            case 3:
                void coment();
                aux=-1;
                break;
            case 0:
                op = 1;
                break;
        }
    } while (aux!=0);
}

void ppedidos(registro &User, int aux){
    int num=-1;
    float recarga=0, gasto=0;
    int op=-1;
    int r=0, v=0;
    system("cls");
    switch (aux){
        case 1:
            if (numProductos=0){
                cout << "NO HAY PRODUCTOS DISPONIBLES";
                break;
            }
            cout<<"PRODUCTOS A LA VENTA\n\n";
            for(int i=0; i<numProductos; i++){
                cout << "Producto #" << i+1<<endl;
                cout << "\t"<<item[i].nom << endl;
                cout << "\t"<<item[i].descripcion << endl;
                cout << "\t"<<item[i].precio << endl;
                cout << "Codigo ID: " << item[i].id << "\n";
                cout << "------------------------------------------------------------------\n";
            }
            cout << "INGRESE '0' cuando desee finalizar el pedido\n";
            do {
                if (num==0){
                    op = 0;
                } else {
                    r=0;
                    do {
                        cout << "Ingrese su Item #"<<v++<<" (Ingresar ID): "; cin >> num;
                        for(int i=0; i<numProductos; i++){
                            if (num==item[i].id){
                                pedido[numPedidos].obj[i] = item[i];
                                User.dinero = User.dinero - item[i].precio;
                                r=1;
                            }
                        }
                    } while (num !=0);
                    if (r==1){
                        pedido[numPedidos].nombre = User.nombre;
                        pedido[numPedidos].telefono = User.telefono;
                        pedido[numPedidos].destino.departamento = User.dir.departamento;
                        pedido[numPedidos].destino.provincia = User.dir.provincia;
                        pedido[numPedidos].destino.distrito = User.dir.distrito;
                        pedido[numPedidos].destino.via = User.dir.via;
                        pedido[numPedidos].destino.manzana = User.dir.manzana;
                        pedido[numPedidos].destino.lote = User.dir.lote;
                        pedido[numPedidos].destino.piso = User.dir.piso;
                        pedido[numPedidos].destino.cod_postal = User.dir.cod_postal;
                        numPedidos++;
                    } else {
                        cout << "\nID no valido\n\n";
                    }
                }
            } while(op!=0);
            break;
        case 2:
            system("cls");
            cout <<"CUENTA MONETARIA\n\n";
            cout << "Estado: ";
            if (User.dinero<0){
                cout<<"En Deuda\n";
            } else {
                cout <<"Sin deudas\n";
            }
            cout <<"Saldo Actual: "<<User.dinero<<"\n";
            cout <<"Añadir Saldo: "; cin >> recarga;
            User.dinero = User.dinero + recarga;
            break;
        case 0:
            break;
    }
}

void menu_e(trabajador &Emp, int &op) {
    int tipoTrab, aux;
    string claveExtra;

    do {
        system("cls");
        cout << "Selecciona como ingresar: " << endl;
        cout << "1. Repartidor\n";
        cout << "2. Administrador\n";
        cout << "0. Cerrar Sesion\n ";
        cin >> tipoTrab;

        switch (tipoTrab) {
            case 1:
                menu_repar();
                aux=-1;
                break;
            case 2: {
                system("cls");
                int intentos = 3;
                while (intentos > 0) {
                    cout << "(es 'FULL2025') Ingrese la clave de ADMIN: ";
                    cin >> claveExtra;
                    if (claveExtra == "FULL2025") {
                        menu_admin();
                        aux=-1;
                        break;
                    } else {
                        intentos--;
                        cout << "Clave incorrecta. Te quedan " << intentos << " intento(s)\n\n";
                    }
                }
                cout << "\nHas excedido el numero de intentos\n";
                system("pause");
                break;
            }
            case 0:
                aux=0;
                op=1;
                break;
            default:
                aux=-1;
                cout << "OPCION INVALIDA\n";
                system("pause");
                break;
        }
    } while (aux!=0);
}

void menu_admin() {
    int op=-1;
    int idBuscar;
    int encontrado = 0;
    do {
        system("cls");
        cout << "MENU DE ADMINISTRADOR\n";
        cout << "1. Registrar producto\n";
        cout << "2. Lista de productos\n";
        cout << "3. Modificar producto\n";
        cout << "0. Salir\n";
        cout << "--------------------------------------"<<endl;
        cout << "Seleccionar Opcion: "; cin >> op;

        switch (op) {
            case 1:
                system("cls");
                if (numProductos > 100) {
                    cout << "\nLIMITE MAXIMO ALCANZADO.\n";
                    system("pause");
                } else{
                    cout << "REGISTRO DE NUEVO PRODUCTO\n";
                    cout << "ID: "; cin >> item[numProductos].id;
                    cin.ignore();
                    cout << "Nombre: "; getline(cin, item[numProductos].nom);
                    cout << "Descripcion: "; getline(cin, item[numProductos].descripcion);
                    cout << "Precio(c/u): "; cin >> item[numProductos].precio;
                    numProductos++;
                    cout << "\nProducto registrado correctamente.......\n";
                    system("pause");
                }
                break;
            case 2:
                system("cls");
                if (numProductos == 0) {
                    cout << "NO HAY PRODUCTOS REGISTRADOS\n";
                    system("pause");
                } else {
                    cout << "LISTA DE PRODUCTOS\n";
                    for (int i = 0; i < numProductos; i++) {
                        cout << "\nProducto #" << i + 1 << endl;
                        cout << "ID: " << item[i].id << endl;
                        cout << "Nombre: " << item[i].nom << endl;
                        cout << "Descripcion: " << item[i].descripcion << endl;
                        cout << "Precio(c/u): " << item[i].precio << endl;
                        cout << "---------------------------------------------------------------" << endl;
                    }
                    system("pause");
                }
                break;
            case 3:
                system("cls");
                if (numProductos == 0){
                    cout << "NO HAY PRODUCTOS PARA MODIFICAR\n";
                    system("pause");
                } else{
                    cout << "Ingrese el ID del producto a modificar: ";
                    cin >> idBuscar;
                    for (int i = 0; i < numProductos; i++) {
                        if (item[i].id == idBuscar) {
                            encontrado = 1;
                            mod_prod(item[i]);
                        }
                    }
                    if (encontrado == 0) {
                        cout << "\nProducto no encontrado\n";
                        system("pause");
                    }
                }
                break;
            case 0:
                op = 0;
                break;
            default:
                system("cls");
                cout << "OPCION INVALIDA\n";
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
        cout << "0. Salir\n";
        cout << "--------------------------------------"<<endl;
        cout << "Seleccionar Opcion: "; cin >> op;

        switch(op){
            case 1:
                system("cls");
                if (numPedidos == 0) {
                    cout << "NO HAY PEDIDOS REGISTRADOS\n";
                } else {
                    cout << "LISTA DE PEDIDOS\n\n";
                    for (int i = 0; i < numPedidos; i++) {
                        cout << "=========== PEDIDO #" <<i+1<< " ==========="<<endl;
                        cout << "Pedido para: "<< pedido[i].nombre <<endl;
                        cout << "Telefono: "<< pedido[i].telefono <<endl;
                        cout << "Direccion:"<<endl;
                        cout << "\t- Departamento: " << pedido[i].destino.departamento << endl;
                        cout << "\t- Provincia: " << pedido[i].destino.provincia << endl;
                        cout << "\t- Distrito: " << pedido[i].destino.distrito << endl;
                        cout << "\t- Via: " << pedido[i].destino.via << endl;
                        cout << "\t- Manzana: " << pedido[i].destino.manzana << endl;
                        cout << "\t- Lote: " << pedido[i].destino.lote << endl;
                        cout << "\t- Piso: " << pedido[i].destino.piso << endl;
                        cout << "\t- Codigo Postal: " << pedido[i].destino.cod_postal << endl;
                        cout << "Productos solicitados:\n";
                        for (int j = 0; j < 100; j++) {
                            if (pedido[i].obj[j].nom != "") {
                                cout << "\t- " << pedido[i].obj[j].nom << "\tS/ " << pedido[i].obj[j].precio << "\n";
                            }
                        }
                        cout << "================================================\n\n";
                    }
                }
                system("pause");
                break;
            case 0:
                break;
            default:
                cout << "OPCION INVALIDA" << endl;
                system("pause");
        }
    } while (op != 0);
}