#include "Transaction.h"

void Transaction::setUserId(int newUserId) {
    if (newUserId>=0){
        userId = newUserId;
    }
}
void Transaction::setTransactionId(int newTransactionId) {
    if (newTransactionId>=0){
        transactionId = newTransactionId;
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

int Transaction::getUserId() {
    return userId;
}
int Transaction::getTransactionId() {
    return transactionId;
}
string Transaction::getDate() const {
    return date;
}
string Transaction::getItem() {
    return item;
}
string Transaction::getValue() {
    return value;
}
