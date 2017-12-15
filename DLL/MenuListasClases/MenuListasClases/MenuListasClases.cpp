//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//Nombre: Gabriela Rosero.
//Listas realizadas con clases.
//Ing. Fernando Solis.
//Fecha de creación: 2017/12/04
//Fecha de modificación: 2017/12/12

#include "stdafx.h"
#include "librerias.h"
#include "Funciones.h"
#include "nodo.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;


int main() {
	//Declaracion e inicializacion de variables
	int cont = 0;
	int i = 0, y = 4, k = 0;
	int opcAd = 0;
	int y2 = 4;
	nodo *cabeza = NULL;
	char c;

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
				int dat = 0;
				char op;
				do {
					cabeza = insertarSimple(cabeza,dat);
					cout << "Desea Ingresar otro dato s/n = " << endl;
					op = _getch();
				} while (op != 'n');
				imprimirSimple(cabeza);
				system("pause");
			}
			if (y2 == 19) {
				limpiar();
				
				int num;
				int cont = 0;
				cout << "Ingrese dato: ";
				cin >> num;
				do {
					cont++;
					cabeza = insertarDoble(cabeza, cont);
				} while (cont != num);
				imprimirDoble(cabeza);
				system("pause");
			}
			if (y2 == 34) {
				limpiar();
				int n;
				for (int i = 0; i < 5; i++) {
					cout << "Ingrese dato: ";
					cin >> n;
					cabeza=insertarCircular(cabeza, n);
				}
				imprimirCircular(cabeza);
				system("pause");
			}
		}
		i = 0;
	} while (k == 0);
	cout << endl;
	system("pause");
	return 0;
}
/*

int menu (){
	int cont = 0;
	int i = 0, y = 4, k = 0;
	int opcAd = 0;
	int y2 = 4;
	nodo *cabeza = NULL;
	char c;

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
				int dat = 0;
				char op;
				do {
					cabeza = insertarSimple(cabeza, dat);
					cout << "Desea Ingresar otro dato s/n = " << endl;
					op = _getch();
				} while (op != 'n');
				imprimirSimple(cabeza);
				system("pause");
			}
			if (y2 == 19) {
				limpiar();

				int num;
				int cont = 0;
				cout << "Ingrese dato: ";
				cin >> num;
				do {
					cont++;
					cabeza = insertarDoble(cabeza, cont);
				} while (cont != num);
				imprimirDoble(cabeza);
				system("pause");
			}
			if (y2 == 34) {
				limpiar();
				int n;
				for (int i = 0; i < 5; i++) {
					cout << "Ingrese dato: ";
					cin >> n;
					cabeza = insertarCircular(cabeza, n);
				}
				imprimirCircular(cabeza);
				system("pause");
			}
		}
		i = 0;
	} while (k == 0);
	cout << endl;
	system("pause");
	return 0;
}*/