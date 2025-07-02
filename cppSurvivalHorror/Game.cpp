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

	//kitchen->printDoorList();
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