#include "stdafx.h"
#include "Arbol.h"
using namespace std;
template <class type>
Arbol<type>::Arbol()
{
	this->raiz = NULL;
	this->aux = new Lista<type>();
}
/*agregar*/
template <class type>
bool Arbol<type>::agregar(Nodo<type>* padre, type dato){
	if (dato < *(padre->dato))
	{
		if ((padre->izquierdo) == NULL)
		{
			type* ndat = new type(dato);
			Nodo<type>*nuevo = new Nodo<type>(ndat);
			padre->izquierdo = nuevo;
			return true;
		}
		else{
			return this->agregar((padre->izquierdo), dato);
		}
	}
	else if (dato > *(padre->dato))
	{
		if ((padre->derecho) == NULL)
		{
			type* ndat = new type(dato);
			Nodo<type>*nuevo = new Nodo<type>(ndat);
			padre->derecho = nuevo;
			return true;
		}
		else{
			return this->agregar(padre->derecho, dato);
		}
	}
	return false;
}
//busqueda
template <class type>
bool Arbol<type>::buscar(Nodo<type>* padre, type dato){
	if (dato < *(padre->dato))
	{
		if (padre->izquierdo == NULL)
			return false;
		else
			return this->buscar(padre->izquierdo, dato);
	}
	else if (dato > *(padre->dato))
	{
		if (padre->derecho == NULL)
			return false;
		else
			return this->buscar(padre->derecho, dato);
	}
	else{
		return true;
	}
}

//buscar publico {devuelve TRUE si lo encuentra, FALSE en caso contrario devuelve}
template <class type>
bool Arbol<type>::buscar(type dato){
	if (this->raiz == NULL)
		return false;
	else
		return this->buscar(this->raiz, dato);
}
//agregar publico
template <class type>
bool Arbol<type>::agregar(type dato){
	if (this->raiz == NULL)
	{
		this->raiz = new Nodo<type>(new type(dato));
		return true;
	}
	else
		return this->agregar(this->raiz, (dato));
}

template <class type>
void Arbol<type>::limpiar(){
	this->raiz = NULL;
	delete this->raiz;
}

template <class type>
void Arbol<type>::imprimirInOrder(Nodo<type>* raiz){
	if (raiz != NULL)//si no es nulo
	{
		if (raiz->izquierdo != NULL)imprimirInOrder(raiz->izquierdo); 
		this->aux->add(*(raiz->dato));
		if (raiz->derecho != NULL)imprimirInOrder(raiz->derecho);
	}
}

template <class type>
void Arbol<type>::imprimirPreOrder(Nodo<type>* raiz){
	if (raiz != NULL)//si no es nulo
	{
		this->aux->add(*(raiz->dato));
		if (raiz->izquierdo != NULL)imprimirPreOrder(raiz->izquierdo);//buscar en rama izquierda
		if (raiz->derecho != NULL)imprimirPreOrder(raiz->derecho); //recorrer rama derecha		
	}
}

template <class type>
void Arbol<type>::imprimirPostOrder(Nodo<type>* raiz ){
	if (raiz != NULL)//si no es nulo
	{
		if (raiz->izquierdo != NULL)imprimirPostOrder(raiz->izquierdo); //recorrer rama derecha
		if (raiz->derecho != NULL)imprimirPostOrder(raiz->derecho);//buscar en rama izquierda
		this->aux->add(*(raiz->dato));
	}
}

template <class type>
Lista<type>* Arbol<type>::getDatos(IMPRIMIR metodo_impresion){
	this->aux->clear();
	if (metodo_impresion == IMP_INORDER)
	{
		imprimirInOrder(this->raiz);
	}
	else if (metodo_impresion == IMP_PREORDER)
	{
		imprimirPreOrder(this->raiz);
	}
	else if (metodo_impresion == IMP_POSORDER)
	{
		imprimirPostOrder(this->raiz);
	}
	return this->aux;
}

template <class type>
Arbol<type>::~Arbol()
{
	delete this->raiz;
}
