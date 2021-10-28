#include "IncomesFile.h"

int IncomesFile::getUserIdFromXmlFile() {

}
//Income IncomesFile::getIncomeData() {
//
//}
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

        xml.FindElem("IncomeId");
        income.setIncomeId(atoi(xml.GetData().c_str()));
        xml.FindElem("UserId");
        income.setUserId(atoi(xml.GetData().c_str()));
        xml.FindElem("Date");
        income.setDate(xml.GetData());
        xml.FindElem("Item");
        income.setItem(xml.GetData());
        xml.FindElem("Value");
        income.setValue(xml.GetData());

        incomes.push_back(income);

        xml.OutOfElem();
    }

    return incomes;
}
int IncomesFile::loadLastIncomeIdFromXmlFile() {

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
        xml.AddElem("Date",income.getDate());
        xml.AddElem("Item",income.getItem());
        xml.AddElem("Value",income.getValue());

        xml.OutOfElem();
        xml.OutOfElem();

        xml.Save(getFilename());
    }
}
int IncomesFile::getIncomeIdFromXmlFile() {

}
