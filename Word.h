#pragma once
#include<string>
class word {
public:
	std::string text;
	int x;
	int y;
	std::string direction;
	Word(std::string t, int startX, int startY, std::string dir);
};