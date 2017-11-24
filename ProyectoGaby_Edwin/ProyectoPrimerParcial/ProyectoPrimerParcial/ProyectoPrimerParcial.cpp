
/************************************************
*UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"      *
*INTEGRANTES: GABRIELA ROSERO   EDWIN ASTUDILLO *
*CARRERA: INGENIERIA EN SISTEMAS E INFORMÁTICA  *
*INGENIERO: ING FERNANDO SOLIS                  *
*Fecha de creación: 2017-11-11                  *
*Fecha de modificación: 2017-11-20              *
*************************************************/

//permite utilizar funciones como strcpy() para que no salga un warning (Problema de la actualización reciente de VS)
#define _CRT_SECURE_NO_WARNINGS
/* #ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif*/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <stdbool.h>
#include "Librerias.h"
#include "Header.h"
#include <windows.h>
#include <time.h>
# include <fstream>
using namespace std; 
# define numCuartos 10

struct Persona {
	string nombre = "";
	string apellido = "";
	long cedula = 0;
};

struct Fecha {
	int dia = 0;
	int mes = 0;
	int año = 0;
};

struct Habitacion {
	struct Persona cliente;
	struct Fecha fechaIngreso;
	struct Fecha fechaSalida;
	int numHabitacion = 0;
	bool estadoHabitacion = false;
	struct Habitacion *sig;
	struct Habitacion *ant;
};

//Prototipos
void gotoxy(int x, int y);
void AjustarVentana(int Ancho, int Alto);
void Cabecera();
void Cabecera2();
void color(int col);
void colorPrinc(int a);
void colorPrinc2(int a);
void Cargando();
void Salida();
void sololetras(char *aux1);
void limpiar();
long ValidarCed();
char* leerClave(char* contrasenia);
void login(long *usuarios, char**claves, int tam);
bool cedulaRepetida(long ced, long *cedulas, int tam);
void agregandoCliente(Habitacion *hotel, Habitacion *clienteactual);
Historial* agregarHistorial(Historial *historial, Habitacion clienteactual);
bool validarCorreo(char *corre, char **correos, int tam);
char* generarCorreo(char* nombre, char* nombre2, char* apP, char *apM, char **correos, int tam, int sA);
char * convertirStringAChar(string dato);
string convertirCharAString(char *dato);
Habitacion* creandoHabitaciones(Habitacion *hotel, int numHabitacion);
void imprimirHabitacionesDisponibles(Habitacion *hotel);
bool cuartoDisponible(Habitacion *hotel, int num);

