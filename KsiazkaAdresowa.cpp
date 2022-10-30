#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wystwietlMenuLogowania() {
    char wybor;

    while (true) {
        if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() == 0) {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor) {
            case '1':
                rejestracjaUzytkownika();
                break;
            case '2':
                logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }

}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

    void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
        uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
    }

    void KsiazkaAdresowa::logowanieUzytkownika() {
        uzytkownikMenedzer.logowanieUzytkownika();
        if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() != 0) {
            adresatMenedzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
            adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
            adresatMenedzer.wyswietlMenuUzytkownika();
        }

    }

    void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
        uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
    }

    void KsiazkaAdresowa::wyloguj() {
        uzytkownikMenedzer.zapiszIdZalogowanegoUzytkownika(0);
        adresatMenedzer.wyczyscPamiec();
    }

    void KsiazkaAdresowa::dodajAdresata() {
        adresatMenedzer.dodajAdresata();
    }

    void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
        adresatMenedzer.wyswietlWszystkichAdresatow();
    }
