//
// Created by Christoph Schnabl on 2019-02-23.
//

#ifndef TURING_MACHINE_MACHINE_HPP
#define TURING_MACHINE_MACHINE_HPP

#include <set>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "tape.hpp"
#include "Direction.hpp"


class Machine {
private:
    Tape tape;

    std::set<int> states;
    std::set<std::string> input_alphabet;
    std::set<std::string> tape_alphabet;
    std::string blank = "";
    int start_state;
    std::set<int> end_states;

    std::map<int, std::map<std::string, std::tuple<std::string, int, Direction>>> transition_table;

    int delta(int state);

public:

    //intialize machine from filename - WIP
    Machine(std::string file_name);


    Machine(std::set<int> states, std::set<std::string> input_alphabet, std::set<std::string> tape_alphabet, int start_state, std::set<int> end_states, std::vector<std::string> tape);

    //adds the following quintuple to the machines configuration
    // (q, s, q', s', d) where
    // q, q' are elements of the set of states
    // s, s' are elements of the input_alphabet
    // d is the direction in which to move the read/write head

    void loadProgram(int state, std::string input_word, int next_state, std::string write_word, Direction direction);

    //runs the machine

    bool run();

    void print();

    ~Machine();

};

#endif //TURING_MACHINE_MACHINE_HPP
