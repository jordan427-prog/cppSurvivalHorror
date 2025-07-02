#include "Room.h"
#include <iostream>
#include <algorithm>

// You need to add furniture and connect rooms separately after instantiation
Room::Room(std::string name, std::string description, std::vector<Item> items) {
    this->name = name;
    this->description = description;
    this->items = items;
}

void Room::addItem(const Item item) {
    items.push_back(item);
}

// this automatically creates a door between both rooms involved
// This function will automatically initialize a door between the rooms upon connecting them
void Room::connectRoom(Room* room, bool isLockedState) {
    bool val = isConnected(room);

    if (val == true)
    {
        return;
    }

    // adding connected room BOTH ways for tracking from each room involved
    connectedRooms.push_back(room);
    room->connectedRooms.push_back(this);

    std::string name = this->name + "_" + room->getName() + "_door";

    Door* newDoor = new Door(name, this, room, isLockedState);

    this->addDoor(newDoor);
    room->addDoor(newDoor);
}

bool Room::isConnected(Room* targ)
{
    for (int i = 0;i < connectedRooms.size();i++)
    {
        if (connectedRooms[i]->getName() == targ->getName())
        {
            return true;
        }
    }
    return false;
}

void Room::Describe() {
    std::cout << "You see " << description << std::endl;
}

std::string Room::getDescription()
{
    return description;
}

void Room::getFurniture() {
    for (int i = 0; i < furniture.size(); i++) {
        std::cout << "You see " << furniture[i].getName() << std::endl;
    }
}

// returns a null furniture object if not found
Furniture Room::getFurnitureByName(std::string name)
{
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    for (int i = 0;i < furniture.size();i++)
    {
        std::string tempName = furniture[i].getName();
        std::transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);

        if (tempName == name)
        {
            return furniture[i];
        }
    }
    return Furniture{};
}

void Room::getItems()
{
    for (int i = 0;i < items.size();i++)
    {
        std::cout << "You see " << items[i].getName() << std::endl;
    }
}

// returns a null item object if not found
Item Room::getItemByName(std::string name)
{
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    for (int i = 0;i < items.size();i++)
    {
        std::string tempName = items[i].getName();
        std::transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);
        if (tempName == name)
        {
            return items[i];
        }
    }
    return Item{};
}

std::vector<Furniture>& Room::getFurnitureList()
{
    return furniture;
}

std::vector<Item>& Room::getItemsList()
{
    return items;
}

// Must do this after instantiation, refer to Furnitures's classes to see how to add items
void Room::addFurniture(std::vector<Furniture> furn) {
    for (int i = 0; i < furn.size(); i++) {
        furniture.push_back(furn[i]);
    }
}

std::string Room::getName()
{
    return name;
}

void Room::addDoor(Door* door)
{
    doors.push_back(door);
}

std::vector<Door*>& Room::getDoorList()
{
    return doors;
}

void Room::printDoorList()
{
    std::cout << std::endl;
    std::cout << "doors list for room: " << this->getName() << " include: " << std::endl;

    for (int i = 0;i < doors.size();i++)
    {
        bool val = doors[i]->isLocked();
        if (val == 1)
        {
            std::cout << doors[i]->getName() << " which is currently: locked" << std::endl;
        }
        else
        {
            std::cout << doors[i]->getName() << " which is currently: unlocked" << std::endl;
        }
    }
}
