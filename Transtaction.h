#ifndef TRANSTACTION_H
#define TRANSTACTION_H


class Transtaction {

public:
    Transtaction();
    int incomeId;
    int expenseId;
    int userId;
    string date;
    string item;
    string value;

public:
    void setIncomeId(int newIncomeId);
    void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setValue(string newValue);

    int getIncomeId();
    int getExpenseId();
    int getUserId();
    string getDate();
    string getItem();
    string getValue();
};

#endif // TRANSTACTION_H
