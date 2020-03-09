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

void UzytkownikMenedzer::zaloguj()
{
    bool hasloPoprawne = false;
    bool istniejeLogin = false;
    Uzytkownik uzytkownik;
    MetodyPomocnicze pomocnik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = pomocnik.wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if ((*itr).pobierzLogin()== login)
        {
            istniejeLogin = true;
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = pomocnik.wczytajLinie();
                if ((*itr).pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    zalogowanyUzytkownik.ustawId((*itr).pobierzId());
                    iloscProb = 0;
                    hasloPoprawne = true;
                }
            }
            if (!hasloPoprawne)
            {
                cout << "Wprowadzono 3 razy bledne haslo." << endl;
                system("pause");
                zalogowanyUzytkownik.ustawId(0);
            }

        }
        itr++;
    }
    if (!istniejeLogin)
    {
        cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
        system("pause");
        zalogowanyUzytkownik.ustawId(0);
    }
}
