#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"
#include "Markup.h"

using namespace std;

class UsersFile : public TextFile {

//    User getUserData(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    string stringToInt(User user); //???

public:
    UsersFile(string usersFilename) : TextFile(usersFilename) {};

        vector <User> loadUsersDataFromXmlFile();
        void writeUserDataToXmlFile(User user);
        void writeAllUsersToXmlFile(vector <User> &users);

};

#endif // USERSFILE_H
