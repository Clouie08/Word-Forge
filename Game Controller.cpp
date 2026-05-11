#include "GameController.h"
#include <iostream>

using namespace std;

GameController::GameController(Puzzle* p) {
    puzzle = p;
    moveCount = 0;
}

void GameController::inputLetter(int x,
    int y,
    char letter) {

    puzzle->setLetter(x, y, letter);

    moveCount++;
}

void GameController::trackMoves() {

    cout << "\nMoves: "
        << moveCount
        << endl;
}

void GameController::checkWin() {

    if (puzzle->isSolved())
        cout << "Puzzle Solved!\n";

    else
        cout << "Puzzle Not Solved Yet!\n";
}
