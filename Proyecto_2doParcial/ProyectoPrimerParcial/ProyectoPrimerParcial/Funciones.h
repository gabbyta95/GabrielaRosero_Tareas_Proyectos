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
bool separarExpresion(string expresionPosfija);
bool esfuncion(string valor);
bool esfuncionTrigonometrica(string valor);
double operacionFunciones(string funcion, double angulo);
float factorial(int n);
bool esParentesisQueAbre(string valor);
int prioridad(string  ch);
bool convertirInfijaAPosfija(string expresionInfija);
float serieTaylorSin(float angulo);
float serieTaylorCos(float angulo);
float calcularTan(float angulo);


bool validarOperadoresExpresion(string expresionInfija);
bool parentesis(string expresionInfija);
bool esOperadorAritmetico(char caracter);


/****************************
string convertirInfijaAPosfija(string expresionInfija);
int prioridadEnExpresion(string operador);
int prioridadEnPila(string operador);*/
# endif

