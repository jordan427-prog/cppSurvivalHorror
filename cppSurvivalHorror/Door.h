#pragma once
#include "Room.h"
#include <string>
#include <vector>

class Room;

class Door
{
public:
	Door();
	Door(std::string name, Room* a, Room* b, bool lockStatus);
	bool isLocked();
	void unlock();
	Room* getOtherRoom(Room* room);
	std::string getName();

private:
	std::string name;
	Room* a;
	Room* b;
	bool isLockedStatus;
};
