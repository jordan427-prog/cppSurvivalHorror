#pragma once
#include <string>
#include <vector>

class Item {
public:
    // In order for items to interact, you must separately add interaction tags AFTER instantiating item
    Item(std::string name, std::string description, std::string purpose);
    Item();

    // Factory generation of items
    static Item createDefaultAxe();
    static Item createDefaultDoorKey();
    static Item createDefaultCabinetKey();

    void addInteractiontags(const std::string& interaction);
    std::string getName();
    std::string getDescription();
    void Describe();
    std::string getPurpose();
    bool canInteractWith(const std::string& tag) const;

private:
    std::string name;
    std::string description;
    std::string purpose;
    std::vector<std::string> interactionTags;
};