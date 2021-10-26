#include "UsersFile.h"

//User UsersFile::getUserData(string daneJednegoUzytkownikaOddzielonePionowymiKreskami) {
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
//}

//string UsersFile::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik) {
//    string liniaZDanymiUzytkownika = "";
//    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId())+ '|';
//    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
//    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';
//
//    return liniaZDanymiUzytkownika;
//}

vector <User> UsersFile::loadUsersDataFromXmlFile() {
    CMarkup xml;
    User user;
    vector <User> users;

    if (!xml.SetDoc(getFilename())) {
        cout << "Blad odczytu pliku!";
        //return 0;
    }
    xml.FindElem("usersFile");
    xml.IntoElem();

    while (xml.FindElem("user")) {
        xml.IntoElem();

        xml.FindElem("userId");
        user.setUserId(atoi(xml.GetData().c_str()));
        xml.FindElem("login");
        user.setLogin(xml.GetData());
        xml.FindElem("password");
        user.setPassword(xml.GetData());
        xml.FindElem("name");
        user.setName(xml.GetData());
        xml.FindElem("surname");
        user.setSurname(xml.GetData());

        users.push_back(user);

        xml.OutOfElem();
    }

    return users;
}

void UsersFile::writeUserDataToXmlFile(User user) {
    CMarkup xml;
    if (!xml.Load(getFilename())) {
        cout << "Blad odczytu pliku!";
        return;
    }
    xml.FindElem("usersFile");
    xml.IntoElem();
    xml.FindElem("users");
    xml.IntoElem();
    xml.AddElem("userId",user.getUserId());
    xml.AddElem("login",user.getLogin());
    xml.AddElem("password",user.getPassword());
    xml.AddElem("name",user.getName());
    xml.AddElem("surname",user.getSurname());

    xml.OutOfElem();
    xml.OutOfElem();

    xml.Save(getFilename());
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
