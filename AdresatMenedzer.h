#ifndef DANEMENEDZER_H
#define DANEMENEDZER_H
#include "Adresat.h"
#include <iostream>
#include <vector>
using namespace std;

class AdresatMenedzer
{
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wyswietlDaneAdresata(Adresat adresat);
    vector<Adresat> adresaci;

public:
    int dodajAdresata(int idZalogowanegoAdresata);
    void wyswietlWszystkichAdresatow();
};
#endif
