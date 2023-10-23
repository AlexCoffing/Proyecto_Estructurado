#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include <cstdlib>
#include<stdio.h>
#include <ctime>
#include <sstream>
#include <cstring>

using namespace std;

#ifndef EMPLEADOS_H
#define EMPLEADOS_H

//declaración de la clase "Empleados"
class Empleados
{
	private:
		char dni[9];
		char nombre[35];
		char cargo[35];
		char edad[3];
		char sueldo[10];
		char fecha_cont[10];
		long int buscarDni(const string &);
	public:
		Empleados(void);
		Empleados(const Empleados &);
		void setDni(const string &);
		void setNombre(const string &);
		void setCargo(const string &);
		void setEdad(const string &);
		void setSueldo(const string &);
		void setFecha_cont(const string &);
		friend ostream &operator<<(ostream &,const Empleados &);
		
		bool altas(const Empleados &);
		bool consultas(const string &, Empleados &);
		bool bajas(const string &, Empleados &);
		bool contiene(const string &);
		Empleados pedirDatos(void);
		
};

#endif

Empleados::Empleados()
{
    dni[0] = '\0';
    nombre[0] = '\0';
    cargo[0] = '\0';
    edad[0] = '\0';
    sueldo[0] = '\0';
    fecha_cont[0] = '\0';
}

//función que retorna un flujo que permite la salida de datos
ostream &operator<<(ostream &salida, const Empleados &empleado)
{
	salida<< "\nDNI: "<<empleado.dni<<endl
	      << "\nNombre del empleado: "<<empleado.nombre<<endl
	      << "\nCargo: "<<empleado.cargo<<endl
	      << "\nEdad: "<<empleado.edad<<endl
	      << "\nSueldo:$"<<empleado.sueldo<<endl
	      << "\nFecha de Contratacion: "<<empleado.fecha_cont<<endl;
	      
	return salida;
}

//constructor o función que inicializará un objeto al mismo tiempo que se declara
Empleados::Empleados(const Empleados &origen)
{
	strcpy(dni, origen.dni);
	strcpy(nombre, origen.nombre);
	strcpy(cargo, origen.cargo);
	strcpy(edad, origen.edad);
	strcpy(sueldo, origen.sueldo);
	strcpy(fecha_cont, origen.fecha_cont);
	
}

//inicio de los métodos de acceso para recuperar un valor asignado y poderlo mostrar en pantalla 
void Empleados::setDni(const string &valorDni)
{
	int longitud=valorDni.size();
	longitud= (longitud<9? longitud: 9-1);
	valorDni.copy(dni, longitud);
	dni[longitud]='\0';
}

void Empleados::setNombre(const string &valorNombre)
{
	int longitud=valorNombre.size();
	longitud= (longitud<35? longitud: 35-1);
	valorNombre.copy(nombre, longitud);
	nombre[longitud]='\0';
}

void Empleados::setCargo(const string &valorCargo)
{
	int longitud=valorCargo.size();
	longitud= (longitud<35? longitud: 35-1);
	valorCargo.copy(cargo, longitud);
	cargo[longitud]='\0';
}

void Empleados::setEdad(const string &valorEdad)
{
	int longitud=valorEdad.size();
	longitud= (longitud<3? longitud: 3-1);
	valorEdad.copy(edad, longitud);
	edad[longitud]='\0';
}

void Empleados::setSueldo(const string &valorSueldo)
{
	int longitud=valorSueldo.size();
	longitud= (longitud<10? longitud: 10-1);
	valorSueldo.copy(sueldo, longitud);
	sueldo[longitud]='\0';
}

void Empleados::setFecha_cont(const string &valorFecha_cont)
{
	int longitud=valorFecha_cont.size();
	longitud= (longitud<10? longitud: 10-1);
	valorFecha_cont.copy(fecha_cont, longitud);
	fecha_cont[longitud]='\0';
} //fin de los métodos de acceso

//funcion para generar el numero aleatorio de 8 digitos
int  generarNumeroAleatorio() 
{
    int numeroAleatorio = std::rand() % 90000000 + 10000000;

    return numeroAleatorio;
}

//funcion para generar la letra correspondiente al residuo
char obtenerLetraPorResiduo(int residuo) 
{
    switch (residuo) 
	{
        case 0: return 'T';
        case 1: return 'R';
        case 2: return 'W';
        case 3: return 'A';
        case 4: return 'G';
        case 5: return 'M';
        case 6: return 'Y';
        case 7: return 'F';
        case 8: return 'P';
        case 9: return 'D';
        case 10: return 'X';
        case 11: return 'B';
        case 12: return 'N';
        case 13: return 'J';
        case 14: return 'Z';
        case 15: return 'S';
        case 16: return 'Q';
        case 17: return 'V';
        case 18: return 'H';
        case 19: return 'L';
        case 20: return 'C';
        case 21: return 'K';
        case 22: return 'E';
        default: return '\0'; // Caracter nulo en caso de residuo inválido
    }
}


