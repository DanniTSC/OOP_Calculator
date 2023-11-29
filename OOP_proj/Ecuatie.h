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
	static int nrEcuatiiRezolvate;
	const int MAX_NECUNOSCUTE = 2;


public:
	Ecuatie():MAX_NECUNOSCUTE(2) {
		coeficienti = nullptr;
	}
	
	Ecuatie(double* coeficienti, const int MAX_NECUNOSCUTE)
	{
		if (coeficienti != nullptr)
		{
			this->coeficienti = new double[sizeof coeficienti];
			this->coeficienti = coeficienti;
		}
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

};//end of class


int Ecuatie::nrEcuatiiRezolvate = 0;
