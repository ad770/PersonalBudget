#include "UsersFile.h"

Uzytkownik UsersFile::getUserData(string daneJednegoUzytkownikaOddzielonePionowymiKreskami) {
//    Uzytkownik uzytkownik;
//    string pojedynczaDanaUzytkownika = "";
//    int numerPojedynczejDanejUzytkownika = 1;
//
//    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
//        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
//            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
//        } else {
//            switch(numerPojedynczejDanejUzytkownika) {
//            case 1:
//                uzytkownik.ustawId(atoi(pojedynczaDanaUzytkownika.c_str()));
//                break;
//            case 2:
//                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
//                break;
//            case 3:
//                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
//                break;
//            }
//            pojedynczaDanaUzytkownika = "";
//            numerPojedynczejDanejUzytkownika++;
//        }
//    }
//    return uzytkownik;
}

//string UsersFile::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik) {
//    string liniaZDanymiUzytkownika = "";
//    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId())+ '|';
//    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
//    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';
//
//    return liniaZDanymiUzytkownika;
//}

vector <Uzytkownik> UsersFile::loadUserDataFromXmlFile() {
    CMarkup xml;
    Uzytkownik uzytkownik;
    vector <uzytkownik> uzytkownicy;

    if (!xml.Load(usersFilename)) {
        cout << "Blad odczytu pliku!";
        break;
    }
    xml.FindElem("incomesFile");
    xml.IntoElem();

//    fstream plikTekstowy;
//    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";
//    Uzytkownik uzytkownik;
//    vector <Uzytkownik> uzytkownicy;
//    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
//
//    if (plikTekstowy.good() == true) {
//        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami)) {
//            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
//            uzytkownicy.push_back(uzytkownik);
//        }
//
//    }
//    plikTekstowy.close();
//    return uzytkownicy;
}

void UsersFile::writeUserDataToXmlFile(User user) {
//    fstream plikTekstowy;
//    string liniaZDanymiUzytkownika = "";
//    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);
//
//    if (plikTekstowy.good() == true) {
//        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);
//
//        if (czyPlikJestPusty() == true) {
//            plikTekstowy << liniaZDanymiUzytkownika;
//        } else {
//            plikTekstowy << endl << liniaZDanymiUzytkownika ;
//        }
//    } else
//        cout << "Nie udalo sie otworzyc pliku " << pobierzNazwePliku() << " i zapisac w nim danych." << endl;
//    plikTekstowy.close();
}

void UsersFile::writeAllUsersToXmlFile(vector <User> &users) {
//    fstream plikTekstowy;
//    string liniaZDanymiUzytkownika = "";
//    vector <Uzytkownik>::iterator itrKoniec = --uzytkownicy.end();
//
//    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out);
//
//    if (plikTekstowy.good() == true)
//    {
//        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
//        {
//            liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(*itr);
//
//            if (itr == itrKoniec)
//            {
//               plikTekstowy << liniaZDanymiUzytkownika;
//            }
//            else
//            {
//                plikTekstowy << liniaZDanymiUzytkownika << endl;
//            }
//            liniaZDanymiUzytkownika = "";
//        }
//    }
//    else
//    {
//        cout << "Nie mozna otworzyc pliku " << pobierzNazwePliku() << endl;
//    }
//    plikTekstowy.close();
}