#include "Empleados.hpp"

using namespace std;

Empleados::Empleados() { // Se inicializan los campos en nulo
    dni[0] = '\0';
    nombre[0] = '\0';
    cargo[0] = '\0';
    edad[0] = '\0';
    sueldo[0] = '\0';
    fecha_cont[0] = '\0';
    }

//constructor o funci�n que inicializar� un objeto al mismo tiempo que se declara
Empleados::Empleados(const Empleados &origen) {
    strcpy(dni, origen.dni);
    strcpy(nombre, origen.nombre);
    strcpy(cargo, origen.cargo);
    strcpy(edad, origen.edad);
    strcpy(sueldo, origen.sueldo);
    strcpy(fecha_cont, origen.fecha_cont);
    }

//funci�n para pedirle al usuario los datos necesarios para un objeto y  retornarlo con informaci�n listo para agregarlo al archivo
Empleados Empleados::pedirDatos(void) {
    int aux,i;
    string cadena;
    Empleados registroARetornar;

    do {
        string DNI = GeneradorDNI();
        if (!contiene(DNI)) {
            registroARetornar.setDni(DNI);
            cout << "\n DNI generado: " << DNI << endl;  // Mostrar el DNI
            break;
            }
        else {
            cout << "\n El DNI ya existe. Generando uno nuevo." << endl;
            }
        }
    while (true);

    cout << "\n Nombre del empleado: ";
    fflush(stdin);
    getline(cin, cadena); //Lee la cadena
    aux = cadena.size(); // Obtiene el tama�o
    for(auto& c:cadena) // Convierte todos los caracteres a mayusculas
        c=toupper(c);
    for(i=0; i<36-aux; i++) // rellena con espacios
        cadena+=" ";
    registroARetornar.setNombre(cadena); // Se setea y se repite el proceso con los demas campos

    cout << "\n Cargo: ";
    fflush(stdin);
    getline(cin, cadena);
    aux = cadena.size();
    for(auto& c:cadena)
        c=toupper(c);
    for(i=0; i<36-aux; i++)
        cadena+=" ";
    registroARetornar.setCargo(cadena);

    cout << "\n Edad: ";
    fflush(stdin);
    getline(cin, cadena);
    registroARetornar.setEdad(cadena);

    cout << "\n Sueldo: $";
    fflush(stdin);
    getline(cin, cadena);
    aux = cadena.size();
    for(i=0; i<10-aux; i++)
        cadena+=" ";
    registroARetornar.setSueldo(cadena);

    cout << "\n Fecha de Contratacion: ";
    fflush(stdin);
    getline(cin, cadena);
    registroARetornar.setFecha_cont(cadena);

    return registroARetornar;
    }

//inicio de los m�todos de acceso para recuperar un valor asignado y poderlo mostrar en pantalla
void Empleados::setDni(const string &valorDni) {
    int longitud=valorDni.size();
    valorDni.copy(dni, longitud);
    dni[longitud]='\0';
    }

void Empleados::setNombre(const string &valorNombre) {
    int longitud=valorNombre.size();
    valorNombre.copy(nombre, longitud);
    nombre[longitud]='\0';
    }

void Empleados::setCargo(const string &valorCargo) {
    int longitud=valorCargo.size();
    valorCargo.copy(cargo, longitud);
    cargo[longitud]='\0';
    }

void Empleados::setEdad(const string &valorEdad) {
    int longitud=valorEdad.size();
    valorEdad.copy(edad, longitud);
    edad[longitud]='\0';
    }

void Empleados::setSueldo(const string &valorSueldo) {
    int longitud=valorSueldo.size();
    valorSueldo.copy(sueldo, longitud);
    sueldo[longitud]='\0';
    }

void Empleados::setFecha_cont(const string &valorFecha_cont) {
    int longitud=valorFecha_cont.size();
    valorFecha_cont.copy(fecha_cont, longitud);
    fecha_cont[longitud]='\0';
    }
//fin de los m�todos de acceso

//Funcion que muestra la lista en la consola
void Empleados::verLista() {
    ifstream lista("LIST_DISP.txt", ios::in);
    string linea;

    if (lista)
        getline(lista, linea);

    lista.close();
    if(linea!="")
        cout <<"\n Lista de disponibles: " <<linea<<endl;
    else
        cout<<"\n No hay ningun elemento" <<endl;
    }

//Funcion que escribe en el txt, recibe un vector de enteros
void Empleados::escribirLista(const stack<int>& registrosEliminados) {
    ofstream lista("LIST_DISP.txt");
    stringstream ss;
    stack<int> copia = registrosEliminados; //Para no usar el original
    bool primero = true; // Siempre el primer numero sera true
    int x;

    if (lista) {
        while (!copia.empty()) { //Mientras no este vacia
            x = copia.top();
            copia.pop();

            if (!primero) // Si no es el primero, entonce a�ade la flechita
                ss << " -> ";
            ss << x;
            primero = false;
            }
        ss << " -> -1\n"; // Al final se le agrega el -1
        lista << ss.str();
        }
    lista.close();
    }

