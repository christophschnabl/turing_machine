#ifndef TAPE_HPP
#define TAPE_HPP

#include <queue>
#include <string>

class Tape {
private:
    std::queue<std::string> queue;

public:
    Tape();

    ~Tape();

    void right();
    void left();
    void write(std::string);
    std::string read();
};

#endif // TAPE_HPP
