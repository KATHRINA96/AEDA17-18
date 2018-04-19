

template <class Clave,class Comparar>
Ordenacion<Clave, Comparar>::Ordenacion(){
}


template <class Clave,class Comparar>
Ordenacion<Clave,Comparar>::Ordenacion(bool m){
}

/**
* Ejemplo
* 1 12 9 5 6 10
* 1 / 12 9 5 6 10
* 1 12/ 9 5 6 10
* 1 9 12/ 5 6 10
* 1 5 9 12 / 6 10
* 1 5 6 9 12 / 10
* 1 5 6 9 10 12
*/

////////////////////////////////////////////////////////////////////////////////
template<class Clave,class Comparar>
void Ordenacion<Clave,Comparar>::insercion(vector<Clave> &v, int tam, bool show){
//eficiencia n^2
	Clave aux;
	int j;

	for (int i=1; i < v.size(); i++){
		aux = v[i];
		j = i-1;

		while(j >= 0 and cmp(aux,v[j]) ){
			if(show){
				cout << endl<< "Comparando: " << aux << " y " << v[j] << endl;
			}
			v[j+1]= v[j];
			j--;
		}

		v[j+1] = aux;

	}
}


////////////////////////////////////////////////////////////////////////////////
template<class Clave,class Comparar>
void Ordenacion<Clave,Comparar>::burbuja(vector<Clave> &v, int tam, bool show){
//eficiencia n^2
	Clave temp;
	for(int i=1; i < v.size(); i++){
		for(int j= v.size()-1; j>=i; j--){
			if (cmp(v[j], v[j-1]) ){
				if(show){
					cout << endl<< "Comparando: " << v[j] << " y " << v[j-1] << endl;
				}
				temp = v[j-1];
				v[j-1] = v[j];
				v[j] = temp;
			}
		}
	}
}


////////////////////////////////////////////////////////////////////////////////
template<class Clave,class Comparar>
void Ordenacion<Clave,Comparar>::heapify(vector<Clave> &v, int tam, int i, bool show){
//eficiencia log(n)
	int l = 2*i+1;
	int r = 2*i+2;
	int max = i;
 	Clave aux;

	if( l < tam and cmp(v[max],v[l]) ){
		if(show){
			cout << endl<< "El hijo es mayor que el padre: Hijo: " << v[l] << " Maximo: " << v[max] <<endl;
		}
		max = l;
	}

	if( r < tam  and cmp(v[max],v[r]) ){
		if(show){
			cout << endl<< "El hijo es mayor que el padre: Hijo: " << v[r] << " Maximo: " << v[max] <<endl;
		}
		max = r;
	}

	if( max != i ){
		aux = v[i];
		v[i] = v[max];
		v[max] = aux;

		heapify(v,tam,max,show);
	}
}

////////////////////////////////////////////////////////////////////////////////
template<class Clave,class Comparar>
void Ordenacion<Clave,Comparar>::heapsort(vector<Clave> &v, int tam, bool show){
//eficiencia n*log(n)
	for(auto i= (tam/2)-1; i >= 0; i--){
		heapify(v,tam,i,show);
	}

	Clave aux;
	for(auto i=tam-1; i>=0; i--){
		aux = v[i];
		v[i] = v[0];
		v[0] = aux;

		heapify(v,i,0,show);
	}
}

////////////////////////////////////////////////////////////////////////////////
template<class Clave,class Comparar>
int Ordenacion<Clave,Comparar>::partition(vector<Clave> &v, int low, int high, bool show){

	Clave pivote = v[high];
	int i = low-1;
	Clave aux;

	for(auto j=low; j <= high-1; j++){
		if( cmp(v[j],pivote) ){
			if(show){
				cout << endl<< "Comparando: " << v[j] << " y " << pivote << endl;
			}
			i++;
			aux = v[j];
			v[j] = v[i];
			v[i] = aux;
		}
	}

	aux = pivote;
	v[high] = v[i+1];
	v[i+1] = aux;

	return i+1;
}

////////////////////////////////////////////////////////////////////////////////
template<class Clave,class Comparar>
void Ordenacion<Clave,Comparar>::quicksort(vector<Clave> &v, int tam, int low, int high, bool show){
//eficiencia n*log(n)


	if(low < high){
		int p = partition(v,low,high,show);
		quicksort(v,tam,low,p-1);
		quicksort(v,tam,p,high);
	}

}


////////////////////////////////////////////////////////////////////////////////
template<class Clave, class Comparar>
void Ordenacion<Clave,Comparar>::print(vector<Clave> &v){

	for (int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout <<endl;
}

////////////////////////////////////////////////////////////////////////////////
template<class Clave,class Comparar>
void Ordenacion<Clave, Comparar>::shellsort(vector<Clave> &v,int tam, float alpha, bool show){

	int gap = tam*alpha;
	Clave temp;
	bool uno = false;

	for(gap; gap >= 0 and !uno; gap *= alpha){

		// Para cuando tenemos un alpha < 0.5
		if(gap < 1){
			gap = 1;
			uno = true;
		}

		for(auto i=0; i < tam; i++){
			if( (i+gap) < tam and cmp(v[i+gap],v[i]) ){
				if(show){
					cout << endl<< "Comparando: " << v[i+gap] << " y " << v[i] << endl;
				}
				temp = v[i];
				v[i] = v[i+gap];
				v[i+gap] = temp;

				for(auto j=i; j >= 0; j -= gap){
					if( (j-gap) >= 0 and cmp(v[j],v[j-gap]) ){
						if(show){
							cout << endl<< "Comparando: " << v[j] << " y " << v[j-gap] << endl;
						}
						temp = v[j-gap];
						v[j-gap] = v[j];
						v[j] = temp;
					}
				}

			}
		}
	}
}
