#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata() {
    if (ID_ZALOGOWANEGO_UZYTKOWNIKA != 0) {

        Adresat adresat;

        system("cls");
        cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
        adresat = podajDaneNowegoAdresata();

        adresaci.push_back(adresat);
        if (plikZAdresatami.dopiszAdresataDoPliku(adresat)){
            cout << "Nowy adresat zostal dodany." << endl;
        } else {
            cout << "Blad. Nie udalo sie dodac nowego adresata do pliku." << endl;
        }
        system("pause");
    }
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    cout << "Podaj imie: ";
    string imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    string nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

void AdresatMenedzer::dopiszAdresataDoPliku(Adresat adresat) {
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}

void AdresatMenedzer::wyswietlWszystkichAdresatow() {
    if (ID_ZALOGOWANEGO_UZYTKOWNIKA != 0) {
        system("cls");
        if (!adresaci.empty()) {
            cout << "             >>> ADRESACI <<<" << endl;
            cout << "-----------------------------------------------" << endl;
            for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
                wyswietlDaneAdresata(*itr);
            }
            cout << endl;
        } else {
            cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
        }
        system("pause");
    }
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}
