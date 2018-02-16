/************************************************
*UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"      *
*INTEGRANTES: GABRIELA ROSERO   EDWIN ASTUDILLO *
*CARRERA: INGENIERIA EN SISTEMAS E INFORMÁTICA  *
*INGENIERO: ING FERNANDO SOLIS                  *
*Fecha de creación: 2018-02-08                  *
*Fecha de modificación: 2018-02-15              *
*************************************************/
# include <stdio.h>
# include <windows.h>
# include "MenuMouse.h"
# include "MenuOpciones.h"
# include "Header.h"
#include "qrcodegen.h"
# include "Funciones.h"
# include <iostream>
#include <sstream>
#include <string>
# include "Librerias.h"
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <fstream>
#include <allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>
#include<allegro5\allegro_ttf.h>
#include<allegro5\allegro_font.h>
#include<allegro5\display.h>
#include<allegro5\bitmap.h>

using namespace std;
static void printQr(const uint8_t qrcode[]);
static void generarQrBasico(char dato1[]);

//Implementacion función gotoxy no devuelve ningun valor.(Es de la libreria conio.h)
//recibe las coordenas X (posición X del cursor(horizontal)) y Y ((posición Y del cursor (vertical))).
//la pantalla de c++ tiene 24 renglones y 80 columnas por lo que no debemos sobre pasarnos de esos valores
//la esquina superior izquierda es la posicion(1,1)

//NODO
class Nodo {
public:
	int dato;
	Nodo *izq;
	Nodo *der;
	Nodo *padre;
};
Nodo *crearNodos(int n, Nodo *padre) {
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	nuevo->der = NULL;
	nuevo->izq = NULL;
	nuevo->padre = padre;
	return nuevo;
}

class avl_node
{
public:
	int data;
	struct avl_node *left;
	struct avl_node *right;
}*raiz;

/*
* Class Declaration
*/
class avlTree
{
public:
	int height(avl_node *);
	int diff(avl_node *);
	avl_node *rr_rotacion(avl_node *);
	avl_node *ll_rotacion(avl_node *);
	avl_node *lr_rotacion(avl_node *);
	avl_node *rl_rotacion(avl_node *);
	avl_node* balance(avl_node *);
	avl_node* insert(avl_node *, int);
	void display(avl_node *, int);
	void inorder(avl_node *);
	void preorder(avl_node *);
	void postorder(avl_node *);
	void displayALLEGRO(avl_node *ptr, int level);
	avlTree()
	{
		raiz = NULL;
	}
};

//ARBOLES BINARIOS 
Nodo *arbol = NULL;
Nodo *crearNodos(int, Nodo*);
void insertar(Nodo*&, int, Nodo*);
void mostrararbolDigitos(Nodo *arbol, int auxY);
void mostrarArbol(Nodo *arbol, int auxY);
void Salida();
void sololetras(char *aux1);
string convertirCharAString(char *dato);
int nVal;
int nPointer;
class node {
public:
	bool leaf;
	bool esRaiz;
	node *par;
	vector<int>value;
	vector<node*>child;

	node *last;
};
class  pNode {
public:
	node * tNode;
	bool nl;
	pNode(node *Node, bool b) {
		tNode = Node;
		nl = b;
	}
	pNode() {

	}
};
node *Root = NULL;
queue<pNode>q;

node* getTargetNode(node *tNode, int val);
node* getNuevoNodo(bool isLeaf, bool esRaiz);
void generarPDF();
void insertInParentNode(node *n, int kprime, node *nprime);
void insertInNodoHoja(node *leafNode, int k, node *p);
void insert2(int k, node *p);
void valueOfNodeInBox(node* tNode);
void bfsTraverse(node *tNode);
bool tooFewEntry(node *N);
bool isCoalesce(node *N, node *Nprime);

