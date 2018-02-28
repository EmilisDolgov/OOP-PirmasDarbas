// Vidurkis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

using std::cout; 
using std::cin; 
using std::string; 
using std::endl; 
using std::array; 
using std::fixed; 
using std::setprecision;
using std::vector;

int main()
{
	string vardas;
	string pavarde;
	bool metodas;
	bool inpmetodas;
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
	//int size = 1;
	int n{};
	//double *paz = new double[size];
	double temp;
	vector<double> paz{};
	cout << "Pazymiu gavimo budas: ivedimas(0) arba generavimas(1)" << endl;
	cin >> inpmetodas;
	int input{};
	/*while (cin >> input)
	{
		if (cin.eof())
			break;
		if (n + 1 > sizeof(paz) / sizeof(double))
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
	}*/
	if (!inpmetodas)
	{
		cout << "Pazymiai. Noredami sustabdyti vedima spauskite CTRL+Z ir Enter" << endl;
		while (cin >> input)
		{
			if (cin.eof())
				break;
			paz.push_back(input);
			n++;
		}
	}
	else
	{
		std::random_device rd;  //Will be used to obtain a seed for the random number engine
		std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		std::uniform_int_distribution<> dis(1, 10);
		cout << "Kiek skaiciu sugeneruoti?" << endl;
		cin >> n;
		for (auto i = 0; i < n; i++)
		{
			paz.push_back(dis(gen));
		}

	}
	
	if (metodas == 1)
	{
		for (auto i = 0; i < paz.size(); i++)
		{
			sum += paz[i];
		}
		vidurkis = sum / n;
	}
	else if (metodas == 0)
	{
		for (auto i = 0; i < paz.size(); i++)
		{
			for (auto j = 0; j < paz.size()-1; j++)
			{
				if (paz[j] > paz[j + 1])
				{
					temp = paz[j];
					paz[j] = paz[j + 1];
					paz[j + 1] = temp;
				}
			}
		}
		if (paz.size() % 2 == 1)
			vidurkis = paz[(paz.size() / 2 + 1)-1];
		else
			vidurkis = (paz[(paz.size()/ 2)-1] + paz[(paz.size() / 2 + 1)-1])/2;
	}
	cout << vardas << " " << pavarde << " ";
	for (auto i = 0; i < paz.size(); i++)
		cout << paz[i] << " ";
	cout << endl;
	galBalas = 0.4*vidurkis + 0.6*egz;
	cout << fixed << setprecision(2) << galBalas << endl;
	return 0;
}