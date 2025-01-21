#include <iostream>
#include <string>
#include <ATRC.h>
#include <Windows.h>
#include <conio.h>
#include "../include/mor.hpp"


mor_args_n_data_t mor_ad;
atrc::ATRC_FD fd;



int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "-V") {
            mor_ad.VERBOSE = true;
        }
    }

    // Initialize ATRC
    fd.Read("c:\\Users\\anton\\Documents\\GitHub\\mortest\\out\\win_64\\Debug\\mortest.data", ReadMode::ATRC_READ_ONLY);
    if (!fd.CheckStatus()) {
        std::cerr << CONSOLE_COLOUR_RED << "Error: ATRC_FD failed to initialize" << CONSOLE_COLOR_RESET << std::endl;
        return 1;
    }

    std::cout << CONSOLE_COLOUR_GREEN << "ATRC data initialized successfully" << CONSOLE_COLOR_RESET << std::endl;



    // Start menu
    const std::string menuItems[] = {
        "View ATRC Settings",
        "Enable/Disable Verbose Mode",
        "Check Extended Character Blocks",
        "View Level Data",
        "Exit"
    };
    const int menuSize = sizeof(menuItems) / sizeof(menuItems[0]);
    int selected = 0;
    // End menu

    mor_ad.RUNNING = true;
    mor_ad.state = State::MENU;
    while (mor_ad.RUNNING) {
        switch (mor_ad.state) {
        int key = _getch();
        case State::MENU:
            displayMenu(menuItems, menuSize, selected);
            handleMenuKeyEvents(selected, key, menuItems, menuSize);
            break;
        case State::EXIT:         
            mor_ad.RUNNING = false;
            break;
        }
    }

    return 0;
}
