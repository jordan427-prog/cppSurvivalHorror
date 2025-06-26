#include "Puzzle.h"

Puzzle::Puzzle(std::string password)
{
	passkey = password;
}

bool Puzzle::passCheck(std::string key)
{
	if (key == passkey)
	{
		return true;
	}
	return false;
}