#include "DaneMenedzer.h"
#include "MetodyPomocnicze.h"
#include "DaneAdresowe.h"

int DaneMenedzer::dodajAdresata()
{
    //int idZalogowanegoUzytkownika, int idOstatniegoAdresata

    int idZalogowanegoUzytkownika = 1;
    int idOstatniegoAdresata = 1;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;

    DaneAdresowe adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
    adresaci.push_back(adresat);
    //dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}

DaneAdresowe DaneMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{

    MetodyPomocnicze metodyPomocnicze;
    DaneAdresowe adresat;
    //adresat.ustawId(++idOstatniegoAdresata);
    //adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    adresat.ustawId(1);
    adresat.ustawIdUzytkownika(1);

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

void DaneMenedzer::wyswietlWszystkichAdresatow()
{
    //vector<DaneMenedzer> adresaci;
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <DaneAdresowe> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
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

void DaneMenedzer::wyswietlDaneAdresata(DaneAdresowe adresat)
{
    cout << endl << "Id:         " << adresat.pobierzId()<< endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

