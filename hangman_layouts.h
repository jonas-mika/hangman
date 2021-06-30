#ifndef HANGMAN_LAYOUTS_H
#define HANGMAN_LAYOUTS_H 

#include <ncurses.h>
#include <string>

using std::string;

string hangman_stages[7] = {
    //"  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",

    "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",

    "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",

    "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",

    "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========", 

    "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",

    "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",

    "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
};

void draw_slogan(int x_start, int y_start) {
    mvprintw(x_start+0, y_start, "#  #   ####  #   #  ####  #   #   ####  #   #" );
    mvprintw(x_start+1, y_start, "#  #   #  #  ##  #  #     ## ##   #  #  ##  #" );
    mvprintw(x_start+2, y_start, "####   ####  # # #  # ##  # # #   ####  # # #" );
    mvprintw(x_start+3, y_start, "#  #   #  #  #  ##  #  #  #   #   #  #  #  ##" );
    mvprintw(x_start+4, y_start, "#  #   #  #  #   #  ####  #   #   #  #  #   #" );
}
// width 27?

/*
void draw_line(int x_start, int width) {
    mvprintw(x_start, 0, string("=", width));
}
*/


void draw_hangman(int x_start, int y_start, int level) {
    // cout << hangman_stages[level];
    //mvprintw(x_start, y_start, "%s", &hangman_stages[level]);
    
    if (level == 0) {
        mvprintw(x_start+0, y_start, "         " );
        mvprintw(x_start+1, y_start, "         " );
        mvprintw(x_start+2, y_start, "         " );
        mvprintw(x_start+3, y_start, "         " );
        mvprintw(x_start+4, y_start, "         " );
        mvprintw(x_start+5, y_start, "         " );
        mvprintw(x_start+6, y_start, "=========" );
    }

    else if (level == 1) {
        mvprintw(x_start+0, y_start, "         " );
        mvprintw(x_start+1, y_start, "|        " );
        mvprintw(x_start+2, y_start, "|        " );
        mvprintw(x_start+3, y_start, "|        " );
        mvprintw(x_start+4, y_start, "|        " );
        mvprintw(x_start+5, y_start, "|        " );
        mvprintw(x_start+6, y_start, "=========" );
    }

    else if (level == 2) {
        mvprintw(x_start+0, y_start, "+---+    " );
        mvprintw(x_start+1, y_start, "|        " );
        mvprintw(x_start+2, y_start, "|        " );
        mvprintw(x_start+3, y_start, "|        " );
        mvprintw(x_start+4, y_start, "|        " );
        mvprintw(x_start+5, y_start, "|        " );
        mvprintw(x_start+6, y_start, "=========" );
    }

    else if (level == 3) {
        mvprintw(x_start+0, y_start, "+---+    " );
        mvprintw(x_start+1, y_start, "|   |    " );
        mvprintw(x_start+2, y_start, "|        " );
        mvprintw(x_start+3, y_start, "|        " );
        mvprintw(x_start+4, y_start, "|        " );
        mvprintw(x_start+5, y_start, "|        " );
        mvprintw(x_start+6, y_start, "=========" );
    }

    else if (level == 4) {
        mvprintw(x_start+0, y_start, "+---+    " );
        mvprintw(x_start+1, y_start, "|   |    " );
        mvprintw(x_start+2, y_start, "|   O    " );
        mvprintw(x_start+3, y_start, "|        " );
        mvprintw(x_start+4, y_start, "|        " );
        mvprintw(x_start+5, y_start, "|        " );
        mvprintw(x_start+6, y_start, "=========" );
    }

    else if (level == 5) {
        mvprintw(x_start+0, y_start, "+---+    " );
        mvprintw(x_start+1, y_start, "|   |    " );
        mvprintw(x_start+2, y_start, "|   O    " );
        mvprintw(x_start+3, y_start, "|   |    " );
        mvprintw(x_start+4, y_start, "|        " );
        mvprintw(x_start+5, y_start, "|        " );
        mvprintw(x_start+6, y_start, "=========" );
    }

    else if (level == 6) {
        mvprintw(x_start+0, y_start, "+---+    " );
        mvprintw(x_start+1, y_start, "|   |    " );
        mvprintw(x_start+2, y_start, "|   O    " );
        mvprintw(x_start+3, y_start, "|  /|    " );
        mvprintw(x_start+4, y_start, "|        " );
        mvprintw(x_start+5, y_start, "|        " );
        mvprintw(x_start+6, y_start, "=========" );
    }

    else if (level == 7) {
        mvprintw(x_start+0, y_start, "+---+    " );
        mvprintw(x_start+1, y_start, "|   |    " );
        mvprintw(x_start+2, y_start, "|   O    " );
        mvprintw(x_start+3, y_start, "|  /|\\  " );
        mvprintw(x_start+4, y_start, "|        " );
        mvprintw(x_start+5, y_start, "|        " );
        mvprintw(x_start+6, y_start, "=========" );
    }

    else if (level == 8) {
        mvprintw(x_start+0, y_start, "+---+    " );
        mvprintw(x_start+1, y_start, "|   |    " );
        mvprintw(x_start+2, y_start, "|   O    " );
        mvprintw(x_start+3, y_start, "|  /|\\  " );
        mvprintw(x_start+4, y_start, "|  /     " );
        mvprintw(x_start+5, y_start, "|        " );
        mvprintw(x_start+6, y_start, "=========" );
    }

    else if (level == 9) {
        mvprintw(x_start+0, y_start, "+---+    " );
        mvprintw(x_start+1, y_start, "|   |    " );
        mvprintw(x_start+2, y_start, "|   O    " );
        mvprintw(x_start+3, y_start, "|  /|\\  " );
        mvprintw(x_start+4, y_start, "|  / \\  " );
        mvprintw(x_start+5, y_start, "|        " );
        mvprintw(x_start+6, y_start, "=========" );
    }

    else if (level == 10) {
        mvprintw(x_start+0, y_start, "+---+    " );
        mvprintw(x_start+1, y_start, "|        " );
        mvprintw(x_start+2, y_start, "|   O    " );
        mvprintw(x_start+3, y_start, "|  /|\\  " );
        mvprintw(x_start+4, y_start, "|  / \\  " );
        mvprintw(x_start+5, y_start, "|        " );
        mvprintw(x_start+6, y_start, "=========" );
    }
}


#endif 
    
