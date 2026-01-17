//
// Created by lax on 1/17/26.
//

#ifndef TERMINALMENU_MENU_H
#define TERMINALMENU_MENU_H

#include <string>
#include <iostream>
#include "terminal.h"
#include <vector>

class Menu {
public:
    explicit Menu(std::vector<std::string> &menuItems, int startMenuIndex = 0);
    std::string MenuRun();

private:
    bool isMenu = true;
    int menuIndex = 0;
    std::vector<std::string> *menuItemsPtr;

    void printMenu();
    void increaseMenuIndex();
    void decreaseMenuIndex();
};

#endif //TERMINALMENU_MENU_H