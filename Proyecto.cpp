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
        cout<<"Seleccione una opcion: "<<endl;
        cout<<"1. Insertar Registro"<<endl;
        cout<<"2. Consultar"<<endl;
        cout<<"3. Salir"<<endl;
        cin>>opcion;
        system("cls");
        switch(opcion) {
            case '1':
                registroAgregar=empleado.pedirDatos();
                if(empleado.altas(registroAgregar))
                    cout<<"Empleado Agregado con exito"<<endl;
                else
                    cout<<" NO SE PUDO AGREGAR AL EMPLEADO"<<endl;
                break;
            case '2':
                cout<<"Ingrese el DNI del empleado a buscar: ";
                fflush(stdin);
                getline(cin, dniABuscar);
                if(empleado.consultas(dniABuscar,empleadoBuscar))
                    cout<<endl<<empleadoBuscar<<endl;
                else
                    cout<<"No existe ese empleado"<<endl;
                break;
            case '3':
                cout<<"Saliendo del programa con exito"<<endl;
                break;
            }
        cout<<endl;
        system("Pause");
        }
    while(opcion!='3');
    return 0;
    }
