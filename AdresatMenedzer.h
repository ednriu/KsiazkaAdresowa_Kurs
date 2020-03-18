#ifndef DANEMENEDZER_H
#define DANEMENEDZER_H
#include "Adresat.h"
#include "PlikZAdresatami.h"
#include <iostream>
#include <vector>
#include "MetodyPomocnicze.h"
using namespace std;

class AdresatMenedzer
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    int podajIdWybranegoAdresata();


public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika):plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    };
    int dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void usunAdresata();
};
#endif
