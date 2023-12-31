#ifndef EMPLEADOS_HDD_HPP_INCLUDED
#define EMPLEADOS_HDD_HPP_INCLUDED

#include <iostream> // Libreria de C++
#include <fstream>  // Los archivos
#include <sstream>  // Cosa para string en archivos
#include <string>   // Pues el String
#include <ctime>    // El tiempo para el rand
#include <cstring>  // porque usamos char
#include <stack> // Para la lista de disponibles

//declaración de la clase "Empleados"
class Empleados {
    private:
        char dni[10];
        char nombre[37];
        char cargo[37];
        char edad[3];
        char sueldo[11];
        char fecha_cont[11];
        int tamano = 110;
        long int buscarDni(const std::string&);

    public:
        Empleados(void);
        Empleados(const Empleados&);

        Empleados pedirDatos(void);

        void setDni(const std::string&);
        void setNombre(const std::string&);
        void setCargo(const std::string&);
        void setEdad(const std::string&);
        void setSueldo(const std::string&);
        void setFecha_cont(const std::string&);

        void verLista();
        void escribirLista(const std::stack<int>&);

        std::stack<int>leerLista();

        std::string GeneradorDNI();

        bool altas(const Empleados&);
        bool consultas(const std::string&,Empleados&);
        bool bajas(const std::string&,Empleados&);
        bool contiene(const std::string&);

        friend std::ostream &operator<<(std::ostream&,const Empleados&);
    };

#endif // EMPLEADOS_HPP_INCLUDED
