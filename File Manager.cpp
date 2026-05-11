#include "FileManager.h"
#include <fstream>
#include <cctype>

using namespace std;

void FileManager::save(Puzzle& puzzle,
    const string& filename) {

    ofstream file(filename);

    for (auto& row : puzzle.grid) {

        for (auto& cell : row) {

            if (cell.isBlocked)
                file << "# ";

            else
                file << cell.letter << " ";
        }

        file << endl;
    }

    file.close();
}

void FileManager::load(Puzzle& puzzle,
    const string& filename) {

    ifstream file(filename);

    string line;
    int y = 0;

    while (getline(file, line)) {

        int x = 0;

        for (char c : line) {

            if (c == '#') {
                puzzle.grid[y][x].isBlocked = true;
                x++;
            }

            else if (isalpha(c)) {
                puzzle.grid[y][x].letter = c;
                x++;
            }
        }

        y++;
    }

    file.close();
}
