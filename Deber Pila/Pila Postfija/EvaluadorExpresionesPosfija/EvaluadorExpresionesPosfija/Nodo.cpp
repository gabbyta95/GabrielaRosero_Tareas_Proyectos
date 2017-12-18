/****************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"               *
*                    PILAS                                   	*
*  AUTORES: GABRIELA ROSERO EDWIN ASTUDILLO *
*  FECHA CREACIÓN : 16 / 12 / 2017 *
*  FECHA MODIFICACIÓN : 16 / 12 / 2017 *
*  CARRERA : INGENIERIA EN SISTEMAS E INFORMÁTICA        		*
*  PROFESOR : ING.FERNANDO SOLIS		                		*
*****************************************************************/

# include "Nodo.h"
# include <stdio.h>

//Implementación de los métodos del Nodo
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

