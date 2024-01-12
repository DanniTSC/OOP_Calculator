#pragma once
#include "Calcul.h"
#include "LucruFisiere.h"
#include<fstream>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

void LucruFisiere::salvareRezultateInFisier(double rezultat)
{

    string numeFisier;
    cout << "introduceti numele fisierului unde se va salva";
    cin >> numeFisier;

    ofstream fisierOut(numeFisier, ios::binary);

    if (!fisierOut)
    {
        cout << "Fisierul nu a putut fi deschis pentru scriere." << endl;
        return;
    }

    fisierOut.write(reinterpret_cast<const char*>(&rezultat), sizeof(rezultat));
    fisierOut.close();
    cout << "rezultat salvar in fisier" << endl;
}

void LucruFisiere::citireEcuatiiDinFisier()
{
    string numeFisier;
    cout << "introduceti nume fisier:";
    cin >> numeFisier;

    ifstream fisierIn(numeFisier);
    if (!fisierIn) {
        cout << "fisierul s-a deschis" << endl;
        return;
    }

    cout << "unde doriti sa se afiseze rezultatul ? ";
    cout << "1.Consola\n";
    cout << "2.Fisier text\n";

    int optiune;
    cin >> optiune;

    ofstream fisierOut;
    if (optiune == 2)
    {
        string numeFisierScrisRezultat;
        cout << "introduceti numele fisierului unde doriti sa fie salvat rezultatul";
        cin >> numeFisierScrisRezultat;
        fisierOut.open(numeFisierScrisRezultat);
        if (!fisierOut) {
            cout << "fisierul s-a deschis" << endl;
            return;
        }
    }
    string linie;
    while (getline(fisierIn, linie)) {
        try {
            vector<string> procesat = Descompunere::procesare(linie);
            double rezultat = Descompunere::evaluare(procesat);
            if (optiune == 1) {
                cout << "Rezultatul pentru ecuatia [" << linie << "] este: " << rezultat << endl;
            }
            else if (optiune == 2 && fisierOut.is_open()) {
                fisierOut << "Rezultatul pentru ecuatia [" << linie << "] este: " << rezultat << endl;
            }
        }
        catch (const exception& e) {
            if (optiune == 1) {
                cout << "Eroare la procesarea ecuatiei: " << linie << ' ' << e.what() << endl;
            }
            else if (optiune == 2 && fisierOut.is_open()) {
                fisierOut << "Eroare la procesarea ecuatiei: " << linie << ' ' << e.what() << endl;
            }
        }
    }
    fisierIn.close();
    if (fisierOut.is_open()) {
        fisierOut.close();
    }
    cout << "Ecuatiile au fost procesate." << endl;
}
