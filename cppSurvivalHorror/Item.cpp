#include "Item.h"
#include <iostream>

// In order for items to interact, you must separately add interaction tags AFTER instantiating item
Item::Item(std::string name, std::string description, std::string purpose) {
    this->name = name;
    this->description = description;
    this->purpose = purpose;
}

Item::Item()
{
    name = "null";
    description = "null";
    purpose = "null";
}

Item Item::createDefaultAxe()
{
    return Item("axe", "A small rusty axe.", "You can use this to break brittle and thin wood");
}

Item Item::createDefaultDoorKey()
{
    return Item("door key", "An old door key", "door key");
}

Item Item::createDefaultCabinetKey()
{
    return Item("cabinet key", "An old cabinet key", "cabinet key");
}

// Must use this function after instantiating to ensure item will be "tied" to certain furniture
void Item::addInteractiontags(const std::string& interaction) {
    interactionTags.push_back(interaction);
}

std::string Item::getName() {
    return name;
}

void Item::Describe() {
    std::cout << "You see " << description << std::endl;
}

std::string Item::getDescription()
{
    return description;
}

std::string Item::getPurpose() {
    return purpose;
}

bool Item::canInteractWith(const std::string& tag) const {
    for (const auto& t : interactionTags) {
        if (t == tag) return true;
    }
    return false;
}