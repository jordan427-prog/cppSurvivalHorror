#pragma once
#include <string>
#include <vector>
#include "Item.h"

class Furniture {
public:
    Furniture(std::string name, std::string description, std::string tag, bool isLocked);

    // Factory pattern to create default and easy furniture for ease of creation
    // Use when many repeats of furniture in different rooms
    static Furniture createDefaultCabinet();
    static Furniture createDefaultShelf();
    static Furniture createDefaultChair();
    static Furniture createDefaultTable();

    std::string getName();
    std::string getDescription();
    void Describe();
    std::string getInteractiontag();
    void addItems(std::vector<Item> items);
    void addItem(Item& item);
    void removeItem(Item& item);

private:
    std::string name;
    std::string description;
    std::string interactionTag;
    std::vector<Item> items;
    bool isLocked;
};