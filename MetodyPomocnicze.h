#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include "Adresat.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    string wczytajLinie();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty(fstream &plikTekstowy);
};

#endif // METODYPOMOCNICZE_H
