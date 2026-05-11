#pragma once

#include <vector>
#include "Cell.h"
#include "Word.h"

class Puzzle {
private:
    int width;
    int height;

public:
    std::vector<std::vector<Cell>> grid;
    std::vector<Word> words;

    Puzzle(int w = 5, int h = 5);

    void setLetter(int x, int y, char letter);
    void toggleBlock(int x, int y);

    bool isValid();
    bool isSolved();

    void display();
};
