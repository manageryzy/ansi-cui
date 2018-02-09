#include <stdio.h>
#include "ansi_cui.h"

int main(int argc, char *argv[])
{
    //here is cpp demo
    screen_clear(stdout);
    cursor_move_to(20, 20, stdout);
    printf("hello");
    cursor_move_to(15, 15, stdout);
    screen_set_graphic(32, stdout);
    printf("world");

    // here is c demo
    cursor_move_to(10, 40, stdout);
    screen_set_graphic(44, stdout);
    printf("This is pure c demo \nAny key to continue");

    getchar();
    return 0;
}
