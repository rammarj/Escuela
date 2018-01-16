#include "stdafx.h"
#include "Lista.h"

template<class tipo>
Lista<tipo>::Lista()
{
	this->first = nullptr;
	this->size = 0;
	this->aux = nullptr;
}

template<class tipo>
NodoLista<tipo>* Lista<tipo>::getLast(NodoLista<tipo>* n){
	if (n != nullptr){
		this->aux = n->getNext();
		if (aux)
		{
			getLast(this->aux);
		}
		else{
			return n;
		}
	}
	else{
		return aux;
	}
}

template<class tipo>
NodoLista<tipo>* Lista<tipo>::getNodeAt(int index){
	NodoLista<tipo>* ret = this->first;
	if (index >= 0 && index<this->size)
	{
		for (size_t i = 0; i < index; i++)
		{
			ret = ret->getNext();
		}
	}
	return ret;
}

template<class tipo>
void Lista<tipo>::add(tipo val){
	NodoLista<tipo>* nuevo = new NodoLista<tipo>();
	if (nuevo){
		nuevo->setData(val);
		if (this->size == 0)
		{
			this->first = nuevo;
		}
		else{
			NodoLista<tipo>* last = nullptr;
			last = getLast(this->first);
			last->setNext(nuevo);
			nuevo->setAfter(last);
		}
		this->size++;
	}
}

template<class tipo>
int Lista<tipo>::indexOf(tipo val){
	for (size_t i = 0; i < this->size; i++)
	{
		int current = getValueAt(i);
		if (current == val)
		{
			return i;
		}
	}
	return -1;
}

template<class tipo>
tipo Lista<tipo>::getValueAt(int index){
	NodoLista<tipo>* ret = getNodeAt(index);
	return ret->getData();
}
template<class tipo>

void Lista<tipo>::setValueAt(int index, tipo val){
	getNodeAt(index)->setData(val);
}

template<class tipo>
bool Lista<tipo>::isEmpty(){
	return(this->first==nullptr);
}

template<class tipo>
void Lista<tipo>::removeElementAt(int index){
	if (index>=0 && index<this->size)
	{
		NodoLista<tipo>* del = nullptr;
		if (index>0)
		{
			NodoLista<tipo>* ret = getNodeAt(index - 1);
			del = ret->getNext();
			if (del->getNext())
			{
				ret->setNext(del->getNext());
				del->getNext()->setAfter(ret);
			}
			delete del;
		}
		else if (index == 0)
		{
			del = getNodeAt(index);
			this->first = del->getNext();
			delete del;
		}
		this->size--;
	}
}

template<class tipo>
void Lista<tipo>::insertElementAt(unsigned int index, tipo data){
	if (index >= 0){
		NodoLista<tipo>* nuevo = new NodoLista<tipo>();
		if (nuevo)
		{
			nuevo->setData(data);
			NodoLista<tipo>* pos = getNodeAt(index);
			if (pos){
				NodoLista<tipo>* ant = pos->getAfter();
				nuevo->setAfter(ant);
				nuevo->setNext(pos);
				pos->setAfter(nuevo);
				if (index>0)
				{
					ant->setNext(nuevo);
				}
			}
			if (index == 0){
				this->first = nuevo;
			}
			this->size++;
		}
	}
}

template<class tipo>
unsigned int Lista<tipo>::getSize(){
	return(this->size);
}

template<class tipo>
void Lista<tipo>::clear(){
	if (!isEmpty() && this->size>0)
	{
		removeElementAt(0);
		clear();
	}
}

template<class tipo>
int Lista<tipo>::pivot(int izq, int der){
	int i;
	int pivote, valor_pivote;
	int aux;
	pivote = izq;
	valor_pivote = getValueAt(pivote);
	for (i = izq + 1; i <= der; i++){
		if (getValueAt(i) < valor_pivote){
			pivote++;
			aux = getValueAt(i);
			setValueAt(i, getValueAt(pivote));
			setValueAt(pivote, aux);

		}
	}
	aux = getValueAt(izq);
	setValueAt(izq, getValueAt(pivote));
	setValueAt(pivote, aux);
	return pivote;
}

