#ifndef EMPLEADOS_HDD_HPP_INCLUDED
#define EMPLEADOS_HDD_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <sstream>
#include <cstring>

//declaración de la clase "Empleados"
class Empleados {
    private:
        char dni[9];
        char nombre[35];
        char cargo[35];
        char edad[3];
        char sueldo[10];
        char fecha_cont[10];
        long int buscarDni(const std::string &);
    public:
        Empleados(void);
        Empleados(const Empleados &);
        void setDni(const std::string &);
        void setNombre(const std::string &);
        void setCargo(const std::string &);
        void setEdad(const std::string &);
        void setSueldo(const std::string &);
        void setFecha_cont(const std::string &);
        friend std::ostream &operator<<(std::ostream &,const Empleados &);

        bool altas(const Empleados &);
        bool consultas(const std::string &, Empleados &);
        bool bajas(const std::string &, Empleados &);
        bool contiene(const std::string &);
        Empleados pedirDatos(void);
    };

#endif // EMPLEADOS_HPP_INCLUDED
