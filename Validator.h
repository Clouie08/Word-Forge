#pragma once
#include "Puzzle.h"
#include <unordered_set>
#include <vector>
#include <string>

class Validator {
private:

    std::unordered_set<std::string> dictionary;

    int dx[8] = { -1,-1,-1,0,0,1,1,1 };
    int dy[8] = { -1,0,1,-1,1,-1,0,1 };

    void dfs(Puzzle& puzzle,
        int x,
        int y,
        std::vector<std::vector<bool>>& visited,
        std::string current,
        std::unordered_set<std::string>& found);

public:

    Validator();

    void loadDictionary(const std::string& filename);

    bool checkWords(Puzzle& puzzle);

    bool detectConflicts(Puzzle& puzzle);

    std::vector<std::string> findAllWords(Puzzle& puzzle);

    std::string getHint(Puzzle& puzzle);

