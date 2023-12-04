#pragma once
#include<iostream>
#include<string>
#include "Descompunere.h"
#include "Ecuatie.h"
//Faza 1 versiunea finala
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

	Calcul(); 

	Calcul(double* rezultate, int nrRezultate);
	
	~Calcul();

	void setRezultate(double* rezultat, int nrRezultate);

	double* getRezultate();

	int getNrRezultate();

	void setNrRezultate(int nrRez);


	Calcul(const Calcul& c);
	

	Calcul& operator=(const Calcul& c);
	

	static double efectuareOperatie(const double numere[], const char operatori[], int nrNumere, int nrOperatori);
	
	

	void adaugaRezultatIntermediar(double rezultat);
	
	friend istream& operator>>(istream& i, Calcul& c);
	friend ostream& operator<<(ostream& o, Calcul c);

	bool operator!(); // verifica daca  exista rezultate
	

	Calcul operator+(double numar);

}; //end of class









