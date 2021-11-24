#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

#include "Expense.h"
#include "TextFile.h"
#include "UsersFile.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class ExpensesFile : public TextFile {
    int lastUserId;

public:
    ExpensesFile(string expensesFilename) : TextFile(expensesFilename) {
        lastUserId = 0;
    };

    vector <Expense> loadExpensesOfLoggedInUserFromXmlFile(int loggedInUserId);
    void writeExpenseToXmlFile(Expense expense);
};

#endif // EXPENSESFILE_H
