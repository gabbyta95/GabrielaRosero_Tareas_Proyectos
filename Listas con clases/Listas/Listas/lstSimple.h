#pragma once
#include "nodo.h"
#include <iostream>
using namespace std;



class lstSimple {
public:
	lstSimple() { primero = actual = NULL; }
	~lstSimple();

	void Insertar(int a);
	void Borrar(int a);
	bool ListaVacia() { return primero == NULL; }
	void Mostrar();
	void Siguiente() { if (actual) actual = actual->siguiente; }
	void Primero() { actual = primero; }
	void Ultimo() { Primero(); if (!ListaVacia()) while (actual->siguiente) Siguiente(); }
	bool Actual() { return actual != NULL; }
	int ValorActual() { return actual->valor; }

private:
	pnodo primero;
	pnodo actual;
};




