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
    int idZalogowanegoUzytkownika;
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    Adresat podajDaneNowegoAdresata();

public:
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void ustawIdZalogowanegoUzytkownika();
    void dodajAdresata();
};

#endif // ADRESATMENEDZER_H
