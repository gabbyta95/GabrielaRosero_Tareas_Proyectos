/****************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"               *
*                    PILAS                                   	*
*  AUTORES: GABRIELA ROSERO EDWIN ASTUDILLO *
*  FECHA CREACI�N : 16 / 12 / 2017 *
*  FECHA MODIFICACI�N : 16 / 12 / 2017 *
*  CARRERA : INGENIERIA EN SISTEMAS E INFORM�TICA        		*
*  PROFESOR : ING.FERNANDO SOLIS		                		*
*****************************************************************/

# include "Nodo.h"
# include <stdio.h>

//Implementaci�n de los m�todos del Nodo
Nodo::Nodo() {
	dato = "";
	ptr_siguiente = NULL;
}

Nodo::Nodo(string dato) {
	this->dato = dato;
}

void Nodo::setDato(string dato) {

	this->dato = dato;
}

string Nodo::getDato() {

	return dato;
}

void Nodo::setPtr_siguiente(Nodo *ptr_siguiente) {
	this->ptr_siguiente = ptr_siguiente;
}

Nodo* Nodo::getPtr_Siguiente() {
	return ptr_siguiente;
}

