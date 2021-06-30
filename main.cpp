#include <ncurses.h>
#include <string>
#include <unordered_set>
#include <vector>
#include <fstream>        // read/write from files

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>
#include <time.h>       /* time */

#include <random>

// own layouts
#include "hangman_layouts.h"

//using namespace std;
using std::string;
using std::unordered_set;
using std::ifstream;
using std::vector;

using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;


// global variables
bool game_over, won, wrong_input;
int input_length, guesses_left, correct_guesses;
string input;
unordered_set<char> unique_chars, guesses;

vector<string> word_list;

int random_num(int start, int stop) {
    random_device dev;

    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(start, stop);

    return dist(rng);
}

void read_input() {
    ifstream infile;
    string line;

    infile.open("words_upper.txt");

    // line number
    while (getline(infile, line)) {
        if (line.size() > 0) {
            word_list.push_back(line);
        }
    }
    infile.close();
}


string get_user_input() {
    string input;

    // let the terminal do the line editing
    nocbreak();
    echo();

    // this reads from buffer after <ENTER>, not "raw"
    // so any backspacing etc. has already been taken care of
    int ch = getch();

    while (ch != '\n')
    {
        input.push_back(ch);
        ch = getch();
    }
    return input;
}

void introduction() {
    initscr();
    clear();
    noecho();
    curs_set(0);
    
    draw_slogan(5, 5);

    
    input = word_list[random_num(1, word_list.size())];

    /*
    mvprintw(12, 5, "Player 1: Insert the word to guess: ");

    input = get_user_input();
    */

    for (int i=0; i < input.length(); i++) {
        if (unique_chars.find(input[i]) == unique_chars.end()) {
            unique_chars.insert(input[i]);
        }
    }
    mvprintw(12,5, "Press ENTER to START GAME!");
    halfdelay(100);
    char c = getch();

    clear();
    endwin();
}

void settings() {
    game_over = false;
    guesses_left = 10;
    correct_guesses = 0;
    input_length = input.length();
    wrong_input = false;
}

void draw() {
    clear();

    draw_hangman(2, 5, 10-guesses_left);

    for (int i=0; i < input.length(); i++) {
        if (guesses.find(input[i]) != guesses.end()) {
            mvprintw(10,5+i, &input[i]);
        } else {
            mvprintw(10,5+i, "_");
        }
    }
    mvprintw(12,5, "Guesses left: %d", guesses_left);
    mvprintw(13,5, "Correct Guesses: %d", correct_guesses);

    if (wrong_input) {
        mvprintw(15,5, "You already guessed this. Try again...");
    }

    refresh();
}

void make_guess() {

    keypad(stdscr, TRUE); // catch arrow keys
    halfdelay(100);
    
    char c = getch();
    c = toupper(c);
    
    // add typed character to guessed
    if (guesses.find(c) == guesses.end()) { // not yet guessed
        guesses.insert(c);

        // update game score
        if (unique_chars.find(c) == unique_chars.end()) { // guess is not in word
            guesses_left--; 
        } else if (unique_chars.find(c) != unique_chars.end()) { // guess is in word and not guessed
            correct_guesses++;
        }
    } else {
        wrong_input = true;
    } 
    // catch error that was already guessed

}

void check() {
    if (guesses_left <= 0) {
        game_over = true;
        won = false;
    } if (correct_guesses == unique_chars.size()) {
        game_over = true;
        won = true;
    }
}


int main() {

    // play hangman
    read_input();
    introduction();
    settings();

    while (!game_over) {
        draw();
        make_guess();
        check();
    }
    clear();
    draw_hangman(2, 5, 10);

    if(won) {
       mvprintw(12,5, "You won!");
    } else {
        mvprintw(12,5, "You lost!");
    }
    mvprintw(13,5, "The word was: %s", &input);
    mvprintw(15,5, "Press Enter to Exit");

    //halfdelay(1);
    noecho();
    char z = getch();
    while (z != '\n') {
        char z = getch();
    }

    clear();
    endwin();

    return 0;
}
