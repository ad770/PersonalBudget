#include "TransactionsManager.h"

string TransactionsManager::getCurrentDate() {
    string newDate;
        time_t currentTime;
        time (&currentTime);

        struct tm currentDate;
        currentDate = *localtime(&currentTime);
        if (currentDate.tm_mday<9 && currentDate.tm_mon<9)
            newDate = to_string(currentDate.tm_year +=1900)+"-"+"0"+to_string(currentDate.tm_mon +=1)+"-"+"0"+to_string(currentDate.tm_mday +=1);
        else if (currentDate.tm_mday<9)
            newDate = to_string(currentDate.tm_year +=1900)+"-"+to_string(currentDate.tm_mon +=1)+"-"+"0"+to_string(currentDate.tm_mday +=1);
        else if (currentDate.tm_mon<9)
            newDate = to_string(currentDate.tm_year +=1900)+"-"+"0"+to_string(currentDate.tm_mon +=1)+"-"+to_string(currentDate.tm_mday +=1);
        else
            newDate = to_string(currentDate.tm_year +=1900)+"-"+to_string(currentDate.tm_mon +=1)+"-"+to_string(currentDate.tm_mday +=1);

    return newDate;
}

Income TransactionsManager::setNewIncomeDetails() {
    Income income;
    bool check;
    string newDate;

    income.setUserId(LOGGED_IN_USER_ID);
    income.setTransactionId(getNewTransactionId());
    choice = menu.selectFromIncomesMenu();
    switch (choice) {
    case '1':
        newDate = getCurrentDate();
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
    income.setValue(AuxiliaryMethods::checkValueFormat(AuxiliaryMethods::convertCommaToDot(AuxiliaryMethods::inputLine())));

    return income;
}
Expense TransactionsManager::setNewExpenseDetails() {
    Expense expense;
    bool check;
    string newDate;

    expense.setUserId(LOGGED_IN_USER_ID);
    expense.setTransactionId(getNewTransactionId());
    choice = menu.selectFromExpensesMenu();
    switch (choice) {
    case '1':
        newDate = getCurrentDate();
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
    expense.setValue(AuxiliaryMethods::checkValueFormat(AuxiliaryMethods::convertCommaToDot(AuxiliaryMethods::inputLine())));

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
    system("cls");
    time_t currentTime;
    time (&currentTime);

    struct tm currentDate;
    currentDate = *localtime(&currentTime);
    currentDate.tm_year += 1900;

    double incomesSum = 0;
    double expensesSum = 0;
    double monthlyBalance = 0;

    sort(incomes.begin(), incomes.end(), [](const Income& lhs, const Income& rhs) {
        return lhs.getDate() < rhs.getDate();
    });
    sort(expenses.begin(), expenses.end(), [](const Expense& lhs, const Expense& rhs) {
        return lhs.getDate() < rhs.getDate();
    });

    string beginOfCurrentMonthInString = to_string(currentDate.tm_year)+to_string(currentDate.tm_mon += 1)+"01";

    cout << setw(5) << "Ponizej znajduje sie zestawienie Twojego bilansu z obecnego miesiaca" << endl << endl;

    cout << setw(15) << "Wartosc" << setw(20) << "Kategoria" << setw(15) << "Data" << endl;
    for (auto incomeItr = incomes.begin(); incomeItr != incomes.end(); incomeItr++) {
        if (incomeItr -> getDate() >= beginOfCurrentMonthInString) {
            incomesSum += stod(incomeItr -> getValue());
            cout << setw(15) << incomeItr -> getValue() << setw(20) << incomeItr -> getItem() << setw(15) << AuxiliaryMethods::convertDateToIntWithDashes(incomeItr -> getDate()) << endl;
        }
    }
    cout << setw(30) << "Wplywy ogolem: " << fixed << setprecision(2) << incomesSum << " zl" << endl << endl;

    cout << setw(15) << "Wartosc" << setw(20) << "Kategoria" << setw(15) << "Data" << endl;
    for (auto expenseItr = expenses.begin(); expenseItr != expenses.end(); expenseItr++) {
        if (expenseItr -> getDate() >= beginOfCurrentMonthInString) {
            expensesSum += stod(expenseItr -> getValue());
            cout << setw(15) << expenseItr -> getValue() << setw(20) << expenseItr -> getItem() << setw(15) << AuxiliaryMethods::convertDateToIntWithDashes(expenseItr -> getDate()) << endl;
        }
    }
    cout << setw(30) << "Wydatki ogolem: " << fixed << setprecision(2) << expensesSum << " zl" << endl << endl;

    monthlyBalance = incomesSum - expensesSum;

    cout << "Saldo Twojego konta w biezacym miesiacu wynosi: ";
    if (monthlyBalance>=0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
    cout << fixed << setprecision(2) << monthlyBalance << " zl" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    system("pause");
}
void TransactionsManager::showBalanceOfPreviousMonth() {
    system("cls");
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

    sort(incomes.begin(), incomes.end(), [](const Income& lhs, const Income& rhs) {
        return lhs.getDate() < rhs.getDate();
    });
    sort(expenses.begin(), expenses.end(), [](const Expense& lhs, const Expense& rhs) {
        return lhs.getDate() < rhs.getDate();
    });

    cout << setw(5) << "Ponizej znajduje sie zestawienie Twojego bilansu z poprzedniego miesiaca" << endl << endl;

    cout << setw(15) << "Wartosc" << setw(20) << "Kategoria" << setw(15) << "Data" << endl;
    for (auto incomeItr = incomes.begin(); incomeItr != incomes.end(); incomeItr++) {
        if (incomeItr -> getDate() >= beginOfPreviousMonthInString && incomeItr -> getDate() <= endOfPreviousMonthInString) {
            incomesSum += stod(incomeItr -> getValue());
            cout << setw(15) << incomeItr -> getValue() << setw(20) << incomeItr -> getItem() << setw(15) << AuxiliaryMethods::convertDateToIntWithDashes(incomeItr -> getDate()) << endl;
        }
    }
    cout << setw(30) << "Wplywy ogolem: " << setprecision(2) << incomesSum << " zl" << endl << endl;

    cout << setw(15) << "Wartosc" << setw(20) << "Kategoria" << setw(15) << "Data" << endl;
    for (auto expenseItr = expenses.begin(); expenseItr != expenses.end(); expenseItr++) {
        if (expenseItr -> getDate() >= beginOfPreviousMonthInString && expenseItr -> getDate() <= endOfPreviousMonthInString) {
            expensesSum += stod(expenseItr -> getValue());
            cout << setw(15) << expenseItr -> getValue() << setw(20) << expenseItr -> getItem() << setw(15) << AuxiliaryMethods::convertDateToIntWithDashes(expenseItr -> getDate()) << endl;
        }
    }
    cout << setw(30) << "Wydatki ogolem: " << setprecision(2) << expensesSum << " zl" << endl << endl;

    monthlyBalance = incomesSum - expensesSum;

    cout << "Saldo Twojego konta w poprzednim miesiacu wynosi: ";
    if (monthlyBalance>=0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
    cout << fixed << setprecision(2) << monthlyBalance << " zl" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    system("pause");
}
void TransactionsManager::showBalanceOfSelectedPeriod() {
    system("cls");
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

    sort(incomes.begin(), incomes.end(), [](const Income& lhs, const Income& rhs) {
        return lhs.getDate() < rhs.getDate();
    });
    sort(expenses.begin(), expenses.end(), [](const Expense& lhs, const Expense& rhs) {
        return lhs.getDate() < rhs.getDate();
    });

    cout << setw(5) << "Ponizej znajduje sie zestawienie Twojego bilansu w okresie " <<
    AuxiliaryMethods::convertDateToIntWithDashes(beginOfSelectedPeriodInString) << " - " << AuxiliaryMethods::convertDateToIntWithDashes(endOfSelectedPeriodInString) << endl << endl;

    cout << setw(15) << "Wartosc" << setw(20) << "Kategoria" << setw(15) << "Data" << endl;
    for (vector <Income>::iterator incomeItr = incomes.begin(); incomeItr != incomes.end(); incomeItr++) {
        if (incomeItr -> getDate() >= beginOfSelectedPeriodInString && incomeItr -> getDate() <= endOfSelectedPeriodInString) {
            incomesSum += stod(incomeItr -> getValue());
            cout << setw(15) << incomeItr -> getValue() << setw(20) << incomeItr -> getItem() << setw(15) << AuxiliaryMethods::convertDateToIntWithDashes(incomeItr -> getDate()) << endl;
        }
    }
    cout << setw(30) << "Wplywy ogolem: " << setprecision(2) << incomesSum << " zl" << endl << endl;

    cout << setw(15) << "Wartosc" << setw(20) << "Kategoria" << setw(15) << "Data" << endl;
    for (vector <Expense>::iterator expenseItr = expenses.begin(); expenseItr != expenses.end(); expenseItr++) {
        if (expenseItr -> getDate() >= beginOfSelectedPeriodInString && expenseItr -> getDate() <= endOfSelectedPeriodInString) {
            expensesSum += stod(expenseItr -> getValue());
            cout << setw(15) << expenseItr -> getValue() << setw(20) << expenseItr -> getItem() << setw(15) << AuxiliaryMethods::convertDateToIntWithDashes(expenseItr -> getDate()) << endl;
        }
    }
    cout << setw(30) << "Wydatki ogolem: " << setprecision(2) << expensesSum << " zl" << endl << endl;

    monthlyBalance = incomesSum - expensesSum;

    cout << "Saldo Twojego konta w wybranym okresie wynosi: ";
    if (monthlyBalance>=0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
    cout << fixed << setprecision(2) << monthlyBalance << " zl" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    system("pause");
}

