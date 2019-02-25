#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "machine.hpp"

using namespace std;


int main() {

    Machine m = Machine("1state");

    /*set<int> states;
    int start_state;
    set<string> input_alphabet;
    set<int> end_states;
    set<string> tape_alphabet;
    vector<string> initial_tape = {};

    states.insert(0);
    states.insert(1);
    states.insert(2);

    start_state = 0;

    input_alphabet = set<string>();

    end_states.insert(2);

    tape_alphabet.insert("0");
    tape_alphabet.insert("1");

    for (int i = 0; i < 10; i++) {
        initial_tape.push_back("0");
    }*/


    /*multiplication
    for (int i = 0; i < 12; i++) {
        states.insert(i);
    }

    start_state = 0;


    input_alphabet.insert("1");
    input_alphabet.insert("X");

    tape_alphabet.insert("1");
    tape_alphabet.insert("X");
    tape_alphabet.insert("*");
    tape_alphabet.insert("A");
    tape_alphabet.insert(""); //blank

    end_states.insert(11);

    initial_tape = {"1","1","1","X","1","1","1","1"};*/

    /*2-state busy beaver*/


    //Machine machine = Machine(states, input_alphabet, tape_alphabet, start_state, end_states, initial_tape);

    /*machine.loadProgram(0, "1", 1, "1", Left);
    machine.loadProgram(1, "", 2, "*", Right);
    machine.loadProgram(2, "",);
    machine.loadProgram(2, "*",);
    machine.loadProgram(2, "1",);
    machine.loadProgram(2, "X",);
    machine.loadProgram(2, "A",);
    machine.loadProgram(3, "1",);
    machine.loadProgram(3, "X",);
    machine.loadProgram(4, "1",);
    machine.loadProgram(4, "X",);
    machine.loadProgram(5, "*");
    machine.loadProgram(5, "1");
    machine.loadProgram(5, "A");
    machine.loadProgram(6, "");
    machine.loadProgram(6, "*");
    machine.loadProgram(6, "1");
    machine.loadProgram(7, "*");
    machine.loadProgram(7, "1");
    machine.loadProgram(7, "X");
    machine.loadProgram(7, "A");
    machine.loadProgram(8, "");
    machine.loadProgram(8, "1");
    machine.loadProgram(8, "X");
    machine.loadProgram(8, "A");
    machine.loadProgram(9, "*");
    machine.loadProgram(9, "1");
    machine.loadProgram(10, "");
    machine.loadProgram(10, "1");
    machine.loadProgram(10, "X");
    machine.loadProgram(10, "A");*/



    /*machine.loadProgram(0, "0", 1, "1", Right);
    machine.loadProgram(0, "1", 1, "1", Left);
    machine.loadProgram(1, "0", 0, "1", Left);
    machine.loadProgram(1, "1", 2, "1", Right);*/


    /*machine.print();
    machine.run();
    machine.print();*/

    m.print();
    m.run();
    m.print();
}
