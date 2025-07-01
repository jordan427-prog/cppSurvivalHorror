#include "Furniture.h"
#include <iostream>
#include <algorithm>

Furniture::Furniture(std::string name, std::string description, std::string tag, bool isLocked) {
    this->name = name;
    this->description = description;
    this->interactionTag = tag;
    this->isLocked = isLocked;
}

Furniture::Furniture()
{
    name = "null";
    description = "null";
    interactionTag = "nothing";
    isLocked = true;
}

Furniture Furniture::createDefaultCabinet()
{
    return Furniture("cabinet", "an old locked dusty cabinet", "cabinet", true);
}

Furniture Furniture::createDefaultShelf()
{
    return Furniture("shelf", "an old locked dusty shelf", "shelf", true);
}

Furniture Furniture::createDefaultChair()
{
    return Furniture("chair", "an old dusty chair", "chair", false);
}

Furniture Furniture::createDefaultTable()
{
    return Furniture("table", "an old dusty table", "table", false);
}

//Furniture Furniture::createDefaultDoor()
//{
//    return Furniture("door", "a locked door, there is probably another room behind this door", "accessible door", true);
//}
//
//Furniture Furniture::createBrokenDoor()
//{
//    return Furniture("broken door", "this door seems jammed, I need to break it down somehow", "broken door", true);
//}

Furniture Furniture::createCouch()
{
    return Furniture("couch", "this seems to be a regular couch. This is at least 100 years old. It sure is dirty", "couch", false);
}

std::string Furniture::getName() {
    return name;
}

std::string Furniture::getDescription()
{
    return description;
}

void Furniture::Describe() {
    std::cout << "You see " << description << std::endl;
}

std::string Furniture::getInteractiontag() {
    return interactionTag;
}

void Furniture::addItems(std::vector<Item> incoming) {
    for (int i = 0; i < incoming.size(); i++) {
        items.push_back(incoming[i]);
    }
}

void Furniture::addItem(Item& item) {
    items.push_back(item);
}

void Furniture::removeItem(Item& item) {
    std::string itemName = item.getName();
    for (int i = 0; i < items.size(); i++) {
        std::string name = items[i].getName();
        if (itemName == name) {
            items.erase(items.begin() + i);
            break;
        }
    }
}

bool Furniture::isLockedCheck()
{
    return isLocked;
}

std::vector<Item> Furniture::getItemsList()
{
    return items;
}

// returns null item object if nothing found
Item Furniture::getItemByName(std::string name)
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