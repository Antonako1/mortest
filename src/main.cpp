#include <iostream>
#include <ATRC.h>

int main() {
    std::cout << "Hello, World!" << std::endl;
    atrc::ATRC_FD fd = atrc::ATRC_FD("c:\\Users\\anton\\Documents\\GitHub\\mortest\\out\\win_64\\Debug\\mortest.conf");
    if(!fd.CheckStatus()){
        std::cout << "Error: ATRC_FD failed to initialize" << std::endl;
        return 1;
    }
    std::cout << "ATRC_FD initialized successfully" << std::endl;
    std::cout << fd["SETTINGS"]["DEBUG"] << std::endl;

    return 0;
}