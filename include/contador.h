#ifndef CONTADOR_H
#define CONTADOR_H

#include <iostream>

using namespace std;


/*Contador de comparaciones, que se inicializa a cero antes de cada búsqueda en la tabla hash
y se incrementa con cada ejecución de una operación de comparación de claves.*/

class Contador {

    private:
        int Cuenta;
        int Min;
        int Max;
        int Acumulado;
        int Pruebas;

    public:
        Contador();
        // Todo a 0
        void reset();
        //Empezamos a contar
        void start();
        // Empezamos a obtener datos y a almacenarlos
        int stop();
        /*Al finalizar cada búsqueda en la tabla hash el valor contenido en el contador se utiliza
        para actualizar una estadística que registra los valores mínimo, máximo y media del número
        de comparaciones obtenidos.*/
        const Contador& operator++();
        friend ostream& operator<<(ostream& sout, const Contador& cont);
};


#endif // CONTADOR_H
