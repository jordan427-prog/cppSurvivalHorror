#include <string>
#include <vector>
#include <iostream>
#include "Item.cpp"

class Furniture {
public:
	Furniture(std::string name, std::string description, std::string tag, bool isLocked)
	{
		name = name;
		description = description;
		tag = tag;
		isLocked = isLocked;
	}

	std::string getName()
	{
		return name;
	}

	void getDescription()
	{
		std::cout << "You see " << description << std::endl;
	}

	std::string getInteractiontag()
	{
		return interactionTag;
	}

	void addItems(std::vector<Item> items)
	{
		for (int i = 0;i < items.size();i++)
		{
			items.push_back(items[i]);
		}
	}

	void addItem(Item& item)
	{
		items.push_back(item);
	}

	void removeItem(Item& item)
	{
		std::string itemName = item.getName();
		for (int i = 0;i < items.size();i++)
		{
			std::string name = items[i].getName();
			if (itemName == name)
			{
				items.erase(items.begin() + i);
				break;
			}
		}
	}
private:
	std::string name;
	std::string description;
	std::string interactionTag;
	std::vector<Item> items;
	bool isLocked;
};