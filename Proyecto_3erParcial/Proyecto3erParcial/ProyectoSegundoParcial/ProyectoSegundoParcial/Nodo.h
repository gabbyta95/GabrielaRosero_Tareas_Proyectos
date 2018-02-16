/*
# ifndef NODO_H
# define NODO_H

#include <string>
using namespace std;
typedef int valor;
class Nodo
{
private:
	valor dato;
	Nodo * izdo;
	Nodo * dcho;
public:
	Nodo() {
		dato = 0;
		izdo = dcho = NULL;
	}
	Nodo(valor dat)
	{

		dato = dat;
		izdo = dcho = NULL;
	}
	Nodo(Nodo* ramaIzdo, valor valor, Nodo*ramaDcho)
	{
		izdo = ramaIzdo;
		dato = valor;
		dcho = ramaDcho;
	}
	valor valorNodo();
	Nodo * subArbolIzdo();
	Nodo * subArbolDcho();
	void nuevoValor(valor);
	void ramaIzdo(Nodo *);
	void ramaDcho(Nodo *);
	~Nodo()
	{
	}
};

# endif
*/

