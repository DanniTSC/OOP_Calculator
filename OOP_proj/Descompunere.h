#pragma once
#include<iostream>
#include<string>
#include "Calcul.h"
#include "Ecuatie.h"

using namespace std;
/*
Mecanism de preprocesare aici este trimisa
expresia prima oara, imparte expresia in termeni
si operatori individuali
*/ 
class Descompunere
{
private:
	char* expresieDescompusa;
	static int nrDescompuneri;
	static const string CARACTERE_PERMISE;

public:
	Descompunere();
	

	Descompunere(char* expresieDescompusa);
	

	Descompunere& operator=(const Descompunere& d);
	

	Descompunere(const Descompunere& d);
	
	
	char* getExpresie();
	

	void setExpresie(const string& expresie);
	

	static bool esteOperator(char Operator);
	

	static void descompunereExpresie(const string& expresie,double numere[],char operatori[], int& nrNumere, int& nrOperatori); //din moment ce string este o clasa evit constr de copiere cu &
	

	string obtineTermeni();

	~Descompunere();
	
	
	friend istream& operator>>(istream& i, Descompunere& d);
	friend ostream& operator<<(ostream& o, Descompunere d);

	char operator[](int index);
	
	

	bool operator==(const Descompunere& desc);
	
};//end of class



