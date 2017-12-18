/****************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"               *
*                    PILAS                                   	*
*  AUTORES: GABRIELA ROSERO EDWIN ASTUDILLO *
*  FECHA CREACIÓN : 16 / 12 / 2017 *
*  FECHA MODIFICACIÓN : 16 / 12 / 2017 *
*  CARRERA : INGENIERIA EN SISTEMAS E INFORMÁTICA        		*
*  PROFESOR : ING.FERNANDO SOLIS		                		*
*****************************************************************/
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
};

# endif