//función para pedirle al usuario los datos necesarios para un objeto y  retornarlo con información listo para agregarlo al archivo
Empleados Empleados::pedirDatos(void)
{
	string cadena;
    Empleados registroARetornar;

    int numeroAleatorio;
    do
    {
        int numero = generarNumeroAleatorio();
        int residuo = numero % 23;
        char letra = obtenerLetraPorResiduo(residuo);

        std::stringstream ss;
        ss << numero;
        std::string DNI = ss.str() + letra;

        if (!contiene(DNI))
        {
            numeroAleatorio = numero;  
            registroARetornar.setDni(DNI);
            std::cout << "DNI generado: " << DNI << std::endl;  // Mostrar el DNI
            break;
        }
        else
        {
            std::cout << "El DNI ya existe. Generando uno nuevo." << std::endl;
        }
        
    } while (true);
  

    cout << "Nombre del empleado: ";
    fflush(stdin);
    std::getline(std::cin, cadena);
    registroARetornar.setNombre(cadena);

    cout << "Cargo: ";
    fflush(stdin);
    getline(cin, cadena);
    registroARetornar.setCargo(cadena);

    cout << "Edad: ";
    fflush(stdin);
    getline(cin, cadena);
    registroARetornar.setEdad(cadena);

    cout << "Sueldo: $";
    fflush(stdin);
    getline(cin, cadena);
    registroARetornar.setSueldo(cadena);

    cout << "Fecha de Contratacion: ";
    fflush(stdin);
    getline(cin, cadena);
    registroARetornar.setFecha_cont(cadena);

    return registroARetornar;
}


//función para agregar objetos nuevos al archivo
bool Empleados::altas(const Empleados &nuevoEmpleado)
{
	string dniCadena = nuevoEmpleado.dni;

    if (contiene(dniCadena))
        return false;
    else
    {
        ofstream archivo("Empleados.txt", ios::app);
            archivo << nuevoEmpleado.dni << "|" << nuevoEmpleado.nombre << "|" << nuevoEmpleado.cargo << "|"
                    << nuevoEmpleado.edad << "|" << nuevoEmpleado.sueldo << "|" << nuevoEmpleado.fecha_cont << "|\n";
            archivo.close();
            return true;
    }
}

//funcion intermediaria que recibe un dni del empleado, llama al método buscarDni y evalúa el retorno de dicha función retornando false cuando el dni no se encuentra en el archivo
bool Empleados::contiene(const string &dniABuscar)
{
	if(buscarDni(dniABuscar)== -1)
	   return false;
	return true;
}


//método que recibe como parámetro el valor de un identificador del empleado o el dni, para ello es necesario abrir el archivo para lectura(ios::in)
long int Empleados::buscarDni(const string &valorDni)
{
	Empleados empleado;
	Empleados temp;
	long int posByte = 0;

	empleado.setDni(valorDni);
	ifstream archivo("Empleados.txt", ios::in);

	if (archivo)
	{
		while (!archivo.eof())
		{
             
            archivo.getline(temp.dni, 9,'|');
            if(strcmp(temp.dni, empleado.dni)==0)
            {
            	posByte = (long)archivo.tellg() - (strlen(temp.dni) + 1);
            	archivo.close();
            	return posByte;
            }
            else
            {
			    archivo.getline(temp.dni,9,'|');
				archivo.getline(temp.nombre, 35, '|');
			    archivo.getline(temp.cargo, 35, '|');
			    archivo.getline(temp.edad, 3, '|');
			    archivo.getline(temp.sueldo, 10, '|');
			    archivo.getline(temp.fecha_cont, 10, '|');
            }
		} //fin del ciclo while
	}// fin del if
	archivo.close();
	return -1;

}

//función consultar la cual recibe el dni del empleado que se desea localizar
bool Empleados::consultas(const string &dniABuscar, Empleados &empleadoEncontrado)
{
	long int posByte;
	
	ifstream archivo("Empleados.txt",ios::in);
        if (!archivo)
        {
            cout<< "Lo sentimos, el archivo no existe :'(" << endl;
            return -1;
        }
        else
        {
        	posByte=buscarDni(dniABuscar);
        	cout<<"posByte= "<<posByte<<endl;
        	if(posByte!= -1)
        	{
        		archivo.seekg(posByte, ios::beg);
        		archivo.getline(empleadoEncontrado.dni,9,'|');
        		archivo.getline(empleadoEncontrado.nombre,35,'|');
        		archivo.getline(empleadoEncontrado.cargo,35,'|');
        		archivo.getline(empleadoEncontrado.edad,3,'|');
        		archivo.getline(empleadoEncontrado.sueldo,10,'|');
        		archivo.getline(empleadoEncontrado.fecha_cont,10,'|');
        		archivo.close();
        		return true;
        		
			}//fin del if
		}//fin del else
    archivo.close();
    return false;

}

int main(void)
{
	std::srand(std::time(0));
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
				          std::getline(std::cin, dniABuscar);
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
