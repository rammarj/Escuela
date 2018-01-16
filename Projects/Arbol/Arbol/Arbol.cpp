#include "stdafx.h"
#include "Arbol.h"
#include <iostream>

using namespace std;

template <class type>
Arbol<type>::Arbol()
{
	this->raiz = NULL;
	this->aux = new Lista<type>();
}
/*agregar*/
template <class type>
bool Arbol<type>::agregar(type dato, type buscar, bool lado){
	/*
	if (buscarNodoInOrder(new type(dato)) != NULL){
		return false;
	}
	*/
	if (this->raiz == NULL)
	{
		this->raiz = new Nodo<type>(new type(dato));
		return (true);
	}
	else
	{
		Nodo<type> *padre = buscarNodoInOrder(new type(buscar));	
		{
			Nodo<type> *nuevo = new Nodo<type>(new type(dato));//Crear el nuevo nodo
			if (lado && padre->izquierdo == NULL){ //Si lado es igual a true se va ir al lado izquierdo, si izquierdo igual a NULL
				padre->izquierdo = nuevo;//Crea nodo hijo izquierdo
				return true;
			}
			else if (!lado && padre->derecho == NULL){//Si lado es igual a false se va ir al lado derecho, y lado derecho igual a NULL
				padre->derecho = nuevo;//Crea nodo hijo derecho
				return true;
			}
		}
	}
	return false;
}
//busqueda INORDER [llama al metodo recursivo]
template <class type>
Nodo<type>* Arbol<type>::buscarNodoInOrder(type* dato){
	return inOrder(this->raiz, dato);
}
//busqueda inorder 
template <class type>
Nodo<type>* Arbol<type>::inOrder(Nodo<type>* raiz, type* dato){
	if (raiz != NULL)//si no es nulo
	{
		if (raiz->izquierdo != NULL)inOrder(raiz->izquierdo, dato); //recorrer rama derecha
		if (raiz->dato == dato)//comparar el dato buscado
		{
			return raiz;//retornar el nodo que contiene el dato
		}
		if (raiz->derecho != NULL)inOrder(raiz->derecho, dato);//buscar en rama izquierda
	}
	else{
		return NULL;
	}
}

template <class type>
Nodo<type>* Arbol<type>::posOrder(Nodo<type>* raiz, type* dato){
	if (raiz != NULL)//si no es nulo
	{
		if (raiz->izquierdo != NULL)posOrder(raiz->izquirdo, dato); //recorrer rama derecha
		if (raiz->derecho != NULL)posOrder(raiz->derecho, dato);//buscar en rama izquierda
		if (raiz->dato == dato)//comparar el dato buscado
		{
			return raiz;//retornar el nodo que contiene el dato
		}
	}else{
		return NULL;
	}
}

template <class type>
Nodo<type>* Arbol<type>::preOrder(Nodo<type>* raiz, type* dato){
	if (raiz != NULL)//si no es nulo
	{
		if (raiz->dato == dato)//comparar el dato buscado
		{
			return raiz;//retornar el nodo que contiene el dato
		}
		if (raiz->izquierdo != NULL)preOrder(raiz->izquierdo, dato);//buscar en rama izquierda
		if (raiz->derecho != NULL)preOrder(raiz->derecho, dato); //recorrer rama derecha		
	}
	else{
		return NULL;
	}
}

template <class type>
Nodo<type>* Arbol<type>::preOrderEliminar(Nodo<type>* raiz, type *dato, bool* lado){
	Nodo<type> *derecho, *izquierdo;
	if (raiz == this->raiz)
	{
		*lado = false;
		return raiz;
	}

	if (raiz != NULL)//si no es nulo
	{
		derecho = raiz->derecho;
		izquierdo = raiz->izquierdo;


		if (*dato == *(izquierdo->dato))//comparar el dato buscado
		{
			*lado = true;
			return raiz;//retornar el nodo que contiene el dato
		}
		else if (*dato == *(derecho->dato))
		{
			*lado = false;
			return raiz;
		}

		if (raiz->izquierdo != NULL)preOrderEliminar(raiz->izquierdo, dato,lado);//buscar en rama izquierda
		if (raiz->derecho != NULL)preOrderEliminar(raiz->derecho, dato,lado); //recorrer rama derecha		
	}
	return NULL;
}

