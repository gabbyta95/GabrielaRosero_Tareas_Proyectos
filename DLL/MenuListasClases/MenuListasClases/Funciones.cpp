#include "stdafx.h"
#include "nodo.h"
#include "Funciones.h"
#include <iostream>
#include <cstdlib>
using namespace std;

nodo* insertarSimple(nodo *colita, int num) {
		nodo *nuevo = new nodo();
	cout << "Ingrese el dato = ";
	cin >> num;
	nuevo->setDato(num);
	if (colita == NULL)
	{		
		nuevo->setSiguiente(NULL);
		colita = nuevo;
	}else{
		nuevo->setSiguiente(colita);
		colita = nuevo;
	}
	
	return colita;
}


void imprimirSimple(nodo *colita) {
	
		nodo *aux = colita;
	cout << "Los valores son:";
	do
	{
		cout << aux->getDato() << "->";
		aux = aux->getSiguiente();
	} while (aux != NULL);
	cout << "NULL" << endl;
}



nodo* insertarDoble(nodo *colita, int num) {
	nodo *nuevo = new nodo();
	nodo *aux = colita;
	if (aux == NULL) {

		nuevo->setDato(num);
		nuevo->setSiguiente(NULL);
		nuevo->setAnterior(NULL);
		aux = nuevo;
		colita = aux;
	}
	else {

		while (aux->getSiguiente() != NULL) {
			aux = aux->getSiguiente();
		}
		nuevo->setDato(num);
		aux->setSiguiente(nuevo);
		nuevo->setAnterior(aux);

	}
	return colita;
}


void imprimirDoble(nodo *colita) {
	nodo *aux = colita;
	cout << "Los valores son:";
	if (aux != NULL) {
		while (aux != NULL) {
			cout << aux->getDato() << endl;
			aux = aux->getSiguiente();
		}
	}
}

nodo* insertarCircular(nodo *colita, int num) {
	nodo *nuevo = new nodo();
	nuevo->setDato(num); //asigna el nuevo valor
	if (colita == NULL) {
		nuevo->setAnterior(nuevo);
		nuevo->setSiguiente(nuevo);
	}
	else {
		nuevo->setAnterior(colita->getAnterior());
		nuevo->setSiguiente (colita);
		colita->getAnterior()->setSiguiente(nuevo);
		colita->setAnterior(nuevo);
	}
	colita = nuevo;
	return colita;
}

void imprimirCircular(nodo *colita) {
	nodo *aux = colita;
	do {
		cout << aux->getDato() << endl;
		aux = aux->getSiguiente();
	} while (aux != colita);
}


