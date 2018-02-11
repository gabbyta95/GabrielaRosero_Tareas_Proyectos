/************************************************
*UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"      *
*INTEGRANTES: GABRIELA ROSERO   EDWIN ASTUDILLO *
*CARRERA: INGENIERIA EN SISTEMAS E INFORMÁTICA  *
*INGENIERO: ING FERNANDO SOLIS                  *
*Fecha de creación: 2017-12-19                  *
*Fecha de modificación: 2018-01-15              *
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "MenuMouse.h"


int  menuMouse() {

	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hinput = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD Input;
	DWORD Events;
	COORD coord;
	CONSOLE_CURSOR_INFO inf;
	SetConsoleCursorInfo(houtput, &inf);
	SetConsoleMode(hinput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	for (;;) {
		ReadConsoleInput(hinput, &Input, 1, &Events);
		if (Input.EventType == MOUSE_EVENT) {
			if (Input.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
				coord.X = Input.Event.MouseEvent.dwMousePosition.X;
				coord.Y = Input.Event.MouseEvent.dwMousePosition.Y;

				
				if (coord.X >= 15 && coord.X <= 40 && coord.Y == 7) {//24 es el numero letras + espacios vacios que tiene esa opcion
					return 1;
				}
				if (coord.X >= 15 && coord.X <= 26 && coord.Y == 8) {//10 es el numero letras + espacios vacios que tiene esa opcion
					return 2;
				}
				if (coord.X >= 15 && coord.X <= 27 && coord.Y == 9) {//11 es el numero letras + espacios vacios que tiene esa opcion
					return 3;
				}

				if (coord.X >= 15 && coord.X <= 27 && coord.Y == 10) {//14 es el numero letras + espacios vacios que tiene esa opcion
					return 4;
				}
				if (coord.X >= 15 && coord.X <= 27 && coord.Y == 11) {//13 es el numero letras + espacios vacios que tiene esa opcion
					return 5;
				}
				if (coord.X >= 15 && coord.X <= 25 && coord.Y == 12) {//5 es el numero letras + espacios vacios que tiene esa opcion
					return 6;
				}
				if (coord.X >= 15 && coord.X <= 25 && coord.Y == 13) {//5 es el numero letras + espacios vacios que tiene esa opcion
					return 7;
				}
				if (coord.X >= 15 && coord.X <= 25 && coord.Y == 14) {//5 es el numero letras + espacios vacios que tiene esa opcion
					return 8;
				}
				if (coord.X >= 15 && coord.X <= 25 && coord.Y == 15) {//5 es el numero letras + espacios vacios que tiene esa opcion
					return 9;
				}

			}
		}
	}

}
