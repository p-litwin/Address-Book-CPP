#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa() {
    uzytkownikMenedzer.wczytajUzytkownikowZPLiku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
