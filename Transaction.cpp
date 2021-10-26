#include "Transaction.h"

//void Transaction::setIncomeId(int newIncomeId) {
//    if (newIncomeId>=0){
//        incomeId = newIncomeId;
//    }
//}
//void Transaction::setExpenseId(int newExpenseId) {
//    if (newExpenseId>=0){
//        expenseId = newExpenseId;
//    }
//}
void Transaction::setUserId(int newUserId) {
    if (newUserId>=0){
        userId = newUserId;
    }
}
void Transaction::setDate(string newDate) {
    date = newDate;
}
void Transaction::setItem(string newItem) {
    item = newItem;
}
void Transaction::setValue(string newValue) {
    value = newValue;
}

//int Transaction::getIncomeId() {
//    return incomeId;
//};
//int Transaction::getExpenseId() {
//    return expenseId;
//};
int Transaction::getUserId() {
    return userId;
}
string Transaction::getDate() {
    return date;
}
string Transaction::getItem() {
    return item;
}
string Transaction::getValue() {
    return value;
}
