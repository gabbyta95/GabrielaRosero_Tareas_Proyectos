#pragma once
#ifndef NODO_H
#define NODO_H


class nodo
{

private:
	int dato;
	nodo *siguiente;
	nodo *anterior;

public:
	nodo();
	void setDato(int dato);
	int getDato();
	void setSiguiente(nodo *siguiente);
	nodo* getSiguiente();
	void setAnterior(nodo *anterior);
	nodo* getAnterior();

};


#endif 
