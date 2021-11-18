#include "ExpensesFile.h"

int ExpensesFile::getUserIdFromXmlFile() {

}
//Expense ExpensesFile::getExpenseData() {
//
//}
vector <Expense> ExpensesFile::loadExpensesOfLoggedInUserFromXmlFile(int loggedInUserId) {
    CMarkup xml;
    Expense expense;
    vector <Expense> expenses;

    if (!xml.Load(getFilename())) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("ExpensesFile");
        xml.Save(getFilename());
    }
    xml.FindElem("ExpensesFile");
    xml.IntoElem();

    while (xml.FindElem("Expense")) {
        xml.IntoElem();

        xml.FindElem("ExpenseId");
        expense.setExpenseId(atoi(xml.GetData().c_str()));
        xml.FindElem("UserId");
        expense.setUserId(atoi(xml.GetData().c_str()));
        xml.FindElem("Date");
        expense.setDate(AuxiliaryMethods::convertDateToIntWithoutDashes(xml.GetData()));
        xml.FindElem("Item");
        expense.setItem(xml.GetData());
        xml.FindElem("Value");
        expense.setValue(xml.GetData());

        expenses.push_back(expense);

        xml.OutOfElem();
    }

    return expenses;
}
int ExpensesFile::loadLastExpenseIdFromXmlFile() {

}
void ExpensesFile::writeExpenseToXmlFile(Expense expense) {
    CMarkup xml;
    if (!xml.Load(getFilename())) {
        cout << "Blad odczytu pliku!";
    } else {

        xml.FindElem("ExpensesFile");
        xml.IntoElem();
        xml.AddElem("Expense");
        xml.IntoElem();
        xml.AddElem("UserId",expense.getUserId());
        xml.AddElem("Date",expense.getDate());
        xml.AddElem("Item",expense.getItem());
        xml.AddElem("Value",expense.getValue());

        xml.OutOfElem();
        xml.OutOfElem();

        xml.Save(getFilename());
    }
}
int ExpensesFile::getExpenseIdFromXmlFile() {

}