node* getTargetNode(node *tNode, int val) {
	if (tNode->leaf) return tNode;
	int i;
	for (i = 0; i<tNode->value.size(); i++) {
		if (tNode->value[i]>val) break;
	}
	return getTargetNode(tNode->child[i], val);
}
node* getNuevoNodo(bool isLeaf, bool esRaiz) {
	node* tmp = new node;
	tmp->esRaiz = esRaiz;
	tmp->leaf = isLeaf;
	tmp->last = NULL;
	return tmp;
}

//CREAR NODO

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

string inf;
//INSERTAR ARBOL BINARIO
void insertar(Nodo *&arbol, int n, Nodo *padre) {
	if (arbol == NULL) {
		Nodo *nuevo = crearNodos(n, padre);
		arbol = nuevo;
	}
	else {
		int comprobar = arbol->dato;
		if (n>comprobar) {
			insertar(arbol->der, n, arbol);
		}
		else {
			insertar(arbol->izq, n, arbol);
		}

	}
	
}
int auxX = 0;//Variable publica.
			 //MOSTRAR ALLEGRO

void mostrararbolDigitos(Nodo *arbol, int auxY) {
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	ALLEGRO_FONT *font1 = al_load_ttf_font("arial.ttf", 11, 0);
	al_draw_text(font1, al_map_rgb(230, 0, 38), 100, 20, ALLEGRO_ALIGN_LEFT, "ARBOLES BINARIOS ");
	//auxY es el nivel del arbol
	if (arbol == NULL) {//Arbol vacio nada que mostrar
		cout << "ARBOL VACIO";
		return;
	}
	auxX += 5;//variable que permite posicionarse en el eje X
	mostrararbolDigitos(arbol->izq, auxY + 2);//Se para hasta el nodo mas a la izquierda del árbol construye primero el subarbol izq porque sus valores en X son menores
	al_draw_circle((10 + auxX - auxY) * 10, (15 + auxY) * 10, 15, al_map_rgb(255, 255, 0), 3.0);
	//al_flip_display();
	al_draw_textf(font1, al_map_rgb(255, 255, 40), (10 + auxX - auxY) * 10, (15 + auxY) * 10, ALLEGRO_ALIGN_LEFT, "%d", arbol->dato);
	al_flip_display();
	mostrararbolDigitos(arbol->der, auxY + 2);//Se para hasta el nodo mas a la derecho del árbol

}

void avlTree::displayALLEGRO(avl_node *ptr, int level)
{
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	ALLEGRO_FONT *font1 = al_load_ttf_font("arial.ttf", 11, 0);
	al_draw_text(font1, al_map_rgb(230, 0, 38), 100, 20, ALLEGRO_ALIGN_LEFT, "ARBOLES AVL ");
	int i;
	if (ptr != NULL)
	{
		auxX += 5;//variable que permite posicionarse en el eje X
		displayALLEGRO(ptr->left, level + 2);//Se para hasta el nodo mas a la izquierda del árbol construye primero el subarbol izq porque sus valores en X son menores
		al_draw_circle((10 + auxX - level) * 10, (15 + level) * 10, 15, al_map_rgb(255, 255, 0), 3.0);
		//al_flip_display();
		al_draw_textf(font1, al_map_rgb(255, 255, 40), (10 + auxX - level) * 10, (15 + level) * 10, ALLEGRO_ALIGN_CENTRE, "%d", ptr->data);
		al_flip_display();
		displayALLEGRO(ptr->right, level + 2);//Se para hasta el nodo mas a la derecho del árbo
	}
}
//MOSTRAR
void mostrarArbol(Nodo *arbol, int auxY)
{
	//auxY es el nivel del arbol
	if (arbol == NULL) {//Arbol vacio nada que mostrar
		return;
	}
	auxX += 5;//variable que permite posicionarse en el eje X
	mostrarArbol(arbol->izq, auxY + 2);//Se para hasta el nodo mas a la izquierda del árbol construye primero el subarbol izq porque sus valores en X son menores
	gotoxy(10 + auxX - auxY, 14 + auxY);//posiciona el nodo segun sus variables en X y en Y
	cout << "___";
	gotoxy(10 + auxX - auxY, 15 + auxY);
	cout << "|" << arbol->dato << "|" << endl << endl << endl;//Muestra el dato del nodo respectivo
	mostrarArbol(arbol->der, auxY + 2);//Se para hasta el nodo mas a la derecho del árbol
									   //Se debe tener el cuenta el funcionamiento de la recursividad la cual implementa una pila para almacenar las instrucciones
}//

