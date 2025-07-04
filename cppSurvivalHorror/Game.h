#pragma once
#include <vector>
#include <string>
#include "Room.h"
#include "Player.h"
#include "Enemy.h"
#include "Furniture.h"
#include "Item.h"
#include <algorithm>

class Game
{
public:
	Game();
	void setup();
	void run();
	void showBackstory();

	//Room movement
	void moveRooms();

private:
	Room* currentRoom;
	Player player;
	std::vector<Room*> rooms;
	//Enemy enemy;
};
