#pragma once
#include"AbstarctEcuatie.h"


class AbstractEcDerivata :public AbstarctEcuatie {
private:
	double a;
	double b;
public:
	AbstractEcDerivata(double a, double b);
	double calculeaza() override;
};
