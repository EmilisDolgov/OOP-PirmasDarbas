// Vidurkis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::string; using std::endl;

int main()
{
	string vardas;
	string pavarde;
	int n{};
	bool metodas;
	double vidurkis{};
	double sum{};
	double egz{};
	double galBalas{};
	cout << "Vardas: ";
	cin >> vardas;
	cout << "Pavarde: ";
	cin >> pavarde;
	cout << "Pazymiu kiekis: ";
	cin >> n;
	cout << "Egzamino ivertinimas: ";
	cin >> egz;
	cout << "Pazymiu skaiciavimo metodas - mediana(0) ar vidurkis(1)?"<< endl;
	cin >> metodas;
	double *paz = new double[n];
	double temp;
	for (auto i = 0; i<n; i++)
	{
		cin >> paz[i];
	}
	if (metodas == 1)
	{
		for (auto i = 0; i < n; i++)
		{
			sum += paz[i];
		}
		vidurkis = sum / n;
	}
	else if (metodas == 0)
	{
		for (auto i = 0; i < n; i++)
		{
			for (auto j = 0; j < n-1; j++)
			{
				if (paz[j] > paz[j + 1])
				{
					temp = paz[j];
					paz[j] = paz[j + 1];
					paz[j + 1] = temp;
				}
			}
		}
		if (n % 2 == 1)
			vidurkis = paz[(n / 2 + 1)-1];
		else
			vidurkis = (paz[(n/ 2)-1] + paz[(n / 2 + 1)-1])/2;
	}
	cout << vidurkis << endl;
	cout << vardas << " " << pavarde << " ";
	for (auto i = 0; i < n; i++)
		cout << paz[i] << " ";
	cout << endl;
	galBalas = 0.4*vidurkis + 0.6*egz;
	cout << galBalas << endl;
	return 0;
}