/****************************************************************************
* PROYECTO SEGUNDO PARCIAL                                                  *
* Autor: Gabriela Rosero , Edwin     Astudillo                              *
* Fecha Creacion :12/01/2017                                                *
* Fecha Modificacion : 13/01/2017                                           *
* Carrera: Ingenieria en Sistemas e informatica                             *
* Profesor :Ing Fernando Solis                                              *
****************************************************************************/


//permite utilizar funciones como strcpy() para que no salga un warning
#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# include <ctime>
# include <string>
# include <string.h>
# include <fstream>
# include <windows.h>
# include <stdbool.h>
# include "Librerias.h"

# include <time.h>
# include <sstream>
# include "Funciones.h"
# include <math.h>
# include <iostream>
# include <sstream>
# include "MenuOpciones.h"
using namespace std;



int  AyudaF1() {
	int x;
	int imp;
	cout << "\n\nPresione F1  ";
	for (;;) {
		x = _getch();//captura la tecla de función ,pertenece a la libreria conio.h
		if (x == 59)
		{
			imp = 1;
			cout << "\n\n Generando...... ";
			break;
		}
	}
	return imp;
}
void limpiar() {
	system("cls");
	system("COLOR 07");
}
char * convertirStringAChar(string dato) {
	char *auxDato = new char[dato.size()];
	strcpy(auxDato, dato.c_str());
	return auxDato;
}






