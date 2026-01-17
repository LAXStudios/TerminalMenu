//
// Created by lax on 1/17/26.
//

#include "menu.h"

Menu::Menu(std::vector<std::string> &menuItems, int startMenuIndex) {
    menuItemsPtr = &menuItems;
    menuIndex = startMenuIndex;
}

std::string Menu::MenuRun() {
    printMenu();

    // Main Menu loop
    while (isMenu) {

        KeyResult keyResult = readKey();

        if (keyResult.character == 'q') {
            isMenu = false;
            break;
        }

        if (keyResult.character == '\n') {
            return menuItemsPtr->at(menuIndex);
        }

        switch (keyResult.keyType) {
            case Key::ArrowUp:
                decreaseMenuIndex();
                break;
            case Key::ArrowDown:
                increaseMenuIndex();
                break;
            default:

                break;
        }
        clearScreen();
        printMenu();
    }
}

void Menu::increaseMenuIndex() {
    if (menuIndex < menuItemsPtr->size() - 1) {
        menuIndex++;
    } else {
        menuIndex = 0;
    }
}

void Menu::decreaseMenuIndex() {
    if (menuIndex > 0 && menuIndex < menuItemsPtr->size()) {
        menuIndex--;
    } else {
        menuIndex = menuItemsPtr->size() - 1;
    }
}

void Menu::printMenu() {
    for (int i = 0; i < menuItemsPtr->size(); i++) {
        if (i == menuIndex) {
            std::cout << "> " << menuItemsPtr->at(i) << std::endl;
        } else {
            std::cout << "  " << menuItemsPtr->at(i) << std::endl;
        }
    }
    std::cout << menuIndex <<std::endl;
}