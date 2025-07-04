#include "Game.h"

Game::Game()
{
	currentRoom = nullptr;
}
void Game::setup()
{
	// living room
	Item intro_photo = Item::Item("house owners photograph", "This photo looks to be an old couple in front of this house. I'm assuming they used to live here years ago. I wonder what happened to them...", "viewing");
	std::vector<Item> livingRoomItems;
	livingRoomItems.push_back(intro_photo);
	Room* livingRoom = new Room("living room", "this dark and dusty room appears to be a living room...", livingRoomItems);
	Item default_axe = Item::createDefaultAxe();
	// the axe can be used for this
	default_axe.addInteractiontags("broken door");
	// key needed for cabinet!
	Furniture livingRoomCabinet = Furniture::Furniture("living room cabinet", "an oak cabinet. This seems expensive, maybe theres something of value inside? It is locked, this requires a key", "cabinet", true);
	Item livingRoomCabinetKey = Item::createDefaultCabinetKey();
	Item first_key = Item::createDefaultDoorKey();
	livingRoomCabinetKey.addInteractiontags(livingRoomCabinet.getInteractiontag());
	livingRoomItems.push_back(livingRoomCabinetKey);
	livingRoomItems.push_back(first_key);


	livingRoomCabinet.addItem(default_axe);
	std::vector<Furniture> furn;
	furn.push_back(livingRoomCabinet);
	livingRoom->addFurniture(furn);
	rooms.push_back(livingRoom);

	// kitchen
	Item kitchen_axe = Item::createDefaultAxe();
	kitchen_axe.addInteractiontags("broken door");
	std::vector<Item> kitchen_items;
	kitchen_items.push_back(kitchen_axe);
	Room* kitchen = new Room("kitchen", "this appears to have once been a kitchen. ", kitchen_items);

	kitchen->connectRoom(livingRoom, true);

	//Player starts in the living room - you can change this, but the room must e initialized above.
	currentRoom = livingRoom;
}

void Game::run()
{
	showBackstory();
}

void Game::showBackstory()
{
	std::cout<<"You wake up in an abandoned and eerie looking house in the middle of nowhere."<<std::endl << "Its clear you have been kidnapped by somebody or something. You dont remember who you are or how you got here. " << std::endl;
	std::cout << "You need to find a way to escape the house." << std::endl;
}

void Game::moveRooms()
{
	std::vector<Door*> connected_doors = currentRoom->getDoorList();

	int size = connected_doors.size();
	
	if (size == 0)
	{
		std::cout << "There are no doors in this room" << std::endl;
		return;
	}
	else if (size == 1)
	{
		std::cout << "There is one door in this room" << std::endl;
	}
	else 
	{
		std::cout << "There are " << size << " doors in this room" << std::endl;
	}

	currentRoom->printDoorList();

	std::cout << "pick a door to interact with" << std::endl;

	std::string choice;
	std::cin >> choice;

	std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

	Door* door=nullptr;

	for (int i = 0;i < connected_doors.size();i++)
	{

		std::string doorName = connected_doors[i]->getName();
		std::transform(doorName.begin(), doorName.end(), doorName.begin(), ::tolower);

		if (doorName == choice)
		{
			door = connected_doors[i];
			break;
		}
	}

	if (door == nullptr)
	{
		std::cout << "Invalid door, that door does not exist" << std::endl;
		return;
	}

	if (door->isLocked() == true)
	{
		std::cout << "This door is locked, you need a key" << std::endl;

		std::vector<Item> items = player.getInventory();

		for (int j = 0;j < items.size();j++)
		{
			if (items[j].getPurpose() == "door key")
			{
				Item k = items[j];

				std::cout << "It looks like you have a door key for this door! You may use a door key only once, do you want to use it here?" << std::endl;
				std::string key_usage;
				std::cin >> key_usage;

				std::transform(key_usage.begin(), key_usage.end(), key_usage.begin(), ::tolower);


				if (key_usage == "yes")
				{
					player.removeItem(k);
					std::cout << "You have successfully unlocked the door. You no longer have that key" << std::endl;
					door->unlock();

					std::cout << "You are now entering the " << door->getOtherRoom(currentRoom)->getName();
					currentRoom = door->getOtherRoom(currentRoom);
					currentRoom->Describe();
					currentRoom->getFurniture();
					currentRoom->getItems();
					currentRoom->printDoorList();
					return;
				}
				else if (key_usage == "no")
				{
					std::cout << "You can not enter this door" << std::endl;
					return;
				}
				else
				{
					std::cout << "Invalid response" << std::endl;
					return;
				}
			}
		}
		std::cout << "You do not have a key for this door" << std::endl;
		return;
	}

	else if (door->isLocked() == false)
	{
		Room* nextRoom = door->getOtherRoom(currentRoom);
		std::cout << "You are now entering the " << nextRoom->getName();
		currentRoom = door->getOtherRoom(currentRoom);
		currentRoom->Describe();
		currentRoom->getFurniture();
		currentRoom->getItems();
		currentRoom->printDoorList();
	}

}
