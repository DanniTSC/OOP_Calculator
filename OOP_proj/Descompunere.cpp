#include "Descompunere.h"
#pragma once
#include<iostream>
#include<string>
#include<cmath>
//Faza 1 versiunea finala
using namespace std;

int Descompunere::nrDescompuneri = 0;
const string Descompunere::CARACTERE_PERMISE = "0123456789+=-/*";

Descompunere::Descompunere() : expresieDescompusa(nullptr) {}

Descompunere::Descompunere(char* expresieDescompusa)
{
		if (expresieDescompusa != nullptr)
		{
			this->expresieDescompusa = new char[strlen(expresieDescompusa) + 1];
			strcpy_s(this->expresieDescompusa, strlen(expresieDescompusa) + 1, expresieDescompusa);
		}
}

Descompunere::Descompunere(const Descompunere& d)
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

Descompunere& Descompunere::operator=(const Descompunere& d)
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

char* Descompunere::getExpresie()
{
	return this->expresieDescompusa;
}

void Descompunere::setExpresie(const string& expresie)
{
		if (this->expresieDescompusa)
		{
			delete[] this->expresieDescompusa;
		}
		expresieDescompusa = new char[expresie.length() + 1];
		strcpy_s(this->expresieDescompusa, expresie.length() + 1, expresie.c_str());
}

bool Descompunere::esteOperator(char Operator)
{
	for (int i = 0; i < CARACTERE_PERMISE.length(); i++)
	{
		if (CARACTERE_PERMISE[i] == Operator)
		{
			return true;
		}
	}
	return false;
}

void Descompunere::descompunereExpresie(const string& expresie, double numere[], char operatori[], int& nrNumere, int& nrOperatori)
{
	nrNumere = 0;
	nrOperatori = 0;
	string nrStr = "";

	for (char ch : expresie) {
		if (ch == ' ') {
			if (!nrStr.empty()) {
				numere[nrNumere++] = stod(nrStr);
				nrStr = "";
			}
			continue;
		}

		if (isdigit(ch) || ch == '.') {
			nrStr += ch;
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			if (!nrStr.empty()) {
				numere[nrNumere++] = stod(nrStr);
				nrStr = "";
			}
			operatori[nrOperatori++] = ch;
		}
	}

	if (!nrStr.empty()) {
		numere[nrNumere++] = stod(nrStr);
	}
	
}

string Descompunere::obtineTermeni()
{
	char* context = nullptr;
	string rezultat;
	if (expresieDescompusa)
	{
		char* copieExpresie = new char[strlen(expresieDescompusa) + 1];
		strcpy_s(copieExpresie, strlen(expresieDescompusa) + 1, expresieDescompusa);
		char* termen = strtok_s(copieExpresie, " ", &context);

		while (termen != nullptr)
		{
			rezultat += termen;
			rezultat += " ";
			termen = strtok_s(nullptr, " ", &context);
		}
		delete[] copieExpresie;
	}
	return rezultat;
}

Descompunere::~Descompunere()
{
	if (this->expresieDescompusa != nullptr)
	{
		delete[] this->expresieDescompusa;
		this->expresieDescompusa = nullptr;
	}
}

char Descompunere::operator[](int index)
{
		if (index >= 0 && index < strlen(expresieDescompusa)) {
			return expresieDescompusa[index];
		}
		else
		{
			return '\0';
		}
}

bool Descompunere::operator==(const Descompunere& desc)
{
	return strcmp(expresieDescompusa, desc.expresieDescompusa) == 0;
	//strcmp 0 daca sirurile sunt egale, deci functia intoarce adevarat
}


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
