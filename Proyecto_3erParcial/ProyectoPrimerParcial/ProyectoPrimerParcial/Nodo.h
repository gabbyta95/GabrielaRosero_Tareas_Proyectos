#pragma once

#include <string>
# include "Librerias.h"
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
	void visitar();
	void ramaIzdo(Nodo *);
	void ramaDcho(Nodo *);
	~Nodo()
	{
	}
};


valor Nodo::valorNodo() {
	return dato;
}

Nodo *Nodo::subArbolIzdo() {
	return izdo;
}

Nodo *Nodo::subArbolDcho() {
	return dcho;
}

void Nodo::nuevoValor(valor d) {
	dato = d;
}

void Nodo::ramaIzdo(Nodo * n) {
	izdo = n;
}

void Nodo::ramaDcho(Nodo * n) {
	dcho = n;
}

void Nodo::visitar()
{	
	cout << dato << "  ";
	//printf("%d  ",dato);
}
