#include "TransactionsManager.h"

Income TransactionsManager::setNewIncomeDetails() {
    Income income;

    income.setUserId(LOGGED_IN_USER_ID);
    income.setTransactionId(getNewTransactionId());
    bool check;
    string newDate;
    choice = menu.selectFromIncomesMenu();
    switch (choice) {
    case '1':
        time_t currentTime;
        time (&currentTime);

        struct tm currentDate;
        currentDate = *localtime(&currentTime);

        newDate = to_string(currentDate.tm_year +=1900)+"-"+to_string(currentDate.tm_mon +=1)+"-"+to_string(currentDate.tm_mday +=1);
        income.setDate(newDate);
        break;
    case '2':
        do {
            cout << "Podaj date [rrrr-mm-dd]: ";
            newDate = AuxiliaryMethods::inputLine();
            if (AuxiliaryMethods::checkDateFormat(newDate)==false) {
                cout << "Wprowadz date w poprawnym formacie [rrrr-mm-dd], sprobuj ponownie" << endl;
                check = false;
            } else if (AuxiliaryMethods::checkDateScope(newDate)==false) {
                cout << "Wprowadzono niepoprawna date, sprobuj ponownie" << endl;
                check = false;
            } else {
                income.setDate(newDate);
                check = true;
            }
        }        while (check==false);
        break;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("pause");
        break;
    }
    cout << "Podaj kategorie: ";
    income.setItem(AuxiliaryMethods::inputLine());

    cout << "Podaj wartosc: ";
    income.setValue(AuxiliaryMethods::convertCommaToDot(AuxiliaryMethods::inputLine()));

    return income;
}
Expense TransactionsManager::setNewExpenseDetails() {
    Expense expense;

    expense.setUserId(LOGGED_IN_USER_ID);
    expense.setTransactionId(getNewTransactionId());

    bool check;
    string newDate;
    choice = menu.selectFromExpensesMenu();
    switch (choice) {
    case '1':
        time_t currentTime;
        time (&currentTime);

        struct tm currentDate;
        currentDate = *localtime(&currentTime);

        newDate = to_string(currentDate.tm_year +=1900)+"-"+to_string(currentDate.tm_mon +=1)+"-"+to_string(currentDate.tm_mday +=1);
        expense.setDate(newDate);
        break;
    case '2':
        do {
            cout << "Podaj date [rrrr-mm-dd]: ";
            newDate = AuxiliaryMethods::inputLine();
            if (AuxiliaryMethods::checkDateFormat(newDate)==false) {
                cout << "Wprowadz date w poprawnym formacie [rrrr-mm-dd], sprobuj ponownie" << endl;
                check = false;
            } else if (AuxiliaryMethods::checkDateScope(newDate)==false) {
                cout << "Wprowadzono niepoprawna date, sprobuj ponownie" << endl;
                check = false;
            } else {
                expense.setDate(newDate);
                check = true;
            }
        }        while (check==false);
        break;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("pause");
        break;
    }
    cout << "Podaj kategorie: ";
    expense.setItem(AuxiliaryMethods::inputLine());

    cout << "Podaj wartosc: ";
    expense.setValue(AuxiliaryMethods::convertCommaToDot(AuxiliaryMethods::inputLine()));

    return expense;
}

int TransactionsManager::getNewTransactionId() {
    if (incomesFile.getLastTransactionId() > expensesFile.getLastTransactionId())
        return incomesFile.getLastTransactionId()+1;
    else
        return expensesFile.getLastTransactionId()+1;
}

void TransactionsManager::addIncome() {
    Income income = setNewIncomeDetails();
    incomesFile.writeIncomeToXmlFile(income);

    income.setDate(AuxiliaryMethods::convertDateToIntWithoutDashes(income.getDate()));
    incomes.push_back(income);

    cout << endl << "Przychod dodano pomyslnie" << endl << endl;
    system("pause");
}

void TransactionsManager::addExpense() {
    Expense expense = setNewExpenseDetails();
    expensesFile.writeExpenseToXmlFile(expense);

    expense.setDate(AuxiliaryMethods::convertDateToIntWithoutDashes(expense.getDate()));
    expenses.push_back(expense);

    cout << endl << "Wydatek dodano pomyslnie" << endl << endl;
    system("pause");
}

