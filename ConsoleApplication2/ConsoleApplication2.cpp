#pragma once
#include <iostream>
using namespace std;

//Ubung 9 
//a)
int Potenz(int x, int power) {
	int aux = x, var = x;
	while (power != 1) {
		aux = aux * var;
		power--;
	}
	return aux;
}

int main()
{
	cout << Potenz(2, 3);
}