//Funcion que lee la lista actual del txt y retorna un vector de enteros
stack<int> Empleados::leerLista() {
    stack<int> registrosEliminados;
    ifstream lista("LIST_DISP.txt",ios::in);

    if(lista) {
        string linea;
        getline(lista, linea);
        lista.close();

        string numero;
        istringstream stream(linea); // Toma lo que tiene linea como si fuera un txt
        while (getline(stream, numero, ' ')) { //itera hasta encontrar el espacio, 3"" termina y luego ->"" y asi sucecivamente
            if(numero != "->") {
                if (numero == "-1") {
                    break;
                    }
                registrosEliminados.push(stoi(numero));
                }
            }
        }
    return registrosEliminados; //Retorna los resultados
    }

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
            letra='\0'; // Caracter nulo en caso de residuo inv�lido
        }
    ss << numeroAleatorio;
    return (ss.str() + letra);
    }

//m�todo que recibe como par�metro el valor de un identificador del empleado o el dni, para ello es necesario abrir el archivo para lectura(ios::in)
long int Empleados::buscarDni(const string &valorDni) {
    Empleados empleado;
    Empleados temp;
    int contador=-1;
    long int posByte = 0;

    if(valorDni[0]=='*'){
        cout<<"\n Registro Borrado Logico"<<endl;
        return -1;
    }

    empleado.setDni(valorDni);
    ifstream archivo("Empleados.txt", ios::in);
    if (archivo) {
        while (archivo.getline(temp.dni, 10,'|')) {
            contador++;
            if(strcmp(temp.dni, empleado.dni)==0) {
                posByte = tamano*contador;
                archivo.close();
                return posByte;
                }
            else {
                archivo.getline(temp.nombre, 37, '|');
                archivo.getline(temp.cargo, 37, '|');
                archivo.getline(temp.edad, 3, '|');
                archivo.getline(temp.sueldo, 11, '|');
                archivo.getline(temp.fecha_cont, 11, '\n');
                }
            } //fin del ciclo while
        }// fin del if
    archivo.close();
    return -1;
    }

//funci�n para agregar objetos nuevos al archivo
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

//funci�n consultar la cual recibe el dni del empleado que se desea localizar
bool Empleados::consultas(const string &dniABuscar, Empleados &empleadoEncontrado) {
    long int posByte;

    ifstream archivo("Empleados.txt",ios::in);
    if (!archivo) {
        cout<< "Lo sentimos, el archivo no existe :'(" << endl;
        return -1;
        }
    else {
        posByte=buscarDni(dniABuscar);
        if(posByte!= -1) {
            archivo.seekg(posByte, ios::beg);
            archivo.getline(empleadoEncontrado.dni,10,'|');
            archivo.getline(empleadoEncontrado.nombre,37,'|');
            archivo.getline(empleadoEncontrado.cargo,37,'|');
            archivo.getline(empleadoEncontrado.edad,3,'|');
            archivo.getline(empleadoEncontrado.sueldo,11,'|');
            archivo.getline(empleadoEncontrado.fecha_cont,11,'\n');
            archivo.close();
            return true;
            }//fin del if
        }//fin del else
    archivo.close();
    return false;
    }

//Funcion que pone un * para realizar el eliminado logico
bool Empleados::bajas(const string &dniABuscar,Empleados &empleadoEliminado) {
    long int posByte;
    stack<int>registroEliminado = leerLista(); //Inicializa el vector con los eliminados
    fstream archivo("Empleados.txt",ios::in | ios::out);

    if (!archivo) {
        cout<< "Lo sentimos, el archivo no existe :'(" << endl;
        return -1;
        }
    else {
        posByte=buscarDni(dniABuscar);
        if(posByte!= -1) {
            if(posByte!=0)
                registroEliminado.push(posByte/110); //Divide los bytes entre su tama�o para tener el NRR
            else
                registroEliminado.push(posByte);

            escribirLista(registroEliminado); //Agrega el NRR a la lista de disponibles

            archivo.seekp(posByte, ios::beg);
            archivo.put('*'); //Pone el "*" en la posicion 0 del DNI
            archivo.getline(empleadoEliminado.nombre,37,'|');
            archivo.getline(empleadoEliminado.cargo,37,'|');
            archivo.getline(empleadoEliminado.edad,3,'|');
            archivo.getline(empleadoEliminado.sueldo,11,'|');
            archivo.getline(empleadoEliminado.fecha_cont,11,'\n');
            archivo.close();
            return true;
            }//fin del if
        }//fin del else
    archivo.close();
    return false;
    }

//funcion intermediaria que recibe un dni del empleado, llama al m�todo buscarDni y eval�a el retorno de dicha funci�n retornando false cuando el dni no se encuentra en el archivo
bool Empleados::contiene(const string &dniABuscar) {
    if(buscarDni(dniABuscar)== -1)
        return false;
    return true;
    }

//funci�n que retorna un flujo que permite la salida de datos
ostream &operator<<(ostream &salida, const Empleados &empleado) {
    salida<< "\n DNI: "<<empleado.dni<<endl
          << "\n Nombre del empleado: "<<empleado.nombre<<endl
          << "\n Cargo: "<<empleado.cargo<<endl
          << "\n Edad: "<<empleado.edad<<endl
          << "\n Sueldo:$"<<empleado.sueldo<<endl
          << "\n Fecha de Contratacion: "<<empleado.fecha_cont<<endl;

    return salida;
    }
