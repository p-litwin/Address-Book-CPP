#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMenedzer.h"

#include <iostream>
#include <vector>

using namespace std;

class AdresatMenedzer {
    int iloscAdresatow;
    int idOstatniegoAdresata;
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

public:
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
};

#endif // ADRESATMENEDZER_H
