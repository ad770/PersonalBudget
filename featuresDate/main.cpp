#include <iostream>
#include <ctime>
#include <string>
#include "Markup.h"

using namespace std;

bool checkDateFormat(string inputDate) {
    bool check = true;

    for (int i=0; i<10; i++) {
        if (i==4 || i==7) {
            if (inputDate[i] != 45) check = false;
            continue;
        } else if (inputDate[i] < 48 || inputDate[i] > 57) check = false;
    }
    return check;
}

bool checkDateScope(string inputDate) {
    bool check = true;

    int year = atoi(inputDate.substr(0,4).c_str());
    int month = atoi(inputDate.substr(5,2).c_str());
    int day = atoi(inputDate.substr(8,2).c_str());

    bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (month > 12) check = false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) check = false;
    else if (month == 2 && leapYear == 1 && day > 29) check = false;
    else if (month == 2 && leapYear == 0 && day > 28) check = false;
    else if (day > 31) check = false;

    return check;
}

void compareDates(string inputDate) {

    time_t currentTime;
    time (&currentTime);

    struct tm dateToCompare;
    dateToCompare = *localtime(&currentTime);

    dateToCompare.tm_year = atoi(inputDate.substr(0,4).c_str())-1900;
    dateToCompare.tm_mon = atoi(inputDate.substr(5,2).c_str())-1;
    dateToCompare.tm_mday = atoi(inputDate.substr(8,2).c_str());

    double dayDifference = difftime(currentTime, mktime(&dateToCompare))/86400;

    cout << "The difference between current day is " << dayDifference << " days" << endl;
}

void createXML();

int main()
{
    string value, inputDate;

    CMarkup xml;

    if (!xml.Load("incomes.xml")) {
        createXML();
        xml.Load("incomes.xml");
    }

    xml.FindElem("incomesFile");
    xml.IntoElem();

    while (xml.FindElem("income")) {
        xml.IntoElem();

        xml.FindElem("date");
        inputDate = xml.GetData();

        if (checkDateFormat(inputDate)==true && checkDateScope(inputDate)==true) {
            compareDates(inputDate);
        } else {
            cout << inputDate << " does not exist or has the wrong format!" << endl << endl;
            xml.OutOfElem();
            continue;
        }

        xml.FindElem("value");
        value = xml.GetData();

        cout << "date - " << inputDate << endl;
        cout << "value - " << value << endl << endl;

        xml.OutOfElem();
    }

    return 0;
}

void createXML() {
        CMarkup xml;

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("incomesFile");
        xml.IntoElem();
        xml.AddElem("income");
        xml.IntoElem();
        xml.AddElem("incomeId", "1");
        xml.AddElem("userId", "1");
        xml.AddElem("date", "2021-07-05");
        xml.AddElem("item", "fuel");
        xml.AddElem("value", "300.00");
        xml.OutOfElem();
        xml.AddElem("income");
        xml.IntoElem();
        xml.AddElem("incomeId", "2");
        xml.AddElem("userId", "1");
        xml.AddElem("date", "2021.08-06");
        xml.AddElem("item", "food");
        xml.AddElem("value", "60.00");
        xml.OutOfElem();
        xml.AddElem("income");
        xml.IntoElem();
        xml.AddElem("incomeId", "3");
        xml.AddElem("userId", "1");
        xml.AddElem("date", "2021-09-06");
        xml.AddElem("item", "cinema");
        xml.AddElem("value", "60.00");
        xml.OutOfElem();
        xml.AddElem("income");
        xml.IntoElem();
        xml.AddElem("incomeId", "4");
        xml.AddElem("userId", "1");
        xml.AddElem("date", "2021-09-31");
        xml.AddElem("item", "cinema");
        xml.AddElem("value", "60.00");
        xml.OutOfElem();

        xml.Save("incomes.xml");
}
