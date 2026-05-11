#pragma once
#include "Puzzle.h"

class GameController {
private:
    Puzzle* puzzle;
    int moveCount;

public:
    GameController(Puzzle* p);

    void inputLetter(int x,
        int y,
        char letter);

    void trackMoves();

    void checkWin();
};
