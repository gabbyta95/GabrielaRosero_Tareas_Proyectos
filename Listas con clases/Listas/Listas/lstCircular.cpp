#include "stdafx.h"
#include "lstCircular.h"
#include "nodo.h"


lstCircular::~lstCircular() {
	pnodo nodo;

	while (actual->siguiente != actual) {
		nodo = actual->siguiente;
		actual->siguiente = nodo->siguiente;
		delete nodo;
	}
	delete actual;
	actual = NULL;
}

void lstCircular::Insertar(int num) {
	pnodo Nodo;

	Nodo = new nodo(num);

	if (actual == NULL) actual = Nodo;
	else Nodo->siguiente = actual->siguiente;
	actual->siguiente = Nodo;
}

void lstCircular::Borrar(int num) {
	pnodo nodo;

	nodo = actual;

	do {
		if (actual->siguiente->valor != num) actual = actual->siguiente;
	} while (actual->siguiente->valor != num && actual != nodo);
	// Si existe un nodo con el valor num:
	if (actual->siguiente->valor == num) {
		if (actual == actual->siguiente) {
			delete actual;
			actual = NULL;
		}
		else {
			nodo = actual->siguiente;
			actual->siguiente = nodo->siguiente;
			delete nodo;
		}
	}
}

void lstCircular::Mostrar() {
	pnodo nodo = actual;

	do {
		cout << nodo->valor << "-> ";
		nodo = nodo->siguiente;
	} while (nodo != actual);

	cout << endl;
}

void lstCircular::Siguiente() {
	if (actual) actual = actual->siguiente;
}
