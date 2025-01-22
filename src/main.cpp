#include "mor.hpp"
#include <filesystem>
mor_args_n_data_t mor_ad;
atrc::ATRC_FD fd;

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "-V") {
            mor_ad.VERBOSE = true;
        }
    }

    // Initialize ATRC
    LPSTR final = new CHAR[MAX_PATH];
    DWORD exePath = GetModuleFileNameA(NULL, final, MAX_PATH);
    if(GetLastError() == ERROR_INSUFFICIENT_BUFFER) {
        std::cerr << CONSOLE_COLOUR_RED << "Error: GetModuleFileNameA failed to get the path" << CONSOLE_COLOR_RESET << std::endl;
        if(final) delete[] final;
        return 1;
    }
    std::string path = final;
    delete[] final;    

    path = path.substr(0, path.find_last_of("\\/"));
    path += "\\mortest.data";
    fd.Read(path.c_str(), ReadMode::ATRC_READ_ONLY);
    if (!fd.CheckStatus()) {
        std::cerr << CONSOLE_COLOUR_RED << "Error: ATRC_FD failed to initialize" << CONSOLE_COLOR_RESET << std::endl;
        return 1;
    }

    std::cout << CONSOLE_COLOUR_GREEN << "ATRC data initialized successfully" << CONSOLE_COLOR_RESET << std::endl;


    // Start menu
    const std::string menuItems[] = {
        "Levels",
        "Translators",
        "View ATRC Settings",
        "Exit"
    };
    const int menuSize = sizeof(menuItems) / sizeof(menuItems[0]);
    int menuSelected = 0;
    // End menu

    // Load levels
    std::vector<std::string> levels = atrc::atrc_to_vector(SEPARATOR, fd["SETTINGS"]["LEVEL_DATA"]);
    levels.push_back("Back to Menu");
    int levelCount = (int)levels.size();
    int levelSelected = 0;
    // End load levels

	// Translators
    const std::string translatorItems[] = {
		"Morse to English",
		"English to Morse",
		"Morse audio to Morse",
		"Morse audio to English",
        "Morse to Audio",
		"Back to Menu"
    };
	const int translatorSize = sizeof(translatorItems) / sizeof(translatorItems[0]);
	int translatorSelected = 0;
	// End translators

    mor_ad.RUNNING = true;
    mor_ad.state = State::MENU;
    while (mor_ad.RUNNING) {
        switch (mor_ad.state) {
        case State::MENU: {
            displayMenu(
                menuItems, 
                menuSize, 
                menuSelected
                );
            int key = _getch();
            handleMenuKeyEvents(menuSelected, key, menuItems, menuSize);
        } break;
        case State::LEVELS: {
            displayLevelSelector(
                levels.data(), 
                levelCount, 
                levelSelected
                );
            int key = _getch();
            handleLevelSelectorKeyEvents(levelSelected, key, levels.data(), levelCount);
        } break;
        case State::TRANSLATORS: {
            displayTranslatorMenu(
                translatorItems,
                translatorSize,
                translatorSelected
            );
            int key = _getch();
            handleTranslatorMenuKeyEvents(
                translatorSelected,
                key,
                translatorItems,
                translatorSize
            );
        } break;
        case State::VIEW_ATRC_SETTINGS: {

        } break;
        default:
            mor_ad.state = State::MENU;
            break;
        case State::EXIT:         
            mor_ad.RUNNING = false;
            break;
        } 
    }

    return 0;
}
