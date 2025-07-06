#pragma once
#include <vector>
#include <string>
#include "item.h"

class Player {
public:
    Player();
    Player(int health, int sanity);

    void changeHealth(int add);
    void changeSanity(int add);
    int getHealth();
    int getSanity();
    std::vector<Item> getInventory();
    void addInventory(Item item);
    void addInventory(std::vector<Item> incoming_item);
    bool hasItem(Item& item);
    bool removeItem(Item& item);

private:
    int health;
    int sanity;
    std::vector<Item> inventory;
};