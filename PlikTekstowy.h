#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

class PlikTekstowy {
protected:
    const string NAZWA_PLIKU;
    bool czyPlikJestPusty(fstream &plikTekstowy);

public:
    PlikTekstowy(string nazwaPliku)
        : NAZWA_PLIKU(nazwaPliku) {};
};


#endif // PLIKTEKSTOWY_H
