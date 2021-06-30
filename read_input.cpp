#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>
#include <time.h>       /* time */

#include <random>

using namespace std;

int random_num(int start, int stop) {
    random_device dev;

    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(start, stop);

    return dist(rng);
}

int main() {
    ifstream in;  
    string line;
    vector<string> words;

    in.open("words_upper.txt");

    while (getline(in, line)) {
        if (line.size() > 0) {
            words.push_back(line);
        }
    }

    cout << words[random_num(0, words.size())] << endl;


    return 0;
}

