#include <iostream>
#include <vector>
#include "terminal.h"
#include "menu.h"

int main() {

    // Example Code:
    RawMode rawMode{};

    std::vector<std::string> mainMenuItems = {"Option 1", "Option 2", "Option 3", "Settings", "Exit"};
    Menu menu(mainMenuItems);
    const std::string selected= menu.MenuRun();

    std::cout << selected << std::endl;

    return 0;
}