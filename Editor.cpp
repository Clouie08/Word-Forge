#include "Editor.h"

EditorController::EditorController(Puzzle* p) {
    puzzle = p;
}

void EditorController::placeLetter(int x,
    int y,
    char letter) {

    puzzle->setLetter(x, y, letter);
}

void EditorController::toggleBlock(int x,
    int y) {

    puzzle->toggleBlock(x, y);
}

void EditorController::savePuzzle(
    const std::string& filename) {

    fileManager.save(*puzzle, filename);
}

