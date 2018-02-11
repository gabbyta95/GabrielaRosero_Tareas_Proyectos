/************************************************
*UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"      *
*INTEGRANTES: GABRIELA ROSERO   EDWIN ASTUDILLO *
*CARRERA: INGENIERIA EN SISTEMAS E INFORMÁTICA  *
*INGENIERO: ING FERNANDO SOLIS                  *
*Fecha de creación: 2018-02-08                  *
*Fecha de modificación: 2018-02-15              *
*************************************************/

# include "Funciones.h"
# include <stdio.h>
# include <conio.h>
# include <Windows.h>
# include "MenuOpciones.h"
void AjustarVentana(int Ancho, int Alto);
void Cargando();
int main()
{
	Cargando();
	menuOpciones();
	system("pause");
	return 0;
}

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

void Cargando() {
	AjustarVentana(85, 40);
	int cont = 0, i = 0, j = 20;
	gotoxy(5, 3);
	cout << "******************************************************************************"; gotoxy(5, 4);
	cout << "**                UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE                 **"; gotoxy(5, 5);
	cout << "**                             PROGRAMACION I                               **"; gotoxy(5, 6);
	cout << "**               PROYECTO DE PRIMER PARCIAL: ARBOLES                        **"; gotoxy(5, 7);
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
