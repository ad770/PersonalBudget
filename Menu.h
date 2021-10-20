#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "AuxiliaryMethods.h"

class Menu {
public:
    char selectFromMainMenu();
    char selectFromLoggedInUserMenu();
    char selectFromIncomesMenu();
    char selectFromExpensesMenu();
};

#endif // MENU_H
