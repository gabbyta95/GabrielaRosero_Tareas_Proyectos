//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//Nombre: Gabriela Rosero.
//Listas realizadas con clases.
//Ing. Fernando Solis.
//Fecha de creación: 2017/12/04
//Fecha de modificación: 2017/12/12

#include "lstSimple.h"
#include "lstDoble.h"
#include "lstCircular.h"
#include "stdafx.h"
#include "librerias.h"
#include "nodo.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define ASCENDENTE 1
#define DESCENDENTE 0

int main() {
	//Declaracion e inicializacion de variables
	int cont = 0;	
	int i = 0, y = 4, k = 0;
	int opcAd = 0;
	int y2 = 4;
	int opc;
	char c;//Variable auxiliar que guardara los caracteres de los comandos
	/*ListaSimple lista=new (Nodo1);
	lista = NULL;*/

	system("COLOR F0");	
	do {
		limpiar();
		Cabecera2();
		gotoxy(y2, 5);
		colorPrinc2(y2);
		c = _getch();
		if (c == -32) {
			c = _getch();
		}
		if (c == 77) {//Segun el codigo ASCII el valor 77 representa a la tecla Derecha
			if (y2 < 49) {
				y2 = y2 + 15;
			}
			else {
				y2 = 4;
			}
		}
		if (c == 75) {//Segun el codigo ASCII el valor 75 representa a la tecla Izquierda
			if (y2 > 4) {
				y2 = y2 - 15;
			}
			else {
				y2 = 49;
			}
		}

		if (c == 13) {//Segun el codigo ASCII el valor 13 representa a Enter.
			if (y2 == 4) {
				limpiar();
				lstSimple Lista;

				Lista.Insertar(20);
				Lista.Insertar(10);
				Lista.Insertar(40);
				Lista.Insertar(30);

				Lista.Mostrar();

				cout << "Lista de elementos:" << endl;
				Lista.Primero();
				while (Lista.Actual()) {
					cout << Lista.ValorActual() << endl;
					Lista.Siguiente();
				}
				Lista.Primero();
				cout << "Primero: " << Lista.ValorActual() << endl;

				Lista.Ultimo();
				cout << "Ultimo: " << Lista.ValorActual() << endl;

				Lista.Borrar(10);
				Lista.Borrar(15);
				Lista.Borrar(45);
				Lista.Borrar(30);
				Lista.Borrar(40);

				Lista.Mostrar();
			}
			if (y2 == 19) {
				limpiar();
				lstDoble Lista;

				Lista.Insertar(20);
				Lista.Insertar(10);
				Lista.Insertar(30);

				Lista.Mostrar(ASCENDENTE);
				Lista.Mostrar(DESCENDENTE);

				Lista.Primero();
				cout << "Primero: " << Lista.ValorActual() << endl;

				Lista.Ultimo();
				cout << "Ultimo: " << Lista.ValorActual() << endl;

				Lista.Borrar(10);
				Lista.Borrar(15);
				Lista.Borrar(45);

				Lista.Mostrar(ASCENDENTE);
				Lista.Mostrar(DESCENDENTE);
			}
			if (y2 == 34) {
				limpiar();
				lstCircular Lista;

				Lista.Insertar(20);
				Lista.Insertar(10);
				Lista.Insertar(40);
				Lista.Insertar(30);
				Lista.Insertar(60);

				Lista.Mostrar();

				cout << "Lista de elementos:" << endl;
				Lista.Borrar(10);
				Lista.Borrar(30);

				Lista.Mostrar();

				cin.get();
			}
		}
		i = 0;
	} while (k == 0);
	cout << endl;
	system("pause");
	return 0;
}
