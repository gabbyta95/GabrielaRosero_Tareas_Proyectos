/************************************************
*UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"      *
*INTEGRANTES: GABRIELA ROSERO   EDWIN ASTUDILLO *
*CARRERA: INGENIERIA EN SISTEMAS E INFORMÁTICA  *
*INGENIERO: ING FERNANDO SOLIS                  *
*Fecha de creación: 2017-12-19                  *
*Fecha de modificación: 2018-01-15              *
*************************************************/

# include "Funciones.h"
# include <string>
# include <math.h>
# include "Lista.h"
# include <iostream>
# include "sstream"
# define PI 3.1416

using std::string;
using std::stringstream;
using std::ostringstream;
using namespace std;

Listita *expresion_Infija;
Listita *expresion_Posfija = new Listita();
Pila *pilaOperadores = new Pila();

void ingresar() {

	string expresion = "";
	double resultado = 0;
	bool bandera = false;
	do {
		expresion_Infija = new Listita();
		cout << "Ingrese la expresión en notación infija ";
		getline(cin, expresion);

		bandera = convertirInfijaAPosfija(expresion);
		if (!bandera) {
			cout << endl << "!!!!EXPRESION INCORRECTA¡¡¡¡" << endl;
		}
	} while (!bandera);


	cout << endl << endl << "La expresion en posfija es:" << expresion_Posfija->expresionConcatenada() << endl;

	cout << "La resp :" << evaluarPosfija() << endl;

}




bool separarExpresion(string expresionInfija) {

	char arreglo[100];
	Listita *auxExpresion_Infija;
	string validado = "";
	string aux = "";
	int contParentesisAbre = 0;
	int contParentesisCierra = 0;
	bool bandera = false;
	//separando 
	for (int i = 0; i < expresionInfija.length(); i++) {
		arreglo[i] = expresionInfija[i];

		if (arreglo[i] == '(') {
			contParentesisAbre++;
		}
		if (arreglo[i] == ')') {
			contParentesisCierra++;
		}

	}


	if (contParentesisAbre == contParentesisCierra) {
		//insertando en la lista

		for (int i = 0; i < expresionInfija.length(); i++) {
			//concatenando si son numeros de 2 o mas digitos 
			if (arreglo[i] != ':') {
				validado = validado + arreglo[i];
			}

			if (arreglo[i] == ':') {
				if (esfuncion(validado)) {
					for (int i = 0; i < validado.length() - 1; i++) {
						aux = aux + validado[i];
					}
					expresion_Infija->insertar(aux);
					aux = "";
					validado = "";
				}
				else {
					expresion_Infija->insertar(validado);
					validado = "";
				}
			}
		}
		expresion_Infija->imprimir();
		return true;
	}

	return false;

}


bool validarOperadoresExpresion(string expresionInfija) {
	//si el primer o ultimo caracter del string son carateres retorna true
	if (expresionInfija[0] == '*'
		|| expresionInfija[0] == '/'
		|| expresionInfija[0] == '%'
		|| expresionInfija[0] == '+'
		|| expresionInfija[0] == '-'
		|| expresionInfija[0] == '^'
		|| expresionInfija[0] == ')'
		|| expresionInfija[0] == ':'
		|| expresionInfija[expresionInfija.length() - 2] == '*'
		|| expresionInfija[expresionInfija.length() - 2] == '/'
		|| expresionInfija[expresionInfija.length() - 2] == '%'
		|| expresionInfija[expresionInfija.length() - 2] == '+'
		|| expresionInfija[expresionInfija.length() - 2] == '-'
		|| expresionInfija[expresionInfija.length() - 2] == '^'
		|| expresionInfija[expresionInfija.length() - 2] == '('
		|| expresionInfija[expresionInfija.length() - 1] != ':') {
		return false;
	}

	for (int i = 1; i < expresionInfija.length() - 3; i++) {
		char caracter = expresionInfija[i];
		char caracterSiguiente = expresionInfija[i + 2];

		if ((esOperadorAritmetico(caracter) == true) && (esOperadorAritmetico(caracterSiguiente) == true)) {
			return false;
		}
	}

	if (parentesis(expresionInfija) == false) {
		return false;
	}
	return true;
}

