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
    //dodac sprawdzanie poprawnosci zapisania danych
    incomesFile.writeIncomeToXmlFile(income);

    cout << endl << "Przychod dodano pomyslnie" << endl << endl;
    system("pause");
}

void TransactionsManager::addExpense() {
    Expense expense = setNewExpenseData();

    expenses.push_back(expense);
    //dodac sprawdzanie poprawnosci zapisania danych
    expensesFile.writeExpenseToXmlFile(expense);

    cout << endl << "Wydatek dodano pomyslnie" << endl << endl;
    system("pause");
}

void TransactionsManager::showBalanceOfCurrentMonth() {
    time_t currentTime;
    time (&currentTime);

    struct tm currentMonth;
    currentMonth = *localtime(&currentTime);

    double incomesSum = 0;
    double expensesSum = 0;
    double monthlyBalance = 0;

    string beginOfCurrentMonthInString = to_string(currentMonth.tm_year += 1900)+to_string(currentMonth.tm_mon += 1)+"01";

    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        if (itr -> getDate() >= beginOfCurrentMonthInString) {
            incomesSum += stod(itr -> getValue());
            cout << incomesSum << endl;
        }
    }

    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
        if (itr -> getDate() >= beginOfCurrentMonthInString) {
            expensesSum += stod(itr -> getValue());
            cout << expensesSum << endl;
        }
    }
    monthlyBalance = incomesSum - expensesSum;

    cout << "Saldo Twojego konta w biezacym miesiacu wynosi: ";
    if (monthlyBalance>=0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
    cout << monthlyBalance << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    system("pause");
}
void TransactionsManager::showBalanceOfPreviousMonth() {

}
void TransactionsManager::showBalanceOfSelectedPeriod() {

}

