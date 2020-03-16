#include "AdresatMenedzer.h"
#include "MetodyPomocnicze.h"
#include "Adresat.h"
#include "PlikZAdresatami.h"

int AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();
    adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
    {
        cout << "Nowy adresat zostal dodany." <<endl;
    }
    else
    {
        cout << "Blad z dodawaniem adresata";
        system("pause");
    };
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{

    MetodyPomocnicze metodyPomocnicze;
    Adresat adresat;
    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata()+1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    cout << plikZAdresatami.pobierzIdOstatniegoAdresata()<<endl;
    cout << "Podaj imie: ";
    adresat.ustawImie(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(metodyPomocnicze.wczytajLinie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(metodyPomocnicze.wczytajLinie()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(metodyPomocnicze.wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(metodyPomocnicze.wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(metodyPomocnicze.wczytajLinie());
    return adresat;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    //vector<AdresatMenedzer> adresaci;
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:         " << adresat.pobierzId()<< endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