int  AyudaF1();
//***************************************PRINCIPAL*****************************************************
int main()
{
	//Declaracion e inicializacion de variables
	int cont = 0;
	long *cedula = (long*)malloc(20 * sizeof(long));
	char **nombre = (char**)malloc(20 * sizeof(char*));
	for (int j = 0; j<20; j++) {
		*(&(*nombre) + j) = (char *)malloc(20 * sizeof(char*));
	}

	char **nombre2 = (char**)malloc(20 * sizeof(char*));
	for (int j = 0; j<20; j++) {
		*(&(*nombre2) + j) = (char *)malloc(20 * sizeof(char*));
	}
	char **apellidoP = (char**)malloc(20 * sizeof(char*));
	for (int j = 0; j<20; j++) {
		*(&(*apellidoP) + j) = (char *)malloc(20 * sizeof(char*));
	}
	char **apellidoM = (char**)malloc(20 * sizeof(char*));
	for (int j = 0; j<20; j++) {
		*(&(*apellidoM) + j) = (char *)malloc(20 * sizeof(char*));
	}
	char **correo = (char**)malloc(20 * sizeof(char*));
	for (int j = 0; j<20; j++) {
		*(&(*correo) + j) = (char *)malloc(20 * sizeof(char*));
	}
	char **clave = (char**)malloc(20 * sizeof(char*));
	for (int j = 0; j<20; j++) {
		*(&(*clave) + j) = (char *)malloc(20 * sizeof(char*));
	}

	*(&(*nombre) + 0) = "Gabriela";
	*(&(*nombre2) + 0) = "Stefania";
	*(&(*apellidoP) + 0) = "Rosero";
	*(&(*apellidoM) + 0) = "Casa";
	*(&(*cedula) + 0) = 1725347866;

	*(&(*correo) + 0) = generarCorreo(*(&(*nombre) + 0), *(&(*nombre2) + 0), *(&(*apellidoP) + 0), *(&(*apellidoM) + 0), correo, cont, 0);
	
	*(&(*clave) + 0) = "123456";
	cont++;
	int i = 0, y = 4, k = 0, z = 0;
	int opcAd = 0;
	int y2 = 4;
	int auxF = 0;
	int opc;
	long cedulita;
	bool banderaF = false;
	char c , ayu ;//Variable auxiliar que guardara los caracteres de los comandos
	Habitacion *hotel = NULL;
	bool banderaNumero = false;
	Habitacion clienteactual;
	string auxDato;

	system("COLOR F0");
	Cargando();
	login(cedula, clave, cont);
	AjustarVentana(200, 58);
	//creando las habitaciones 
	do {
		hotel = creandoHabitaciones(hotel, cont);
		cont++;
	} while (cont != numCuartos);
	//ingresando datos
	do {
		opc = 0;
		limpiar();
		/**************************************************************/
		cout << "INGRESANDO DATOS" << endl;
		imprimirHabitacionesDisponibles(hotel);
		agregandoCliente(hotel, &clienteactual);
		historial = agregarHistorial(historial, clienteactual);
		/***********************************************************/
		cout << "ingrese 1 para registrar otro cliente";
		cin >> opc;
	} while (opc == 1);
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
			if (y2<49) {
				y2 = y2 + 15;
			}
			else {
				y2 = 4;
			}
		}
		if (c == 75) {//Segun el codigo ASCII el valor 75 representa a la tecla Izquierda
			if (y2>4) {
				y2 = y2 - 15;
			}
			else {
				y2 = 49;
			}
		}

		if (c == 0)
		{
		
			//AYUDA ShellExecute(NULL, TEXT("open"), TEXT("C:\\Users\\DANIELAROSERO\\Desktop\\ProyectoGaby_Edwin\\ProyectoPrimerParcial\\ayuda.chm"), NULL, NULL, SW_SHOWNORMAL);
		
		} 

		if (c == 13) {//Segun el codigo ASCII el valor 13 representa a Enter.
			if (y2 == 4) {
				limpiar();
				cout << "\t\t**************REGISTRO********************" << endl;
				gotoxy(2, 6);
				//Cedula
				*(&(*cedula) + cont) = 0;
				while (*(&(*cedula) + cont) == 0 || (cedulaRepetida(*(&(*cedula) + cont), cedula, cont))) {
					limpiar();
					cout << "\t\t**************REGISTRO********************" << endl;
					*(&(*cedula) + cont) = ValidarCed();
				}
				cout << "Apellido Paterno: ";
				sololetras(*(&(*apellidoP) + cont));
				cout << "\n";
				cout << "Apellido Materno: ";
				sololetras(*(&(*apellidoM) + cont));
				cout << "\n";
				cout << "Primer Nombre: ";
				sololetras(*(&(*nombre) + cont));
				cout << "\n";
				cout << "Segundo Nombre: ";
				sololetras(*(&(*nombre2) + cont));
				cout << "\n";
				cout << "Correo generado: ";
				*(&(*correo) + cont) = generarCorreo(*(&(*nombre) + cont), *(&(*nombre2) + cont), *(&(*apellidoP) + cont), *(&(*apellidoM) + cont), correo, cont, 0);
				cout << *(&(*correo) + cont);
				cout << endl;
				cout << "¿El usuario registrado sera administrador?(1=si-0=no)";
				cin >> opcAd;
				if (opcAd == 1) {
					cout << "Contrasenia: ";
					cin >> *(&(*clave) + cont);
				}
				else {
					*(&(*clave) + cont) = "0";
				}
				cont++;
				cout << "Registro exitoso";
			}
			if (y2 == 19) {
				do {
					limpiar();
					Cabecera();//Llama  a la cabecera para que imprima el menu
					gotoxy(y, 5);
					colorPrinc(y);
					c = _getch();
					if (c == -32) {
						c = _getch();
					}
					if (c == 77) {//Segun el codigo ASCII el valor 77 representa a la tecla Derecha
						if (y<94) {
							y = y + 15;
						}
						else {
							y = 4;
						}
					}
					if (c == 75) {//Segun el codigo ASCII el valor 75 representa a la tecla Izquierda
						if (y>4) {
							y = y - 15;
						}
						else {
							y = 94;
						}
					}
					if (c == 0)//f1
					{
						ShellExecute(NULL, TEXT("open"), TEXT("C:\\Users\\DANIELAROSERO\\Documents\\GitHub\\Proyecto1\\ProyectoGaby_Edwin\\ProyectoPrimerParcial\\ayuda.chm"), NULL, NULL, SW_SHOWNORMAL);
						
					}
					if (c == 13) {//Segun el codigo ASCII el valor 13 representa a Enter.
						if (y == 4) {
							limpiar();
							cout << "***********************Imagen en consola*************************" << endl;
							ShellExecute(NULL, TEXT("open"), TEXT("C:\\Users\\DANIELAROSERO\\Documents\\GitHub\\Proyecto1\\ProyectoGaby_Edwin\\ProyectoPrimerParcial\\Untitled1.exe"), NULL, NULL, SW_SHOWNORMAL);
							//codigo inestable, solo en dev me esta funcionando.

						}
							if (y == 19) {
								cout << "***********************Habitaciones***************************" << endl;
								do {
									opc = 0;
									limpiar();
									/**************************************************************/
									cout << "INGRESANDO DATOS" << endl;
									imprimirHabitacionesDisponibles(hotel);
									/***********************************************************/
									cout << "ingrese 1 para registrar otro cliente";
									cin >> opc;
								} while (opc == 1);

							}

							if (y == 34) {
								limpiar();
								cout << "***********************Eliminar***************************" << endl;
								/*Aquí va código para eliminación del ingreso.*/
								
							}


						if (y == 49) {
							limpiar();
							cout << "***********************Buscar Cliente***************************" << endl;
							/*Aquí va código para busqueda de cliente.*/
						}
						if (y == 64) {
							//Generar QR

							limpiar();
							cout << "*********************** Generar QR ***************************" << endl;
							/*Aquí va código para generar QR.*/

						}
						if (y == 79) {

							limpiar();
							cout << "*********************** Generar PDF ***************************" << endl;
							/*Aquí va código para generar PDF.*/
						}
						if (y == 94) {
							//REGRESAR A MENU PRINCIPAL
							system("COLOR F0");
							system("cls");
							i = 1;
						}
					}
				} while (i == 0);

			}
			if (y2 == 34) {
				login(cedula, clave, cont);
			}
			if (y2 == 49) {
				system("COLOR F0");
				system("cls");
				AjustarVentana(55, 20);
				Salida();
				k = 1;
			}
		}
		i = 0;
	} while (k == 0);
	cout << endl;
	system("pause");
	return 0;
}
void agregandoCliente(Habitacion *hotel, Habitacion *clienteactual) {
	char *auxNombre = (char*)malloc(20 * sizeof(char*));
	char *auxApellido = (char*)malloc(20 * sizeof(char*));


	Habitacion *auxHotel = hotel;
	int aux = 0;
	int auxNumHabitacion = 0;
	long auxCedula = 0;
	string auxDato = "";
	bool bandera;
	bool banderaNumero;
	do {
		bandera = false;
		do {
			banderaNumero = false;
			cout << "Ingrese la habitación:";
			cin >> auxDato;

			banderaNumero = soloNumeros(auxDato);
			if (!banderaNumero) {
				cout << "  NO EXISTE LA HABITACION  " << endl;
				Sleep(1500);
				limpiar();
			}
		} while (!banderaNumero);

		auxNumHabitacion = atoi((auxDato).c_str()); //convierte de string a int 

		if (auxNumHabitacion>0 && auxNumHabitacion<numCuartos) {
			bandera = cuartoDisponible(hotel, auxNumHabitacion);
			if (bandera == true) {
				cout << endl << "LA HABITACIÓN ESTA OCUPADA  " << endl;
				cout << endl << "ELIJA OTRA HABITACIÓN " << endl;
			}
		}
		else {
			cout << "EL HOTEL TIENE  " << numCuartos - 1 << " CUARTOS" << endl;
			cout << "INGRESE OTRO CUARTO" << endl;
			bandera = true;
		}
	} while (bandera != false);



	while (auxHotel != NULL) {

		if (auxHotel->numHabitacion == auxNumHabitacion) {
			cout << endl << "Ingrese el nombre: ";
			sololetras(*(&(auxNombre)));
			auxHotel->cliente.nombre = convertirCharAString((*(&(auxNombre))));
			//cin >> auxHotel->cliente.nombre;
			cout << endl << "Ingrese el Apellido: ";
			sololetras(*(&(auxApellido)));
			auxHotel->cliente.apellido = convertirCharAString((*(&(auxApellido))));
			//cin >> auxHotel->cliente.apellido;

			// ingreso cédula y validando
			do {
				auxCedula = validarCed();
			} while (auxCedula == 0);
			auxHotel->cliente.cedula = auxCedula;
			//cin >> auxHotel->cliente.cedula;

			do {
				banderaNumero = false;
				cout << endl << "Ingrese el año : ";
				cin >> auxDato;
				banderaNumero = soloNumeros(auxDato);
				if (!banderaNumero) {
					cout << " ANIO INVALIDO " << endl;
					Sleep(1500);
					limpiar();
				}
				aux = atoi((auxDato).c_str());
				if (aux<2017) {
					banderaNumero = false;
				}
			} while (!banderaNumero);
			aux = atoi((auxDato).c_str()); //convierte de string a int 
			auxHotel->fechaIngreso.año = aux;
			//cin >> auxHotel->fechaIngreso.año;
			do {
				banderaNumero = false;
				cout << endl << "Ingrese el mes de entrada: ";
				cin >> auxDato;
				banderaNumero = soloNumeros(auxDato);
				if (!banderaNumero) {
					cout << " MES INVALIDO " << endl;
					Sleep(1500);
					limpiar();
				}
				aux = atoi((auxDato).c_str());
				if (aux<0 || aux>12) {
					banderaNumero = false;
				}
			} while (!banderaNumero);
			aux = atoi((auxDato).c_str()); //convierte de string a int 
			auxHotel->fechaIngreso.mes = aux;
			//cin >> auxHotel->fechaIngreso.mes;

			do {
				banderaNumero = false;
				cout << endl << "Ingrese el dia Entrada: ";
				cin >> auxDato;
				banderaNumero = soloNumeros(auxDato);
				if (!banderaNumero) {
					cout << " DIA INVALIDO " << endl;
					Sleep(1500);
					limpiar();
				}
				aux = atoi((auxDato).c_str());
				if (aux<0 || aux>31) {
					banderaNumero = false;
				}
			} while (!banderaNumero);
			aux = atoi((auxDato).c_str()); //convierte de string a int 
			auxHotel->fechaIngreso.dia = aux;
			//cin >> auxHotel->fechaIngreso.dia;
			do {
				banderaNumero = false;
				cout << endl << "Ingrese el año salida: ";
				cin >> auxDato;
				banderaNumero = soloNumeros(auxDato);
				if (!banderaNumero) {
					cout << " ANIO INVALIDO " << endl;
					Sleep(1500);
					limpiar();
				}
				aux = atoi((auxDato).c_str());
				if (aux<2017) {
					banderaNumero = false;
				}
			} while (!banderaNumero);
			aux = atoi((auxDato).c_str()); //convierte de string a int 
			auxHotel->fechaSalida.año = aux;
			//cin >> auxHotel->fechaSalida.año;

			do {
				banderaNumero = false;
				cout << endl << "Ingrese el mes salida: ";
				cin >> auxDato;
				banderaNumero = soloNumeros(auxDato);
				if (!banderaNumero) {
					cout << " MES INVALIDO " << endl;
					Sleep(1500);
					limpiar();
				}
				aux = atoi((auxDato).c_str());
				if (aux<0 || aux>12) {
					banderaNumero = false;
				}
			} while (!banderaNumero);
			aux = atoi((auxDato).c_str()); //convierte de string a int 
			auxHotel->fechaSalida.mes = aux;
			//cin >> auxHotel->fechaSalida.mes;
			do {
				banderaNumero = false;
				cout << endl << "Ingrese el dia salida: ";
				cin >> auxDato;
				banderaNumero = soloNumeros(auxDato);
				if (!banderaNumero) {
					cout << " DIA INVALIDO " << endl;
					Sleep(1500);
					limpiar();
				}
				aux = atoi((auxDato).c_str());
				if (aux<0 || aux>31) {
					banderaNumero = false;
				}
			} while (!banderaNumero);
			aux = atoi((auxDato).c_str()); //convierte de string a int 
			auxHotel->fechaSalida.dia = aux;
			//cin >> auxHotel->fechaSalida.dia;
			auxHotel->estadoHabitacion = true;
			//guardando en el historial
			clienteactual->cliente.nombre = auxHotel->cliente.nombre;
			clienteactual->cliente.apellido = auxHotel->cliente.apellido;
			clienteactual->cliente.cedula = auxHotel->cliente.cedula;
			clienteactual->fechaIngreso.año = auxHotel->fechaIngreso.año;
			clienteactual->fechaIngreso.mes = auxHotel->fechaIngreso.mes;
			clienteactual->fechaIngreso.dia = auxHotel->fechaIngreso.dia;
			clienteactual->fechaSalida.año = auxHotel->fechaSalida.año;
			clienteactual->fechaSalida.mes = auxHotel->fechaSalida.mes;
			clienteactual->fechaSalida.dia = auxHotel->fechaSalida.dia;
			clienteactual->numHabitacion = auxNumHabitacion;
		}
		auxHotel = auxHotel->sig;
	}

}
//agrega al historial del hotel nombre , fecha de ingreso, fecha de salida y habitación ocupadas
Historial* agregarHistorial(Historial *historial, Habitacion clienteactual) {
	Historial *nuevo = new(Historial);
	Historial *auxHotel = historial;

	if (auxHotel == NULL) {
		nuevo->sig = NULL;
		nuevo->ant = NULL;
		nuevo->cliente.nombre = clienteactual.cliente.nombre;
		nuevo->cliente.apellido = clienteactual.cliente.apellido;
		nuevo->cliente.cedula = clienteactual.cliente.cedula;
		nuevo->numHabitacionH = clienteactual.numHabitacion;
		nuevo->fechaIngresoH.año = clienteactual.fechaIngreso.año;
		nuevo->fechaIngresoH.mes = clienteactual.fechaIngreso.mes;
		nuevo->fechaIngresoH.dia = clienteactual.fechaIngreso.dia;
		nuevo->fechaSalidaH.año = clienteactual.fechaSalida.año;
		nuevo->fechaSalidaH.mes = clienteactual.fechaSalida.mes;
		nuevo->fechaSalidaH.dia = clienteactual.fechaSalida.dia;
		historial = nuevo;

	}
	else {
		Historial *aux = historial;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		nuevo->cliente.nombre = clienteactual.cliente.nombre;
		nuevo->cliente.apellido = clienteactual.cliente.apellido;
		nuevo->cliente.cedula = clienteactual.cliente.cedula;
		nuevo->numHabitacionH = clienteactual.numHabitacion;
		nuevo->fechaIngresoH.año = clienteactual.fechaIngreso.año;
		nuevo->fechaIngresoH.mes = clienteactual.fechaIngreso.mes;
		nuevo->fechaIngresoH.dia = clienteactual.fechaIngreso.dia;
		nuevo->fechaSalidaH.año = clienteactual.fechaSalida.año;
		nuevo->fechaSalidaH.mes = clienteactual.fechaSalida.mes;
		nuevo->fechaSalidaH.dia = clienteactual.fechaSalida.dia;
		nuevo->sig = NULL;
		nuevo->ant = aux;
		aux->sig = nuevo;

	}
	return historial;
}


