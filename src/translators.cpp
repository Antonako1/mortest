#include "mor.hpp"

void displayTranslatorMenu(
	const std::string translatorItems[],
	int translatorSize,
	int selected
)
{
	system("cls"); // Clear screen
	std::cout << CONSOLE_COLOUR_CYAN << "========= Translator Selector =========" << CONSOLE_COLOR_RESET << "\n";
	for (int i = 0; i < translatorSize; i++) {
		if (i == selected) {
			// Highlight selected menu item
			std::cout << CONSOLE_COLOUR_WHITE_BG << CONSOLE_COLOUR_BLACK;
		}
		std::cout << " " << translatorItems[i] << " " << CONSOLE_COLOR_RESET << "\n";
	}
	std::cout << CONSOLE_COLOUR_GREEN << "\nUse UP/DOWN arrows to navigate, ENTER to select, ESC to exit." << CONSOLE_COLOR_RESET << "\n";
}

KeyEventHandleStatus handleTranslatorMenuKeyEvents(
	int& selected,
	int& key,
	const std::string translatorItems[],
	int translatorSize
) {
	bool getch_at_end = false;
	switch (key) {
	case KEY_UP:
		selected = (selected - 1 + translatorSize) % translatorSize;
		break;
	case KEY_DOWN:
		selected = (selected + 1) % translatorSize;
		break;
	case KEY_ENTER:
		system("cls");
		if (translatorItems[selected] == "Back to Menu") {
			mor_ad.state = State::MENU;
		}
		if (getch_at_end) {
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