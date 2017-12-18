
/****************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"               *
*                    PILAS                                   	*
*  AUTORES: GABRIELA ROSERO EDWIN ASTUDILLO *
*  FECHA CREACIÓN : 16 / 12 / 2017 *
*  FECHA MODIFICACIÓN : 16 / 12 / 2017 *
*  CARRERA : INGENIERIA EN SISTEMAS E INFORMÁTICA        		*
*  PROFESOR : ING.FERNANDO SOLIS		                		*
*****************************************************************/
# ifndef  PILAS_H
# define PILAS_H
# include "Nodo.h"

//Prototipos Pila
# include <string>

# include <iostream>
using namespace std;


class Pila {
private:
	Nodo * cabeza;
public:
	Pila();
	void apilar(string  dato);
	bool estaVacia();
	string desapilar();
	string  elementoTope();
};



# endif
