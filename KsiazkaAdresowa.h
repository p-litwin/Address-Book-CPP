#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;

    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami = "Users.txt") : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {
        uzytkownikMenedzer.wczytajUzytkownikowZPLiku();
        adresatMenedzer.ustawIdZalogowanegoUzytkownika(0);
    };
    void wystwietlMenuLogowania();
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wyswietlMenuUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wyswietlWszystkichAdresatow();
    void dodajAdresata();
    void wyloguj();
};

#endif // KSIAZKAADRESOWA_H
