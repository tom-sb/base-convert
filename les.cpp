#include "lista.h"
#include "nodo.h"
#include <stddef.h>
#include <iostream>
#include <math.h>

using namespace std;

template <typename T>
int Nodo<T>::count=0;

template <typename T>
Nodo<T>::Nodo(T _valor){
	count++;
	this->valor=_valor;
	this->next=NULL;
}

template <typename T>
T Nodo<T>::getval(){
	return this->valor;
}

template <typename T>
lista<T>::lista(){
	this->head=NULL;
}

template <typename T>
bool lista<T>::vacio(){
	return (this->head==NULL);

}
     ///////////////////////////////////////////////
   /////////////////    dec to    ////////////////
 ///////////////////////////////////////////////

template <typename T>
void lista<T>::dec_to(int _valor, int base){
	while (vacio()==false){
		Nodo<T> *temp=this->head;
		this->head=this->head->next;
		delete temp;
		Nodo<T>::count--;
	}
	int i=_valor;
	while(true){
		Nodo<T> *temp =new Nodo<T>(i%base);
		if (vacio()==true){
			this->head=temp;
		}else{
			temp->next=this->head;
			this->head=temp;
		}
		i=i/base;
		if (i==0) {
			break;
		}
	}
}
    ///////////////////////////////////////////////
  /////////////////     insert    ///////////////
///////////////////////////////////////////////
template <typename T>
void lista<T>::insert(int _valor){
	Nodo<T> *temp =new Nodo<T>(_valor);
	if (vacio()==true){
		this->head=temp;
	}else{
		temp->next=this->head;
		this->head=temp;
	}
}
	///////////////////////////////////////////////
  /////////////     convert to     //////////////
///////////////////////////////////////////////
template <typename T>
void lista<T>::conv_to(int n){
	int deci;
	Nodo<T> *temp =this->head;
	int potencia= Nodo<T>::count-1;
	while(temp!=NULL){
		if (temp->getval() >= 1) {
			deci+=temp->getval() * pow(n,potencia--);
		}
		temp=temp->next;
	}
	lista<T>::filtertoshow(deci, n);
}
	///////////////////////////////////////////////
  ///////////     filter to show    /////////////
///////////////////////////////////////////////
template <typename T>
void lista<T>::filtertoshow(int deci, int n){
	cout <<"Decimal:\t"<< deci<<endl;
	switch (n) {
		case 2:	cout <<"Octal:\t\t";
				lista<T>::dec_to(deci,8);
				lista<T>::mostrar(8);
				cout <<"Hexadecimal:\t";
				lista<T>::dec_to(deci,16);
				lista<T>::mostrar(16);
				break;
		case 8:	cout <<"Binario:\t";
				lista<T>::dec_to(deci,2);
				lista<T>::mostrar(2);
				cout <<"Hexadecimal:\t";
				lista<T>::dec_to(deci,16);
				lista<T>::mostrar(16);
				break;
		case 16:cout <<"Binario:\t";
				lista<T>::dec_to(deci,2);
				lista<T>::mostrar(2);
				cout <<"Octal:\t\t";
				lista<T>::dec_to(deci,8);
				lista<T>::mostrar(8);
				break;
	}
}
    ///////////////////////////////////////////////////
  //////////////////    mostrar   ///////////////////
///////////////////////////////////////////////////
template <typename T>
void lista<T>::mostrar(int base){
	if(vacio()==true){
		cout<<"no hay nada";
	}else{

		Nodo<T> *temp =this->head;
		if (base == 16){
			switch (temp->getval()) {
				case 10: cout << "a";
					break;
				case 11: cout << "b";
					break;
				case 12: cout << "c";
					break;
				case 13: cout << "d";
					break;
				case 14: cout << "e";
					break;
				case 15: cout << "f";
					break;
				default: cout << temp->getval();
					break;
			}
		}else{
			cout<<temp->getval();
		}

		temp=temp->next;
		while(temp!=NULL){

			if (base == 16){
				switch (temp->getval()) {
					case 10: cout << "a";
						break;
					case 11: cout << "b";
						break;
					case 12: cout << "c";
						break;
					case 13: cout << "d";
						break;
					case 14: cout << "e";
						break;
					case 15: cout << "f";
						break;
					default: cout << temp->getval();
						break;
				}
			}else{
				cout<<temp->getval();
			}
			temp=temp->next;
		}
		cout<<endl;
		while (vacio()==false){
			Nodo<T> *temp=this->head;
			this->head=this->head->next;
			delete temp;
			Nodo<T>::count--;
		}
	}
}
