#include <iostream>
#include "Puzzle.h"
#include "EditorController.h"
#include "GameController.h"
#include "Validator.h"

using namespace std;

int main() {

    Puzzle puzzle(5, 5);

    EditorController editor(&puzzle);
    GameController game(&puzzle);
    Validator validator;

    cout << "===== WORD FORGE =====\n";

    EDITOR MODE

    editor.placeLetter(0, 0, 'H');
    editor.placeLetter(1, 0, 'I');

    editor.placeLetter(0, 1, 'C');
    editor.placeLetter(1, 1, 'A');
    editor.placeLetter(2, 1, 'T');

    editor.placeLetter(0, 2, 'D');
    editor.placeLetter(1, 2, 'O');
    editor.placeLetter(2, 2, 'G');

    puzzle.words.push_back(
        Word("HI", 0, 0, "RIGHT")
    );

    puzzle.words.push_back(
        Word("CAT", 0, 1, "RIGHT")
    );

    puzzle.words.push_back(
        Word("DOG", 0, 2, "RIGHT")
    );

    puzzle.display();

    VALIDATION

    cout << "\nChecking Words...\n";

    if (validator.checkWords(puzzle))
        cout << "All Words Valid!\n";

    else
        cout << "Invalid Word Found!\n";

     HINT

    cout << "\nHint: "
        << validator.getHint(puzzle)
        << endl;

    AUTO SOLVER

    cout << "\nAuto Solver:\n";

    vector<string> words =
        validator.findAllWords(puzzle);

    for (string w : words) {
        cout << "- " << w << endl;
    }

    GAME MODE

    game.trackMoves();
    game.checkWin();

    return 0;
}

