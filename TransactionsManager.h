#ifndef TRANSACTIONSMANAGER_H
#define TRANSACTIONSMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Transaction.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "AuxiliaryMethods.h"
#include "Menu.h"

using namespace std;

class TransactionsManager {
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    IncomesFile incomesFile;
    ExpensesFile expensesFile;
    Menu menu;
    string usersFilename = "Users.txt";
    string incomesFilename = "Incomes.txt";
    string expensesFilename = "Expenses.txt";

    Income setNewIncomeData();
    Expense setNewExpenseData();
    void displayIncomeData();
    void displayExpenseData();


public:
    TransactionsManager(string incomesFilename, string expensesFilename, int loggedInUserId)
        : incomesFile(incomesFilename), expensesFile(expensesFilename), LOGGED_IN_USER_ID(loggedInUserId) {
        incomes = incomesFile.loadIncomesOfLoggedInUserFromXmlFile(loggedInUserId);
        expenses = expensesFile.loadExpensesOfLoggedInUserFromXmlFile(loggedInUserId);
    };

    void addIncome();
    void addExpense();
    void showBalanceOfCurrentMonth();
    void showBalanceOfPreviousMonth();
    void showBalanceOfSelectedPeriod();
};

#endif // TRANSACTIONSMANAGER_H