int  AyudaF1() {
	int x;
	int imp;
	cout << "\n\nPresione F1  ";
	for (;; ) {
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
//*****************************FUNCIONES MENU*******************************************************
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
	printf("Ingresar");
	gotoxy(35, 5);
	printf("Eliminar");
	gotoxy(50, 5);
	printf("Buscar");
	gotoxy(65, 5);
	printf("Generar QR");
	gotoxy(80, 5);
	printf("Generar PDF");
	gotoxy(95, 5);
	printf("Regresar");
}
void Cabecera2() {
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
	case 109:
		a = 7;
		break;
	}
	string Menu[7] = { "Imagen", "Ingresar", "Eliminar","Buscar","Generar QR","Generar PDF","Regresar" };
	color(240);
	printf("\20");
	cout << Menu[a] << endl;
	color(7);
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
	cout << "**               PROYECTO DE PRIMER PARCIAL: Hotel                          **"; gotoxy(5, 7);
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
//***************************************Validar Solo letras******************************************
void sololetras(char *aux1) {
	/*me recibe la direccion de lo que estoy escribiendo*/
	int i = 0;
	while (aux1[i] != 13 || i<3)//13 es el ascii de enter
								/*no acepta nombres que sean menores a tres letras*/
	{
		aux1[i] = _getch();//valida letra por letra
						   /* solo me acepta letras mayusculas y minusculas*/
		if ((aux1[i]>32 && i<20) && (aux1[i] >= 97 && aux1[i] <= 122) || (aux1[i] >= 65 && aux1[i] <= 90) && i<10)
		{
			printf("%c", aux1[i]);
			i++;
		}
		else if (aux1[i] == 8 && i>0)
		{
			putchar(8);/*me imprime un retroceso*/
			putchar(' ');
			putchar(8);
			i--;/*baja el tamaño de la palabra*/
				/* es para poder borrar*/
		}

	}
	aux1[i] = '\0';//cuando ya acaba la palabra
}

//***************************************LIMPIAR PANTALLA**********************************************
void limpiar() {
	system("cls");
	system("COLOR 07");
}
//***************************************Validar cédula************************************************


long ValidarCed()
{
	bool continuar;
	int contador = 0;
	bool bandera2;
	long coc2 = 0, coc1 = 0, sum1 = 0, ci=0, coc, cedula;
	int res, cont, mul, sumapar, sumimpar, sumtotal, digver;
	long digitoc;

	do {
		continuar = false;
		cin.clear();
		if (contador > 0) cin.ignore(1024, '\n');
		{
			cout << "Ingresa la cedula: " << endl;
			cin >> digitoc;
			contador++;
			bandera2 = true;
		}
		if (cin.fail() && cin.rdstate()) {
			limpiar();
			continuar = true;
		}
	} while (continuar);
	ci = digitoc;
	fflush(stdin);
	while (ci<99999999 || ci >= 11111111111)
	{
		limpiar();
		contador = 0;
		do {
			
			continuar = false;
			cin.clear();
			if (contador > 0) cin.ignore(1024, '\n');
			{
				cout << "Ingresa la cedula: " << endl;
				cin >> digitoc;
				contador++;
				bandera2 = true;


			}

			if (cin.fail() && cin.rdstate()) {

				limpiar();
				continuar = true;
			}
		} while (continuar);
		fflush(stdin);	
		ci = digitoc;
	}
	
	sumimpar = sumapar = 0;
	cedula = ci;
	cont = 1;
	digver = ci % 10;
	ci = ci / 10;

	do
	{
		coc = ci / 10;
		res = ci % 10;
		if (cont == 1)
		{
			mul = res * 2;
			if (mul>9)
				mul = mul - 9;
			sumimpar += mul;
			cont = 2;
		}
		else {
			sumapar += res;
			cont = 1;
		}
		ci = coc;
	} while (coc != 0);
	sumtotal = sumimpar + sumapar;
	res = 10 - (sumtotal % 10);
	if (res == 10)
		res = 0;
	if (res == digver) {
		return cedula;
	}
	else
	{
		printf("La cedula es invalida");
		return 0;
	}
}
//**************************************LOGIN*********************************************************
char* leerClave(char* contrasenia)
{
	int i = 0;
	cout.flush();
	char *aux = "";
	do
	{
		contrasenia[i] = (unsigned char)_getch();
		aux = aux + contrasenia[i];
		if (contrasenia[i] != 8)  // no es retroceso
		{
			cout << '*';  // muestra por pantalla
			i++;
		}
		else if (i>0)    // es retroceso y hay caracteres
		{
			cout << (char)8 << (char)32 << (char)8;
			i--;  //el caracter a borrar e el backspace
		}
		cout.flush();

	} while (contrasenia[i - 1] != 13);  // si presiona ENTER

	contrasenia[i - 1] = NULL;
	cout << endl;
	return aux;
}


void login(long *usuarios, char**claves, int tam) {
	bool continuar = false;
	int contador = 0;
	bool bandera2 = false;

	AjustarVentana(50, 30);
	limpiar();
	long usuario;
	bool bandera = false;
	char contrasenia[20];
	long user; char *clv;
	cout << "\t\tLOGIN - ROL DE PAGOS" << endl;

	do {

		continuar = false;
		cin.clear();
		if (contador > 0) cin.ignore(1024, '\n');
		{

			cout << "Usuario: ";
			cin >> usuario;
			contador++;
			bandera2 = true;
		}

		if (cin.fail() && cin.rdstate()) {

			limpiar();
			continuar = true;
		}
	} while (continuar);


	cout << "Contraseña: "; leerClave(contrasenia);
	clv = contrasenia; user = usuario;

	for (int i = 0; i < tam; i++) {
		if (user == *(&(*usuarios) + i)) {
		
			if (*(&(*claves) + i) == "0") {
				
				bandera = false;
				break;
			}
			else {
				
			if (strcmp(clv, *(&(*claves) + i)) == 0){
				
					bandera = true;
					break;
				}
				cout << *(&(*claves) + i);
			}
		}
	}
	if (!bandera)
		login(usuarios, claves, tam);
	system("PAUSE");
}
//************************************Validar Cedula Repetida*****************************************
bool cedulaRepetida(long ced, long *cedulas, int tam) {
	
	for (int i = 0; i < tam; i++) {
		if (ced == (*(&(*cedulas) + i))) {
			return true;
		}
	}
	return false;
}
//************************************Validar Correo Repetido*****************************************
bool validarCorreo(char *corre, char **correos, int tam) {

	bool bandera = true;
	for (int i = 0; i < tam; i++) {
		if (strcmp(corre, *(&(*correos) + i)) == 0) {
		
			bandera=false;
		}
	}
	return bandera;
}
//***************************************GenerarCorreo************************************************
char* generarCorreo(char* nombre, char* nombre2, char* apP, char *apM, char **correos, int tam, int sA) {
	//char *correo = (*(&(*nombre) + 0)) + (*(&(*nombre2) + 0)) + (apP);
	
	string aux1, aux2, aux3, aux4;
	aux1= convertirCharAString(nombre);
	aux2 = convertirCharAString(nombre2);
	aux3 = convertirCharAString(apP);
	aux4 = convertirCharAString(apM);
	string aux5 = aux1.substr(0,1);
	string aux6 = aux2.substr(0,1);
	string aux7;
	char *correo;
	if (sA != 0) {
		aux7 = aux4.substr(0, sA);
		correo=convertirStringAChar(aux5 + aux6 + aux3+ aux7);
	}
	else {	
		correo = convertirStringAChar(aux5 + aux6 + aux3);
	}
	string correoTotal = convertirCharAString(correo) + "@espe.edu.ec";
	correo = convertirStringAChar(correoTotal);
	if (tam != 0) {
		if (!validarCorreo(correo, correos, tam)) {
			sA++;
			return generarCorreo(nombre, nombre2, apP, apM, correos, tam, sA);
		}
		else {
			return correo;
		}
	}
	else {
		return correo;
	}
}

//****************************************Convertir Char A String**************************************
string convertirCharAString(char *dato) {
	string auxDato = dato;
	return auxDato;
}
//****************************************Convertir string A Char**************************************
char * convertirStringAChar(string dato) {
	char *auxDato = new char[dato.size()];
	strcpy(auxDato, dato.c_str());
	return auxDato;
}
//crea las habitaciones del hotel 
Habitacion* creandoHabitaciones(Habitacion *hotel, int numCuarto) {

	Habitacion *nuevo = new(Habitacion);
	if (hotel == NULL) {
		nuevo->sig = NULL;
		nuevo->ant = NULL;
		nuevo->numHabitacion = numCuarto;
		hotel = nuevo;
	}
	else {
		Habitacion *aux = hotel;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		nuevo->numHabitacion = numCuarto;
		nuevo->sig = NULL;
		nuevo->ant = aux;
		aux->sig = nuevo;
	}
	return hotel;
}
//comprueba si la habitacion esta disponible
bool cuartoDisponible(Habitacion *hotel, int num) {

	Habitacion *aux = hotel;
	while (aux != NULL) {

		if (aux->numHabitacion == num) {
			if (aux->estadoHabitacion == false) {
				return false; //disponible
			}
			else {
				return true; //ocupado
			}
		}
		aux = aux->sig;

	}
	return false;
}

//imprime las habitaciones ocupadas y disponibles
void imprimirHabitacionesDisponibles(Habitacion *hotel) {

	Habitacion *aux = hotel;
	int x = 5;
	int y = 5;

	while (aux != NULL) {

		if (aux->estadoHabitacion == true) {//ocupado

			cout << endl << "**************" << endl;
			cout << "* HABITACION *" << endl;
			cout << "* OCUPADA *" << endl;
			cout << "*     " << aux->numHabitacion << "       *" << endl;
			cout << "**************" << endl;

		}
		else {//disponible
			cout << endl << "**************" << endl;
			cout << "* HABITACION *" << endl;
			cout << "* DISPONIBLE *" << endl;
			cout << "*      " << aux->numHabitacion << "     *" << endl;
			cout << "**************" << endl;
		}

		aux = aux->sig;
	}

}
