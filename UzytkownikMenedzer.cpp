#include "UzytkownikMenedzer.h"


void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    system("cls");
    Uzytkownik uzytkownik;
    //uzytkownik.id = pobierzIdNowegoUzytkownika(uzytkownicy);
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);
    string haslo;
    cout << "Podaj haslo: ";
    cin>>haslo;
    uzytkownik.ustawHaslo(haslo);
    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    system("cls");
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzId()<<endl;
        cout << uzytkownicy[i].pobierzLogin()<<endl;
        cout << uzytkownicy[i].pobierzHaslo()<<endl;
    }
}

void UzytkownikMenedzer::wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
};

int UzytkownikMenedzer::logowanieUzytkownika()
{
    bool hasloPoprawne = false;
    bool istniejeLogin = false;
    Uzytkownik uzytkownik;
    MetodyPomocnicze pomocnik;
    string login = "", haslo = "";
    system("cls");
    cout << "Podaj login: ";
    login = pomocnik.wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if ((*itr).pobierzLogin()== login)
        {
            istniejeLogin = true;
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                if (iloscProb<3) cout << "Pozostalo prob: " << iloscProb <<endl;
                cout << "Podaj haslo: ";
                haslo = pomocnik.wczytajLinie();
                if ((*itr).pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = itr ->pobierzId();
                    //zalogowanyUzytkownik.ustawId((*itr).pobierzId());
                    iloscProb = 0;
                    hasloPoprawne = true;
                }
            }
            if (!hasloPoprawne)
            {
                cout << "Wprowadzono 3 razy bledne haslo." << endl;
                system("pause");
                idZalogowanegoUzytkownika = 0;
                return idZalogowanegoUzytkownika;
            }

        }
        itr++;
    }
    if (!istniejeLogin)
    {
        cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
        system("pause");
        idZalogowanegoUzytkownika = 0;
    }
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    MetodyPomocnicze pomocnik;
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = pomocnik.wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if ((*itr).pobierzId() == idZalogowanegoUzytkownika)
        {
            (*itr).ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
void UzytkownikMenedzer::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
}
bool UzytkownikMenedzer::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika>0)
        return true;
    else
        return false;
}
int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

