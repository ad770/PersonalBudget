#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "TransactionsManager.h"
#include "User.h"
#include "UsersFile.h"
#include "AuxiliaryMethods.h"

using namespace std;


class UserManager {
    int loggedInUserId;
    vector <User> users;
    UsersFile usersFile;

    User setNewUserData();
    bool isLoginExist(string login);
    int getNewUserId();

public:
    UserManager(string usersFilename) : usersFile(usersFilename) {
        loggedInUserId = 0;
        users = usersFile.loadUsersDataFromXmlFile();
    };
    void userRegistration();
    void userLogging();
    void changeLoggedInUserPassword();
    int getLoggedInUserId();
    int userLogout();
    bool isUserLoggedIn();
};

#endif // USERMANAGER_H
