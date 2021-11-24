#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
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
    static string convertCommaToDot(string value);
    static int stringToInt(string number);
    static string intToString(int number);
    static void changeFilename(string oldFilename, string newFilename);
    static void deleteFile(string filenameWithFiletype);
};

#endif // AUXILIARYMETHODS_H
