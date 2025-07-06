#include "Game.h"

Game::Game()
{
	currentRoom = nullptr;
}
void Game::setup()
{
	// living room
	Item intro_photo = Item::Item("A photograph", "An old photograph that's at least 100 years old. It seems to be the original owners of the house.", "viewing");
	std::vector<Item> livingRoomItems;
	livingRoomItems.push_back(intro_photo);
	//Room* livingRoom = new Room("living room", "this dark and dusty room appears to be a living room...", livingRoomItems);
	Item default_axe = Item::createDefaultAxe();
	// the axe can be used for this
	default_axe.addInteractiontags("broken door");
	// key needed for cabinet!
	Furniture livingRoomCabinet = Furniture::Furniture("A living room cabinet", "an oak cabinet. This seems expensive, maybe theres something of value inside? It is locked, this requires a key", "cabinet", true);
	Item livingRoomCabinetKey = Item::createDefaultCabinetKey();
	Item first_key = Item::createDefaultDoorKey();
	livingRoomCabinetKey.addInteractiontags(livingRoomCabinet.getInteractiontag());
	livingRoomItems.push_back(livingRoomCabinetKey);
	livingRoomItems.push_back(first_key);


	livingRoomCabinet.addItem(default_axe);
	std::vector<Furniture> furn;
	furn.push_back(livingRoomCabinet);
	//here
	Room* livingRoom = new Room("living room", "this dark and dusty room appears to be a living room...", livingRoomItems);

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
	bool playing = true;

	while (playing == true)
	{
		showOptions();

		int choice = 0;
		std::cin >> choice;

		if (std::cin.fail() || choice > 6 || choice <=0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input." << std::endl;
			continue;
		}

		if (choice == 1)
		{
			moveRooms();
		}

		else if (choice == 2)
		{
			currentRoom->Describe();
			currentRoom->getFurniture();
			currentRoom->getItems();
			std::vector<Door*> doors = currentRoom->getDoorList();

			if (doors.size() == 0)
			{
				std::cout << "You see no doors in this room. This room appears to be a dead end." << std::endl;
			}
			else
			{
				std::cout << "You see " << doors.size() << " door(s) in this room." << std::endl;
			}
		}

		else if (choice == 3)
		{
			std::vector<Item> items = player.getInventory();
			std::cout << "Your inventory includes: " << std::endl;
			if (items.size() == 0)
			{
				std::cout << "nothing. it is empty" << std::endl;
			}
			else
			{
				for (int i = 0;i < items.size();i++)
				{
					std::cout << "- " << items[i].getName() << " (" << items[i].getPurpose() << ")" << std::endl;
				}
			}
		}

		else if (choice == 4)
		{

			std::vector<Item> items = currentRoom->getItemsList();

			if (items.size() == 0)
			{
				std::cout << "There are no items in this room to interact with" << std::endl;
			}
			else
			{
				std::cout << "\n===== Item Interaction Menu =====" << std::endl;
				std::cout << "Select one of the following items to ineract with: " << std::endl;
				for (int i = 0;i < items.size();i++)
				{
					std::cout << (i + 1) << ":" << items[i].getName() << std::endl;
				}
				int choice_item = 0;
				std::cout << "Enter choice: ";
				std::cin >> choice_item;

				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input." << std::endl;
					continue;
				}

				if (choice_item <= 0 || choice_item > items.size())
				{
					std::cout << "Invalid input." << std::endl;
				}
				else
				{
					Item item = items[choice_item - 1];

					std::cout << "You have selected: " << item.getName() << " (" << item.getPurpose() << ")" << std::endl;
					std::cout << "Description: " << item.getDescription() << std::endl;

					std::cout << "\nWould you like to add this item to inventory?" << std::endl;
					std::cout << "1. Yes" << std::endl;
					std::cout << "2. No" << std::endl;
					int choice2 = 0;
					std::cin >> choice2;

					if (std::cin.fail())
					{
						std::cin.clear(); 
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
						std::cout << "Invalid input." << std::endl;
						continue;
					}


					if(choice2 == 1)
					{
						player.addInventory(item);
						currentRoom->removeItem(item);
						std::cout << "You have successfully added " << item.getName() << " to your inventory" << std::endl;
					}
					else if (choice2 == 2)
					{
						std::cout << "Item has been placed back down. You can come back to this item later" << std::endl;
					}
					else
					{
						std::cout << "Invalid input." << std::endl;
					}
				}
			}
		}

		else if (choice == 5)
		{

		}

		else if (choice == 6)
		{
			std::cout << "Quitting game. Thanks for playing." << std::endl;
			playing = false;
		}

	/*	else
		{
			std::cout << "Invalid input" << std::endl;
		}*/
	}
}

void Game::showBackstory()
{
	std::cout<<"You wake up in an abandoned and eerie looking house in the middle of nowhere."<<std::endl << "Its clear you have been kidnapped by somebody or something. You dont remember who you are or how you got here. " << std::endl;
	std::cout << "You need to find a way to escape the house." << std::endl;
}

void Game::showOptions()
{
	std::cout << "\n===== Main Menu =====" << std::endl;
	std::cout << "1. Move to another room" << std::endl;
	std::cout << "2. Inspect room" << std::endl;
	std::cout << "3. Check inventory" << std::endl;
	std::cout << "4. Inspect Item" << std::endl;
	std::cout << "5. Inspect Furniture" << std::endl;
	std::cout << "6. Quit game" << std::endl;
	std::cout << "Enter choice: ";
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

	std::cout << "pick a door to interact with" << std::endl;


	for (int k = 0;k < connected_doors.size();k++)
	{
		std::cout << (k + 1) << ". " << connected_doors[k]->getName() << std::endl;
	}

	int choice = 0;
	std::cin >> choice;

	if (std::cin.fail() || choice <= 0 || choice > size)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid choice." << std::endl;
		return;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  


	Door* door = connected_doors[choice - 1];

	if (door->isLocked() == true)
	{
		std::cout << "This door is locked, you need a key" << std::endl;

		std::vector<Item> items = player.getInventory();

		for (int j = 0;j < items.size();j++)
		{
			if (items[j].getPurpose() == "door key")
			{
				Item k = items[j];

				std::cout << "\nIt looks like you have a door key for this door! You may use a door key only once" << std::endl;
				std::cout << "You have the following options:" << std::endl;
				std::cout << "1. Use door key for this door" << std::endl;
				std::cout << "2. Do not use key here and go back" << std::endl;
				int key_usage=0;
				std::cin >> key_usage;

				if (std::cin.fail() || key_usage <= 0 || key_usage > 2)
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input." << std::endl;
					return;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (key_usage == 1)
				{
					player.removeItem(k);
					std::cout << "You have successfully unlocked the door. You no longer have that key" << std::endl;
					door->unlock();

					std::cout << "You are now entering the " << door->getOtherRoom(currentRoom)->getName();
					currentRoom = door->getOtherRoom(currentRoom);
					return;
				}
				else if (key_usage == 2)
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
	}

}
