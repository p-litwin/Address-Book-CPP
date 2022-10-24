#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami = "Users.txt") : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {
        uzytkownikMenedzer.wczytajUzytkownikowZPLiku();
    };
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
};

#endif // KSIAZKAADRESOWA_H
