#include<iostream>
#include<string>
#include "Calcul.h"
#include "Descompunere.h"
#include "Ecuatie.h"
using namespace std;

int main() {
	Calcul calc;
	Descompunere desc;
	Ecuatie ec;

	calc.adaugaRezultatIntermediar(5.0);
	desc.setExpresie("3+4*5");
	desc.descompunereExpresie(desc.getExpresie());
	cout << desc.obtineTermeni();

	

}