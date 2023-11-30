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

	Descompunere(char* expresieDescompusa)
	{
		if (expresieDescompusa != nullptr)
		{
			this->expresieDescompusa = new char[strlen(expresieDescompusa) + 1];
			strcpy_s(this->expresieDescompusa, strlen(expresieDescompusa) + 1, expresieDescompusa);
		}
	}

	Descompunere& operator=(const Descompunere& d)
	{
		if (this == &d)
		{
			throw exception("autoasignare");
		}
		
		if (d.expresieDescompusa != nullptr)
		{
			if (this->expresieDescompusa)
			{
				delete[] this->expresieDescompusa;
			}
			this->expresieDescompusa = new char[strlen(d.expresieDescompusa) + 1];
			strcpy_s(this->expresieDescompusa, strlen(d.expresieDescompusa) + 1, d.expresieDescompusa);
		}
		else
		{
			this->expresieDescompusa = nullptr;
		}
		return *this;
	}

	Descompunere(const Descompunere& d)
	{
		if (d.expresieDescompusa != nullptr)
		{
			this->expresieDescompusa = new char[strlen(d.expresieDescompusa) + 1];
			strcpy_s(this->expresieDescompusa, strlen(d.expresieDescompusa) + 1, d.expresieDescompusa);
		}
		else
		{
			this->expresieDescompusa = nullptr;
		}
	}
	
	void setExpresie(const string& expresie)
	{
		if (this->expresieDescompusa)
		{
			delete[] this->expresieDescompusa;
		}
		expresieDescompusa = new char[expresie.length() + 1];
		strcpy_s(this->expresieDescompusa, expresie.length() + 1, expresie.c_str());
	}

	static bool esteOperator(char Operator)
	{

	}

	void descompunereExpresie(const string& expresie) //din moment ce string este o clasa evit constr de copiere cu &
	{
		if (this->expresieDescompusa)
		{
			delete[] this->expresieDescompusa;
			this->expresieDescompusa = nullptr;
		}
		
	

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
	
	friend istream& operator>>(istream& i, Descompunere& d);
	friend ostream& operator<<(ostream& o, Descompunere d);

};//end of class

istream& operator>>(istream& i, Descompunere& d)
{
	string buffer;
	i >> buffer;
	if (d.expresieDescompusa)
	{
		delete[] d.expresieDescompusa;
	}
	d.expresieDescompusa = new char[buffer.length() + 1];
	strcpy_s(d.expresieDescompusa, buffer.length() + 1, buffer.c_str());
	return i;
}

ostream& operator<<(ostream& o, Descompunere d)
{
	if (d.expresieDescompusa)
	{
		o << d.expresieDescompusa;
	}
	else
	{
		o << "expresie nula";
	}
	return o;
}

int Descompunere::nrDescompuneri = 0;

