#pragma once
#include <string>
#include <vector>

class Item {
public:
    Item(std::string name, std::string description, std::string purpose);

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