#pragma once
#include <string>

class Puzzle
{
public:
	Puzzle(std::string password);
	bool passCheck(std::string key);

private:
	std::string passkey;
};
