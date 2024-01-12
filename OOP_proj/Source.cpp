#include<iostream>
#include<string>
#include<fstream>
#include "Calcul.h"
#include "Descompunere.h"
#include "Ecuatie.h"
#include "LucruFisiere.h"
#include<iomanip>
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

        while (true)
        {
            cout << "Meniu:" << endl;
            cout << "1. Introducere Ecuatie si rezolvare" << endl;
            cout << "2. Citire ecuatie din fisier si afisare rezultat consola/fisier" << endl;
            cout << "3. Salvare rezultat intermediar in fisier" << endl;
            cout << "4. Exit" << endl;

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
                }
                catch (const runtime_error& e) {
                    cout << "Eroare: " << e.what() << endl;
                }
                break;
            }
            case 2:
                //LucruFisiere::citireEcuatiiDinFisier();
                break;
            case 3:
               // LucruFisiere::salvareRezultateInFisier(intermediar);
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
}