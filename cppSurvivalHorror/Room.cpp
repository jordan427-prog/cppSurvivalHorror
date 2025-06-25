#include "Room.h"
#include <iostream>

Room::Room(std::string name, std::string description, std::vector<Item> items,
    std::vector<Room*> connectedRooms, bool isLocked) {
    this->name = name;
    this->description = description;
    this->items = items;
    this->connectedRooms = connectedRooms;
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

void Room::addFurniture(std::vector<Furniture> furn) {
    for (int i = 0; i < furn.size(); i++) {
        furniture.push_back(furn[i]);
    }
}

std::string Room::getName()
{
    return name;
}