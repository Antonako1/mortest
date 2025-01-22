#include <iostream>
#include <string>
#include <ATRC.h>
#include <Windows.h>
#include <conio.h>
#include "mor.hpp"

void displayMenu(const std::string menuItems[], int menuSize, int selected) {
    system("cls"); // Clear screen
    std::cout << CONSOLE_COLOUR_CYAN << "========= MORTEST MORSE PROGRAM =========" << CONSOLE_COLOR_RESET << "\n";
    for(int i = 0; i < menuSize; i++) {
        if(i == selected) {
            // Highlight selected menu item
            std::cout << CONSOLE_COLOUR_WHITE_BG << CONSOLE_COLOUR_BLACK;
        }
        std::cout << " " << menuItems[i] << " " << CONSOLE_COLOR_RESET << "\n";
    }
    std::cout << CONSOLE_COLOUR_GREEN << "\nUse UP/DOWN arrows to navigate, ENTER to select, ESC to exit." << CONSOLE_COLOR_RESET << "\n";
}

KeyEventHandleStatus handleMenuKeyEvents(int &selected, int &key, const std::string menuItems[], int menuSize) {
    bool getch_at_end = true;
    switch (key) {
    case KEY_UP:
        selected = (selected - 1 + menuSize) % menuSize;
        break;
    case KEY_DOWN:
        selected = (selected + 1) % menuSize;
        break;
    case KEY_ENTER:
        system("cls");
        if (menuItems[selected] == "Exit") {
            mor_ad.RUNNING = false;
            getch_at_end = false;
        } else if(menuItems[selected] == "Levels") {
            mor_ad.state = State::LEVELS;
        } else if(menuItems[selected] == "Translators") {
            mor_ad.state = State::TRANSLATORS;
        } else if(menuItems[selected] == "View ATRC Settings") {
            mor_ad.state = State::VIEW_ATRC_SETTINGS;
        }
        
        // if(getch_at_end){
        //     std::cout << "\nPress any key to continue...";
        //     _getch();
        // }
        break;
    case KEY_QUIT:
        mor_ad.state = State::EXIT;
        return KeyEventHandleStatus::EXIT_PROGRAM;
    default:
        break;
    }
    return KeyEventHandleStatus::KEY_EVENT_HANDLED;
}