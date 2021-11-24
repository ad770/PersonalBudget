#include "UserManager.h"

User UserManager::setNewUserData() {
    User user;

    user.setUserId(getNewUserId());

    do {
        cout << "Podaj login: ";
        user.setLogin(AuxiliaryMethods::inputLine());
    } while (isLoginExist(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods::inputLine());

    cout << "Podaj imie: ";
    user.setName(AuxiliaryMethods::inputLine());

    cout << "Podaj nazwisko: ";
    user.setSurname(AuxiliaryMethods::inputLine());
    return user;
}
bool UserManager::isLoginExist(string login) {
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}
int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}
void UserManager::userRegistration() {
    User user = setNewUserData();

    users.push_back(user);
    usersFile.writeUserDataToXmlFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
void UserManager::userLogging() {
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::inputLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int trials = 3; trials > 0; trials--) {
                cout << "Podaj haslo. Pozostalo prob: " << trials << ": ";
                password = AuxiliaryMethods::inputLine();

                if (itr -> getPassword() == password) {
                    loggedInUserId = itr -> getUserId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}
void UserManager::changeLoggedInUserPassword() {
    User user;
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::inputLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getUserId() == loggedInUserId) {
                itr -> setPassword(newPassword);
                cout << "Haslo zostalo zmienione." << endl << endl;
                user.setUserId(itr ->getUserId());
                user.setPassword(itr -> getPassword());
                system("pause");
            }
        }
    usersFile.changePasswordInXmlFile(user);
}
int UserManager::getLoggedInUserId() {
    return loggedInUserId;
}
int UserManager::userLogout() {
    loggedInUserId = 0;
    return loggedInUserId;
};
bool UserManager::isUserLoggedIn() {
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}
