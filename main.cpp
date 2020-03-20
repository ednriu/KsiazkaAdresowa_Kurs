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
        cout << "Wypisz Adresatow (w)" << endl;
        cout << "Usun Adresata (u)" << endl;
        cout << "Edytuj Adresata (e)" << endl;
        cout << "Zmiana Hasla (h)" << endl;
        cout << "Wyloguj (k)" << endl;
        cout << "Zakonczenie Programu (0)" << endl;
        char wybor = _getch();
        switch (wybor)
        {
        case 'd':
            ksiazkaAdresowa.dodajAdresata();
            break;
        case 'w':
            ksiazkaAdresowa.wyswietlWszystkichAdresatow();
            break;
        case 'u':
            ksiazkaAdresowa.usunAdresata();
            break;
        case 'e':
            ksiazkaAdresowa.edytujAdresata();
            break;
        case 'h':
            ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
            break;
        case 'k':
            ksiazkaAdresowa.wylogowanieUzytkownika();
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
        cout << "Koniec Programu (0)" << endl;
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
    return 0;
}

int test_main()
{
    AdresatMenedzer adresatMenedzer("Adresaci.txt",1);
    cout <<"dziala"<<endl;

    adresatMenedzer.wyswietlWszystkichAdresatow();
    adresatMenedzer.edytujAdresata();
    adresatMenedzer.wyswietlWszystkichAdresatow();
    return 0;
}


