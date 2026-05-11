#pragma once
#include "Puzzle.h"
#include <string>

class FileManager {
public:
    void save(Puzzle& puzzle, const std::string& filename);
    void load(Puzzle& puzzle, const std::string& filename);
};
