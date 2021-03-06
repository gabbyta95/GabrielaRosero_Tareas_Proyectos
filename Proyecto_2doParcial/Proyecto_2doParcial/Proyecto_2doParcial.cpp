/************************************************
*UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"      *
*INTEGRANTES: GABRIELA ROSERO   EDWIN ASTUDILLO *
*CARRERA: INGENIERIA EN SISTEMAS E INFORMÁTICA  *
*INGENIERO: ING FERNANDO SOLIS                  *
*Fecha de creación: 2017-12-19                  *
*Fecha de modificación: 2017-12-25              *
*************************************************/


#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
# include <fstream>
# include <sstream>
using namespace std;



int main()
{
    return 0;
}





//FUNCIONES PARA LA CREACION DEL MENU

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
void Cabecera() {
	gotoxy(32, 1);
	printf("UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE");
	gotoxy(5, 5);
	printf("Imagen");
	gotoxy(20, 5);
	printf("Postfija");
	gotoxy(35, 5);
	printf("Prefija");
	gotoxy(50, 5);	
	printf("Generar QR");
	gotoxy(65, 5);
	printf("Generar PDF");
	gotoxy(80, 5);
	printf("Regresar");
}
void Cabecera2() {
	AjustarVentana(200, 58);
	gotoxy(32, 1);
	printf("UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE");
	gotoxy(5, 5);
	printf("Crear Usuario");
	gotoxy(20, 5);
	printf("Funciones");
	gotoxy(35, 5);
	printf("CerrarSesion");
	gotoxy(50, 5);
	printf("Salir");
}
void color(int col) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col); //Asigna color
}
//Color para el menu principal 
void colorPrinc(int a) {
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
	case 49:
		a = 3;
		break;
	case 64:
		a = 4;
		break;
	case 79:
		a = 5;
		break;
	case 94:
		a = 6;
		break;
	}
	string Menu[6] = { "Imagen", "Postfija", "Prefija","Generar QR","Generar PDF","Regresar" };
	color(240);
	printf("\20");
	cout << Menu[a] << endl;
	color(6);
}
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
	case 49:
		a = 3;
		break;
	}
	string Menu[4] = { "Crear Usuario", "Funciones","CerrarSesion","Salir" };
	color(240);
	printf("\20");
	cout << Menu[a] << endl;
	color(7);
}
void Cargando() {
	AjustarVentana(85, 40);
	int cont = 0, i = 0, j = 20;
	gotoxy(5, 3);
	cout << "******************************************************************************"; gotoxy(5, 4);
	cout << "**                UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE                 **"; gotoxy(5, 5);
	cout << "**                             PROGRAMACION I                               **"; gotoxy(5, 6);
	cout << "**               PROYECTO DE PRIMER PARCIAL: Calculadora                    **"; gotoxy(5, 7);
	cout << "**  INTEGRANTES: ASTUDILLO EDWIN - ROSERO GABRIELA                          **"; gotoxy(5, 8);
	cout << "**  DOCENTE: ING. FERNANDO SOLIS                                            **"; gotoxy(5, 9);
	cout << "******************************************************************************";

	gotoxy(40, 20);
	cout << "CARGANDO" << endl << endl;
	//Parte para que se cargue la barra
	do {
		gotoxy(15, 25);
		printf("%i %c", i, '%');//este contador va aumentando desde el 0 al 100, conforme va corriendo el sleep, da la ilusión de que carga el porcentaje.
		gotoxy(j, 25);
		printf("\333");
		cont++;
		i = i + 2;
		j++;
		Sleep(75);
	} while (i<100);
	system("COLOR F0"); //Hace blanco el fondo
}