#include<iostream>
#include<string>
#include "Calcul.h"
#include "Descompunere.h"
#include "Ecuatie.h"
#include<iomanip>
using namespace std;

int main() {
    string expresie;
    getline(cin, expresie);

    double numere[100];
    char operatori[100];
    int nrNumere = 0, nrOperatori = 0;

    Descompunere::descompunereExpresie(expresie, numere, operatori, nrNumere, nrOperatori);

    for (int i = 0; i < nrNumere; i++) {
        cout << "Numar: " << numere[i] << endl;
    }

    for (int i = 0; i < nrOperatori; i++) {
        cout << "Operator: " << operatori[i] << endl;
    }

    double rezultat = Calcul::efectuareOperatie(numere, operatori, nrNumere, nrOperatori);

    cout << fixed << setprecision(4) << "Rezultatul este: " << rezultat << endl;

    return 0;
}