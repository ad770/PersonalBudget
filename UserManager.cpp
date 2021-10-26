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

    return user;
}
bool UserManager::isLoginExist(string login) {
    for (int i=0; i<users.size(); i++) {
        if (users[i].getLogin() == login) {
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
            for (int trialsAmount = 3; trialsAmount > 0; trialsAmount--) {
                cout << "Podaj haslo. Pozostalo prob: " << trialsAmount << ": ";
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
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::inputLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getUserId() == loggedInUserId) {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    usersFile.writeAllUsersToXmlFile(users);
}
void UserManager::displayAllUsers() {
    for (int i=0; i<users.size(); i++) {
        cout << users[i].getUserId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}
int UserManager::getLoggedInUserId() {
    return loggedInUserId;
}
int UserManager::userLogout() {
    loggedInUserId = 0;
    return loggedInUserId;
};
bool UserManager::isUserLoggedIn() {
    if (loggedInUserId>0)
        return true;
    else
        return false;
}
