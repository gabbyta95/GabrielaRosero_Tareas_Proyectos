# include "Lista.h"
# include <string>
#include <iostream>
using namespace std;
Listita::Listita() {

	cabeza = NULL;
	fin = NULL;
}

string Listita::retornarElementoDelInicio() {
	string  elemento = cabeza->getDato() + "";
	if (cabeza == NULL) {
		return "";
	}
	else {
		if (cabeza == fin) {
			fin = NULL;
		}
		else {
			cabeza = cabeza->getPtr_Siguiente();
		}
	}
	return elemento;
}

int Listita::numeroDeElementos() {
	Nodo *aux = cabeza;
	int cont = 0;
	while (aux != NULL) {
		cont++;
		aux = aux->getPtr_Siguiente();
	}
	return cont;
}

//Método para insertar en la lista
void Listita::insertar(string dato) {

	Nodo *nuevo = new Nodo(dato);
	Nodo *aux = cabeza;
	if (aux == NULL) {
		cabeza = nuevo;
	}
	else {
		while (aux->getPtr_Siguiente() != NULL) {
			aux = aux->getPtr_Siguiente();
		}
		aux->setPtr_siguiente(nuevo);
	}
}

void Listita :: imprimir() {

	Nodo *aux = cabeza;
	cout << "La lista es:" << endl;
	while (aux!=NULL) {
		cout << aux->getDato() <<endl;
		aux = aux->getPtr_Siguiente();
	}

}