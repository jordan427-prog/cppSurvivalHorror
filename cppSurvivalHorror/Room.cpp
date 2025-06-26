#include "Room.h"
#include <iostream>

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

void Room::getItems()
{
    for (int i = 0;i < items.size();i++)
    {
        std::cout << "You see " << items[i].getName() << std::endl;
    }
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