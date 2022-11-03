#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    do {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);
    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login) {
    for (size_t i = 0; i < uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow() {

    for (size_t i = 0; i < uzytkownicy.size(); i++) {
        cout << uzytkownicy[i].pobierzId() <<endl;
        cout << uzytkownicy[i].pobierzLogin() <<endl;
        cout << uzytkownicy[i].pobierzHaslo() <<endl;
    }
}

void UzytkownikMenedzer::zapiszWszystkichUzytkownikowDoPliku(vector<Uzytkownik> &uzytkownicy) {
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMenedzer::logowanieUzytkownika() {
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end()) {
        if (itr -> pobierzLogin() == login) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> pobierzHaslo() == haslo) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = itr -> pobierzId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            idZalogowanegoUzytkownika = 0;
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    idZalogowanegoUzytkownika = 0;
    return;
}

void UzytkownikMenedzer::zapiszIdZalogowanegoUzytkownika(int id) {
    idZalogowanegoUzytkownika = id;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika() {
    if (idZalogowanegoUzytkownika != 0) {
        string noweHaslo = "";
        cout << "Podaj nowe haslo: ";
        noweHaslo = MetodyPomocnicze::wczytajLinie();

        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
            if (itr -> pobierzId() == idZalogowanegoUzytkownika) {
                itr -> ustawHaslo(noweHaslo);
                cout << "Haslo zostalo zmienione." << endl << endl;
                system("pause");
            }
        }
        zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
    }
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}
