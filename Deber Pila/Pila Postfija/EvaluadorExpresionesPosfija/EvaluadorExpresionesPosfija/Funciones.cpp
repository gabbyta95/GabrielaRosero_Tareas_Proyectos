/****************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"               *
*                    PILAS                                   	*
*  AUTORES: GABRIELA ROSERO EDWIN ASTUDILLO *
*  FECHA CREACIÓN : 16 / 12 / 2017 *
*  FECHA MODIFICACIÓN : 16 / 12 / 2017 *
*  CARRERA : INGENIERIA EN SISTEMAS E INFORMÁTICA        		*
*  PROFESOR : ING.FERNANDO SOLIS		                		*
*****************************************************************/
# include "Funciones.h"
# include <string>
# include <math.h>
# include "Lista.h"
# include <iostream>

#include "sstream"
using std::string;
using std::stringstream;
using std::ostringstream;
using namespace std;

Listita *expresion_Posfija = new Listita();


void ingresar() {
	string expresion;
	double resultado;
	cout << "Ingrese la expresión en posfija ";

	getline (cin,expresion) ;
	//cout << "estoes: "<<expresion;
	
	separarExpresion(expresion);
	resultado=evaluarPosfija();
	cout << "la operación evaluada es :";
	cout << resultado<<endl;
}

double evaluarPosfija() {

	Pila *pilaNumeros = new Pila();
	int numeroElementos = expresion_Posfija->numeroDeElementos();
	for (int i = 0; i < numeroElementos; i++) {
		
		string caracter = expresion_Posfija->retornarElementoDelInicio();
		if (esOperador(caracter)==false) {
			//double num = atof((caracter).c_str());
			//pilaNumeros->apilar(num )
				pilaNumeros->apilar(caracter);
		}
		else {
			double num2 = atof((pilaNumeros->desapilar()).c_str());
			double num1 = atof((pilaNumeros->desapilar()).c_str());
			double num3 = operacion(caracter, num1, num2);
			
			ostringstream ss;
			ss << num3;
			string out = ss.str();
			pilaNumeros->apilar(out);
		}
	}
	return atof((pilaNumeros->elementoTope()).c_str());
}



double operacion(string caracter, double num1, double num2) {

	// if (caracter == '*') {
	if (caracter == "*") {
		return num1 * num2;
	}
	//if (caracter == '/') {
	if (caracter == "/") {
		return num1 / num2;
	}
	//if (caracter == '%') {
	if (caracter == "%") {
		return (int)num1 % (int)num2;
	}
	// if (caracter == '+') {
	if (caracter == "+") {
		return num1 + num2;
	}
	// if (caracter == '-') {
	if (caracter == "-") {
		return num1 - num2;
	}
	// if (caracter == '^') {
	if (caracter == "^") {
		return pow(num1, num2);
	}
	return 0;
}

bool esOperador(string operador) {
	if (operador == "*"
		|| operador == "/"
		|| operador == "+"
		|| operador == "-"
		|| operador == "^"
		|| operador == "%") {
		return true;
	} return false;
}
//En postfija no hay parentesis


void separarExpresion(string expresionPosfija) {
	
	char arreglo[50];
	string validado = "";
	for (int i = 0; i < expresionPosfija.length();i++) {
		arreglo[i] = expresionPosfija[i];
	}

	for (int i = 0; i < expresionPosfija.length(); i++) {
		if (arreglo[i]!=':') {
			validado = validado + arreglo[i];
		}
		
		if (arreglo[i]==':') {
			expresion_Posfija->insertar(validado);
			validado = "";
		}
		
	}
}

