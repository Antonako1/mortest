#pragma once
#include <iostream>
#include <string>
#include <ATRC.h>
#include <Windows.h>
#include <conio.h>

#define SEPARATOR                   '|'

#define CONSOLE_COLOR_RESET         "\033[0m"
#define CONSOLE_COLOUR_WHITE        "\033[37m"
#define CONSOLE_COLOUR_WHITE_BG     "\033[47m"

#define CONSOLE_COLOUR_BLACK        "\033[30m"
#define CONSOLE_COLOUR_BLACK_BG     "\033[40m"


#define CONSOLE_COLOUR_RED          "\033[31m"  
#define CONSOLE_COLOUR_RED_BG       "\033[41m"

#define CONSOLE_COLOUR_GREEN        "\033[32m"
#define CONSOLE_COLOUR_GREEN_BG     "\033[42m"

#define CONSOLE_COLOUR_YELLOW       "\033[33m"
#define CONSOLE_COLOUR_YELLOW_BG    "\033[43m"

#define CONSOLE_COLOUR_BLUE         "\033[34m"
#define CONSOLE_COLOUR_BLUE_BG      "\033[44m"

#define CONSOLE_COLOUR_MAGENTA      "\033[35m"
#define CONSOLE_COLOUR_MAGENTA_BG   "\033[45m"

#define CONSOLE_COLOUR_CYAN         "\033[36m"
#define CONSOLE_COLOUR_CYAN_BG      "\033[46m"

#define CONSOLE_WARNING             CONSOLE_COLOUR_YELLOW
#define CONSOLE_ERROR               CONSOLE_COLOUR_RED
#define CONSOLE_DEBUG               CONSOLE_COLOUR_BLUE
#define CONSOLE_TRACE               CONSOLE_COLOUR_MAGENTA
#define CONSOLE_SUCCESS             CONSOLE_COLOUR_GREEN
#define CONSOLE_INFO                CONSOLE_COLOUR_WHITE


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define KEY_ESCAPE 27
#define KEY_BACKSPACE 8
#define KEY_SPACE 32
#define KEY_TAB 9
#define KEY_DELETE 83
#define KEY_INSERT 82
#define KEY_HOME 71
#define KEY_END 79
#define KEY_PAGE_UP 73
#define KEY_PAGE_DOWN 81
#define KEY_F1 59
#define KEY_F2 60
#define KEY_F3 61
#define KEY_F4 62
#define KEY_F5 63
#define KEY_F6 64
#define KEY_F7 65
#define KEY_F8 66
#define KEY_F9 67
#define KEY_F10 68
#define KEY_F11 133
#define KEY_F12 134

#define KEY_A 65
#define KEY_B 66
#define KEY_C 67
#define KEY_D 68
#define KEY_E 69
#define KEY_F 70
#define KEY_G 71
#define KEY_H 72
#define KEY_I 73
#define KEY_J 74
#define KEY_K 75
#define KEY_L 76
#define KEY_M 77
#define KEY_N 78
#define KEY_O 79
#define KEY_P 80
#define KEY_Q 81
#define KEY_R 82
#define KEY_S 83
#define KEY_T 84
#define KEY_U 85
#define KEY_V 86
#define KEY_W 87
#define KEY_X 88
#define KEY_Y 89
#define KEY_Z 90

#define KEY_0 48
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_8 56
#define KEY_9 57


#define KEY_a 97
#define KEY_b 98
#define KEY_c 99
#define KEY_d 100
#define KEY_e 101
#define KEY_f 102
#define KEY_g 103
#define KEY_h 104
#define KEY_i 105
#define KEY_j 106
#define KEY_k 107
#define KEY_l 108
#define KEY_m 109
#define KEY_n 110
#define KEY_o 111
#define KEY_p 112
#define KEY_q 113
#define KEY_r 114
#define KEY_s 115
#define KEY_t 116
#define KEY_u 117
#define KEY_v 118
#define KEY_w 119
#define KEY_x 120
#define KEY_y 121
#define KEY_z 122

#define KEY_QUIT    KEY_ESCAPE

enum class State {
    MENU = 0,
    EXIT,
    LEVELS,
    TRANSLATORS,
    VIEW_ATRC_SETTINGS,

    STATE_AMOUNT,
};

typedef struct {
    bool VERBOSE;
    bool RUNNING;
    State state;
} mor_args_n_data_t;

extern mor_args_n_data_t mor_ad;

extern atrc::ATRC_FD fd;

enum class KeyEventHandleStatus {
    KEY_EVENT_HANDLED = 0,
    KEY_EVENT_NOT_HANDLED,
    EXIT_PROGRAM
};

void displayMenu(const std::string menuItems[], int menuSize, int selected);
KeyEventHandleStatus handleMenuKeyEvents(int &selected, int &key, const std::string menuItems[], int menuSize);



#define LEVEL_SELECTOR_HEIGHT       10

void displayLevelSelector(
    const std::string levelItems[], 
    int levelSize, 
    int selected
);
KeyEventHandleStatus handleLevelSelectorKeyEvents(
    int &selected, 
    int &key, 
    const std::string levelItems[], 
    int levelSize
);


void displayTranslatorMenu(
	const std::string translatorItems[],
	int translatorSize,
	int selected
);
KeyEventHandleStatus handleTranslatorMenuKeyEvents(
	int& selected,
	int& key,
	const std::string translatorItems[],
	int translatorSize
);