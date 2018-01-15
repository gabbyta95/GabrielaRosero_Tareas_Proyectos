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

void Listita::imprimir() {

	Nodo *aux = cabeza;
	cout << endl << endl << "La expresión Infija es: ";
	while (aux != NULL) {

		if (aux->getDato() == "sin" || aux->getDato() == "cos" || aux->getDato() == "tan" || aux->getDato() == "sen") {
			cout << aux->getDato() << "(";
		}
		else {
			cout << aux->getDato();
		}
		aux = aux->getPtr_Siguiente();
	}

}

string Listita::expresionConcatenada() {
	Nodo *aux = cabeza;
	string cadena = "";
	while (aux != NULL) {
		cadena = cadena + aux->getDato() + "   ";
		aux = aux->getPtr_Siguiente();
	}
	return cadena;
}