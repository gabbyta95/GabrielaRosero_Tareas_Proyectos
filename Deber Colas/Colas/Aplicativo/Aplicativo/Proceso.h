#pragma once
#include"Cola.h"
#include"stdafx.h"
#include<string>
#include<iostream>
#include<stdlib.h>
using namespace std;
Cola *cola = NULL;
int max(int num1, int num2);
void push(int num,int ser)
{
	Cola *nuevo = new Cola();
	if (cola==NULL)
	{
		nuevo->setTser(ser);
		nuevo->setTdes(0);
		nuevo->setTespe(0);
		nuevo->setNum(num);
		nuevo->setTlle(num);
		nuevo->setTsal(nuevo->getNum() + nuevo->getTser() + nuevo->getTespe());
		nuevo->setSgt(NULL);
		nuevo->setAnt(NULL);
		cola = nuevo;
	}
	else
	{
		//////////////////////////////////////////////////
		nuevo->setTser(ser);
		nuevo->setNum(num+cola->getNum());
		nuevo->setTespe((max(nuevo->getNum(), cola->getTsal()) - nuevo->getNum()));
		nuevo->setTsal(nuevo->getNum() + nuevo->getTser() + nuevo->getTespe());
		nuevo->setTdes((max(nuevo->getNum(), cola->getTsal()) - cola->getTsal()));
		nuevo->setTlle(nuevo->getNum() - cola->getNum());
		nuevo->setSgt(cola);
		nuevo->setAnt(NULL);
		cola->setAnt(nuevo);
		cola = nuevo;
	}
}
int max(int num1, int num2)
{
	if (num1 > num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}
void imprimir()
{
	int i = 1;
	Cola *aux =cola;
	while (aux->getSgt()!=NULL)
	{
		aux = aux->getSgt();
	}
	do
	{

		cout <<i<<"\t"<<aux->getNum()<<"\t"<<"\t\t"<<aux->getTespe()<<"\t\t"<<aux->getTdes()<<"\t\t"<<aux->getTser()<<"\t\t"<<aux->getTsal()<<"\t\t"<<aux->getTlle() << endl;
		aux = aux->getAnt();
		i++;
	} while (aux != NULL);

}
