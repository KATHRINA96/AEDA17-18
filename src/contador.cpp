#include "contador.h"

Contador::Contador():
Cuenta(0),
Min(0),
Max(0),
Acumulado(0),
Pruebas(0)
{}

void Contador::reset(){
        Cuenta=0;
        Min=0;
        Max=0;
        Acumulado=0;
        Pruebas=0;
}

void Contador::start(){
        Cuenta=0;
}

int Contador::stop(){
        Pruebas++;
        if(Pruebas==1)
                Min=999999999;
        if(Cuenta>Max)
                Max=Cuenta;
        if(Cuenta<Min)
                Min=Cuenta;
        Acumulado+=Cuenta;
        return Pruebas;
}

const Contador& Contador::operator++(){
        Cuenta++;
}

ostream& operator<<(ostream& cout_aux, const Contador& contador_aux){
        cout << "\t\t";
        cout_aux << contador_aux.Min;
        cout << "\t\t";


        cout_aux << contador_aux.Max;
        cout << "\t\t";

        cout_aux << (contador_aux.Max+contador_aux.Min)/2;
        cout << endl;

}
