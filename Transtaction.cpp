#include "Transtaction.h"

void Transtaction::setIncomeId(int newIncomeId) {
    if (newIcomeId>=0){
        incomeId = newIcomeId;
    }
};
void Transtaction::setExpenseId(int newExpenseId) {
    if (newExpenseId>=0){
        expenseId = newExpenseId;
    }
};
void Transtaction::setUserId(int newUserId) {
    if (newUserId>=0){
        userId = newUserId;
    }
};
void Transtaction::setDate(string newDate) {
    date = newDate;
};
void Transtaction::setItem(string newItem) {
    item = newItem;
};
void Transtaction::setValue(string newValue) {
    value = newValue;
};

int Transtaction::getIncomeId() {
    return incomeId;
};
int Transtaction::getExpenseId() {
    return expenseId;
};
int Transtaction::getUserId() {
    return userId;
};
string Transtaction::getDate() {
    return date;
};
string Transtaction::getItem() {
    return item;
};
string Transtaction::getValue() {
    return value;
};
