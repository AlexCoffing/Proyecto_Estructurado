#include "Empleados.hpp"

using namespace std;

Empleados::Empleados() {
    dni[0] = '\0';
    nombre[0] = '\0';
    cargo[0] = '\0';
    edad[0] = '\0';
    sueldo[0] = '\0';
    fecha_cont[0] = '\0';
    }

//constructor o función que inicializará un objeto al mismo tiempo que se declara
Empleados::Empleados(const Empleados &origen) {
    strcpy(dni, origen.dni);
    strcpy(nombre, origen.nombre);
    strcpy(cargo, origen.cargo);
    strcpy(edad, origen.edad);
    strcpy(sueldo, origen.sueldo);
    strcpy(fecha_cont, origen.fecha_cont);
    }

//inicio de los métodos de acceso para recuperar un valor asignado y poderlo mostrar en pantalla
void Empleados::setDni(const string &valorDni) {
    int longitud=valorDni.size();
    longitud=(longitud<10? longitud: 10-1);
    valorDni.copy(dni, longitud);
    dni[longitud]='\0';
    }

void Empleados::setNombre(const string &valorNombre) {
    int longitud=valorNombre.size();
    longitud= (longitud<37? longitud: 37-1);
    valorNombre.copy(nombre, longitud);
    nombre[longitud]='\0';
    }

void Empleados::setCargo(const string &valorCargo) {
    int longitud=valorCargo.size();
    longitud= (longitud<37? longitud: 37-1);
    valorCargo.copy(cargo, longitud);
    cargo[longitud]='\0';
    }

void Empleados::setEdad(const string &valorEdad) {
    int longitud=valorEdad.size();
    longitud= (longitud<3? longitud: 3-1);
    valorEdad.copy(edad, longitud);
    edad[longitud]='\0';
    }

void Empleados::setSueldo(const string &valorSueldo) {
    int longitud=valorSueldo.size();
    longitud= (longitud<10? longitud: 10-1);
    valorSueldo.copy(sueldo, longitud);
    sueldo[longitud]='\0';
    }

void Empleados::setFecha_cont(const string &valorFecha_cont) {
    int longitud=valorFecha_cont.size();
    longitud= (longitud<11? longitud: 11-1);
    valorFecha_cont.copy(fecha_cont, longitud);
    fecha_cont[longitud]='\0';
    } //fin de los métodos de acceso

//Fusion de Numero aleatorio y residuo, para retornar la letra
string  Empleados::GeneradorDNI() {
    stringstream ss;
    int numeroAleatorio = rand() % 90000000 + 10000000; // Se genera un numero aleatorio de 8 digitos
    int numero = numeroAleatorio%23; //Se obtiene su residuo
    char letra='\0';

    switch (numero) { //Se busca la letra correspondiente al residuo
        case 0:
            letra='T';
            break;
        case 1:
            letra='R';
            break;
        case 2:
            letra='W';
            break;
        case 3:
            letra='A';
            break;
        case 4:
            letra='G';
            break;
        case 5:
            letra='M';
            break;
        case 6:
            letra='Y';
            break;
        case 7:
            letra='F';
            break;
        case 8:
            letra='P';
            break;
        case 9:
            letra='D';
            break;
        case 10:
            letra='X';
            break;
        case 11:
            letra='B';
            break;
        case 12:
            letra='N';
            break;
        case 13:
            letra='J';
            break;
        case 14:
            letra='Z';
            break;
        case 15:
            letra='S';
            break;
        case 16:
            letra='Q';
            break;
        case 17:
            letra='V';
            break;
        case 18:
            letra='H';
            break;
        case 19:
            letra='L';
            break;
        case 20:
            letra='C';
            break;
        case 21:
            letra='K';
            break;
        case 22:
            letra='E';
            break;
        default:
            letra='\0'; // Caracter nulo en caso de residuo inválido
        }
    ss << numeroAleatorio;
    return (ss.str() + letra);
    }


