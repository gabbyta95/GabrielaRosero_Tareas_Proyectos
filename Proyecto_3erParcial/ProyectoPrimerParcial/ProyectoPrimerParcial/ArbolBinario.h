#pragma once
#include <iostream>
#include "Nodo.h"
using namespace std;
typedef int valor;
class ArbolBinario
{
protected:

	Nodo * raiz;
	Nodo * actual;
	Nodo* aux;
public:
	ArbolBinario();
	ArbolBinario(Nodo *);
	void Praiz(Nodo *);
	Nodo *Oraiz();
	bool esVacio();
	void dibujarArbol(Nodo *, int);
	Nodo raizArbol();
	Nodo * hijoIzdo();
	Nodo * hijoDcho();
	Nodo * nuevoArbol(Nodo*, valor, Nodo *);
	bool Vacio(Nodo *r) { return r == NULL; }
	void Insertar(valor);
	bool EsHoja(Nodo *);
	void inorden(Nodo*);
	void preorden(Nodo*);
	void postorden(Nodo*);
};


void ArbolBinario::Insertar(valor dat)
{
	Nodo *padre = NULL;

	actual = raiz;

	while (!Vacio(actual) && dat != actual->valorNodo()) {
		padre = actual;
		if (dat > actual->valorNodo()) actual = actual->subArbolDcho();
		else if (dat < actual->valorNodo()) actual = actual->subArbolIzdo();
	}



	if (Vacio(padre)) raiz = new Nodo(dat);

	else if (dat < padre->valorNodo()) padre->ramaIzdo(new Nodo(dat));

	else if (dat > padre->valorNodo()) padre->ramaDcho(new Nodo(dat));
}



ArbolBinario::ArbolBinario() {
	raiz = NULL;

}

ArbolBinario::ArbolBinario(Nodo *r) {
	raiz = r;
}

void ArbolBinario::Praiz(Nodo *r) {
	raiz = r;
}


Nodo *ArbolBinario::Oraiz() {
	return raiz;
}

Nodo * ArbolBinario::hijoIzdo() {
	if (raiz) {
		return raiz->subArbolIzdo();
	}
	else
		throw "arbol vacio";
}

Nodo * ArbolBinario::hijoDcho() {
	if (raiz) {
		return raiz->subArbolDcho();
	}
	else
		throw "arbol vacio";
}

Nodo ArbolBinario::raizArbol() {
	if (raiz) {
		return *raiz;
	}
	else
		throw "arbol vacio";
}

bool ArbolBinario::esVacio() {
	return raiz == NULL;
}

Nodo * ArbolBinario::nuevoArbol(Nodo * ramaIzqda, valor dato, Nodo * ramaDrcha) {
	Nodo*p = new Nodo();
	p->nuevoValor(dato);
	p->ramaIzdo(ramaIzqda);
	p->ramaDcho(ramaDrcha);
	return p;
}

bool ArbolBinario::EsHoja(Nodo *r) {
	return !r->subArbolDcho() && !r->subArbolIzdo();
}


void ArbolBinario::inorden(Nodo *r)
{
	if (r != NULL)
	{
		inorden(r->subArbolIzdo());
		r->visitar();
		inorden(r->subArbolDcho());
	}
}


void ArbolBinario::postorden(Nodo *r)
{
	if (r != NULL)
	{
		postorden(r->subArbolIzdo());
		postorden(r->subArbolDcho());
		r->visitar();
	}
}


void ArbolBinario::preorden(Nodo *r)
{
	if (r != NULL)
	{
		r->visitar();
		preorden(r->subArbolIzdo());
		preorden(r->subArbolDcho());
	}
}

void ArbolBinario::dibujarArbol(Nodo *r, int h) {
	int i;
	if (r != NULL) {
		dibujarArbol(r->subArbolIzdo(), h + 1);
		for (i = 1; i <= h; i++) {
			cout << "               ";
		}
		cout << r->valorNodo() << endl;
		dibujarArbol(r->subArbolDcho(), h + 1);
	}
}