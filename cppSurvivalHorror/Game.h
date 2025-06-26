#pragma once
#include <vector>
#include <string>
#include "Room.h"
#include "Player.h"
#include "Enemy.h"
#include "Furniture.h"
#include "Item.h"

class Game
{
public:
	void setup();
	void run();

private:
	Room* currentRoom;
	Player player;
	std::vector<Room> rooms;
	Enemy enemy;
};
