#include "stdafx.h"
#include "lstSimple.h"
#include "nodo.h"


lstSimple::~lstSimple() {
	pnodo aux;

	while (primero) {
		aux = primero;
		primero = primero->siguiente;
		delete aux;
	}
	actual = NULL;
}

void lstSimple::Insertar(int a) {
	pnodo anterior;

	if (ListaVacia() || primero->valor > a) {                 
		primero = new nodo(a, primero);
	}
	else {
		anterior = primero;
		while (anterior->siguiente && anterior->siguiente->valor <= a)
			anterior = anterior->siguiente;
		anterior->siguiente = new nodo(a, anterior->siguiente);
	}
}

void lstSimple::Borrar(int a) {
	pnodo anterior, nodo;

	nodo = primero;
	anterior = NULL;
	while (nodo && nodo->valor < a) {
		anterior = nodo;
		nodo = nodo->siguiente;
	}
	if (!nodo || nodo->valor != a) return;
	else { 
		if (!anterior)  
			primero = nodo->siguiente;
		else  
			anterior->siguiente = nodo->siguiente;
		delete nodo;
	}
}

void lstSimple::Mostrar() {
	nodo *aux;

	aux = primero;
	while (aux) {
		cout << aux->valor << "-> ";
		aux = aux->siguiente;
	}
	cout << endl;
}