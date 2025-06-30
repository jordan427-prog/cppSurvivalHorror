#include "Room.h"
#include <iostream>
#include <algorithm>

// You need to add furniture and connect rooms separately after instantiation
Room::Room(std::string name, std::string description, std::vector<Item> items, bool isLocked) {
    this->name = name;
    this->description = description;
    this->items = items;
    this->isLocked = isLocked;
}

void Room::addItem(const Item item) {
    items.push_back(item);
}

void Room::connectRoom(Room* room) {
    connectedRooms.push_back(room);
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