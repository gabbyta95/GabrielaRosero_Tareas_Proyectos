# include "Pilas.h"
# include "Nodo.h"
# include <iostream>
# include <stdio.h>
# include <string>
# include <sstream>
using namespace std;



//la apunta a toda la pila 
//Método para insertar en la Pila
Pila::Pila() {
	cabeza = NULL;
}
//push
void Pila::apilar(string  dato) {
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

//Métodos para saber si la Pila esta vacia
bool  Pila::estaVacia() {
	return cabeza == NULL;
}
//Método para eliminar de la Pila POP
string  Pila::desapilar() {
	Nodo *aux = cabeza;
	Nodo *aux2 = cabeza;
	string auxE;
	if (!estaVacia()) {
		if (cabeza->getPtr_Siguiente() == NULL) {
			auxE = cabeza->getDato();
			cabeza = NULL;
		}
		else {
			while (aux->getPtr_Siguiente() != NULL) {
				aux = aux->getPtr_Siguiente();
			}
			auxE = aux->getDato();
			while (aux2->getPtr_Siguiente() != aux) {
				aux2 = aux2->getPtr_Siguiente();
			}
			aux2->setPtr_siguiente(NULL);
		}
	}
	return auxE;
}

string  Pila::elementoTope() {
	Nodo *aux = cabeza;

	if (!estaVacia()) {
		while (aux->getPtr_Siguiente() != NULL) {
			aux = aux->getPtr_Siguiente();
		}
		ostringstream auxNum;
		auxNum << aux->getDato();
		return auxNum.str();
	}
	else {
		return "(";
	}
}


