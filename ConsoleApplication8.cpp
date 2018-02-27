// Vidurkis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <cmath>

using std::cout; using std::cin; using std::string; using std::endl; using std::array; using std::fixed; using std::setprecision;

int main()
{
	string vardas;
	string pavarde;
	bool metodas;
	double vidurkis{};
	double sum{};
	double egz{};
	double galBalas{};
	cout << "Vardas: ";
	cin >> vardas;
	cout << "Pavarde: ";
	cin >> pavarde;
	cout << "Egzamino ivertinimas: ";
	cin >> egz;
	cout << "Pazymiu skaiciavimo metodas - mediana(0) ar vidurkis(1)?"<< endl;
	cin >> metodas;
	int size = 1;
	int n{};
	double *paz = new double[size];
	double temp;
	cout << "Pazymiai. Noredami sustabdyti vedima spauskite CTRL+Z ir Enter" << endl;
	auto i = 0;
	int input{};
	while (cin >> input)
	{
		if (cin.eof())
			break;
		if (i + 1 > sizeof(paz) / sizeof(double))
		{
			int newSize = size * 2;
			double *newArr = new double[newSize];
			for (auto i = 0; i < size; i++)
				newArr[i] = paz[i];
			paz = newArr;
			size = newSize;
			paz[n] = input;
		}
		else
			paz[n] = input;
		n++;
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
	//cout << vidurkis << endl;
	cout << vardas << " " << pavarde << " ";
	for (auto i = 0; i < n; i++)
		cout << paz[i] << " ";
	cout << endl;
	galBalas = 0.4*vidurkis + 0.6*egz;
	cout << fixed << setprecision(2) << galBalas << endl;
	return 0;
}