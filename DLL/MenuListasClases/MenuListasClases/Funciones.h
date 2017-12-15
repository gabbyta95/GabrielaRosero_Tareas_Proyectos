#pragma once
#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "nodo.h"
#include "librerias.h"

nodo* insertarDoble(nodo *colita, int num);
void imprimirDoble(nodo *colita);
nodo* insertarSimple(nodo *colita, int num);
void imprimirSimple(nodo *colita);
nodo* insertarCircular(nodo *colita, int num);
void imprimirCircular(nodo *colita);
#endif