/************************************************
*UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"      *
*INTEGRANTES: GABRIELA ROSERO   EDWIN ASTUDILLO *
*CARRERA: INGENIERIA EN SISTEMAS E INFORMÁTICA  *
*INGENIERO: ING FERNANDO SOLIS                  *
*Fecha de creación: 2017-12-19                  *
*Fecha de modificación: 2018-01-15              *
*************************************************/
# include <stdio.h>
# include <windows.h>
# include "MenuMouse.h"
# include "MenuOpciones.h"
# include <iostream>
# include "Funciones.h"
#include <string>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;
void Salida();
//Implementacion función gotoxy no devuelve ningun valor.(Es de la libreria conio.h)
//recibe las coordenas X (posición X del cursor(horizontal)) y Y ((posición Y del cursor (vertical))).
//la pantalla de c++ tiene 24 renglones y 80 columnas por lo que no debemos sobre pasarnos de esos valores
//la esquina superior izquierda es la posicion(1,1)


void gotoxy(int x, int y) {
	/*propio de la consola*/

	/*Struct COORD Define las coordenadas de una celda de caracteres
	en un búfer de pantalla de consola.El origen del sistema de coordenadas(0, 0)
	está en la parte superior, la celda izquierda del buffer*/
	COORD coord;
	coord.X = x;
	coord.Y = y;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); //La función GetStdHandle () 
													  //nos proporciona un mecanismo para recuperar 
													  //la entrada estándar
	SetConsoleCursorPosition(hStdOut, coord); //Establece la posición del cursor en el
											  //búfer de pantalla de consola especificado.
}


void menuOpciones() {

	int opcion;
	bool bandera = false;
	do {

		system("cls");

		gotoxy(37, 3);//coodenadas XyY
		cout << "\tMENU  DE OPCIONES \n";
		gotoxy(15, 7);//coodenadas XyY
		cout << "  EVALUADOR DE EXPRESIONES \n";
		gotoxy(15, 8);
		cout << "  GENERAR QR\n";
		gotoxy(15, 9);
		cout << "  GENERAR PDF\n";
		gotoxy(15, 10);
		cout << "  GENERAR IMAGEN\n";
		gotoxy(15, 11);
		cout << "  AYUDA\n";
		gotoxy(15, 12);
		cout << "  SALIR \n";


		opcion = menuMouse();
		system("cls");
		switch (opcion) {


		case 1:
			//EVALUADOR
			ingresar();
			gotoxy(25, 25);
			system("pause");
			bandera = true;
			break;
		case 2:
			//QR
			gotoxy(25, 25);
			system("pause");
			bandera = true;
			break;
		case 3:
			//PDF
			mostrarHistorial();
			gotoxy(25, 25);
			system("pause");
			bandera = true;
			break;
		case 4:
			//IMAGEN
			cout << "***********************Imagen en consola*************************" << endl;
			ShellExecute(NULL, TEXT("open"), TEXT("C:\\Users\\DANIELAROSERO\\Documents\\GitHub\\GabrielaRosero_Tareas_Proyectos\\Proyecto_2doParcial\\imagen.exe"), NULL, NULL, SW_SHOWNORMAL);
			//codigo inestable, solo en dev me esta funcionando "mejor".
			gotoxy(25, 25);
			system("pause");
			bandera = true;
			break;
		case 5:
			//AYUDA
			cout << "\n\n Generando...... ";
			ShellExecute(NULL, TEXT("open"), TEXT("C:\\Users\\DANIELAROSERO\\Documents\\GitHub\\GabrielaRosero_Tareas_Proyectos\\Proyecto_2doParcial\\ayuda.chm"), NULL, NULL, SW_SHOWNORMAL);
			gotoxy(25, 25);
			system("pause");
			bandera = true;
			break;
		case 6:
			//Salir
			Salida();
			bandera = false;
			gotoxy(25, 25);
			break;
		}

	} while (bandera != false);
}

void Salida() {
	int cont = 0, i = 0, j = 3;
	gotoxy(23, 3);
	cout << "FINALIZANDO" << endl << endl;
	//Parte para que se cargue la barra
	do {
		gotoxy(1, 6);
		printf("%i %c", i, '%');//este contador va disminuyendo de 0 a 100, conforme va corriendo el sleep, da la ilusión de que carga el porcentaje.
		gotoxy(j, 8);
		printf("\333"); //barrita negra ascii
		cont++;
		i = i + 2;
		j++;
		Sleep(75);
	} while (i <= 100);
	cout << endl << "\n\t\tGRACIAS POR USAR EL PROGRAMA" << endl;
	system("COLOR F0"); //Hace blanco el fondo
}
