#include<iostream>
#include<string>
#include<fstream>
#include "Calcul.h"
#include "Descompunere.h"
#include "Ecuatie.h"
#include "LucruFisiere.h"
#include<iomanip>
using namespace std;

//double proceseazaExpresie(const string& expresie)
//{
//    double numere[100];
//    char operatori[100];
//    int nrNumere = 0, nrOperatori = 0;
//
//    Descompunere::descompunereExpresie(expresie, numere, operatori, nrNumere, nrOperatori);
//
//    for (int i = 0; i < nrNumere; i++) {
//        cout << "numar: " << numere[i] << endl;
//    }
//
//    for (int i = 0; i < nrOperatori; i++) {
//        cout << "operator: " << operatori[i] << endl;
//    }
//
//    double rezultat = Calcul::efectuareOperatie(numere, operatori, nrNumere, nrOperatori);
//    return rezultat;
//}




int main(int argc, char* argv[]) {
   
    if (argc > 1) {
      
        string expresie = argv[1];
        cout << "Procesarea ecuatiei din linia de comanda: " << expresie << endl;
        double rezultat = proceseazaExpresie(expresie);
        cout << "Rezultatul ecuatiei: " << fixed << setprecision(4) << rezultat << endl;
        return 0; 
    }
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

        switch (alegMeniu){
        case 1: {
            string expresie;
            cout << "Introduceti ecuatia: ";
            cin.ignore();
            getline(cin, expresie);
            intermediar = proceseazaExpresie(expresie);
            cout << fixed << setprecision(4) << "rezultatul este: " << proceseazaExpresie(expresie) << endl;
            break;
        }
        case 2:
            //citireEcuatiiDinFisier();
        break;
        case 3:
            //salvareRezultateInFisier(intermediar);
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