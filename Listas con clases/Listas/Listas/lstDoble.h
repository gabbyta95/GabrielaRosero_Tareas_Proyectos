#pragma once
#include "nodo.h"
#include <iostream>
using namespace std;

class lstDoble {
public:
	lstDoble() : plista(NULL) {}
	~lstDoble();

	void Insertar(int num);
	void Borrar(int num);
	bool ListaVacia() { return plista == NULL; }
	void Mostrar(int);
	void Siguiente();
	void Anterior();
	void Primero();
	void Ultimo();
	bool Actual() { return plista != NULL; }
	int ValorActual() { return plista->valor; }

private:
	pnodo plista;
};
