#ifdef _MSC_VER
#include <windows.h>
#endif
#include <iostream>
#include "ansi_cui.hpp"
#include "ansi_cui.h"

#if __cplusplus <= 199711L
    #error This demo needs at least a C++11 compliant compiler
#endif

#ifdef _MSC_VER
// Enable VT Mode on Windows 10
bool EnableVTMode()
{
    // Set output mode to handle virtual terminal sequences
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return false;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        return false;
    }
    return true;
}
#endif

int main(int argc, char* argv[])
{
#ifdef _MSC_VER
    // enable vt mode on windows 10
    EnableVTMode();
#endif

    //here is cpp demo
    ansi_cui::screen::clear(std::cout);
    ansi_cui::cursor::move_to(20, 20);
    std::cout << "hello";
    ansi_cui::cursor::move_to(15, 15);
    ansi_cui::screen::set_graphic({ansi_cui::screen::foreground_green});
    std::cout << "world";

    // here is c demo
    cursor_move_to(10, 40);
    screen_set_graphic({ansi_cui::screen::background_blue});
    printf("This is cpp11+ demo \nAny key to continue");

    std::cin.get();
    return 0;
}
