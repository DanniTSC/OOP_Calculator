#include "Calcul.h"
#pragma once
#include<iostream>
#include<string>
#include<cmath>
//Faza 1 versiunea finala
using namespace std;

int Calcul::nrOperatiiEfectuate = 0;

Calcul::Calcul() : rezultate(nullptr), nrRezultate(0) {}

Calcul::Calcul(double* rezultate, int nrRezultate)
{
	if (rezultate != nullptr && nrRezultate > 0)
	{
		this->nrRezultate = nrRezultate;
		this->rezultate = new double[nrRezultate];
		for (int i = 0; i < nrRezultate; i++)
		{
			this->rezultate[i] = rezultate[i];
		}
	}
	else
	{
		this->rezultate = nullptr;
		this->nrRezultate = 0;
	}
}

Calcul::~Calcul()
{
	{
		if (rezultate != nullptr)
		{
			delete[] this->rezultate;
			this->rezultate = nullptr;
		}
	}
}

void Calcul::setRezultate(double* rezultat, int nrRezultate)
{
	if (rezultat != nullptr && nrRezultate > 0)
	{
		if (this->rezultate)
		{
			delete[] rezultate;
		}
		this->nrRezultate = nrRezultate;
		this->rezultate = new double[nrRezultate];
		for (int i = 0; i < nrRezultate; i++)
		{
			this->rezultate[i] = rezultat[i];
		}

	}
	else
	{
		this->rezultate = nullptr;
		this->nrRezultate = 0;
	}

}

double* Calcul::getRezultate()
	{

		return this->rezultate;

	}

int Calcul::getNrRezultate()
{
		return this->nrRezultate;	
}

void Calcul::setNrRezultate(int nrRez)
{
	this->nrRezultate = nrRez;
}

Calcul::Calcul(const Calcul& c)
{
	if (c.rezultate != nullptr && c.nrRezultate > 0)
	{
		this->nrRezultate = c.nrRezultate;
		this->rezultate = new double[nrRezultate];
		for (int i = 0; i < c.nrRezultate; i++)
		{
			this->rezultate[i] = c.rezultate[i];
		}
	}
	else
	{
		this->rezultate = nullptr;
		this->nrRezultate = 0;
	}

}

Calcul& Calcul::operator=(const Calcul& c)
{
	if (this == &c)
	{
		throw exception("autoasignare");
	}

	if (c.rezultate != nullptr && c.nrRezultate > 0)
	{
		if (c.rezultate)
		{
			delete[] rezultate;
		}
		this->nrRezultate = c.nrRezultate;
		this->rezultate = new double[nrRezultate];
		for (int i = 0; i < c.nrRezultate; i++)
		{
			this->rezultate[i] = c.rezultate[i];
		}
	}
	else
	{
		this->rezultate = nullptr;
		this->nrRezultate = 0;
	}

	return *this;
}

double Calcul::efectuareOperatie(const double numere[], const char operatori[], int nrNumere, int nrOperatori)
{
	if (nrNumere == 0)
	{
		throw exception("Niciun numar de calculat");
	}

	double rezultat = numere[0];
	for (int i = 0; i < nrNumere - 1; ++i)
	{
		switch (operatori[i])
		{
		case '+':
			rezultat += numere[i + 1];
			cout << "Rezultat intermediar: " << rezultat << endl;
				break;
		case '-':
			rezultat -= numere[i + 1];
			cout << "Rezultat intermediar: " << rezultat << endl;
			break;
		case '/':
			if (numere[i + 1] == 0)
			{
				cout << "eroare impartire la 0";
				throw exception("impartire la 0");
			}
			rezultat /= numere[i + 1];
			cout << "Rezultat intermediar: " << rezultat << endl;
			break;
		case '*':
			rezultat *= numere[i + 1];
			cout << "Rezultat intermediar: " << rezultat << endl;
			break;
			default:
				throw exception("operator necunoscut");
				
		}
	}
	return rezultat;
}
//adauga un nr la toate rezultatele din obj calcul
Calcul Calcul::operator+(double numar)
{
	Calcul temporar;
	temporar.rezultate = new double[nrRezultate];
	temporar.nrRezultate = nrRezultate;
	for (int i = 0; i < nrRezultate; ++i) {
		temporar.rezultate[i] = rezultate[i] + numar;
	}
	return temporar;
}

void Calcul::adaugaRezultatIntermediar(double rezultat)
{
		double* temp = new double[nrRezultate];
		for (int i = 0; i < nrRezultate; i++)
		{
			temp[i] = rezultate[i];
		}
		delete[] rezultate;
		rezultate = new double[nrRezultate + 1];
		for (int i = 0; i < nrRezultate; i++)
		{
			rezultate[i] = temp[i];
		}
		rezultate[nrRezultate] = rezultat;
		delete[] temp;
		nrRezultate++;
}

bool Calcul::operator!()
{
	if (nrRezultate == 0)
	{
		return true;
	}

}

istream& operator>>(istream& i, Calcul& c)
{
	cout << "nrRezultate";
	i >> c.nrRezultate;
	if (c.nrRezultate < 0) {
		cout << "nr rezultate trebuie sa fie >0";
		throw exception();
	}
	cout << "dati rezultate:";

	if (c.rezultate)
	{
		delete[] c.rezultate;
	}

	c.rezultate = new double[c.nrRezultate];

	for (int j = 0; j < c.nrRezultate; j++)
	{
		i >> c.rezultate[j];
	}
	return i;
}

ostream& operator<<(ostream& o, Calcul c)
{
	if (c.rezultate != nullptr && c.nrRezultate > 0)
	{
		o << "Rezultate:";
		for (int i = 0; i < c.nrRezultate; i++)
		{
			o << c.rezultate[i] << " ";
		}
		o << "nr Rezultate:" << c.nrRezultate << endl;
	}
	else
	{
		o << "Calculul nu are rezultate";
	}
	return o;
}