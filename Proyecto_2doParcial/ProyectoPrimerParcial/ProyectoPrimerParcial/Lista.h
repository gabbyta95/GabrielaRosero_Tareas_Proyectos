# ifndef LISTA_H
# define LISTA_H
# include "Nodo.h"
# include <string>
using namespace std;

class Listita {
private:
	Nodo * cabeza;
	Nodo *fin;
public:
	Listita();
	int numeroDeElementos();
	string retornarElementoDelInicio();
	void insertar(string dato);
	void imprimir();
	string expresionConcatenada();
};

# endif

