#pragma once

class nodo
{
public:
	nodo();
	~nodo(); 
	nodo(int num, nodo *sig = NULL, nodo *ant = NULL) :
	valor(num), siguiente(sig), anterior(ant) {}

	private:
		int valor;
		nodo *siguiente;
		nodo *anterior;

		friend class lstSimple;
		friend class lstDoble;
		friend class lstCircular;
};
typedef nodo *pnodo;
