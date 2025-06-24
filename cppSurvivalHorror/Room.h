#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include "Furniture.h"

class Room {
public:
    Room(std::string name, std::string description, std::vector<Item> items,
        std::vector<Room*> connectedRooms, bool isLocked);

    void addItem(const Item item);
    void connectRoom(Room* room);
    void Describe();
    std::string getDescription();
    void getFurniture();
    void addFurniture(std::vector<Furniture> furn);

private:
    std::string name;
    std::string description;
    std::vector<Item> items;
    std::vector<Room*> connectedRooms;
    std::vector<Furniture> furniture;
    bool isLocked;
};