#include "mor.hpp"

void displayLevelSelector(
    const std::string levelItems[], 
    int levelSize, 
    int selected
)
{
    system("cls"); // Clear screen
    std::cout << CONSOLE_COLOUR_CYAN << "========= Level Selector =========" << CONSOLE_COLOR_RESET << "\n";
    for (int i = 0; i < levelSize; i++) {
        if (i == selected) {
            // Highlight selected menu item
            std::cout << CONSOLE_COLOUR_WHITE_BG << CONSOLE_COLOUR_BLACK;
        }
        std::cout << " " << levelItems[i] << " " << CONSOLE_COLOR_RESET << "\n";
    }
    std::cout << CONSOLE_COLOUR_GREEN << "\nUse UP/DOWN arrows to navigate, ENTER to select, ESC to exit." << CONSOLE_COLOR_RESET << "\n";
}


KeyEventHandleStatus handleLevelSelectorKeyEvents(
    int &selected, 
    int &key, 
    const std::string levelItems[], 
    int levelSize
){
    bool getch_at_end = false;
    switch (key) {
    case KEY_UP:
        selected = (selected - 1 + levelSize) % levelSize;
        break;
    case KEY_DOWN:
        selected = (selected + 1) % levelSize;
        break;
    case KEY_ENTER:
        system("cls");
        if (levelItems[selected] == "Back to Menu") {
            mor_ad.state = State::MENU;
        }
        
        if(getch_at_end){
            std::cout << "\nPress any key to continue...";
            _getch();
        }
        break;
    case KEY_QUIT:
        mor_ad.state = State::EXIT;
        return KeyEventHandleStatus::EXIT_PROGRAM;
    default:
        break;
    }
    return KeyEventHandleStatus::KEY_EVENT_HANDLED;
}