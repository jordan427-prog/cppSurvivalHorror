#pragma once
#include <string>
#include <vector>
#include "Item.h"

class Furniture {
public:
    Furniture(std::string name, std::string description, std::string tag, bool isLocked);

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