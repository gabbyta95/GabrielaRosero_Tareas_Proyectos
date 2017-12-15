#include "stdafx.h"
#include "librerias.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <stdbool.h>
#include <time.h>
#include <fstream>
# include <sstream>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS
/* #ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif*/

void limpiar() {
	system("cls");
	system("COLOR 07");
}
//Funcion Gotoxy para dar posicion al curso
void gotoxy(int x, int y) {
	HANDLE hCon; //Tipo particular de punteros
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}
//Funcion para dar dimensiones deseadas a la consola
void AjustarVentana(int Ancho, int Alto) {
	_COORD Coordenada;
	Coordenada.X = Ancho;
	Coordenada.Y = Alto;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = Ancho - 1;
	Rect.Bottom = Alto - 1;

	// Obtener el handle de la consola
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ajustar el buffer al nuevo tamaño
	SetConsoleScreenBufferSize(hConsola, Coordenada);

	// Cambiar tamaño de consola a lo especificado en el buffer
	SetConsoleWindowInfo(hConsola, TRUE, &Rect);
}
//Cabecera: Parte superior del programa
void Cabecera2() {
	AjustarVentana(200, 58);
	gotoxy(32, 1);
	printf("UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE");
	gotoxy(5, 5);
	printf("Lista Simple");
	gotoxy(20, 5);
	printf("Lista Doble");
	gotoxy(35, 5);
	printf("Lista Circular");
}
void color(int col) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col); //Asigna color
}
//Color para el menu principal 
void colorPrinc2(int a) {
	switch (a) {
	case 4:
		a = 0;
		break;
	case 19:
		a = 1;
		break;
	case 34:
		a = 2;
		break;
	}
	string Menu[4] = { "Lista Simple", "Lista Doble","Lista Circular"};
	color(240);
	printf("\20");
	cout << Menu[a] << endl;
	color(7);
}