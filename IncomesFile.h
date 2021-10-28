#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

#include "Income.h"
#include "TextFile.h"
#include "UsersFile.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class IncomesFile : public TextFile {
    int lastUserId;
    int getUserIdFromXmlFile();
//    Income getIncomeData();

public:
    IncomesFile(string incomesFilename) : TextFile(incomesFilename) {
        lastUserId = 0;
    };

    vector <Income> loadIncomesOfLoggedInUserFromXmlFile(int loggedInUserId);
    int loadLastIncomeIdFromXmlFile();
    void writeIncomeToXmlFile(Income income);
    int getIncomeIdFromXmlFile();

};

#endif // INCOMESFILE_H
