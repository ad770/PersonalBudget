#include "IncomesFile.h"

vector <Income> IncomesFile::loadIncomesOfLoggedInUserFromXmlFile(int loggedInUserId) {
    CMarkup xml;
    Income income;
    vector <Income> incomes;

    if (!xml.Load(getFilename())) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("IncomesFile");
        xml.Save(getFilename());
    }
    xml.FindElem("IncomesFile");
    xml.IntoElem();

    while (xml.FindElem("Income")) {
        xml.IntoElem();

        xml.FindElem("UserId");
        if (atoi(xml.GetData().c_str())!=loggedInUserId)
            xml.OutOfElem();
        else {
            income.setUserId(atoi(xml.GetData().c_str()));
            xml.FindElem("TransactionId");
            income.setTransactionId(atoi(xml.GetData().c_str()));
            xml.FindElem("Date");
            income.setDate(AuxiliaryMethods::convertDateToIntWithoutDashes(xml.GetData()));
            xml.FindElem("Item");
            income.setItem(xml.GetData());
            xml.FindElem("Value");
            income.setValue(xml.GetData());

            incomes.push_back(income);
            xml.OutOfElem();
        }
    }
    return incomes;
}
void IncomesFile::writeIncomeToXmlFile(Income income) {
    CMarkup xml;
    if (!xml.Load(getFilename())) {
        cout << "Blad odczytu pliku!";
    } else {

        xml.FindElem("IncomesFile");
        xml.IntoElem();
        xml.AddElem("Income");
        xml.IntoElem();
        xml.AddElem("UserId",income.getUserId());
        xml.AddElem("TransactionId",income.getTransactionId());
        xml.AddElem("Date",income.getDate());
        xml.AddElem("Item",income.getItem());
        xml.AddElem("Value",income.getValue());

        xml.OutOfElem();
        xml.OutOfElem();

        xml.Save(getFilename());
    }
}

int IncomesFile::getLastTransactionId() {
    CMarkup xml;
    int lastTransactionId = 0;
    if (!xml.Load(getFilename())) {
        cout << "Blad odczytu pliku!";
    } else {

        xml.FindElem("IncomesFile");
        xml.IntoElem();
        while (xml.FindElem("Income")) {
            xml.IntoElem();
            xml.FindElem("TransactionId");
            lastTransactionId = atoi(xml.GetData().c_str());
            xml.OutOfElem();
        }
    }
    return lastTransactionId;
}
