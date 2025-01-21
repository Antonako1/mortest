#include <iostream>
#include <string>
#include <ATRC.h>
#include <Windows.h>
#include <conio.h>
#include "../include/mor.hpp"

void displayMenu(const std::string menuItems[], int menuSize, int selected) {
    system("cls"); // Clear screen
    std::cout << CONSOLE_COLOUR_CYAN << "========= ATRC Data Viewer =========" << CONSOLE_COLOR_RESET << "\n";
    for (int i = 0; i < menuSize; i++) {
        if (i == selected) {
            // Highlight selected menu item
            std::cout << CONSOLE_COLOUR_WHITE_BG << CONSOLE_COLOUR_BLACK;
        }
        std::cout << " " << menuItems[i] << " " << CONSOLE_COLOR_RESET << "\n";
    }
    std::cout << CONSOLE_COLOUR_GREEN << "\nUse UP/DOWN arrows to navigate, ENTER to select, ESC to exit." << CONSOLE_COLOR_RESET << "\n";
}

KeyEventHandleStatus handleMenuKeyEvents(int &selected, int &key, const std::string menuItems[], int menuSize) {
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
        } else if (menuItems[selected] == "View ATRC Settings") {
            std::cout << CONSOLE_COLOUR_MAGENTA << "DEBUG MODE: " << fd["SETTINGS"]["DEBUG"] << CONSOLE_COLOR_RESET << "\n";
        } else if (menuItems[selected] == "Enable/Disable Verbose Mode") {
            mor_ad.VERBOSE = !mor_ad.VERBOSE;
            std::cout << "Verbose mode " << (mor_ad.VERBOSE ? "enabled" : "disabled") << ".\n";
        } else if (menuItems[selected] == "Check Extended Character Blocks") {
            if (fd.DoesExistKey("SETTINGS", "EXTENDED_CHARACTER_BlOCKS")) {
                std::cout << "EXTENDED CHARACTER BLOCKS: '" << fd["SETTINGS"]["EXTENDED_CHARACTER_BlOCKS"] << "'\n";
            } else {
                std::cout << "EXTENDED CHARACTER BLOCKS: NOT FOUND\n";
            }
        } else if (menuItems[selected] == "View Level Data") {
            if (fd.DoesExistKey("SETTINGS", "LEVEL_DATA")) {
                std::cout << "LEVELS FOUND: '" << fd["SETTINGS"]["LEVEL_DATA"] << "'\n";
            } else {
                std::cout << "LEVELS NOT FOUND\n";
            }
        }
        std::cout << "\nPress any key to return to the menu...";
        _getch();
        break;
    case KEY_QUIT:
        mor_ad.state = State::EXIT;
        return EXIT_PROGRAM;
    default:
        break;
    }
    return KEY_EVENT_HANDLED;
}