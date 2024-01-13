#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include "Calcul.h"
#include "Descompunere.h"
#include "Ecuatie.h"
#include "LucruFisiere.h"
#include"AbstarctEcuatie.h"
#include"AbstractEcDerivata.h"
using namespace std;


int main(int argc, char* argv[]) {
    if (argc > 1) {
        string expresie = argv[1];
        cout << "Procesarea ecuatiei din linia de comanda: " << expresie << endl;
        vector<string> procesat = Descompunere::procesare(expresie);
        double rezultat = Descompunere::evaluare(procesat);
        cout << "Rezultatul ecuatiei: " << rezultat;
        return 0; 
    }
    else {

        double intermediar = 0;
        double nrBinar = 0;
        string fisier;

        while (true)
        {
            cout << "Meniu:" << endl;
            cout << "1. Introducere Ecuatie si rezolvare:" << endl;
            cout << "2. Citire ecuatie din fisier si afisare rezultatului: in fisier sau in consola" << endl;
            cout << "3. Salvare rezultat intermediar in fisier" << endl;
            cout << "4. Folosirea unui rezultat din fisier binar daca acesta a fost salvat(optiunea 4)"<<endl;
            cout << "5. Exit" << endl;

            int alegMeniu;
            cout << "Ce optiune alegeti ?";
            cin >> alegMeniu;
            cin.ignore();

            switch (alegMeniu) {
            case 1: {
                string expresie;
                cout << "Introduceti ecuatia: ";
                getline(cin, expresie);
                try {
                    vector<string> procesat = Descompunere::procesare(expresie);
                    double rezultat = Descompunere::evaluare(procesat);
                    cout << "Rezultatul expresiei: " << rezultat << endl;
                    intermediar = rezultat;
                }
                catch (const runtime_error& e) {
                    cout << "Eroare: " << e.what() << endl;
                }
                break;
            }
            case 2:
                LucruFisiere::citireEcuatiiDinFisier();
                break;
            case 3:
                LucruFisiere::salvareRezultateInFisier(intermediar);

                break;
            case 4:
                cout << "Introduceti numele fisierului de unde sa se intoarca rezultatul:" << endl;
                cin >> fisier;
                nrBinar = LucruFisiere::citireBinar(fisier);
                cout << "Rezultatul salvat este:" << nrBinar << endl;
                
                break;
            case 5:
                cout << "Iesire din program" << endl;
                return 0;
            default:
                cout << "Momentan optiune invalida. Incercati din nou." << endl;

            }
        }

        return 0;
    }
}