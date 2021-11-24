#include "PersonalBudget.h"

void PersonalBudget::userRegistration() {
    userManager.userRegistration();
}
void PersonalBudget::userLogging() {
    userManager.userLogging();
    if (userManager.isUserLoggedIn()) {
        transactionsManager = new TransactionsManager(INCOMES_FILENAME, EXPENSES_FILENAME, userManager.getLoggedInUserId());
    }
}
void PersonalBudget::userLogout() {
    userManager.userLogout();
    delete transactionsManager;
    transactionsManager = NULL;
}
void PersonalBudget::addIncome() {
    transactionsManager->addIncome();
}
void PersonalBudget::addExpense() {
    transactionsManager->addExpense();
}
void PersonalBudget::showBalanceOfCurrentMonth() {
    transactionsManager->showBalanceOfCurrentMonth();
}
void PersonalBudget::showBalanceOfPreviousMonth() {
    transactionsManager->showBalanceOfPreviousMonth();
}
void PersonalBudget::showBalanceOfSelectedPeriod() {
    transactionsManager->showBalanceOfSelectedPeriod();
}
void PersonalBudget::changeLoggedInUserPassword() {
    userManager.changeLoggedInUserPassword();
}
