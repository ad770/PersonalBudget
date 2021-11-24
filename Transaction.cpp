#include "Transaction.h"

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
