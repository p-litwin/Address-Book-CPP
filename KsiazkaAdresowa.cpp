#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wystwietlMenuLogowania() {
    char wybor;

    while (true) {
        if (!uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
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
        if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
            adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
            wyswietlMenuUzytkownika();
        }

    }

    void KsiazkaAdresowa::wylogowanieUzytkownika() {
        uzytkownikMenedzer.wylogowanie();
        delete adresatMenedzer;
        adresatMenedzer = NULL;
        wystwietlMenuLogowania();
    }

    void KsiazkaAdresowa::dodajAdresata() {
        adresatMenedzer -> dodajAdresata();
    }

    void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
        adresatMenedzer -> wyswietlWszystkichAdresatow();
    }

    void KsiazkaAdresowa::wyswietlMenuUzytkownika() {
    char wybor;
    while (true) {
        wybor = wybierzOpcjeZMenuUzytkownika();
        switch (wybor) {
        case '1':
            adresatMenedzer -> dodajAdresata();
            break;
        case '2':
            //wyszukajAdresatowPoImieniu(adresaci);
            break;
        case '3':
            //wyszukajAdresatowPoNazwisku(adresaci);
            break;
        case '4':
            adresatMenedzer -> wyswietlWszystkichAdresatow();
            break;
        case '5':
            adresatMenedzer -> usunAdresata();
            //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
            break;
        case '6':
            //edytujAdresata(adresaci);
            break;
        case '7':
            uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
            break;
        case '8':
            wylogowanieUzytkownika();
            break;
        }
    }
}
char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    //cout << "2. Wyszukaj po imieniu" << endl;
    //cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    //cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