bool parentesis(string expresionInfija) {

	int cont = 0;

	do {
		string caracter = expresionInfija[cont] + "";
		string caracter1 = "";
		if (cont == expresionInfija.length() - 1) {
			caracter1 = ")";
		}
		else {
			caracter1 = expresionInfija[cont + 1] + "";
		}
		//si un parentesis que abre y un parentesis que cierra estan juntos retorna true
		if (caracter == "(" && caracter1 == ")") {
			return false;
		}
		//si un operador aritmético y un parentesis que cierra estan juntos retorna true
		if (esOperadorAritmetico(expresionInfija[cont]) == true && caracter1 == ")") {
			return false;
		}
		//si un parentesis que abre y un operador aritmético están juntos  retorna true
		if (caracter == "(" && esOperadorAritmetico(expresionInfija[cont + 1]) == true) {
			return false;
		}

		cont++;
	} while (cont < expresionInfija.length());
	return true;
}

bool esOperadorAritmetico(char caracter) {
	if (caracter == '*'
		|| caracter == '/'
		|| caracter == '%'
		|| caracter == '+'
		|| caracter == '-'
		|| caracter == '^') {
		return true;
	}
	return false;
}


int prioridad(string  ch) {

	if (ch == "^")
		return 3;
	if (ch == "/" || ch == "*")
		return 2;
	if (ch == "+" || ch == "-")
		return 1;
	return 0;

}

bool convertirInfijaAPosfija(string expresionInfija) {

	int valorPrioridad;
	int i = 0;
	int k = 0;
	string  ch;

	if (separarExpresion(expresionInfija)) {
		// numero de elementos de la expresion infija
		int elementos = expresion_Infija->numeroDeElementos();
		// convierte infijo expresión a postfija usando una pila
		while (i < elementos) {
			ch = expresion_Infija->retornarElementoDelInicio();

			if (ch == "(" || ch == "sin" || ch == "cos" || ch == "tan" || ch == "sen") {
				// simplemente insertar el paréntesis de apertura
				pilaOperadores->apilar(ch);
				i++;
				continue;
			}
			if (ch == ")") {

				// si vemos un paréntesis de cierre,
				// pop de todos los elementos y añádelo a
				// la expresión de postfix hasta que nos encontramos
				// un paréntesis de apertura
				while (!pilaOperadores->estaVacia() && pilaOperadores->elementoTope() != "("
					&&pilaOperadores->elementoTope() != "sin"
					&&pilaOperadores->elementoTope() != "tan"
					&&pilaOperadores->elementoTope() != "cos"
					&&pilaOperadores->elementoTope() != "sen") {
					expresion_Posfija->insertar(pilaOperadores->elementoTope());
					pilaOperadores->desapilar();

				}

				// saca el paréntesis de apertura también
				if (!pilaOperadores->estaVacia()) {
					if (pilaOperadores->elementoTope() == "sin"
						|| pilaOperadores->elementoTope() == "sen"
						|| pilaOperadores->elementoTope() == "cos"
						|| pilaOperadores->elementoTope() == "tan") {
						expresion_Posfija->insertar(pilaOperadores->elementoTope());
						pilaOperadores->desapilar();
					}
					else {
						pilaOperadores->desapilar();
					}

				}
				i++;
				continue;
			}
			valorPrioridad = prioridad(ch);
			if (valorPrioridad == 0) {
				// solo apilamos los números
				// simplemente añádalo a la expresión de postfija
				expresion_Posfija->insertar(ch);

			}
			else {

				// apilamos operadores dos casos cuando esta vacia y cuando ya tiene elementos en la pila
				if (pilaOperadores->estaVacia()) {

					// simplemente inserta al operador a la pila si
					// la pila está vacía
					pilaOperadores->apilar(ch);

				}
				else {
					// sacamos todos  los operadores de la pila y
					// lo adjuntamos a la expresión de postfija hasta que
					// el operador actual sea mayor al operador de la pila
					while (!pilaOperadores->estaVacia() && pilaOperadores->elementoTope() != "("
						&&valorPrioridad <= prioridad(pilaOperadores->elementoTope())) {
						expresion_Posfija->insertar(pilaOperadores->elementoTope());
						pilaOperadores->desapilar();
					}
					// insertando  el operador actual en la pila
					pilaOperadores->apilar(ch);
				}
			}
			i++;
		}
		// desapila  los operadores restantes presentes en la pila
		// y anexarlo a la expresión de postfija
		while (!pilaOperadores->estaVacia()) {
			expresion_Posfija->insertar(pilaOperadores->elementoTope());
			pilaOperadores->desapilar();
		}

		return true;
	}


	return false;


}


