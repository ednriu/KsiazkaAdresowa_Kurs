#include "DaneAdresowe.h"

void DaneAdresowe::ustawId(int noweId)
{
    if (noweId>=0)
    id = noweId;
}
int DaneAdresowe::pobierzId()
{
    return id;
}
void DaneAdresowe::ustawIdUzytkownika(int noweId)
{
    if (noweId>=0)
    id = noweId;
}
int DaneAdresowe::pobierzIdUzytkownika()
{
    return idUzytkownika;
}
void DaneAdresowe::ustawImie(string noweImie)
{
    imie = noweImie;
}
string DaneAdresowe::pobierzImie()
{
    return imie;
}
void DaneAdresowe::ustawNazwisko(string noweNazwisko)
{
    nazwisko = noweNazwisko;
}
string DaneAdresowe::pobierzNazwisko()
{
    return nazwisko;
}
void DaneAdresowe::ustawNumerTelefonu(string nowyNumerTelefonu)
{
    numerTelefonu = nowyNumerTelefonu;
}
string DaneAdresowe::pobierzNumerTelefonu()
{
    return numerTelefonu;
}
void DaneAdresowe::ustawEmail(string nowyEmail)
{
    email = nowyEmail;
}
string DaneAdresowe::pobierzEmail()
{
    return email;
}
void DaneAdresowe::ustawAdres(string nowyAdres)
{
    adres = nowyAdres;
}
string DaneAdresowe::pobierzAdres()
{
    return adres;
}

