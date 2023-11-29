#pragma once
#include<iostream>
#include<string>
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
	static int nrEcuatiiRezolvate;
	const int MAX_NECUNOSCUTE = 2;


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

	static bool verificaFormat(const string& ecuatie)
	{
		
	}

	void rezolvaEcuatie()
	{

	}

	string obtineSolutie()
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

};//end of class
istream& operator>>(istream& i, Ecuatie& e)
{
	

}

ostream& operator<<(ostream& o, Ecuatie e)
{

}

int Ecuatie::nrEcuatiiRezolvate = 0;
