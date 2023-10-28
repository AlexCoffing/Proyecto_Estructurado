#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <sstream>
#include <cstring>
#include "Empleados.hpp"

using namespace std;

int main(void)
{
	srand(time(0));
	Empleados empleado, empleadoBuscar;
	Empleados registroAgregar;
	string dniABuscar;
	char opcion;


	cout << endl;
    cin.get();
	system("cls");
	do
	{
		cout<<" \n\n\t\t BIENVENIDO AL REGISTRO DE EMPLEADOS\n\n";
		cout<<"Seleccione una opcion: "<<endl;
		cout<<"1. Insertar Registro"<<endl;
		cout<<"2. Consultar"<<endl;
		cout<<"3. Salir"<<endl;
		    cin>>opcion;
		    cin.ignore();
		    switch(opcion)
		    {
		    	case '1': registroAgregar=empleado.pedirDatos();
				          if(empleado.altas(registroAgregar))
						    cout<<"Empleado Agregado con exito"<<endl;
						  else
						    cout<<" NO SE PUDO AGREGAR AL EMPLEADO"<<endl;
						  break;
				case '2': cout<<"Ingrese el DNI del empleado a buscar: ";
				          fflush(stdin);
				          getline(cin, dniABuscar);
				          if(empleado.consultas(dniABuscar,empleadoBuscar))
				             cout<<endl<<empleadoBuscar<<endl;
				          else
				            cout<<"No existe ese empleado"<<endl;
				          break;
				case '3': cout<<"Saliendo del programa con exito"<<endl;
			}
			cout<<endl;
			system("Pause");
			system("cls");
	}while(opcion!='3');
	return 0;
}
