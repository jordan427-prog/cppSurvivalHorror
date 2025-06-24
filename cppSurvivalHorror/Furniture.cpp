#include "Furniture.h"
#include <iostream>

Furniture::Furniture(std::string name, std::string description, std::string tag, bool isLocked) {
    this->name = name;
    this->description = description;
    this->interactionTag = tag;
    this->isLocked = isLocked;
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