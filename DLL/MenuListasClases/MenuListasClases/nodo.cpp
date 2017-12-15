#include "stdafx.h"
#include "nodo.h"



nodo::nodo()
{
	dato = 0;
	this->siguiente = NULL;
	this->anterior = NULL;
}


void nodo::setDato(int dato) {
	this->dato = dato;
}
int nodo::getDato() {
	return dato;
}

void nodo::setSiguiente(nodo *siguiente) {
	this->siguiente = siguiente;
}
nodo* nodo::getSiguiente() {
	return siguiente;
}

void nodo::setAnterior(nodo *anterior) {
	this->anterior = anterior;
}

nodo* nodo::getAnterior() {
	return anterior;
}