/************************************************
*UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"      *
*INTEGRANTES: GABRIELA ROSERO   EDWIN ASTUDILLO *
*CARRERA: INGENIERIA EN SISTEMAS E INFORMÁTICA  *
*INGENIERO: ING FERNANDO SOLIS                  *
*Fecha de creación: 2018-02-08                  *
*Fecha de modificación: 2018-02-15              *
*************************************************/

# include "Funciones.h"
# include "Librerias.h"
# include "MenuOpciones.h"
# include <string>
# include <math.h>
# include "qrcodegen.h"
# include "header.h"
# include <iostream>
# include "sstream"

using std::string;
using std::stringstream;
using std::ostringstream;
using namespace std;



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

char * convertirStringAChar(string dato) {
	char *auxDato = new char[dato.size()];
	strcpy(auxDato, dato.c_str());
	return auxDato;
}