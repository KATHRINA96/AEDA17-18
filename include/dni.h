#ifndef DNI_H
#define DNI_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <cctype>
#include "contador.h"

#pragma once
using namespace std;

class Dni {
private:
        int num;
        string letra;
        string nombre;// string nombre.
        string apellidos;// string apellidos.

public:

        class lessDniNum{
        public:
                bool operator()(const Dni &a, const Dni &b);
        };

        class greaterDniNum{
        public:
                bool operator()(const Dni &a, const Dni &b);
        };

        class lessDniLetra{
        public:
                bool operator()(const Dni &a, const Dni &b);
        };

        class greaterDniLetra{
        public:
                bool operator()(const Dni &a, const Dni &b);
        };

        class lessDniNombre{
        public:
                bool operator()(const Dni &a, const Dni &b);
        };

        class greaterDniNombre{
        public:
                bool operator()(const Dni &a, const Dni &b);
        };

        Dni();
        Dni(int dni, string l, string n, string a);
        Dni(int dni);
        static Contador Comparaciones;

        //Sobrecarga de operadores
        bool operator==(int dni);
        bool operator==(const Dni& dni);
        bool operator!=(string nombre);
        bool operator!=(int dni);
        Dni& operator=(int dni);
        Dni& operator=(const Dni& dni);
        operator int() const;
        void setDni(int dni);
        friend ostream& operator<<(ostream& os, const Dni& dni);
        friend istream& operator>>(istream& is, Dni& dni);
        ostream& toStream(ostream& os) const;

        // Sobrecarga de comparacion:
        bool operator<=(const Dni& dni);
        bool operator>=(const Dni& dni);
        bool operator<(const Dni& dni);
        bool operator>(const Dni& dni);

};

#endif // DNI_H
