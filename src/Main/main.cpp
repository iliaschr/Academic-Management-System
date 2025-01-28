// ../src/Main/main.cpp

#include "../Menu/menu.hpp"

int main() {
    // Create a Secretary object
    Secretary secretary;

    // Menu-driven loop
    int choice;

    Menu::mainMenu(secretary, choice);

    return 0;
}
