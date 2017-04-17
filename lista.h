#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "nodo.h"

template <typename T>
class lista
{
	private:
		Nodo<T> *head;
		//Nodo<T> *tail;
	public:
		lista();
		//void deletelista();
		void dec_to(int, int);
		void conv_to(int);
		void filtertoshow(int deci, int n);
		void insert(int);
		void mostrar(int);
		bool vacio();
};

#endif
