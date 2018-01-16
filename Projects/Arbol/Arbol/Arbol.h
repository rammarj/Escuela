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

	Nodo<type>* inOrder(Nodo<type>* raiz, type* dato);
	Nodo<type>* posOrder(Nodo<type>* raiz, type* dato);
	Nodo<type>* preOrder(Nodo<type>* raiz, type* dato);

	Nodo<type>* preOrderEliminar(Nodo<type>* raiz, type* dato, bool *lado);
	Nodo<type>* getUltimoNodo(Nodo<type>* nodo_inicial,bool lado);//lado true si debe buscar en el lado izquierdo

public:
	enum IMPRIMIR
	{
		IMP_INORDER, IMP_PREORDER, IMP_POSORDER
	};
	Arbol();
	bool agregar(type dato, type buscar, bool lado);
	Nodo<type>* buscarNodoInOrder(type* dato);
	Nodo<type>* buscarNodoPosOrder(type* dato);
	Nodo<type>* buscarNodoPreOrder(type* dato);
	void limpiar();
	//impresion
	Lista<type>* getDatos(enum IMPRIMIR metodo_impresion);

	bool eliminar(type dato);

	~Arbol();
};

#endif