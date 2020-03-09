// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

//b)
int Reihe(int v[100], int n, int& mx) {
	int ct, ok, j;
	ct = 0;
	ok = 0;
	for (int i = 0; i < n; i++) {
		if ((v[i] >= 0 && v[i + 1] < 0) || v[i] < 0 && v[i + 1] >= 0) {
			ct++;
			ok = 1;
		}
		else {
			ok = 0;
		}
		if (mx < ct && ok == 0) {
			mx = ct;
			ct = 0;
			j = i - mx;
		}
	}
	return j;
}
int Prim(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i < n / 2 + 1; i++)
		if (n%i == 0)
			return false;
	return true;
}

void UB1_a()
{
	int n;
	cout << "n=" << ' ';
	cin >> n;
	for (int i = 0; i < n; i++)
		if (Prim(i))
			cout << i << ' ';
}
void UB1_b()
{
	int v[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int smax, ctmax, ct;
	smax = ctmax = ct = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i] > v[i - 1])
			ct++;
		if (ctmax < ct)
		{
			ctmax = ct;
			smax = i;
		}
		if (v[i] < v[i - 1])
			ct = 0;
	}
	for (int i = smax - ctmax; i < smax + 1; i++)
		cout << v[i] << ' ';
}
void UB9()
{
	cout << "Ubung 9.\na)" << Potenz(5, 3) << '\n';
	int v[] = { 8, -3, -4, 0, -1, 2, -5, -7 }, mx = 0, n = 8;
	int poz = Reihe(v, n, mx);
	cout << "b)";
	while (mx != -1) {
		cout << v[poz] << ' ';
		poz++;
		mx--;
	}
	cout << '\n';
}

int main()
{
	//UB9();
	UB1_b();
}