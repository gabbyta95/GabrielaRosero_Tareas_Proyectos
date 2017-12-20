#include <jni.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
JNIEXPORT jint JNICALL Java_Menu_inDLL(JNIEnv *jenv, jobject jobj){	

//Funcion Gotoxy para dar posicion al curso
void gotoxy(int x, int y) {
	HANDLE hCon; //Tipo particular de punteros
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}
	
void color(int col) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col); //Asigna color
}

gotoxy(32, 1);
	printf("UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE");
	gotoxy(5, 5);
	printf("Lista Simple");
	gotoxy(20, 5);
	printf("Lista Doble");
	gotoxy(35, 5);
	printf("Lista Circular");

}
