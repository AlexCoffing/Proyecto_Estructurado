/*
    Nombre de los integrantes y codigos:
    1. De La Paz Espinosa Brandon Alexander 219575098
    2. Romo Lopez Juan Diego 222790617

    Nombre de la materia: Estructuras de Datos II
    Seccion: D03
    Profesora: Lara Lopez Graciela
*/

#include "Empleados.hpp"

using namespace std;

int main(void) {
    srand(time(0));
    Empleados empleado, empleadoBuscar;
    Empleados registroAgregar;
    string dniABuscar,seguro;
    char opcion;

    do {
        system("cls");
        cout<<" \n\n\t\t BIENVENIDO AL REGISTRO DE EMPLEADOS\n\n";
        cout<<" Seleccione una opcion: "<<endl;
        cout<<" 1. Insertar Registro"<<endl;
        cout<<" 2. Consultar registro por su DNI"<<endl;
        cout<<" 3. Eliminar registro de manera logica"<<endl;
        cout<<" 4. Visualizar la lista de disponibles"<<endl;
        cout<<" 5. Salir"<<endl;
        cout<<" -> ";
        cin>>opcion;
        system("cls");
        switch(opcion) {
            case '1':
                registroAgregar=empleado.pedirDatos();
                if(empleado.altas(registroAgregar))
                    cout<<"\n Empleado Agregado con exito"<<endl<<endl;
                else
                    cout<<"\n NO SE PUDO AGREGAR AL EMPLEADO"<<endl<<endl;
                break;
            case '2':
                cout<<"\n Ingrese el DNI del empleado a buscar: ";
                fflush(stdin);
                getline(cin, dniABuscar);
                if(empleado.consultas(dniABuscar,empleadoBuscar))
                    cout<<empleadoBuscar<<endl;
                else
                    cout<<"\n No existe ese empleado"<<endl<<endl;
                break;
            case '3':
                cout<<"\n Ingrese el DNI del empleado a Eliminar: ";
                fflush(stdin);
                getline(cin, dniABuscar);
                if(empleado.consultas(dniABuscar,empleadoBuscar)) {
                    cout<<empleadoBuscar<<endl;
                    cout<<" Estas seguro de Eliminar a este Empleado? (Si / No)"<<endl;
                    cout<<" -> ";
                    cin>>seguro;
                    if(seguro=="SI" || seguro=="Si" || seguro=="si" || seguro=="sI") {
                        if(empleado.bajas(dniABuscar,empleadoBuscar))
                            cout<<"\n El empleado sea eliminado de manera logica con exito"<<endl;
                        else
                            cout<<"\n No se pudo eliminar al empleado"<<endl;
                        }
                    cout<<endl;
                    }
                else
                    cout<<"\n No existe ese empleado"<<endl<<endl;
                break;
            case '4':
                empleado.verLista();
                cout<<endl;
                break;
            case '5':
                cout<<"\n Saliendo del programa con exito"<<endl<<endl;
                break;
            default:
                cout<<"\n Esa opcion no existe, vuelva a intentarlo"<<endl<<endl;
            }
        cout<<" ";
        system("Pause");
        }
    while(opcion!='5');
    return 0;
    }
