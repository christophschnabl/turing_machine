#ifndef TAPE_HPP
#define TAPE_HPP

#include <deque>
#include <string>
#include <vector>
#include "Direction.hpp"

class Tape {
private:
    std::deque<std::string> tape;
    int index;

    void left();
    void right();

public:
    Tape();

    Tape(unsigned long n, std::string blank);

    Tape(std::string blank);

    Tape(std::vector<std::string>);

    ~Tape();

    void move(Direction direction);
    void write(std::string symbol);
    std::string read();

    void print();
};

#endif // TAPE_HPP
