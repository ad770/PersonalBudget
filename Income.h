#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "Transaction.h"

using namespace std;

class Income : public Transaction {
    int incomeId;

public:
    Income();

    void setIncomeId(int newIncomeId);

    int getIncomeId();
};

#endif // INCOME_H
