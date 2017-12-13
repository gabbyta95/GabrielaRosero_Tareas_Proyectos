#include "stdafx.h"
#include "lstDoble.h"
#include "nodo.h"
#include <iostream>
using namespace std;




lstDoble::~lstDoble() {
	pnodo aux;

	Primero();
	while (plista) {
		aux = plista;
		plista = plista->siguiente;
		delete aux;
	}
}

void lstDoble::Insertar(int num) {
	pnodo nuevo;

	Primero();
	// Si la lista está vacía
	if (ListaVacia() || plista->valor > num) {                
		nuevo = new nodo(num, plista);
		if (!plista) plista = nuevo;
		else plista->anterior = nuevo;
	}
	else {
		while (plista->siguiente && plista->siguiente->valor <= num) Siguiente();
		nuevo = new nodo(num, plista->siguiente, plista);
		plista->siguiente = nuevo;
		if (nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
	}
}

void lstDoble::Borrar(int num) {
	pnodo nodo;

	nodo = plista;
	while (nodo && nodo->valor < num) nodo = nodo->siguiente;
	while (nodo && nodo->valor > num) nodo = nodo->anterior;

	if (!nodo || nodo->valor != num) return;
	// Borrar el nodo 

	if (nodo->anterior) // no es el primer elemento 
		nodo->anterior->siguiente = nodo->siguiente;
	if (nodo->siguiente) // no el el último nodo
		nodo->siguiente->anterior = nodo->anterior;
	delete nodo;
}

void lstDoble::Mostrar(int orden) {
	pnodo nodo;
	if (orden == ASCENDENTE) {
		Primero();
		nodo = plista;
		while (nodo) {
			cout << nodo->valor << "-> ";
			nodo = nodo->siguiente;
		}
	}
	else {
		Ultimo();
		nodo = plista;
		while (nodo) {
			cout << nodo->valor << "-> ";
			nodo = nodo->anterior;
		}
	}
	cout << endl;
}

void lstDoble::Siguiente() {
	if (plista) plista = plista->siguiente;
}

void lstDoble::Anterior() {
	if (plista) plista = plista->anterior;
}

void lstDoble::Primero() {
	while (plista && plista->anterior) plista = plista->anterior;
}

void lstDoble::Ultimo() {
	while (plista && plista->siguiente) plista = plista->siguiente;
}
