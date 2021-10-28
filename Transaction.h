#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction {

    //int incomeId;
    //int expenseId;
    int userId;
    string date;
    string item;
    string value;

public:
    //void setIncomeId(int newIncomeId);
    //void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setValue(string newValue);

    //int getIncomeId();
    //int getExpenseId();
    int getUserId();
    string getDate();
    string getItem();
    string getValue();
};

#endif // TRANSACTION_H
