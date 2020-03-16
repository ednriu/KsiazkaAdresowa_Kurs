#include <iostream>
#include <conio.h>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    while(true)
    {
      if (ksiazkaAdresowa.czyUzytkownikJestZalogowany())
    {
        system("cls");
        cout << "Dodaj Adresata (d)" << endl;
        cout << "Wypisz Adresatow (a)" << endl;
        cout << "Zmiana Hasla (h)" << endl;
        cout << "Wyloguj (w)" << endl;
        char wybor = _getch();
        switch (wybor)
        {
        case 'd':
            ksiazkaAdresowa.dodajAdresata();
            break;
        case 'a':
            ksiazkaAdresowa.wyswietlWszystkichAdresatow();
            break;
        case 'w':
            ksiazkaAdresowa.wylogowanieUzytkownika();
            break;
        case 'h':
            ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
            break;
        case '0':
            exit(0);
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    }
    else
    {
        system("cls");
        cout << "Zaloguj (z)" << endl;
        cout << "Rejestracja Uzytkownika (r)" << endl;
        char wybor = _getch();
        switch (wybor)
        {
        case 'z':
            ksiazkaAdresowa.logowanieUzytkownika();
            break;
        case 'r':
            ksiazkaAdresowa.rejestracjaUzytkownika();
            break;
        case '0':
            exit(0);
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    }
    }


    //ksiazkaAdresowa.czyUzytkownikJestZalogowany();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    //ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    //ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    return 0;
}

int testmain()
{
    AdresatMenedzer adresatMenedzer("Adresaci.txt",1);
    cout <<"dziala"<<endl;
    adresatMenedzer.wyswietlWszystkichAdresatow();
    adresatMenedzer.dodajAdresata();
    return 0;
}


