#include "Item.h"
#include <iostream>

Item::Item(std::string name, std::string description, std::string purpose) {
    this->name = name;
    this->description = description;
    this->purpose = purpose;
}

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