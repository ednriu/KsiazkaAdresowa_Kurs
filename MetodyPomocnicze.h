#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include "Adresat.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>

using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    string wczytajLinie();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty(fstream &plikTekstowy);
    static int konwersjaStringNaInt(string liczba);
    char wczytajZnak();
    int wczytajLiczbeCalkowita();
};

#endif // METODYPOMOCNICZE_H
