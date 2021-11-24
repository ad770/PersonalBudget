#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"
#include "Markup.h"

using namespace std;

class UsersFile : public TextFile {

public:
    UsersFile(string usersFilename) : TextFile(usersFilename) {};

    vector <User> loadUsersDataFromXmlFile();
    void writeUserDataToXmlFile(User user);
    void changePasswordInXmlFile(User user);
};

#endif // USERSFILE_H
