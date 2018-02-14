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
# include "Header.h"
# include <time.h>
# include <sstream>
# include "Funciones.h"
# include <math.h>
# include <iostream>
# include <sstream>
# include "MenuOpciones.h"
# define PI 3.1416
using std::string;
using std::stringstream;
using std::ostringstream;
using namespace std;

string pf;
string inf;
string pref; 
float resp; 

void generarPDF() {
	//Generar pdf

	//Declaracion variables para el manejo de ficheros
	ofstream archivo;
	ofstream archivoP;
	ofstream fechas;
	limpiar();
	ofstream fs("Datos.txt");
	limpiar();
	fs << "*****************************EXPRESION INGRESADA**********************************" << endl << endl;
	fs << " La expresión es : " << endl << endl;

	fs << inf;
	fs << endl << endl;
	fs.close();

	int imp;
	system("cls");
	imp = AyudaF1();
	if (imp == 1) {
		ofstream LeerDatos;
		LeerDatos.open("Datos.txt", ios::out | ios::app);
		tifstream in(TEXT("Datos.txt"));
		PrintFile(in);
		ShellExecute(NULL, TEXT("open"), TEXT("C:\\Users\\DANIELAROSERO\\Documents\\GitHub\\GabrielaRosero_Tareas_Proyectos\\Proyecto_3erParcial\\Datos.pdf"), NULL, NULL, SW_SHOWNORMAL);
	}
	system("pause");
	_getch();


}
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






