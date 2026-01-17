#include <iostream>
#include <vector>
#include "terminal.h"
#include "menu.h"

void printMenu() {
    std::cout <<
        "\n=== Hauptmenü ===\n"
        "1) Option Eins\n"
        "2) Option Zwei\n"
        "q) Beenden\n"
        "Wähle: " << std::flush;
}

int main() {

    RawMode rawMode{};

    std::vector<std::string> mainMenuItems = {"Add File", "Edit File", "List all Files", "Settings", "Exit"};
    Menu menu(mainMenuItems);
    const std::string selected= menu.MenuRun();

    std::cout << selected << std::endl;

    return 0;
}