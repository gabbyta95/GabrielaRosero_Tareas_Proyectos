# ifndef  PILAS_H
# define PILAS_H
# include "Nodo.h"

//Prototipos Pila
# include <string>

# include <iostream>
using namespace std;


class Pila {
private:
	Nodo * cabeza;
public:
	Pila();
	void apilar(string  dato);
	bool estaVacia();
	string desapilar();
	string  elementoTope();
};



# endif
