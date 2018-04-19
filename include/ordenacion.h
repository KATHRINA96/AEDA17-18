#ifndef ORDENACION_H
#define ORDENACION_H

#include <vector>
#include <iostream>

using namespace std;

template <class Clave, class Comparar = std::less_equal<Clave> >
class Ordenacion{
	Comparar cmp;
public:
	Ordenacion();
	Ordenacion(bool m);
	void insercion(vector<Clave> &v,int tam, bool show=false);
	void burbuja(vector<Clave> &v,int tam, bool show=false);
	void heapify(vector<Clave> &v, int tam, int i, bool show=false);
	void heapsort(vector<Clave> &v, int tam, bool show=false);
	void quicksort(vector<Clave> &v, int tam, int low=0, int high=0, bool show=false);
	int partition(vector<Clave> &v, int low, int high, bool show=false);
	void shellsort(vector<Clave> &v, int tam, float alpha, bool show=false );
	void print(vector<Clave> &v);
};

#include "ordenacion.hpp"

#endif
