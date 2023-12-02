#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include "Calcul.h"
#include "Descompunere.h"
using namespace std;
/*
rezolvare ecuatii
*/
class Ecuatie
{
private:
	double* coeficienti;
	int nrCoef;
	const int MAX_NECUNOSCUTE = 2; // ecuatie de gradul 2 max


public:
	Ecuatie() {
		coeficienti = nullptr;
		nrCoef = 0;
	}
	
	Ecuatie(double* coeficienti, int nrCoef)
	{

		if (coeficienti != nullptr && nrCoef > 0)
		{
			this->nrCoef = nrCoef;
			this->coeficienti = new double[nrCoef];
			for (int i = 0; i < this->nrCoef; i++)
			{
				this->coeficienti[i] = coeficienti[i];

			}
		}
		else
		{
			this->coeficienti = nullptr;
			this->nrCoef = 0;
		}
	}

	Ecuatie(const Ecuatie& e)
	{

		if (coeficienti != nullptr && nrCoef > 0)
		{
			this->nrCoef = nrCoef;
			this->coeficienti = new double[nrCoef];
			for (int i = 0; i < this->nrCoef; i++)
			{
				this->coeficienti[i] = coeficienti[i];

			}
		}
		else
		{
			this->coeficienti = nullptr;
			this->nrCoef = 0;
		}
	}

	Ecuatie& operator=(const Ecuatie& e)
	{
		if (this == &e)
		{
			throw exception("autoasignare");
		}

		if (e.coeficienti != nullptr && e.nrCoef > 0)
		{
			if (this->coeficienti)
			{
				delete[] this->coeficienti;
			}
			this->nrCoef = nrCoef;
			this->coeficienti = new double[nrCoef];
			for (int i = 0; i < nrCoef; i++)
			{
				this->coeficienti[i] = e.coeficienti[i];
			}
		}
		else
		{
			this->coeficienti = nullptr;
			this->nrCoef = 0;
		}
		return *this;
	}

	void setCoef(double* Coef, int nrCoeficienti)
	{
		if (Coef != nullptr && nrCoeficienti > 0) {
			if (this->coeficienti)
			{
				if (this->coeficienti)
				{
					delete[] this->coeficienti;
				}
			}
			for (int i = 0; i < nrCoeficienti; i++)
			{
				this->coeficienti[i] = Coef[i];
			}
		}
		else
		{
			this->coeficienti = nullptr;
		}
	}
	
	void setNrCoef(int nrCoeficienti) {
		if (nrCoeficienti > 0)
		{
			this->nrCoef = nrCoeficienti;
		}
		else
		{
			this->nrCoef = 0;
		}
	}

	double* getCoef()
	{
		return this->coeficienti;
	}

	int getNrCoef()
	{
		return this->nrCoef;
	}

	static bool verificaFormat(const string& ecuatie)
	{
		bool existaX = false;
		bool areOperatori = false;

		for (int i = 0; i < ecuatie.size(); i++)
		{
			if (ecuatie[i] == 'x')
			{
				existaX = true;
			}

			if (ecuatie[i] == '+' || ecuatie[i] == '-' || ecuatie[i] == '*' || ecuatie[i] == '/' || ecuatie[i] == '^')
			{
				areOperatori = true;
			}
			if (existaX && areOperatori)
			{
				return true;
			}
		}
		return false;
	}

	void rezolvaEcuatie()
	{
		double a; //ax^2
		double b; //bx
		double c; //termen liber
		
		if (nrCoef >= 1) c = coeficienti[0];
		if (nrCoef >= 2) b = coeficienti[1];
		if (nrCoef >= 3) a = coeficienti[2];

		if (nrCoef == 3 && a != 0)
		{
			double delta = b * b - 4 * a * c;
			if (delta >= 0)
			{
				double x1 = ((-b + sqrt(delta)) / (2 * a));
				double x2 = ((-b - sqrt(delta)) / (2 * a));
				cout << "solutiile sunt:" << endl << "x1=" << x1 << endl << "x2=" <<x2 << endl;
			}
			else
			{
				cout << "ecuatia nu are solutii reale delta < 0";
			}
		}
		else if (nrCoef >= 2 && b != 0)
		{
			double solutie = -c / b;
			cout << "solutia ec de grad 1 este:" << solutie << endl;
		}
		else
		{
			throw exception("ecuatie invalida");
		}
		
		
	}

	string obtineCoef()
	{

	}

	~Ecuatie()
	{
		if (this->coeficienti)
		{
			delete[] this->coeficienti;
			this->coeficienti = nullptr;
		}
	}

	friend istream& operator>>(istream& i, Ecuatie& e);
	friend ostream& operator<<(ostream& o, Ecuatie e);

	Ecuatie& operator++()
	{
		for (int i = 0; i < nrCoef; i++)
		{
			coeficienti[i]++;
		}
		return *this;
	}

	Ecuatie& operator--()
	{
		for (int i = 0; i < nrCoef; i++)
		{
			coeficienti[i]--;
		}
		return *this;
	}

	explicit operator bool() //verifica daca este de gradul 2 ecuatia
	{
		return (nrCoef == 3 || nrCoef == 2) && coeficienti[nrCoef - 1] != 0;
	}

};//end of class
istream& operator>>(istream& i, Ecuatie& e)
{
	cout << "introduceti nr coeficietni:";
	i >> e.nrCoef;
	if (e.coeficienti)
	{
		delete[] e.coeficienti;
	}

	for (int j = 0; j < e.nrCoef; j++)
	{
		i >> e.coeficienti[j];
	}
	return i;
}

ostream& operator<<(ostream& o, Ecuatie e)
{
	if (e.coeficienti != nullptr && e.nrCoef > 0)
	{
		o << "coeficienti:";
		for (int i = 0; i < e.nrCoef; i++)
		{
			o << e.coeficienti[i] << " ";
		}
	}
	else
	{
		o << "ec fara coeficienti";
	}
	
	return o;
	
}

