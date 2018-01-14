# ifndef FUNCIONES_H
# define FUNCIONES_H
# include "Pilas.h"
# include "Nodo.h"

# include <string>
# include <iostream>
using namespace std;

void ingresar();
double evaluarPosfija();
bool esOperador(string caracter);
double operacion(string caracter, double num1, double num2);
void separarExpresion(string expresionPosfija);
int esOperadorChar(char caracter);
# endif