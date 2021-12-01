#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction {

    int userId;
    int transactionId;
    string date;
    string item;
    string value;

public:
    void setUserId(int newUserId);
    void setTransactionId(int newTransactionId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setValue(string newValue);

    int getUserId();
    int getTransactionId();
    string getDate() const;
    string getItem();
    string getValue();
};

#endif // TRANSACTION_H
