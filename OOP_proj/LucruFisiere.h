#pragma once
#include "Calcul.h"
#include<fstream>
#include<vector>
#include<string>
#include<iostream>

class LucruFisiere : public Calcul {
public:
	LucruFisiere() : Calcul() {};

	void salvareRezultateInFisier(double rezultat);

	void citireEcuatiiDinFisier();

};