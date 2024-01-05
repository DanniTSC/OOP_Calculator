#include<iostream>
#include<string>
#include<fstream>
#include "Calcul.h"
#include "Descompunere.h"
#include "Ecuatie.h"
#include<iomanip>
using namespace std;

double proceseazaExpresie(const string& expresie)
{
    double numere[100];
    char operatori[100];
    int nrNumere = 0, nrOperatori = 0;

    Descompunere::descompunereExpresie(expresie, numere, operatori, nrNumere, nrOperatori);

    for (int i = 0; i < nrNumere; i++) {
        cout << "numar: " << numere[i] << endl;
    }

    for (int i = 0; i < nrOperatori; i++) {
        cout << "operator: " << operatori[i] << endl;
    }

    double rezultat = Calcul::efectuareOperatie(numere, operatori, nrNumere, nrOperatori);
    return rezultat;
}

void citireEcuatiiDinFisier()
{
    string numeFisier;
    cout << "introduceti nume fisier:";
    cin >> numeFisier;

    ifstream fisierIn(numeFisier);
    if (!fisierIn) {
        cout << "fisierul s-a deschis" << endl;
        return;
    }
    
    string linie;
    while (getline(fisierIn, linie))
    {
        try
        {
            double rezultat = proceseazaExpresie(linie);
            cout << "rezultatul pentru ecuatia : " << linie << ' ' << rezultat << endl;
        }
        catch (const exception& e)
        {
            cout << "Eroare la procesarea ecuatiei: " << linie << ' ' << e.what() << endl;
        }
    }
    fisierIn.close();
    cout << "Ecuatii citite din fisier" << endl;
}

void salvareRezultateInFisier(double rezultat)
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





int main() {
    double intermediar = 0;

        while (true) 
        {
        cout << "Meniu:" << endl;
        cout << "1. Introducere Ecuatie si rezolvare" << endl;
        cout << "2. Citire ecuatie din fisier" << endl;
        cout << "3. Salvare rezultat intermediar in fisier" << endl;
        cout << "4. Exit" << endl;

        int alegMeniu;
        cout << "Ce optiune alegeti ?";
        cin >> alegMeniu;

        switch (alegMeniu){
        case 1: {
            string expresie;
            cout << "Introduceti ecuatia: ";
            cin.ignore();
            getline(cin, expresie);

            cout << fixed << setprecision(4) << "rezultatul este: " << proceseazaExpresie(expresie) << endl;
            break;
        }
        case 2:
            citireEcuatiiDinFisier();
        break;
        case 3:
            salvareRezultateInFisier(intermediar);
        break;
        case 4:
            cout << "Iesire din program" << endl;
            return 0;
        default:
            cout << "Momentan optiune invalida. Incercati din nou." << endl;

            }
        }

    return 0;
}