//función para pedirle al usuario los datos necesarios para un objeto y  retornarlo con información listo para agregarlo al archivo
Empleados Empleados::pedirDatos(void) {
    string cadena;
    Empleados registroARetornar;

    do {
        string DNI = GeneradorDNI();
        if (!contiene(DNI)) {
            registroARetornar.setDni(DNI);
            cout << "DNI generado: " << DNI << endl;  // Mostrar el DNI
            break;
            }
        else {
            cout << "El DNI ya existe. Generando uno nuevo." << endl;
            }
        }
    while (true);

    cout << "Nombre del empleado: ";
    fflush(stdin);
    getline(cin, cadena);
    for(auto& c:cadena)
        c=toupper(c);
    registroARetornar.setNombre(cadena);

    cout << "Cargo: ";
    fflush(stdin);
    getline(cin, cadena);
    for(auto& c:cadena)
        c=toupper(c);
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
bool Empleados::altas(const Empleados &nuevoEmpleado) {
    string dniCadena = nuevoEmpleado.dni;

    if (contiene(dniCadena))
        return false;
    else {
        ofstream archivo("Empleados.txt", ios::app);
        archivo << nuevoEmpleado.dni << "|" << nuevoEmpleado.nombre << "|" << nuevoEmpleado.cargo << "|"
                << nuevoEmpleado.edad << "|" << nuevoEmpleado.sueldo << "|" << nuevoEmpleado.fecha_cont << "\n";
        archivo.close();
        return true;
        }
    }

//funcion intermediaria que recibe un dni del empleado, llama al método buscarDni y evalúa el retorno de dicha función retornando false cuando el dni no se encuentra en el archivo
bool Empleados::contiene(const string &dniABuscar) {
    if(buscarDni(dniABuscar)== -1)
        return false;
    return true;
    }


//método que recibe como parámetro el valor de un identificador del empleado o el dni, para ello es necesario abrir el archivo para lectura(ios::in)
long int Empleados::buscarDni(const string &valorDni) {
    Empleados empleado;
    Empleados temp;
    long int posByte = 0;

    empleado.setDni(valorDni);
    ifstream archivo("Empleados.txt", ios::in);
    if (archivo) {
        while (!archivo.eof()) {
            archivo.getline(temp.dni, 10,'|');
            if(strcmp(temp.dni, empleado.dni)==0) {
                posByte = (long)archivo.tellg() - (strlen(temp.dni) + 1);
                archivo.close();
                return posByte;
                }
            else {
                archivo.getline(temp.nombre, 37, '|');
                archivo.getline(temp.cargo, 37, '|');
                archivo.getline(temp.edad, 3, '|');
                archivo.getline(temp.sueldo, 10, '|');
                archivo.getline(temp.fecha_cont, 11, '\n');
                }
            } //fin del ciclo while
        }// fin del if
    archivo.close();
    return -1;

    }

//función consultar la cual recibe el dni del empleado que se desea localizar
bool Empleados::consultas(const string &dniABuscar, Empleados &empleadoEncontrado) {
    long int posByte;

    ifstream archivo("Empleados.txt",ios::in);
    if (!archivo) {
        cout<< "Lo sentimos, el archivo no existe :'(" << endl;
        return -1;
        }
    else {
        posByte=buscarDni(dniABuscar);
        cout<<"posByte= "<<posByte<<endl;
        if(posByte!= -1) {
            archivo.seekg(posByte, ios::beg);
            archivo.getline(empleadoEncontrado.dni,10,'|');
            archivo.getline(empleadoEncontrado.nombre,37,'|');
            archivo.getline(empleadoEncontrado.cargo,37,'|');
            archivo.getline(empleadoEncontrado.edad,3,'|');
            archivo.getline(empleadoEncontrado.sueldo,10,'|');
            archivo.getline(empleadoEncontrado.fecha_cont,11,'\n');
            archivo.close();
            return true;

            }//fin del if
        }//fin del else
    archivo.close();
    return false;

    }

//función que retorna un flujo que permite la salida de datos
ostream &operator<<(ostream &salida, const Empleados &empleado) {
    salida<< "\nDNI: "<<empleado.dni<<endl
          << "\nNombre del empleado: "<<empleado.nombre<<endl
          << "\nCargo: "<<empleado.cargo<<endl
          << "\nEdad: "<<empleado.edad<<endl
          << "\nSueldo:$"<<empleado.sueldo<<endl
          << "\nFecha de Contratacion: "<<empleado.fecha_cont<<endl;

    return salida;
    }
