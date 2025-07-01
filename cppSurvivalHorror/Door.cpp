#include "Door.h"
#include <vector>
#include <string>

Door::Door()
{
	name = "null door";
}

Door::Door(std::string name, Room* a, Room* b, bool lockStatus)
{
	name = name;
	a = a;
	b = b;
	isLockedStatus = lockStatus;
}

bool Door::isLocked()
{
	return isLockedStatus;
}

void Door::unlock()
{
	isLockedStatus = false;
}