#pragma once
#include "Puzzle.h"
#include "FileManager.h"

class EditorController {
private:
    Puzzle* puzzle;
    FileManager fileManager;

public:
    EditorController(Puzzle* p);

    void placeLetter(int x, int y, char letter);
    void toggleBlock(int x, int y);

    void savePuzzle(const std::string& filename);
};