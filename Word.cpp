#include "Word.h"

Word::Word(std::string t, int startX, int startY, std::string dir) {
    text = t;
    x = startX;
    y = startY;
    direction = dir;
}