#ifndef DANEMENEDZER_H
#define DANEMENEDZER_H
#include "DaneAdresowe.h"
#include <iostream>
#include <vector>
using namespace std;

class DaneMenedzer
{
    DaneAdresowe podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wyswietlDaneAdresata(DaneAdresowe adresat);
    vector<DaneAdresowe> adresaci;

public:
    int dodajAdresata(int idZalogowanegoAdresata);
    void wyswietlWszystkichAdresatow();
};
#endif
