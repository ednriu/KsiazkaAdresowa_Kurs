#ifndef PLIKZDANYMI_H
#define PLIKZDANYMI_H
#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include <iostream>
#include <fstream>


using namespace std;

class PlikZAdresatami
{
    Adresat adresat;
public:
    void dopiszAdresataDoPliku(Adresat adresat);
};
#endif // PlikZAdresatami
