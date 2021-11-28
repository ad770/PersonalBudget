#include "Menu.h"

char Menu::selectFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::inputChar();

    return choice;
}

char Menu::selectFromLoggedInUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::inputChar();

    return choice;
}

char Menu::selectFromIncomesMenu() {
    char choice;

    system("cls");
    cout << endl << "   >>> DODAJ PRZYCHOD <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1 - Dodaj dzisiejszy przychod" << endl;
    cout << "2 - Dodaj przychod z inna data" << endl;
    cout << endl << "Twoj wybor: ";
    choice = AuxiliaryMethods::inputChar();

    return choice;
}

char Menu::selectFromExpensesMenu() {
    char choice;

    system("cls");
    cout << endl << "   >>> DODAJ WYDATEK <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1 - Dodaj dzisiejszy wydatek" << endl;
    cout << "2 - Dodaj wydatek z inna data" << endl;
    cout << endl << "Twoj wybor: ";
    choice = AuxiliaryMethods::inputChar();

    return choice;
}
