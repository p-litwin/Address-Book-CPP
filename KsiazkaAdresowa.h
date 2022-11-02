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
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami = "Users.txt", string nazwaPlikuZAdresatami = "Contacts.txt"):
        uzytkownikMenedzer(nazwaPlikuZUzytkownikami), adresatMenedzer(nazwaPlikuZAdresatami) {
        wystwietlMenuLogowania();
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
