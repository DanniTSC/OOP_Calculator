#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
#include "Calcul.h"
#include "Descompunere.h"

using namespace std;

class Ecuatie
{
private:
	double* coeficienti;
	int nrCoef;
	const int MAX_NECUNOSCUTE = 2; // ecuatie de gradul 2 max


public:
	Ecuatie();

	Ecuatie(double* coeficienti, int nrCoef);

	Ecuatie(const Ecuatie& e);


	Ecuatie& operator=(const Ecuatie& e);


	void setCoef(double* Coef, int nrCoeficienti);


	void setNrCoef(int nrCoeficienti);

	double* getCoef();


	int getNrCoef();


	static bool verificaFormat(const string& ecuatie);


	void rezolvaEcuatie();


	~Ecuatie();


	friend istream& operator>>(istream& i, Ecuatie& e);
	friend ostream& operator<<(ostream& o, Ecuatie e);

	Ecuatie& operator++();


	Ecuatie& operator--();


	explicit operator bool(); //verifica daca este de gradul 2 ecuatia


};//end of class


