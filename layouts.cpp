#include <ncurses.h>
#include <string>
#include <iostream>

using std::string;
using std::cout;

string hangman_stages[7] = {
    //"  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",

    "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",

    "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",

    "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",

    "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========", 

    "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",

    "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",

    "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n"
};

void draw_slogan(int x_start) {
    mvprintw(x_start+0, 0, "#  #   ####  #   #  ####  #   #   ####  #   #" );
    mvprintw(x_start+1, 0, "#  #   #  #  ##  #  #     ## ##   #  #  ##  #" );
    mvprintw(x_start+2, 0, "####   ####  # # #  # ##  # # #   ####  # # #" );
    mvprintw(x_start+3, 0, "#  #   #  #  #  ##  #  #  #   #   #  #  #  ##" );
    mvprintw(x_start+4, 0, "#  #   #  #  #   #  ####  #   #   #  #  #   #" );
}
// width 27?

/*
void draw_line(int x_start, int width) {
    mvprintw(x_start, 0, string("=", width));
}
*/

void draw_hangman(int x_start, int level) {
    cout << hangman_stages[level];
    // mvprintw(x_start, 0, &hangman_stages[level]);
}


int main() {
    return 0;
}
