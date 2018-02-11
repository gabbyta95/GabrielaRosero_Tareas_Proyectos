# ifndef NODO_H
# define NODO_H
# include <string>
using namespace std;
class Nodo {

private:
	string dato;
	Nodo *ptr_siguiente;

public:

	//Métodos
	//constructor sin parámetros
	Nodo();
	Nodo(string dato);
	void setDato(string dato);
	string getDato();
	void setPtr_siguiente(Nodo *ptr_siguiente);
	Nodo* getPtr_Siguiente();
};

# endif

