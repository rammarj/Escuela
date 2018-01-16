#ifndef _ARBOL_H_
#define _ARBOL_H_

#include "NodoArbol.cpp"
#include "Lista.cpp"

template <class type>
class Arbol
{
private:
	Nodo<type>* raiz;
	Lista<type>* aux;
	void imprimirInOrder(Nodo<type>* raiz );
	void imprimirPreOrder(Nodo<type>* raiz);
	void imprimirPostOrder(Nodo<type>* raiz);
	bool buscar(Nodo<type>* raiz, type dato);
	bool agregar(Nodo<type>* raiz, type dato);


public:
	enum IMPRIMIR{IMP_INORDER, IMP_PREORDER, IMP_POSORDER};
	Arbol();
	void limpiar();
	bool buscar( type dato);
	bool agregar( type dato);
	//impresion
	Lista<type>* getDatos(enum IMPRIMIR metodo_impresion);
	~Arbol();
};

#endif