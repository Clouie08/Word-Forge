#include "Validator.h"
#include <fstream>
#include <algorithm>

using namespace std;

Validator::Validator() {
    loadDictionary("dictionary.txt");
}

void Validator::loadDictionary(
    const string& filename) {

    ifstream file(filename);

    string word;

    while (file >> word) {

        transform(word.begin(),
            word.end(),
            word.begin(),
            ::toupper);

        dictionary.insert(word);
    }

    file.close();
}

bool Validator::checkWords(Puzzle& puzzle) {

    for (const Word& w : puzzle.words) {

        string upper = w.text;

        transform(upper.begin(),
            upper.end(),
            upper.begin(),
            ::toupper);

        if (!dictionary.count(upper))
            return false;
    }

    return true;
}

bool Validator::detectConflicts(Puzzle& puzzle) {
    return false;
}

void Validator::dfs(
    Puzzle& puzzle,
    int x,
    int y,
    vector<vector<bool>>& visited,
    string current,
    unordered_set<string>& found) {

    int h = puzzle.grid.size();
    int w = puzzle.grid[0].size();

    if (x < 0 || y < 0 ||
        x >= w || y >= h)
        return;

    if (visited[y][x])
        return;

    if (puzzle.grid[y][x].isBlocked)
        return;

    if (puzzle.grid[y][x].letter == ' ')
        return;

    current += puzzle.grid[y][x].letter;

    visited[y][x] = true;

    if (current.length() >= 2 &&
        dictionary.count(current)) {

        found.insert(current);
    }

    for (int i = 0; i < 8; i++) {

        dfs(puzzle,
            x + dx[i],
            y + dy[i],
            visited,
            current,
            found);
    }

    visited[y][x] = false;
}

vector<string> Validator::findAllWords(
    Puzzle& puzzle) {

    unordered_set<string> found;

    int h = puzzle.grid.size();
    int w = puzzle.grid[0].size();

    vector<vector<bool>> visited(
        h,
        vector<bool>(w, false)
    );

    for (int y = 0; y < h; y++) {

        for (int x = 0; x < w; x++) {

            dfs(puzzle,
                x,
                y,
                visited,
                "",
                found);
        }
    }

    return vector<string>(
        found.begin(),
        found.end()
    );
}

string Validator::getHint(
    Puzzle& puzzle) {

    vector<string> words =
        findAllWords(puzzle);

    if (words.empty())
        return "No Hint Available";

    sort(words.begin(),
        words.end(),
        [](string a, string b) {

            return a.length() < b.length();
        });

    return words[0];
}