#include"AbstarctEcuatie.h"
#include"AbstractEcDerivata.h"
#include<iostream>
using namespace std;
//Faza 2 final

AbstractEcDerivata::AbstractEcDerivata(double a, double b) : a(a), b(b) {}

double AbstractEcDerivata::calculeaza(){
	if (a == 0)
	{
		throw runtime_error("ec invalida");
	}
	return -b / a;
}

