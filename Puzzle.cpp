#include "Puzzle.h"
#include <iostream>
#include <cctype>

using namespace std;

Puzzle::Puzzle(int w, int h) {
    width = w;
    height = h;

    grid.resize(height, vector<Cell>(width));
}

void Puzzle::setLetter(int x, int y, char letter) {
    if (!grid[y][x].isBlocked) {
        grid[y][x].letter = toupper(letter);
    }
}

void Puzzle::toggleBlock(int x, int y) {
    grid[y][x].isBlocked = !grid[y][x].isBlocked;
}

bool Puzzle::isValid() {
    return !words.empty();
}

bool Puzzle::isSolved() {

    for (const Word& w : words) {

        int x = w.x;
        int y = w.y;

        for (char c : w.text) {

            if (grid[y][x].letter != c) {
                return false;
            }

            if (w.direction == "RIGHT")
                x++;

            else if (w.direction == "DOWN")
                y++;
        }
    }

    return true;
}

void Puzzle::display() {

    cout << "\nGRID:\n";

    for (auto& row : grid) {

        for (auto& cell : row) {

            if (cell.isBlocked)
                cout << "# ";

            else if (cell.letter == ' ')
                cout << ". ";

            else
                cout << cell.letter << " ";
        }

        cout << endl;
    }
}