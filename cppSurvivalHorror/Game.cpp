#include "Game.h"

void Game::setup()
{
	// living room
	Item intro_photo = Item::Item("house owners photograph", "This photo looks to be an old couple in front of this house. I'm assuming they used to live here years ago. I wonder what happened to them...", "viewing");
	std::vector<Item> livingRoomItems;
	livingRoomItems.push_back(intro_photo);
	Room livingRoom = Room::Room("living room", "this dark and dusty room appears to be a living room...", livingRoomItems, false);
	Item default_axe = Item::createDefaultAxe();
	// the axe can be used for this
	default_axe.addInteractiontags("broken door");
	// key needed!
	Furniture livingRoomCabinet = Furniture::Furniture("living room cabinet", "an oak cabinet. This seems expensive, maybe theres something of value inside? It is locked, this requires a key", "cabinet", true);
	livingRoomCabinet.addItem(default_axe);
	Furniture livingRoomDoor1 = Furniture::createDefaultDoor();
	Furniture livingRoomDoor2 = Furniture::createDefaultDoor();
	std::vector<Furniture> furn;
	furn.push_back(livingRoomCabinet);
	furn.push_back(livingRoomDoor1);
	furn.push_back(livingRoomDoor2);
	livingRoom.addFurniture(furn);
	rooms.push_back(livingRoom);

	// kitchen
	//Room kitchen= Room::Room("kitchen", "this appears to have once been a kitchen. ")
}

void Game::run()
{

}