double evaluarPosfija() {

	Pila *pilaNumeros = new Pila();

	double num2;
	double num1;
	double num3;
	int numeroElementos = expresion_Posfija->numeroDeElementos();
	for (int i = 0; i < numeroElementos; i++) {

		string caracter = expresion_Posfija->retornarElementoDelInicio();
		if (esOperador(caracter) == false && esfuncionTrigonometrica(caracter) == false) {
			pilaNumeros->apilar(caracter);
		}
		else {
			//cuando encuentra operador saca dos numeros

			if (pilaNumeros->estaVacia() == false) {
				if (!esfuncionTrigonometrica(caracter)) {
					num2 = atof((pilaNumeros->elementoTope()).c_str());
					pilaNumeros->desapilar();
					num1 = atof((pilaNumeros->elementoTope()).c_str());
					pilaNumeros->desapilar();
					num3 = operacion(caracter, num1, num2);
				}
				else {
					num3 = operacionFunciones(caracter, atof((pilaNumeros->elementoTope()).c_str()));
					pilaNumeros->desapilar();
				}

				ostringstream ss;
				ss << num3;
				string out = ss.str();
				pilaNumeros->apilar(out);
			}




		}
	}
	return atof((pilaNumeros->elementoTope()).c_str());
}

string  elementoTope() {
	return pilaOperadores->elementoTope();
}

float factorial(int n) {
	int i; //contador

	float prod = 1;//Acumulador
	for (i = 1; i <= n; i++)
	{
		prod = prod * i;
	}
	return(prod);
}

//Funciones trigonometricas
float serieTaylorCos(float angulo)
{
	int i;         // Contador
	float sum = 0; // Acumulador
	int numeroTerminos = 20;
	// Convertir de grados a radianes.
	angulo = angulo * (float)PI / 180;

	for (i = 0; i <= numeroTerminos - 1; i++)
	{
		sum = sum + ((float)pow(-1.0f, i) * (float)pow(angulo, 2 * i)) / factorial(2 * i);
	}
	return  sum;
}

float calcularTan(float angulo) {
	float seno = serieTaylorSin(angulo);
	float coseno = serieTaylorCos(angulo);
	float respuesta;
	respuesta = seno / coseno;
	return respuesta;
}

float serieTaylorSin(float angulo)
{

	int i;         // Contador
	float sum = 0; // Acumulador
	int numeroTerminos = 70;
	// Convertir de grados a radianes.
	angulo = angulo * (float)PI / 180;
	for (i = 0; i <= numeroTerminos - 1; i++)
	{
		sum = sum + ((float)pow(-1.0f, i) / factorial(2 * i + 1)* (float)pow(angulo, 2 * i + 1));
	}
	return  sum;
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

double operacionFunciones(string funcion, double angulo) {
	if (funcion == "sin" || funcion == "sen") {
		return serieTaylorSin(angulo);
	}
	if (funcion == "cos") {
		return serieTaylorCos(angulo);
	}
	if (funcion == "tan") {
		return calcularTan(angulo);
	}
}

bool esOperador(string operador) {
	if (operador == "*" || operador == "/" || operador == "+" || operador == "-" || operador == "^" || operador == "%") {
		return true;
	}
	return false;
}

bool esfuncion(string valor) {
	if (valor == "sin(" || valor == "cos(" || valor == "tan(" || valor == "sen(") {
		return true;
	}
	return false;
}
bool esfuncionTrigonometrica(string valor) {
	if (valor == "sin" || valor == "cos" || valor == "tan" || valor == "sen") {
		return true;
	}
	return false;
}

