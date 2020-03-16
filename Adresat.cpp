#include "Adresat.h"


void Adresat::ustawId(int noweId)
{
    if (noweId>=0)
    id = noweId;
}
int Adresat::pobierzId()
{
    return id;
}
void Adresat::ustawIdUzytkownika(int noweId)
{
    if (noweId>=0)
    idUzytkownika = noweId;
}
int Adresat::pobierzIdUzytkownika()
{
    return idUzytkownika;
}
void Adresat::ustawImie(string noweImie)
{
    imie = noweImie;
}
string Adresat::pobierzImie()
{
    return imie;
}
void Adresat::ustawNazwisko(string noweNazwisko)
{
    nazwisko = noweNazwisko;
}
string Adresat::pobierzNazwisko()
{
    return nazwisko;
}
void Adresat::ustawNumerTelefonu(string nowyNumerTelefonu)
{
    numerTelefonu = nowyNumerTelefonu;
}
string Adresat::pobierzNumerTelefonu()
{
    return numerTelefonu;
}
void Adresat::ustawEmail(string nowyEmail)
{
    email = nowyEmail;
}
string Adresat::pobierzEmail()
{
    return email;
}
void Adresat::ustawAdres(string nowyAdres)
{
    adres = nowyAdres;
}
string Adresat::pobierzAdres()
{
    return adres;
}

