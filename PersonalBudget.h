#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "TransactionsManager.h"
#include "UserManager.h"
#include "Menu.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"

using namespace std;
class PersonalBudget {
    TransactionsManager *transactionsManager;
    Menu menu;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;
    char wybor;


public:
    PersonalBudget(

    );

    void userRegistration();
    void userLogging();
    void userLogout();
    void addIncome();
    void addExpense();
    void showBalanceOfCurrentMonth();
    void showBalanceOfPreviousMonth();
    void showBalanceOfSelectedPeriod();
    void changeLoggedInUserPassword();
    void displayAllUsers();
};

#endif // PERSONALBUDGET_H
