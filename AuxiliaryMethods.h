#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cctype>
#include <ctime>

#include "Markup.h"

using namespace std;

class AuxiliaryMethods {
public:
    static char inputChar();
    static string inputNumber(string inputText, int charPosition);
    static string inputLine();
    static int inputInteger();
    static string swapToFirstCapitalLetterThanLowercaseLetters(string inputText);
    static bool checkDateFormat(string inputDate);
    static bool checkDateScope(string inputDate);
    static string convertDateToIntWithoutDashes(string date);
    static string convertDateToIntWithDashes(string date);
    static string convertCommaToDot(string value);
    static string checkValueFormat(string value);
};

#endif // AUXILIARYMETHODS_H
