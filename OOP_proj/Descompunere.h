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
	const string CARACTERE_PERMISE = "0123456789+=*/";

public:
	Descompunere()
	{
		this->expresieDescompusa = nullptr;

	}

	Descompunere()
	{
	}

	static bool esteOperator(char Operator)
	{

	}

	void descompunereExpresie(const string& expresie) //din moment ce string este o clasa evit constr de copiere cu &
	{

	}

	string obtineTermeni() {

	}

	~Descompunere()
	{
		if (this->expresieDescompusa != nullptr)
		{
			delete[] this->expresieDescompusa;
			this->expresieDescompusa = nullptr;
		}
	}


};//end of class


int Descompunere::nrDescompuneri = 0;

