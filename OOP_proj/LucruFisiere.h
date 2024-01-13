#pragma once
#include "Calcul.h"
#include<fstream>
#include<vector>
#include<string>
#include<iostream>

class LucruFisiere : public Calcul {
public:
	LucruFisiere() : Calcul() {};

	static void salvareRezultateInFisier(double rezultat);

	static void citireEcuatiiDinFisier();
	
	static double citireBinar(const string& numeFisier);

};