void TransactionsManager::showBalanceOfCurrentMonth() {
    time_t currentTime;
    time (&currentTime);

    struct tm currentDate;
    currentDate = *localtime(&currentTime);
    currentDate.tm_year += 1900;

    double incomesSum = 0;
    double expensesSum = 0;
    double monthlyBalance = 0;

    string beginOfCurrentMonthInString = to_string(currentDate.tm_year)+to_string(currentDate.tm_mon += 1)+"01";

    for (vector <Income>::iterator incomeItr = incomes.begin(); incomeItr != incomes.end(); incomeItr++) {
        if (incomeItr -> getDate() >= beginOfCurrentMonthInString) {
            incomesSum += stod(incomeItr -> getValue());
        }
    }
    cout << "Wplywy: " << incomesSum << endl;
    for (vector <Expense>::iterator expenseItr = expenses.begin(); expenseItr != expenses.end(); expenseItr++) {
        if (expenseItr -> getDate() >= beginOfCurrentMonthInString) {
            expensesSum += stod(expenseItr -> getValue());
        }
    }
    cout << "Wydatki: " << expensesSum << endl;

    monthlyBalance = incomesSum - expensesSum;

    cout << "Saldo Twojego konta w biezacym miesiacu wynosi: ";
    if (monthlyBalance>=0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
    cout << fixed;
    cout << setprecision(2) << monthlyBalance << " zl" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    system("pause");
}
void TransactionsManager::showBalanceOfPreviousMonth() {
    time_t currentTime;
    time (&currentTime);

    struct tm currentDate;
    currentDate = *localtime(&currentTime);
    currentDate.tm_year += 1900;

    double incomesSum = 0;
    double expensesSum = 0;
    double monthlyBalance = 0;

    string beginOfPreviousMonthInString;
    if (currentDate.tm_mon==0)
        beginOfPreviousMonthInString = to_string(currentDate.tm_year -= 1)+to_string(currentDate.tm_mon +=12)+"01";
    else
        beginOfPreviousMonthInString = to_string(currentDate.tm_year)+to_string(currentDate.tm_mon)+"01";

    string endOfPreviousMonthInString;
    if (currentDate.tm_mon==0)
        endOfPreviousMonthInString = to_string(currentDate.tm_year -= 1)+to_string(currentDate.tm_mon +=12)+"31";
    else
        endOfPreviousMonthInString = to_string(currentDate.tm_year)+to_string(currentDate.tm_mon)+"31";

    for (vector <Income>::iterator incomeItr = incomes.begin(); incomeItr != incomes.end(); incomeItr++) {
        if (incomeItr -> getDate() >= beginOfPreviousMonthInString && incomeItr -> getDate() <= endOfPreviousMonthInString) {
            incomesSum += stod(incomeItr -> getValue());
        }
    }
    cout << "Wplywy: " << incomesSum << endl;
    for (vector <Expense>::iterator expenseItr = expenses.begin(); expenseItr != expenses.end(); expenseItr++) {
        if (expenseItr -> getDate() >= beginOfPreviousMonthInString && expenseItr -> getDate() <= endOfPreviousMonthInString) {
            expensesSum += stod(expenseItr -> getValue());
        }
    }
    cout << "Wydatki: " << expensesSum << endl;
    monthlyBalance = incomesSum - expensesSum;

    cout << "Saldo Twojego konta w poprzednim miesiacu wynosi: ";
    if (monthlyBalance>=0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
    cout << fixed;
    cout << setprecision(2) << monthlyBalance << " zl" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    system("pause");
}
void TransactionsManager::showBalanceOfSelectedPeriod() {
    time_t currentTime;
    time (&currentTime);

    struct tm currentDate;
    currentDate = *localtime(&currentTime);
    currentDate.tm_year += 1900;

    double incomesSum = 0;
    double expensesSum = 0;
    double monthlyBalance = 0;

    string beginOfSelectedPeriodInString;
    bool check;
    do {
        cout << "Podaj date poczatkowa [rrrr-mm-dd]: ";
        beginOfSelectedPeriodInString = AuxiliaryMethods::inputLine();
        if (AuxiliaryMethods::checkDateFormat(beginOfSelectedPeriodInString)==false) {
            cout << "Wprowadz date w poprawnym formacie [rrrr-mm-dd], sprobuj ponownie" << endl;
            check = false;
        } else if (AuxiliaryMethods::checkDateScope(beginOfSelectedPeriodInString)==false) {
            cout << "Wprowadzono niepoprawna date, sprobuj ponownie" << endl;
            check = false;
        } else {
            beginOfSelectedPeriodInString = AuxiliaryMethods::convertDateToIntWithoutDashes(beginOfSelectedPeriodInString);;
            check = true;
        }
    } while (check==false);

    string endOfSelectedPeriodInString;
    do {
        cout << "Podaj date koncowa [rrrr-mm-dd]: ";
        endOfSelectedPeriodInString = AuxiliaryMethods::inputLine();
        if (AuxiliaryMethods::checkDateFormat(endOfSelectedPeriodInString)==false) {
            cout << "Wprowadz date w poprawnym formacie [rrrr-mm-dd], sprobuj ponownie" << endl;
            check = false;
        } else if (AuxiliaryMethods::checkDateScope(endOfSelectedPeriodInString)==false) {
            cout << "Wprowadzono niepoprawna date, sprobuj ponownie" << endl;
            check = false;
        } else {
            endOfSelectedPeriodInString = AuxiliaryMethods::convertDateToIntWithoutDashes(endOfSelectedPeriodInString);;
            check = true;
        }
    } while (check==false);

    for (vector <Income>::iterator incomeItr = incomes.begin(); incomeItr != incomes.end(); incomeItr++) {
        if (incomeItr -> getDate() >= beginOfSelectedPeriodInString && incomeItr -> getDate() <= endOfSelectedPeriodInString) {
            incomesSum += stod(incomeItr -> getValue());
        }
    }
    cout << "Wplywy: " << incomesSum << endl;
    for (vector <Expense>::iterator expenseItr = expenses.begin(); expenseItr != expenses.end(); expenseItr++) {
        if (expenseItr -> getDate() >= beginOfSelectedPeriodInString && expenseItr -> getDate() <= endOfSelectedPeriodInString) {
            expensesSum += stod(expenseItr -> getValue());
        }
    }
    cout << "Wydatki: " << expensesSum << endl;
    monthlyBalance = incomesSum - expensesSum;

    cout << "Saldo Twojego konta w poprzednim miesiacu wynosi: ";
    if (monthlyBalance>=0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
    cout << fixed;
    cout << setprecision(2) << monthlyBalance << " zl" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    system("pause");
}

