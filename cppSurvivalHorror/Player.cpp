#include "Player.h"
#include <algorithm>

Player::Player() {
    this->health = 100;
    this->sanity = 100;
}

Player::Player(int health, int sanity) {
    this->health = health;
    this->sanity = sanity;
}

void Player::changeHealth(int add) {
    if ((health + add) >= 100) {
        health = 100;
    }
    else if ((health + add) <= 0) {
        health = 0;
    }
    else {
        health += add;
    }
}

void Player::changeSanity(int add) {
    if ((sanity + add) >= 100) {
        sanity = 100;
    }
    else if ((sanity + add) <= 0) {
        sanity = 0;
    }
    else {
        sanity += add;
    }
}

int Player::getHealth() {
    return health;
}

int Player::getSanity() {
    return sanity;
}

std::vector<Item> Player::getInventory() {
    return inventory;
}

void Player::addInventory(Item item1)
{
    std::vector<Item> item;
    item.push_back(item1);
    addInventory(item);
}

void Player::addInventory(std::vector<Item> incoming_item) {
    for (int i = 0; i < incoming_item.size(); i++) {
        inventory.push_back(incoming_item[i]);
    }
}

bool Player::hasItem(Item& item) {
    for (int j = 0;j < inventory.size();j++)
    {
        if (inventory[j].getName() == item.getName())
        {
            return true;
        }
    }
    return false;
}

bool Player::removeItem(Item& item) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->getName() == item.getName()) {
            inventory.erase(it);
            return true;
        }
    }
    return false;
}
