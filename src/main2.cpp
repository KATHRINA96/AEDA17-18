#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>

#include "ordenacion.h"
#include "colores.hpp"
#include "dni.h"

using namespace std;


int main(){

   cout << endl;
   cout<<FYEL("************************************************************************") << endl;
   cout<<FYEL("************************************************************************") << endl;
   cout<<FYEL("**                                                                    **") << endl;
   cout<<FYEL("**                            ORDENACION                              **") << endl;
   cout<<FYEL("**                                                                    **") << endl;
   cout<<FYEL("************************************************************************") << endl;
   cout<<FYEL("************************************************************************") << endl;

   cout << endl;
   cout << endl;

   int npruebas=0;
    int tam=0;
    float alpha;
    Ordenacion<Dni,Dni::lessDniNum> ord_dni;
    Ordenacion<int,less_equal<int>> ord_entero;
    vector<Dni> v_dni;
    vector<Dni> v_copia_dni;

    cout << "Ingrese el tamaño del vector de prueba:" <<endl;
    cin >> tam;
    v_dni.resize(tam);
    for (auto i = 0; i < tam; i++){
      v_dni[i] = *new Dni;
    }

    cout <<endl << "Ingrese el numero de pruebas a realizar:" <<endl;
    cin >> npruebas;

    cout << endl << "Ingrese la constante alpha para el algoritmo shellsort:" <<endl;
    cin >> alpha;

    //cout << "numero de pruebas:" << npruebas << endl;

    Dni::Comparaciones.reset();

    cout << endl;
    cout << FCYN("*******************************************************************") <<endl;
    cout <<FCYN("MODO ESTADISTICO") << endl << endl;
    cout << "\t\t\t" << "Minimo" << "\t\t" << " Maximo" << "\t\t" << " Media" << endl;
    for(auto i=0; i < npruebas; i++){
      for (auto i = 0; i < tam; i++){
        v_dni[i] = *new Dni;
      }
      v_copia_dni = v_dni;
      Dni::Comparaciones.start();
      ord_dni.insercion(v_copia_dni,tam, false);
      Dni::Comparaciones.stop();
    }

    cout << "Insercion " << Dni::Comparaciones << endl;

    for(auto i=0; i < npruebas; i++){
      for (auto i = 0; i < tam; i++){
        v_dni[i] = *new Dni;
      }
      v_copia_dni = v_dni;
      Dni::Comparaciones.start();
      ord_dni.burbuja(v_copia_dni,tam, false);
      Dni::Comparaciones.stop();
    }

    cout << "Burbuja " << Dni::Comparaciones << endl;

    for(auto i=0; i < npruebas; i++){
      for (auto i = 0; i < tam; i++){
        v_dni[i] = *new Dni;
      }
      v_copia_dni = v_dni;
      Dni::Comparaciones.start();
      ord_dni.heapsort(v_copia_dni,tam, false);
      Dni::Comparaciones.stop();
    }

    cout << "Heapsort " << Dni::Comparaciones << endl;

    for(auto i=0; i < npruebas; i++){
      for (auto i = 0; i < tam; i++){
        v_dni[i] = *new Dni;
      }
      v_copia_dni = v_dni;
      Dni::Comparaciones.start();
      ord_dni.quicksort(v_copia_dni,tam,0,tam-1, false);
      Dni::Comparaciones.stop();
    }

    cout << "Quicksort " << Dni::Comparaciones << endl;


    for(auto i=0; i < npruebas; i++){
      for (auto i = 0; i < tam; i++){
        v_dni[i] = *new Dni;
      }
      v_copia_dni = v_dni;
      Dni::Comparaciones.start();
      ord_dni.shellsort(v_copia_dni,tam,alpha, false);
      Dni::Comparaciones.stop();
    }

    cout << "Shellsort " << Dni::Comparaciones << endl;

    char d;
    cout <<endl<< "Introduce la letra d si desea visualizar el modo demostración o introduzca cualquier otra para finalizar el programa:" <<endl;
    cin >> d;
    if (d == 'd'){

      cout << endl;
      cout <<FCYN("*******************************************************************") <<endl;
      cout <<FCYN("MODO DEMOSTRACION") << endl << endl;

      cout << "Ingrese el tamaño del vector de prueba:" <<endl;
      cin >> tam;
      v_dni.clear();
      v_dni.resize(tam);

      int dni;
      string l;
      string n;
      string a;

      cout << "Ingrese DNI, letra, nombre y apellidos:" <<endl;
      for (auto i=0; i < tam; i++){
        cin >> dni;
        cin >> l;
        cin >> n;
        cin >> a;

        v_dni[i] = *new Dni(dni,l,n,a);

      }

      v_copia_dni = v_dni;

      cout << endl << endl << "-------------------------------------------------------------------"<<endl;
      cout << " --- Ordenacion por insercion --- " << endl;
      ord_dni.insercion(v_copia_dni,tam, true);
      cout <<endl<< "SOLUCION: ";
      for(auto i=0; i < v_copia_dni.size(); i++){
          cout << v_copia_dni[i] << ' ';
      }


      v_copia_dni = v_dni;

        cout << endl << endl << "-------------------------------------------------------------------"<<endl;
      cout << " --- Ordenacion por burbuja --- " << endl;
      ord_dni.burbuja(v_copia_dni,tam, true);
      cout <<endl<< "SOLUCION: ";
      for(auto i=0; i < v_copia_dni.size(); i++){
          cout << v_copia_dni[i] << ' ';
      }

      v_copia_dni = v_dni;

      cout << endl << endl << "-------------------------------------------------------------------"<<endl;
      cout << " --- Ordenacion por heapsort --- " << endl;
      ord_dni.heapsort(v_copia_dni,tam, true);
      cout <<endl<< "SOLUCION: ";
      for(auto i=0; i < v_copia_dni.size(); i++){
          cout << v_copia_dni[i] << ' ';
      }

      v_copia_dni = v_dni;

      cout << endl << endl << "-------------------------------------------------------------------"<<endl;
      cout << " --- Ordenacion por quicksort --- " << endl;
      ord_dni.quicksort(v_copia_dni,tam,0,tam-1, true);
      cout <<endl<< "SOLUCION: ";
      for(auto i=0; i < v_copia_dni.size(); i++){
          cout << v_copia_dni[i] << ' ';
      }

      v_copia_dni = v_dni;

      cout << endl << endl << "-------------------------------------------------------------------"<<endl;
      cout << " --- Ordenacion por shellsort --- " << endl;
      ord_dni.shellsort(v_copia_dni,tam,alpha, true);
      cout <<endl<< "SOLUCION: ";
      for(auto i=0; i < v_copia_dni.size(); i++){
          cout << v_copia_dni[i] << ' ';
      }

      cout << endl <<endl;
      cout << FCYN("*******************************************************************") <<endl;
      cout << endl;
    }else{
      cout << FCYN("*******************************************************************") <<endl;
      cout <<endl << FCYN("PROGRAMA FINALIZADO")<<endl;
      return 0;
    }

}
