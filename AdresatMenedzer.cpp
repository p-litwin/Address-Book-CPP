#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata() {
    if (ID_ZALOGOWANEGO_UZYTKOWNIKA != 0) {

        Adresat adresat;

        system("cls");
        cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
        adresat = podajDaneNowegoAdresata();

        adresaci.push_back(adresat);
        if (plikZAdresatami.dopiszAdresataDoPliku(adresat)) {
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

void AdresatMenedzer::usunAdresata() {
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
        if (itr -> pobierzId() == idUsuwanegoAdresata) {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't') {
                adresaci.erase(itr);
                plikZAdresatami.usunLinieZPliku(idUsuwanegoAdresata);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return;
            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("p       ause");
                return;
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return;
}

int AdresatMenedzer::podajIdWybranegoAdresata() {
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}
