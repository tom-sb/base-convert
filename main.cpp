#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#include "lista.h"
#include "les.cpp"

int main()
{
	lista<int> lst;
	int opcion;

	while (true) {
		cout << "Seleccione una de las opciones digitando el numero que corresponde al tipo de entrada, luego presione enter." << '\n' << "1) Decimal\t2) Binario\t3) Octal\t4) Hexadecimal"<<endl;
		cin >> opcion;
		switch (opcion) {
			case 1:
				int dec;
				cout <<"n: ";
				cin >> dec;
				lst.dec_to(dec,2);
				cout <<"Binario: ";
				lst.mostrar(2);
				lst.dec_to(dec,8);
				cout <<"Octal: ";
				lst.mostrar(8);
				lst.dec_to(dec,16);
				cout <<"Hexadecimal: ";
				lst.mostrar(16);
				break;

			case 2:
				int bin;
				cin>>bin;
				while(bin>0){
					lst.insert(bin%10);
					bin=bin/10;
				}
				lst.conv_to(2);

				break;

			case 3:
				int oct;
				cin>>oct;
				while(oct>0){
					lst.insert(oct%10);
					oct=oct/10;
				}
				lst.conv_to(8);
				break;

			case 4:
				string hex;
				cin>>hex;
				int i=hex.length()-1;
				while(i != -1){
					if(hex[i]=='1')lst.insert(1);
					if(hex[i]=='2')lst.insert(2);
					if(hex[i]=='3')lst.insert(3);
					if(hex[i]=='4')lst.insert(4);
					if(hex[i]=='5')lst.insert(5);
					if(hex[i]=='6')lst.insert(6);
					if(hex[i]=='7')lst.insert(7);
					if(hex[i]=='8')lst.insert(8);
					if(hex[i]=='9')lst.insert(9);
					if(hex[i]=='a')lst.insert(10);
					if(hex[i]=='b')lst.insert(11);
					if(hex[i]=='c')lst.insert(12);
					if(hex[i]=='d')lst.insert(13);
					if(hex[i]=='e')lst.insert(14);
					if(hex[i]=='f')lst.insert(15);
					i--;
				}
				lst.conv_to(16);
				break;
		}
	}
	return 0;
}
