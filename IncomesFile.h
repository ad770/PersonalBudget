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

public:
    IncomesFile(string incomesFilename) : TextFile(incomesFilename) {
        lastUserId = 0;
    };

    vector <Income> loadIncomesOfLoggedInUserFromXmlFile(int loggedInUserId);
    void writeIncomeToXmlFile(Income income);
    int getLastTransactionId();
};

#endif // INCOMESFILE_H
