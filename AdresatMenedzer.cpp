#include "AdresatMenedzer.h"

AdresatMenedzer::AdresatMenedzer() {
    idOstatniegoAdresata = 0;
}

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {

    idOstatniegoAdresata = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);
}

void AdresatMenedzer::dodajAdresata() {
    if (idZalogowanegoUzytkownika != 0) {

        Adresat adresat;

        system("cls");
        cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
        adresat = podajDaneNowegoAdresata();

        adresaci.push_back(adresat);
        dopiszAdresataDoPliku(adresat);

        idOstatniegoAdresata++;
    }
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);
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

void AdresatMenedzer::ustawIdZalogowanegoUzytkownika(int id) {
    idZalogowanegoUzytkownika = id;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow() {
    if (idZalogowanegoUzytkownika != 0) {
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

void AdresatMenedzer::wyczyscPamiec() {
    adresaci.clear();
}
