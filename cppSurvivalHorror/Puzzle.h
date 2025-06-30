#pragma once
#include <string>

// To add later
class Puzzle
{
public:
	Puzzle(std::string password);
	bool passCheck(std::string key);

private:
	std::string passkey;
};