void preorden(Nodo *arbol) {
	if (arbol == NULL) {
		return;
	}
	cout << arbol->dato << " ";
	preorden(arbol->izq);
	preorden(arbol->der);
}
void inorden(Nodo *arbol) {
	
	if (arbol == NULL) {
		return;
	}
	else {
		inorden(arbol->izq);
		cout << arbol->dato << " ";		
		inorden(arbol->der);
	}

	
	
}
void posorden(Nodo *arbol) {
	std::stringstream st;
	if (arbol == NULL) {
		return;
	}
	else {
		posorden(arbol->izq);
		posorden(arbol->der);
		cout << arbol->dato << " ";		
	}
	st << arbol->dato;
	std::string numberAsString(st.str());
	inf = numberAsString;
}
bool banderaNumero;
//MENU

void menuOpciones() {
	string aux1;
	nVal = 3;
	nPointer = 4;
	int opcion;
	ALLEGRO_DISPLAY *display = NULL;
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return;
	}

	display = al_create_display(1200, 600);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return;
	}
	int n = 0;
	int cont = 0;
	int o = 0;
	char **num = (char**)malloc(20 * sizeof(char*));
	for (int j = 0; j<20; j++) {
		*(&(*num) + j) = (char *)malloc(20 * sizeof(char*));
	}
	//int opcion = 0;
	cont++;
	avlTree avl;
	bool bandera = false;
	do {

		system("cls");

		gotoxy(37, 3);//coodenadas XyY
		cout << "\tMENU  DE OPCIONES \n";
		gotoxy(15, 7);//coodenadas XyY
		cout << "  Ingreso \n";
		gotoxy(15, 8);
		cout << "  Mostrar Arboles Binarios\n";
		gotoxy(15, 9);
		cout << "  Arboles B\n";
		gotoxy(15, 10);
		cout << "  Arboles B+\n";
		gotoxy(15, 11);
		cout << "  Arboles AVL\n";
		gotoxy(15, 12);
		cout << "  Imagen\n";
		gotoxy(15, 13);
		cout << "  QR\n";
		gotoxy(15, 14);
		cout << "  PDF\n";
		gotoxy(15, 15);
		cout << "  MONGO\n";
		gotoxy(15, 16);
		cout << "  BACKUP\n";
		gotoxy(15, 17);
		cout << "  AYUDA\n";
		gotoxy(15, 18);
		cout << "  SALIR \n";

		ifstream fe("datos.txt");
		string cadena;
		string cadenaT;
		opcion = menuMouse();
		system("cls");
		switch (opcion) {


		case 1:
			int numerito;
			cout << "\nDigite Numero: ";
			//cin >> n;
			sololetras(*(&(*num) + cont));
			aux1= convertirCharAString(*(&(*num) + cont));
			n = atoi(aux1.c_str());
			insertar(arbol, n, NULL);
			raiz = avl.insert(raiz, n);
			insert2(n, NULL);
			gotoxy(25, 25);
			system("pause");
			bandera = true;
		//	cout << "\nDigite Numero: "; 
		//	cin >> n;
			//soloNumeros(n);			
			break;
		case 2:
			cout << "\t\tGRAFICAR ARBOL\n";
			auxX = 0;//se debe reestablecer a 0 cada vez que se desea llamar la función
			al_clear_to_color(al_map_rgb(0, 0, 0));
			mostrararbolDigitos(arbol, 0);
			mostrarArbol(arbol, 0);
			cout << "\nInorden:"; inorden(arbol);
			cout << "\nPreorden:"; preorden(arbol);
			cout << "\nPosorden:"; posorden(arbol);
			gotoxy(25, 25);
			system("pause");
			bandera = true;
			break;
		case 3:
			gotoxy(25, 25);
			system("pause");
			bandera = true;
			break;
		case 4:
			//ARBOLES B+
			printf("Orden = %d\n", nPointer);
			printf("\n\n\n");
			bfsTraverse(Root);
			printf("\n\n\n");
			/*cout << "\nInorden :"; avl.inorder(raiz);
			cout << "\nPreorden:";	avl.preorder(raiz);
			cout << "\nPostorden:";	avl.postorder(raiz);*/
			gotoxy(25, 25);
			system("pause");
			bandera = true;
			break;
		case 5:
			//ARBOLES AVL
			cout << "Arbol Balanceado AVL:" << endl;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			avl.displayALLEGRO(raiz, 1);
			avl.display(raiz, 1);
			/*cout << "\nInorden :"; avl.inorder(raiz);
			cout << "\nPreorden:";	avl.preorder(raiz);
			cout << "\nPostorden:";	avl.postorder(raiz);*/
			gotoxy(25, 25);
			system("pause");
			bandera = true;
			break;
		case 6:
			//IMAGEN
			cout << "***********************Imagen en consola*************************" << endl;
			ShellExecute(NULL, TEXT("open"), TEXT("C:\\Users\\DANIELAROSERO\\Documents\\GitHub\\GabrielaRosero_Tareas_Proyectos\\Proyecto_3erParcial\\imagen.exe"), NULL, NULL, SW_SHOWNORMAL);
			//codigo inestable, solo en dev me esta funcionando "mejor".
			gotoxy(25, 25);
			system("pause");
			bandera = true;
			break;
		case 7:
			//QR
			while (!fe.eof()) {
				fe >> cadena;
				cadenaT = cadenaT + cadena + " ";
			}
			fe.close();
			generarQrBasico(convertirStringAChar(cadenaT));
			//gotoxy(25, 25);
			system("pause");
			bandera = true;
			break;
		case 8:
			//PDF
			generarPDF();
			gotoxy(25, 25);
			system("pause");
			bandera = true;
			break;
		case 9:
			//MONGO
			gotoxy(25, 25);
			system("pause");
			bandera = true;
			break;
		case 10:
			//BACKUP
			gotoxy(25, 25);
			system("pause");
			bandera = true;
			break;
		case 11:
			//AYUDA
			cout << "\n\n Generando...... ";
			ShellExecute(NULL, TEXT("open"), TEXT("C:\\Users\\DANIELAROSERO\\Documents\\GitHub\\GabrielaRosero_Tareas_Proyectos\\Proyecto_3erParcial\\ayuda.chm"), NULL, NULL, SW_SHOWNORMAL);
			gotoxy(25, 25);
			system("pause");
			bandera = true;
			break;
		case 12:
			//Salir
			Salida();
			bandera = false;
			gotoxy(25, 25);
			break;
		}

	} while (bandera != false);
}
string convertirCharAString(char *dato) {
	string auxDato = dato;
	return auxDato;
}
void sololetras(char *aux1) {
	/*me recibe la direccion de lo que estoy escribiendo*/
	int i = 0;
	while (aux1[i] != 13)//13 es el ascii de enter
								/*no acepta nombres que sean menores a tres letras*/
	{
		aux1[i] = _getch();//valida letra por letra
						   /* solo me acepta letras mayusculas y minusculas*/
		if ( (aux1[i] >= 48 && aux1[i] <= 57) && i<10)
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
void insertInParentNode(node *n, int kprime, node *nprime) {

	if (n->esRaiz) {
		Root = getNuevoNodo(false, true);
		n->esRaiz = false;

		Root->child.push_back(n);
		Root->child.push_back(nprime);
		Root->value.push_back(kprime);
		n->par = Root;
		nprime->par = Root;
	}
	else {
	
		node *p = n->par;



		int i;
		for (i = 0; i<p->value.size(); i++) {
			if (p->value[i]>kprime) break;
		}
		int tmpK;
		node *tmpP;

		for (int j = i; j<p->value.size(); j++) {
			tmpK = p->value[j];
			tmpP = p->child[j + 1];

			p->value[j] = kprime;
			p->child[j + 1] = nprime;

			kprime = tmpK;
			nprime = tmpP;
		}
		p->value.push_back(kprime);
		p->child.push_back(nprime);
		nprime->par = p;

		if (p->child.size()>nPointer) {
			node *pprime = getNuevoNodo(false, false);
			int nbytwoceil = (nPointer + 1) / 2;
			int kdoubleprime = p->value[nbytwoceil - 1];
			for (i = nbytwoceil; i<p->value.size(); i++) {
				pprime->child.push_back(p->child[i]);
				p->child[i]->par = pprime;
				pprime->value.push_back(p->value[i]);
			}
			pprime->child.push_back(p->child[i]);
			p->child[i]->par = pprime;


			p->value.erase(p->value.begin() + nbytwoceil - 1, p->value.end());
			p->child.erase(p->child.begin() + nbytwoceil, p->child.end());

			insertInParentNode(p, kdoubleprime, pprime);
		}
	}

}
void generarPDF() {
	//Generar pdf

	//Declaracion variables para el manejo de ficheros
	ofstream archivo;
	ofstream archivoP;
	ofstream fechas;
	limpiar();
	ofstream fs("Datos.txt");
	limpiar();
	fs << "**********************EXPRESION INGRESADA*******************" << endl << endl;
	fs << " La expresión ingresada fue : " << endl << endl;
	fs << inf << endl;
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



void insertInNodoHoja(node *leafNode, int k, node *p) {
	int i;
	for (i = 0; i<leafNode->value.size(); i++) {
		if (k<leafNode->value[i]) break;
	}
	int tmpK;
	node *tmpP;

	for (int j = i; j<leafNode->value.size(); j++) {
		tmpP = leafNode->child[j];
		tmpK = leafNode->value[j];

		leafNode->child[j] = p;
		leafNode->value[j] = k;

		p = tmpP;
		k = tmpK;
	}
	leafNode->child.push_back(p);
	leafNode->value.push_back(k);

}


void insert2(int k, node *p) {
	node *leafNode;
	if (Root == NULL) {
		Root = getNuevoNodo(true, true);
		leafNode = Root;
	}
	else leafNode = getTargetNode(Root, k);

	//printf("dbg: target node content:\n");
	//if(leafNode->value.size()>0) bfsTraverse(leafNode);

	int keyValueCount = leafNode->value.size();
	if (keyValueCount<nVal) insertInNodoHoja(leafNode, k, p);
	else {

		//printf("dbg: reached in else1\n");
		node* leafNode2 = getNuevoNodo(true, false);
		insertInNodoHoja(leafNode, k, p);

		//printf("dbg: inserted in leaf node\n");
		// printf("dbg: content\n");
		//bfsTraverse(leafNode);

		leafNode2->last = leafNode->last;
		leafNode2->par = leafNode->par;

		leafNode->last = leafNode2;
		int nbytwoceil = (nPointer + 1) / 2;

		for (int i = nbytwoceil; i<nPointer; i++) {
			leafNode2->child.push_back(leafNode->child[i]);
			leafNode2->value.push_back(leafNode->value[i]);
		}
		leafNode->value.erase(leafNode->value.begin() + nbytwoceil, leafNode->value.end());
		leafNode->child.erase(leafNode->child.begin() + nbytwoceil, leafNode->child.end());



		int kprime = leafNode2->value[0];
		insertInParentNode(leafNode, kprime, leafNode2);
	}
}
void valueOfNodeInBox(node* tNode) {
	printf(" [");
	int i;
	for (i = 0; i<tNode->value.size() - 1; i++) {
		printf("%d|", tNode->value[i]);
	}
	if (tNode->value.size()>0) printf("%d]", tNode->value[i]);
	//printf(" ");
}




void bfsTraverse(node *tNode) {

	q.push(pNode(tNode, true));
	while (!q.empty()) {
		pNode p = q.front();
		//printf("  Got pNode ");
		node *temp = p.tNode;
		q.pop();
		valueOfNodeInBox(temp);
		//printf(" printed temp ");
		if (p.nl) printf("\n");
		int i;
		if (!temp->leaf) {
			for (i = 0; i<temp->child.size() - 1; i++) {
				q.push(pNode(temp->child[i], false));
			}
			//printf(" inserted second last child  ");
			if (p.nl) q.push(pNode(temp->child[i], true));
			else q.push(pNode(temp->child[i], false));
			//printf(" inserted  last child  ");
		}

	}
}




bool tooFewEntry(node *N) {

	if (N->leaf) {
		int minV = nPointer / 2;
		if (N->value.size()<minV) return true;
	}
	else {
		int minC = (nPointer + 1) / 2;
		if (N->child.size()<minC) return true;
	}
	return false;
}



bool isCoalesce(node *N, node *Nprime) {
	if (N->leaf) {
		if (nVal >= (N->value.size() + Nprime->value.size())) return true;
		return false;
	}
	if (nPointer >= (N->child.size() + Nprime->child.size())) return true;
	return false;
}

//ABOLES AVL
int avlTree::height(avl_node *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

int avlTree::diff(avl_node *temp)
{
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	int b_factor = l_height - r_height;
	return b_factor;
}


avl_node *avlTree::rr_rotacion(avl_node *parent)
{
	avl_node *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

avl_node *avlTree::ll_rotacion(avl_node *parent)
{
	avl_node *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

avl_node *avlTree::lr_rotacion(avl_node *parent)
{
	avl_node *temp;
	temp = parent->left;
	parent->left = rr_rotacion(temp);
	return ll_rotacion(parent);
}

avl_node *avlTree::rl_rotacion(avl_node *parent)
{
	avl_node *temp;
	temp = parent->right;
	parent->right = ll_rotacion(temp);
	return rr_rotacion(parent);
}

avl_node *avlTree::balance(avl_node *temp)
{
	int bal_factor = diff(temp);
	if (bal_factor > 1)
	{
		if (diff(temp->left) > 0)
			temp = ll_rotacion(temp);
		else
			temp = lr_rotacion(temp);
	}
	else if (bal_factor < -1)
	{
		if (diff(temp->right) > 0)
			temp = rl_rotacion(temp);
		else
			temp = rr_rotacion(temp);
	}
	return temp;
}

avl_node *avlTree::insert(avl_node *raiz, int value)
{
	if (raiz == NULL)
	{
		raiz = new avl_node;
		raiz->data = value;
		raiz->left = NULL;
		raiz->right = NULL;
		return raiz;
	}
	else if (value < raiz->data)
	{
		raiz->left = insert(raiz->left, value);
		raiz = balance(raiz);
	}
	else if (value >= raiz->data)
	{
		raiz->right = insert(raiz->right, value);
		raiz = balance(raiz);
	}
	return raiz;
}

void avlTree::display(avl_node *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == raiz)
			cout << "Raiz -> ";
		for (i = 0; i < level && ptr != raiz; i++)
			cout << "        ";
		cout << "[" << ptr->data << "]";
		display(ptr->left, level + 1);
	}
}

void avlTree::inorder(avl_node *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	cout << tree->data << "  ";
	inorder(tree->right);
}

void avlTree::preorder(avl_node *tree)
{
	if (tree == NULL)
		return;
	cout << tree->data << "  ";
	preorder(tree->left);
	preorder(tree->right);

}

void avlTree::postorder(avl_node *tree)
{
	if (tree == NULL)
		return;
	postorder(tree->left);
	postorder(tree->right);
	cout << tree->data << "  ";
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