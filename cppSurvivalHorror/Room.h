#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include "Furniture.h"
#include "Door.h"
#include <iostream>

class Door;

class Room {
public:
    // You must connect rooms after instantiation
    // You must also add furniture separately
    Room(std::string name, std::string description, std::vector<Item> items);

    void addItem(const Item item);
    void connectRoom(Room* room, bool isLockedState);
    bool isConnected(Room* targ);
    void Describe();
    std::string getDescription();
    void getFurniture();
    Furniture getFurnitureByName(std::string name);
    void getItems();
    Item getItemByName(std::string name);
    std::vector<Furniture>& getFurnitureList();
    std::vector<Item>& getItemsList();
    void addFurniture(std::vector<Furniture> furn);
    std::string getName();
    void addDoor(Door* door);
    std::vector<Door*>& getDoorList();
    void printDoorList();
    bool removeItem(Item& item);

private:
    std::string name;
    std::string description;
    std::vector<Item> items;
    std::vector<Room*> connectedRooms;
    std::vector<Furniture> furniture;
    std::vector<Door*> doors;
    bool isLocked;
};