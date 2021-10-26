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
    UserManager userManager;
    TransactionsManager *transactionsManager;
    Menu menu;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;
    char choice;

public:
    PersonalBudget(string usersFilename, string incomesFilename, string expensesFilename)
        : userManager(usersFilename), INCOMES_FILENAME(incomesFilename), EXPENSES_FILENAME(expensesFilename) {
        transactionsManager = NULL;
        while (true) {
            if (!userManager.isUserLoggedIn()) {
                choice = menu.selectFromMainMenu();
                switch (choice) {
                case '1':
                    userRegistration();
                    break;
                case '2':
                    userLogging();
                    break;
                case '9':
                    exit(0);
                    break;
                default:
                    cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                    system("pause");
                    break;
                }
            } else {
                choice = menu.selectFromLoggedInUserMenu();

                switch (choice) {
                case '1':
                    addIncome();
                    break;
                case '2':
                    addExpense();
                    break;
                case '3':
                    showBalanceOfCurrentMonth();
                    break;
                case '4':
                    showBalanceOfPreviousMonth();
                    break;
                case '5':
                    showBalanceOfSelectedPeriod();
                    break;
                case '6':
                    changeLoggedInUserPassword();
                    break;
                case '7':
                    userLogout();
                    break;
                }
            }
        }
    };

    ~PersonalBudget() {
        delete transactionsManager;
        transactionsManager = NULL;
    }

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
