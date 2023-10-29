/*
    Nombre de los integrantes y codigos:
    1. De La Paz Espinosa Brandon Alexander 219575098
    2. Romo Lopez Juan Diego 21

    Nombre de la materia: Estructuras de Datos II
    Seccion: D03
    Profesora: Lara Lopez Graciela
*/

#include <iostream>
#include "Empleados.hpp"

using namespace std;

int main(void) {
    srand(time(0));
    Empleados empleado, empleadoBuscar;
    Empleados registroAgregar;
    string dniABuscar;
    char opcion;

    do {
        system("cls");
        cout<<" \n\n\t\t BIENVENIDO AL REGISTRO DE EMPLEADOS\n\n";
        cout<<" Seleccione una opcion: "<<endl;
        cout<<" 1. Insertar Registro"<<endl;
        cout<<" 2. Consultar"<<endl;
        cout<<" 3. Salir"<<endl;
        cout<<" -> ";
        cin>>opcion;
        system("cls");
        switch(opcion) {
            case '1':
                registroAgregar=empleado.pedirDatos();
                if(empleado.altas(registroAgregar))
                    cout<<"\n Empleado Agregado con exito"<<endl<<endl;
                else
                    cout<<"\n NO SE PUDO AGREGAR AL EMPLEADO"<<endl<<endl;;
                break;
            case '2':
                cout<<"\n Ingrese el DNI del empleado a buscar: ";
                fflush(stdin);
                getline(cin, dniABuscar);
                if(empleado.consultas(dniABuscar,empleadoBuscar))
                    cout<<endl<<empleadoBuscar<<endl;
                else
                    cout<<"\n No existe ese empleado"<<endl<<endl;
                break;
            case '3':
                cout<<"\n Saliendo del programa con exito"<<endl<<endl;
                break;
            default:
                cout<<"\n Esa opcion no existe, vuelva a intentarlo"<<endl<<endl;
            }
        cout<<" ";
        system("Pause");
        }
    while(opcion!='3');
    return 0;
    }
