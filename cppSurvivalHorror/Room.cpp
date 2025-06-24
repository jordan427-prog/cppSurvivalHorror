#include <string>
#include <vector>
#include <iostream>
#include "Item.cpp"
#include "Furniture.cpp"

class Room
{
public:
	Room(std::string name, std::vector<Item> items, std::vector<Room> connectedRooms, bool isLocked)
	{
		name = name;
		description = description;
		isLocked = isLocked;
	}

	void addItem(const Item item)
	{
		items.push_back(item);
	}

	void connectRoom(Room* room)
	{
		connectedRooms.push_back(room);
	}

	void describeRoom()
	{
		std::cout << "You see " << description << std::endl;
	}

	void getFurniture()
	{
		for (int i = 0;i < furniture.size();i++)
		{
			std::cout << "You see " << furniture[i].getName() << std::endl;
		}
	}

	void addFurniture(std::vector<Furniture> furn)
	{
		for (int i = 0;i < furn.size();i++)
		{
			furniture.push_back(furn[i]);
		}
	}

private:
	std::string name;
	std::string description;
	std::vector<Item> items;
	std::vector<Room*> connectedRooms;
	std::vector<Furniture> furniture;
	bool isLocked;
};