template<class tipo>
void Lista<tipo>::quickSort(int izq, int der){
	int pivote;
	if (izq < der){
		pivote = pivot(izq, der);
		quickSort(izq, pivote - 1);
		quickSort(pivote + 1, der);
	}
}


template<class tipo>
void Lista<tipo>::quick_sort(){
	quickSort(0, this->size-1);
}

template<class tipo>
void Lista<tipo>::sort_burbuja(){
	tipo aux;
	for (size_t i = 0; i < this->getSize(); i++)//numero de movimientos
	{
		for (size_t j = 0; j < (this->getSize() - 1); j++)//ordenar el contenido de la lista
		{
			if (this->getValueAt(j) > this->getValueAt((j + 1)))
			{
				aux = this->getValueAt(j);
				this->setValueAt(j, this->getValueAt((j + 1)));
				this->setValueAt((j + 1), aux);
			}
		}
	}
}

template<class tipo>
void Lista<tipo>::sort_seleccion_directa(){
	tipo menor, aux;
	int pos_menor;
	for (unsigned int i = 0; i < this->getSize(); i++)
	{
		menor = this->getValueAt(i);
		pos_menor = i;
		//buscar el menor y su posicion
		for (unsigned int j = (i + 1); j < this->getSize(); j++)
		{
			if (this->getValueAt(j) < menor)
			{
				menor = this->getValueAt(j);
				pos_menor = j;
			}
		}
		//hacer el intercambio
		aux = getValueAt(i);
		this->setValueAt(i, menor);
		this->setValueAt(pos_menor, aux);
	}
}

template<class tipo>
void Lista<tipo>::sort_insercion(){
	int i, a;
	tipo aux;
	for (i = 1; i < this->getSize(); i++) //empezar desde 1
	{
		aux = this->getValueAt(i); //guardar el valor a comparar en un auxiliar
		for (a = (i - 1); a >= 0 && this->getValueAt(a) > aux; a--)
		{
			this->setValueAt(a + 1, this->getValueAt(a)); //recorrer los elementos
		}
		this->setValueAt(a + 1, aux); //poner al elemento en su pocicion real
	}
}

template<class tipo>
Lista<int>* Lista<tipo>::find_secuencial(tipo t){
	tipo aux;
	Lista<int>* l = new Lista<int>(); //la lista de posiciones
	for (unsigned int i = 0; i < this->getSize(); i++) //recorrer toda la lista
	{
		aux = this->getValueAt(i);
		if (aux == t) //comparar si es el que se esta buscando
		{
			l->add(i); //aniadir la posicion a la lista
		}
	}
	return l;
}

template<class tipo>
Lista<int>* Lista<tipo>::find_binaria(tipo clave)
{
	Lista<int>* j = new Lista<int>();
	/*while (pos!=-1){
		j->add(pos);
		pos = busquedaBinaria(clave, pos+1);
	}*/
	for (int i = 0; i < this->getSize(); i++)
	{
		pos = busquedaBinaria(clave, i);
		if (pos != -1 && j->indexOf(pos) == -1)
		{
			j->add(pos);
		}
	}
	return j;
}

template<class tipo>
int Lista<tipo>::busquedaBinaria(tipo clave, int desde) //buscar 
{
	int izquierdo, derecho, puntomedio;
	izquierdo = desde;
	derecho = this->getSize()-1;
	while(izquierdo <= derecho)
	{
		puntomedio = (int)((izquierdo + derecho) / 2);
		if(clave == this->getValueAt(puntomedio))
		{
			return puntomedio;
		}
		else if (clave > this->getValueAt(puntomedio))
			izquierdo = puntomedio + 1;
		else
			derecho = puntomedio - 1;
	}
	return - 1;
}

template<class tipo>
Lista<tipo>::~Lista(){
	clear();
}
