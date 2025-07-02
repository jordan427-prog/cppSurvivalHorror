#include "Door.h"
#include <vector>
#include <string>

Door::Door()
{
	name = "null door";
}

Door::Door(std::string name, Room* a, Room* b, bool lockStatus)
{
	this->name = name;
	this->a = a;
	this->b = b;
	this->isLockedStatus = lockStatus;
}

bool Door::isLocked()
{
	return isLockedStatus;
}

void Door::unlock()
{
	isLockedStatus = false;
}

Room* Door::getOtherRoom(Room* room)
{
	if (room == a)
	{
		return b;
	}
	if (room == b)
	{
		return a;
	}
	else
	{
		return nullptr;
	}
}

std::string Door::getName()
{
	return name;
}
