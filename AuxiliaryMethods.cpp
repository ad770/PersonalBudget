#include "AuxiliaryMethods.h"

char AuxiliaryMethods::inputChar() {
    string input = "";
    char textChar  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            textChar = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return textChar;
}
string AuxiliaryMethods::inputNumber(string inputText, int charPosition) {
    string number = "";
    while(isdigit(inputText[charPosition]) == true) {
        number += inputText[charPosition];
        charPosition ++;
    }
    return number;
}
string AuxiliaryMethods::inputLine() {
    string input = "";
    getline(cin, input);
    return input;
}
int AuxiliaryMethods::inputInteger() {
    string input = "";
    int number = 0;

    while (true) {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}
string AuxiliaryMethods::swapToFirstCapitalLetterThanLowercaseLetters(string inputText) {
    if (!inputText.empty()) {
        transform(inputText.begin(), inputText.end(), inputText.begin(), ::tolower);
        inputText[0] = toupper(inputText[0]);
    }
    return inputText;
}
bool AuxiliaryMethods::checkDateFormat(string inputDate) {
    bool check = true;

    for (int i=0; i<10; i++) {
        if (i==4 || i==7) {
            if (inputDate[i] != 45) check = false;
            continue;
        } else if (inputDate[i] < 48 || inputDate[i] > 57) check = false;
    }
    return check;
}
bool AuxiliaryMethods::checkDateScope(string inputDate) {
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
bool AuxiliaryMethods::checkValueFormat(string inputValue) {
    return true;
}
string AuxiliaryMethods::convertDateToIntWithoutDashes(string date) {
    string dateWithoutDashes = date;

    for (int i=0; i<dateWithoutDashes.length(); i++) {
        if (dateWithoutDashes[i]==45)
            dateWithoutDashes.erase(i,1);
    }
//    string dateWithoutDashes = date.erase(4,1);
//    dateWithoutDashes = dateWithoutDashes.erase(6,1);
    //zmienic na bardziej zaawansowane --> jezeli znajdziesz znak "-" to go usun
    return dateWithoutDashes;
}
int AuxiliaryMethods::convertCommaToDot(string value) {
    for (int i=0; i<value.length(); i++) {
        if (value[i]==46)
            value[i]=44;
    }
}
int AuxiliaryMethods::stringToInt(string number) {
    int integer;
    string shortNumber;

    shortNumber = number.erase(4,1);
    shortNumber = shortNumber.erase(6,1);

    istringstream iss(shortNumber);
    iss >> integer;

    return integer;
}
string AuxiliaryMethods::intToString(int number) {
    string shortNumber, numberWithDash;

    ostringstream ss;
    ss << number;
    shortNumber = ss.str();
    numberWithDash = shortNumber.insert(4,"-");
    numberWithDash = numberWithDash.insert(7,"-");

    return numberWithDash;
}
void AuxiliaryMethods::isCurrentPasswordCorrect() {

}
void AuxiliaryMethods::loadCurrentDate() {

}
void AuxiliaryMethods::checkLenghtOfTheMonth() {

}
void AuxiliaryMethods::changeFilename(string oldFilename, string newFilename) {
    if (rename(oldFilename.c_str(), newFilename.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << oldFilename << endl;
}
void AuxiliaryMethods::deleteFile(string filenameWithFiletype) {
    if (remove(filenameWithFiletype.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << filenameWithFiletype << endl;
}
