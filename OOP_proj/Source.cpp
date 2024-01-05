#include<iostream>
#include<string>
#include "Calcul.h"
#include "Descompunere.h"
#include "Ecuatie.h"
#include<iomanip>
using namespace std;

int main() {
    //string expresie;
    //getline(cin, expresie);

    //double numere[100];
    //char operatori[100];
    //int nrNumere = 0, nrOperatori = 0;

    //Descompunere::descompunereExpresie(expresie, numere, operatori, nrNumere, nrOperatori);

    //for (int i = 0; i < nrNumere; i++) {
    //    cout << "numar: " << numere[i] << endl;
    //}

    //for (int i = 0; i < nrOperatori; i++) {
    //    cout << "operator: " << operatori[i] << endl;
    //}

    //double rezultat = Calcul::efectuareOperatie(numere, operatori, nrNumere, nrOperatori);
    //
    ////fixed este pentru 24343243.0002 - 3 
    //cout << fixed << setprecision(4) << "rezultatul este: " << rezultat << endl;

    while (true) {
        cout << "Meniu:" << endl;
        cout << "1. Introducere Ecuatie" << endl;
        cout << "2. Citire ecuatie din fisier" << endl;
        cout << "3. Salvare rezultat intermediar in fisier" << endl;
        cout << "4. Exit" << endl;

        int alegMeniu = 0;
        cout << "Ce optiune alegeti ?";
        cin >> alegMeniu;

        switch (alegMeniu)
        {
        case 1:
            //ecuatie cod
            break;
        case 2:
            //cod ecuatie fisier
        break;
        case 3:
            //salvare rez in fisier
        break;
        case 4:
            cout << "iesire din program" << endl;
            return 0;
        default:
            cout << "Momentan optiune invalida. Incercati din nou." << endl;

        }
    }

    return 0;
}