template <class type>
void Arbol<type>::limpiar(){
	this->raiz = NULL;
	delete this->raiz;
}

template <class type>
bool Arbol<type>::eliminar(type dato){
	//preorder
	Nodo<type> *padre = NULL, *aux = NULL, *aux2 = NULL;
	bool lado = false;
	padre = preOrderEliminar(this->raiz, new type(dato), &lado);
	if (this->raiz == padre)
	{
		aux = this->raiz;
	}
	else{
		if (lado) //si el nodo a eliminar está en el lado izquierdo
			aux = padre->izquierdo;
		else //si está en el lado derecho
			aux = padre->derecho;
	}
	//verificacion
	if (aux->derecho == NULL) //si no tiene hijo derecho
	{
		if (aux->izquierdo == NULL){ //si no tiene hijo izquierdo [NINGUNO DE LOS DOS HIJOS]
			//
			if (lado) //si el lado en que está el numero buscado es en el hijo izquierdo
			{
				padre->izquierdo = NULL; //el padre lo elimina quitando el link en el izquierdo
			}
			else{
				padre->derecho = NULL; //si no es izquierdo ha de ser el derecho
			}
			aux = NULL;
			delete aux;
		}
		else{//si el hijo izquierdo existe
			aux2 = aux->izquierdo;//hijo izquierdo del nodo a eliminar
			aux->izquierdo = aux2->izquierdo;
			aux->derecho = aux2->derecho;
			aux->dato = aux2->dato;
			aux2 = NULL;	
			delete aux2;
		}
			
	}
	else
	{//si tiene hijo derecho
			if (aux->izquierdo == NULL) //TIENE hijo derecho pero no el izquierdo
			{
				aux2 = aux->derecho;
				aux->derecho = aux2->derecho;
				aux->izquierdo = aux2->izquierdo;
				aux->dato = aux2->dato;
				aux2 = NULL;
				delete aux2;
			}
			else{//si tiene los dos hijos
				/*if (aux->izquierdo->derecho == NULL)
				{
					if (aux->izquierdo->izquierdo == NULL)
					{
						aux2 = aux->izquierdo;
						aux->dato = aux2->dato;
						aux->izquierdo = NULL;
						delete aux2;
					}
					else{

					}
				}
				aux2 = getUltimoNodo(aux->izquierdo, false); //obtengo el nodo a eliminar
				//{nodo mas a la derecha de la parte izquierda} aux2 va a ser el nodo a intercambiar con el que se eliminará
				padre = preOrderEliminar(this->raiz, *(aux2->dato), lado);//busca el padre del nodo a intercambiar info. con el
				//nodo a eliminar
				padre->derecho = aux2->izquierdo;
				//aux->dato = aux2->dato;
				//aux->derecho = aux2->izquierdo;
				delete aux2;*/
			}
		}
		
	return false;
}

template <class type>
void Arbol<type>::imprimirInOrder(Nodo<type>* raiz){
	if (raiz != NULL)//si no es nulo
	{
		if (raiz->izquierdo != NULL)imprimirInOrder(raiz->izquierdo); 
		this->aux->add(*(raiz->getDato()));
		if (raiz->derecho != NULL)imprimirInOrder(raiz->derecho);
	}
}

template <class type>
void Arbol<type>::imprimirPreOrder(Nodo<type>* raiz){
	if (raiz != NULL)//si no es nulo
	{
		this->aux->add(*(raiz->getDato()));
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
		this->aux->add(*(raiz->getDato()));
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
Nodo<type>* Arbol<type>::getUltimoNodo(Nodo<type>* nodo_inicial, bool lado){
	Nodo<type>* aux = nodo_inicial;
	if (lado)
	{
		while (aux->izquierdo != NULL)
		{
			aux = aux->izquierdo;	
		}
	}
	else{
		while (aux->derecho != NULL)
		{
			aux = aux->derecho;
		}
	}
	return aux;
}

template <class type>
Arbol<type>::~Arbol()
{
	delete this->raiz;
}
