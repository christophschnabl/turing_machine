#include "tape.hpp"
#include <deque>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


Tape::Tape() {
    tape = deque<string>();
    index = 0;
}


Tape::Tape(unsigned long n, string blank) : Tape() {
    for (unsigned long i = 0; i < n; i++) {
        tape.push_back(blank);
    }
}

Tape::Tape(string blank) : Tape() {
    Tape(tape.max_size(), blank);
}


Tape::Tape(vector<string> tape) : Tape() {
    for (int i = 0; i < tape.size(); i++)
    {
        this->tape.push_back(tape[i]);
    }
}


void Tape::right() {
    index++;

    if (index > tape.size()) {
        tape.push_back("0");
        index = tape.size();
    }
}


void Tape::left() {
    index--;

    if (index < 0) {
        tape.push_front("0");
        index = 0;
    }
}

void Tape::move(Direction direction) {
    switch (direction) {
        case Left:
            left();
            break;
        case Right:
            right();
            break;
        default:
            break;
    }
}

void Tape::write(string symbol) {
    //tape[index] = symbol;
    /*if (index < 0) {
        tape.push_front(symbol);
        index = 0;
    }*/

    tape[index] = symbol;
}


string Tape::read() {
    /*if (position < tape.begin()) {
        tape.push_front("!"); //may be problematic
        index = 0;
    }*/
    return tape[index];
}

void Tape::print() {
    cout << "Head at posititon: " << index << endl;
    for (int i = 0; i < tape.size(); i++) {
        cout << tape[i] << endl;
    }
}


Tape::~Tape() {

}
