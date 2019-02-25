//
// Created by Christoph Schnabl on 2019-02-23.
//


#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "machine.hpp"

using namespace std;


Machine::Machine(string file_name) {
    ifstream file("./" + file_name);

    if (file.is_open()) {
        string line;
        string tmp;
        set<int> states;
        set<int> end_states;
        int start_state;
        vector<string> initial_tape; //oder is es eingabealphabet
        set<string> tape_alphabet;
        string blank;

        //begin parse states

        if (!getline(file, line))
            throw 'Invalid state defintion';

        for (char c : line) {
            if (c == ' ') {
                try {
                    states.insert(stoi(tmp));
                } catch (...) {
                    throw 'States not parsable as numbers';
                }
                tmp = "";
            } else {
                tmp = tmp + c;
            }
        }

        try {
            states.insert(stoi(tmp));
        } catch (...) {
            throw 'States not parsable as numbers';
        }

        tmp = "";

        //end parse states


        //begin parse start state

        if (!getline(file, line))
            throw 'Invalid start state definition';

        try {
            start_state = stoi(line);
        } catch (...) {
            throw 'Start State not parsable as number';
        }

        if (states.find(start_state)  == states.end()) {
            throw 'Start State is not a valid state';
        }

        //end parse start state

        //start parse tape
        if (!getline(file, line))
            throw 'Invalid tape definition';

        if (line == "-") {

        } else {
            //initial tape?? TODO
        }

        //end parse tape

        //start parse end state
        if (!getline(file, line))
            throw 'Invalid end state definition';

        for (char c : line) {
            if (c == ' ') {
                try {
                    end_states.insert(stoi(tmp));
                } catch (...) {
                    throw 'End States not parsable as numbers';
                }
                tmp = "";
            } else {
                tmp = tmp + c;
            }
        }

        try {
            end_states.insert(stoi(tmp));
        } catch (...) {
            throw 'End States not parsable as numbers';
        }

        tmp = "";

        int n = end_states.size();
        //cout << endl << n << endl << endl;

        //end parse end state


        //start parse tape alphabet

        if (!getline(file, line))
            throw 'Invalid tape definition';

        for (char c : line) {
            if (c == ' ') {
                try {
                    tape_alphabet.insert(tmp);
                } catch (...) {
                    throw 'tape not parsable as string';
                }
                tmp = "";
            } else {
                tmp = tmp + c;
            }
        }

        try {
            tape_alphabet.insert(tmp);
        } catch (...) {
            throw 'tape not parsable as string';
        }

        tmp = "";

        cout << tape_alphabet.size() << endl;
        //end parse tape alphabet


        //start parse blank symbol

        if (!getline(file, line))
            throw 'Invalid parse blank definition';

        blank = line;

        //end parse blank symbol


        //start parse turing machine configuration

        Direction d;


        while (getline(file, line)) {
            try {
                char c = line[8];

                if (c == 'L')
                    d = Left;
                if (c == 'R')
                    d = Right;
                if (c == 'S')
                    d = Stop;

                loadProgram(stoi(string(1, line[0])), string(1, line[2]), stoi(string(1, line[4])), string(1, line[6]), d); //add multi chracter support for states support
            } catch (...) {
                throw "Couldnt parse turing machine configuration";
            }
        }

        //end parse turing machine configuration

        this->tape = Tape(20, blank);
        this->states = states;
        this->input_alphabet = input_alphabet;
        this->tape_alphabet = tape_alphabet;
        this->start_state = start_state;
        this->end_states = end_states;
        this->blank = blank;

        file.close();
    }
}


Machine::Machine(set<int> states, set<string> input_alphabet, set<string> tape_alphabet, int start_state, set<int> end_states, vector<string> tape) {
    this->tape = Tape(tape);
    this->states = states;
    this->input_alphabet = input_alphabet;
    this->tape_alphabet = tape_alphabet;
    this->start_state= start_state;
    this->end_states = end_states;
}


void Machine::loadProgram(int state, string input_word, int next_state, string write_word,
                          Direction direction) {

    tuple<string, int, Direction> t;
    get<0>(t) = write_word;
    get<1>(t) = next_state;
    get<2>(t) = direction;

    transition_table[state][input_word] = t;
}

int Machine::delta(int state) {
    string symbol = tape.read();

    tuple<string, int, Direction> t = transition_table[state][symbol];

    tape.write(get<0>(t));
    tape.move(get<2>(t));

    return get<1>(t);
}


bool Machine::run() {
    int state = start_state;

    while (end_states.find(state) == end_states.end()) {
        state = delta(state);
    }

    return true;
}


void Machine::print() {
    cout << "Tape: " << endl;
    tape.print();
}

Machine::~Machine() {

}

