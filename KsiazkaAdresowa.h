#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void wystwietlMenuLogowania();
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wyswietlMenuUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wyswietlWszystkichAdresatow();
    void dodajAdresata();
    void wylogowanieUzytkownika();

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami = "Users.txt", string nazwaPlikuZAdresatami = "Contacts.txt"):
        uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
        adresatMenedzer = NULL;
        wystwietlMenuLogowania();
    };
    ~KsiazkaAdresowa() {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    }

};

#endif // KSIAZKAADRESOWA_H
