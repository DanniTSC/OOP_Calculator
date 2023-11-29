#pragma once
#include<iostream>
#include<string>
#include "Descompunere.h"
#include "Ecuatie.h"
using namespace std;

/*
Cu termeni si operatorii scosi din descompunere
ii iau aici pt a efectua operatiile matematice
necesare tinand cont de prioritatea operatorilor
*/

class Calcul
{
private:
	double* rezultate;
	int nrRezultate; //dimensiune vect de sus
	const double EROARE_MAX = 0.0001;
	static int nrOperatiiEfectuate;
public:

	Calcul() : EROARE_MAX(0.0001){
		rezultate = nullptr;
		nrRezultate = 0;
	}

	Calcul(double* rezultate, int nrRezultate, const double eroare): EROARE_MAX(eroare)
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

	void setRezultate(double* rezultat, int nrRezultate) {
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

	void setNrOperatiiEfectuate(int nrOpEf)
	{
		if (nrOpEf > 0)
		{
			this->nrOperatiiEfectuate = nrOpEf;
		}
		else
		{
			throw exception();
		}
	}

	double* getRezultate() {
		
			return this->rezultate;
		
	}

	int getNrRezultate() {
		return this->nrRezultate;
	}

	Calcul(const Calcul& c)
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

	Calcul& operator=(const Calcul& c)
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

	double efectuareOperatie(double operand1, double operand2, char Operator)
	{

	}

	static bool verificaOperator(char Operator)
	{

	}

	void adaugaRezultatIntermediar(double rezultat) 
	{


	}

	~Calcul() {
		if (rezultate != nullptr)
		{
			delete[] this->rezultate;
			this->rezultate = nullptr;
		}
	}
	friend istream& operator>>(istream& i, Calcul& c);
	friend ostream& operator<<(ostream& o, Calcul c);


}; //end of class



istream& operator>>(istream& i, Calcul& c)
{
	cout << "nrRezultate";
	i >> c.nrRezultate;
	if (c.nrRezultate > 0) {
		cout << "nr rezultate negativ";
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

int Calcul::nrOperatiiEfectuate = 0;
