#include "TransactionsManager.h"

Income TransactionsManager::setNewIncomeData() {
    Income income;

    income.setIncomeId(getNewIncomeId());
    income.setUserId(LOGGED_IN_USER_ID);

    cout << "Podaj date: ";
    income.setDate(AuxiliaryMethods::inputLine()); //dodac sprawdzanie poprawnosci formatu i zakresu daty

    cout << "Podaj kategorie: ";
    income.setItem(AuxiliaryMethods::inputLine());

    cout << "Podaj wartosc: ";
    income.setValue(AuxiliaryMethods::inputLine()); //dodac zamiane przecinka na kropke
    return income;
}
Expense TransactionsManager::setNewExpenseData() {
    Expense expense;

    expense.setExpenseId(getNewExpenseId());
    expense.setUserId(LOGGED_IN_USER_ID);

    cout << "Podaj date: ";
    expense.setDate(AuxiliaryMethods::inputLine()); //dodac sprawdzanie poprawnosci formatu i zakresu daty

    cout << "Podaj kategorie: ";
    expense.setItem(AuxiliaryMethods::inputLine());

    cout << "Podaj wartosc: ";
    expense.setValue(AuxiliaryMethods::inputLine()); //dodac zamiane przecinka na kropke
    return expense;
}
int TransactionsManager::getNewIncomeId() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

int TransactionsManager::getNewExpenseId() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}
void TransactionsManager::displayIncomeData() {

}
void TransactionsManager::displayExpenseData() {

}
void TransactionsManager::addIncome() {
    Income income = setNewIncomeData();

    incomes.push_back(income);
    incomesFile.writeIncomeToXmlFile(income);

    cout << endl << "Przychod dodano pomyslnie" << endl << endl;
    system("pause");
}

void TransactionsManager::addExpense() {
    Expense expense = setNewExpenseData();

    expenses.push_back(expense);
    expensesFile.writeExpenseToXmlFile(expense);

    cout << endl << "Wydatek dodano pomyslnie" << endl << endl;
    system("pause");}

void TransactionsManager::showBalanceOfCurrentMonth() {

}
void TransactionsManager::showBalanceOfPreviousMonth() {

}
void TransactionsManager::showBalanceOfSelectedPeriod() {

}

