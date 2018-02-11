# ifndef FUNCIONES_H
# define FUNCIONES_H
# include "Nodo.h"

# include <string>
# include <iostream>
using namespace std;





void  mostrarHistorial();
static void printQr(const uint8_t qrcode[]);
void visualizarQR();
static void generarQrBasico(char dato1[]);
char * convertirStringAChar(string dato);
int  AyudaF1();


# endif

