#pragma once
#include "nodo.h"
#include <iostream>
using namespace std;


class lstCircular {
public:
	lstCircular() { actual = NULL; }
	~lstCircular();

	void Insertar(int num);
	void Borrar(int num);
	bool ListaVacia() { return actual == NULL; }
	void Mostrar();
	void Siguiente();
	bool Actual() { return actual != NULL; }
	int ValorActual() { return actual->valor; }

private:
	pnodo actual;
};