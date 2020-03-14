#ifndef PLIKZDANYMI_H
#define PLIKZDANYMI_H
#include "DaneAdresowe.h"
#include "MetodyPomocnicze.h"
#include <iostream>
#include <fstream>


using namespace std;

class PlikZDanymi
{
    DaneAdresowe adresat;
public:
    void dopiszAdresataDoPliku(DaneAdresowe adresat);
};
#endif // PlikZDanymi
