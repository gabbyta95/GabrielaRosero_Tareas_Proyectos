/************************************************
*UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"      *
*INTEGRANTES: GABRIELA ROSERO   EDWIN ASTUDILLO *
*CARRERA: INGENIERIA EN SISTEMAS E INFORM�TICA  *
*INGENIERO: ING FERNANDO SOLIS                  *
*Fecha de creaci�n: 2017-12-19                  *
*Fecha de modificaci�n: 2017-12-27              *
*************************************************/

//strcpy() para que no salga un warning 
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
# include "qrcodegen.h"
#include "Header.h"
#include <windows.h>
#include <time.h>
# include <fstream>
# include <sstream>

using namespace std;

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
bool validarCorreo(char *corre, char **correos, int tam);
char* generarCorreo(char* nombre, char* nombre2, char* apP, char *apM, char **correos, int tam, int sA);
char * convertirStringAChar(string dato);
string convertirCharAString(char *dato);
bool soloNumeros(string datoIngresado);
static void generarQrBasico(char dato1[]);
static void printQr(const uint8_t qrcode[]);
//void visualizarQR(Habitacion *hotel);


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
	bool banderaF = false;
	char c;//Variable auxiliar que guardara los caracteres de los comandos
	bool banderaNumero = false;
	string auxDato;

	system("COLOR F0");
	Cargando();
	login(cedula, clave, cont);
	AjustarVentana(200, 58);

	do {

		limpiar();
		Cabecera2();
		AjustarVentana(400, 58);
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

			//	ShellExecute(NULL, TEXT("open"), TEXT("C:\\Users\\DANIELAROSERO\\Documents\\GitHub\\Proyecto1\\ProyectoGaby_Edwin\\ProyectoPrimerParcial\\ayuda.chm"), NULL, NULL, SW_SHOWNORMAL);

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
				cout << "�El usuario registrado sera administrador?(1=si-0=no)";
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
						//	ShellExecute(NULL, TEXT("open"), TEXT("C:\\Users\\DANIELAROSERO\\Documents\\GitHub\\Proyecto1\\ProyectoGaby_Edwin\\ProyectoPrimerParcial\\ayuda.chm"), NULL, NULL, SW_SHOWNORMAL);

					}
					if (c == 13) {//Segun el codigo ASCII el valor 13 representa a Enter.
						if (y == 4) {
							limpiar();
							cout << "***********************Imagen en consola*************************" << endl;
							//	ShellExecute(NULL, TEXT("open"), TEXT("C:\\Users\\DANIELAROSERO\\Documents\\ESPE\\3er Semestre\\ProgramacionI\\ProyectoGaby_Edwin - Copy\\IMAGEN C\\Untitled1.exe"), NULL, NULL, SW_SHOWNORMAL);
							//codigo inestable, solo en dev me esta funcionando "mejor".
							system("pause");
						}
						if (y == 19) {
							limpiar();
							cout << "***********************Postfijo***************************" << endl;

							system("pause");
						}

						if (y == 34) {
							limpiar();
							cout << "***********************Prefijo***************************" << endl;

							system("pause");
						}
						if (y == 49) {
							//Generar QR

							limpiar();
							cout << "*********************** Generar QR ***************************" << endl;
							//visualizarQR(hotel);
							system("pause");

						}
						if (y == 64) {

							limpiar();
							cout << "*********************** Generar PDF ***************************" << endl;

						}
						if (y == 79) {
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


int  AyudaF1() {
	int x;
	int imp;
	cout << "\n\nPresione F1  ";
	for (;; ) {
		x = _getch();//captura la tecla de funci�n ,pertenece a la libreria conio.h
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

	// Ajustar el buffer al nuevo tama�o
	SetConsoleScreenBufferSize(hConsola, Coordenada);

	// Cambiar tama�o de consola a lo especificado en el buffer
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
	cout << "**               PROYECTO DE PRIMER PARCIAL: Hotel                          **"; gotoxy(5, 7);
	cout << "**  INTEGRANTES: ASTUDILLO EDWIN - ROSERO GABRIELA                          **"; gotoxy(5, 8);
	cout << "**  DOCENTE: ING. FERNANDO SOLIS                                            **"; gotoxy(5, 9);
	cout << "******************************************************************************";

	gotoxy(40, 20);
	cout << "CARGANDO" << endl << endl;
	//Parte para que se cargue la barra
	do {
		gotoxy(15, 25);
		printf("%i %c", i, '%');//este contador va aumentando desde el 0 al 100, conforme va corriendo el sleep, da la ilusi�n de que carga el porcentaje.
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
		printf("%i %c", i, '%');//este contador va disminuyendo de 0 a 100, conforme va corriendo el sleep, da la ilusi�n de que carga el porcentaje.
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
			i--;/*baja el tama�o de la palabra*/
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
//***************************************Validar c�dula************************************************


long ValidarCed()
{
	bool continuar;
	int contador = 0;
	bool bandera2;
	long coc2 = 0, coc1 = 0, sum1 = 0, ci = 0, coc, cedula;
	int res, cont, mul, sumapar, sumimpar, sumtotal, digver;
	long digitoc;

	do {
		continuar = false;
		cin.clear();
		if (contador > 0) cin.ignore(1024, '\n');
		{
			cout << endl << "Ingresa la cedula: ";
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
	cout << "\t\tLOGIN - HOTEL " << endl;

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


	cout << "Contrase�a: "; leerClave(contrasenia);
	clv = contrasenia; user = usuario;

	for (int i = 0; i < tam; i++) {
		if (user == *(&(*usuarios) + i)) {

			if (*(&(*claves) + i) == "0") {

				bandera = false;
				break;
			}
			else {

				if (strcmp(clv, *(&(*claves) + i)) == 0) {

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

			bandera = false;
		}
	}
	return bandera;
}
//***************************************GenerarCorreo************************************************
char* generarCorreo(char* nombre, char* nombre2, char* apP, char *apM, char **correos, int tam, int sA) {
	//char *correo = (*(&(*nombre) + 0)) + (*(&(*nombre2) + 0)) + (apP);

	string aux1, aux2, aux3, aux4;
	aux1 = convertirCharAString(nombre);
	aux2 = convertirCharAString(nombre2);
	aux3 = convertirCharAString(apP);
	aux4 = convertirCharAString(apM);
	string aux5 = aux1.substr(0, 1);
	string aux6 = aux2.substr(0, 1);
	string aux7;
	char *correo;
	if (sA != 0) {
		aux7 = aux4.substr(0, sA);
		correo = convertirStringAChar(aux5 + aux6 + aux3 + aux7);
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

static void generarQrBasico(char dato1[]) {
	char *dato = dato1;  // User-supplied text
	enum qrcodegen_Ecc errCorLvl = qrcodegen_Ecc_LOW;  // Error correction level

													   // Make and print the QR Code symbol
	uint8_t qrcode[qrcodegen_BUFFER_LEN_MAX];
	uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];
	bool ok = qrcodegen_encodeText(dato, tempBuffer, qrcode, errCorLvl,
		qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, qrcodegen_Mask_AUTO, true);
	if (ok)
		printQr(qrcode);
}
//visualizar QR/*
/*void visualizarQR(Habitacion *hotel) {
Habitacion *aux = hotel;
long auxCedula;
bool bandera = false;

do {
auxCedula = ValidarCed();
} while (auxCedula == 0);


while (aux != NULL) {
if (aux->cliente.cedula == auxCedula) {
bandera = true;
break;
}
aux = aux->sig;
}

if (bandera == true) {
ostringstream ss;
ss << aux->cliente.cedula;
string nCedula = ss.str();
ostringstream st;
st << aux->numHabitacion;
string nHabitacion = st.str();
gotoxy(10, 40);
generarQrBasico(convertirStringAChar("\nNombre:" + aux->cliente.nombre + " " + aux->cliente.apellido + " \nCedula:" + nCedula + " \nHabitacion:" + nHabitacion));
}
else {
cout << "El Usuario  no se encuentra registrado en el Hotel";
}

}
*/
static void printQr(const uint8_t qrcode[]) {
	int size = qrcodegen_getSize(qrcode);
	int border = 4;
	for (int y = -border; y < size + border; y++) {
		for (int x = -border; x < size + border; x++) {
			fputs((qrcodegen_getModule(qrcode, x, y) ? "\333\333" : "  "), stdout);
		}
		fputs("\n", stdout);
	}
}

bool soloNumeros(string datoIngresado) {

	int cont = 0;
	bool bandera = false;
	for (int i = 0; i < datoIngresado.length(); i++) {

		if (datoIngresado[i] >= 48 && datoIngresado[i] <= 57) {
			cont++;
		}
	}

	if (cont == datoIngresado.length()) {
		bandera = true;
	}

	return bandera;
}