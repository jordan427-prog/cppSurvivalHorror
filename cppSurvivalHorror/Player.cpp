#include <vector>
#include <string>

class Player {
public:
	Player()
	{
		this->health = 100;
		this->sanity = 100;
	}

	Player(int health, int sanity)
	{
		this->health = health;
		this->sanity = sanity;
	}

	void changeHealth(int add)
	{
		if ((health + add) >= 100)
		{
			health = 100;
		}
		else if ((health + add) <= 0)
		{
			health = 0;
		}
		else
		{
			health += add;
		}
	}

	void changeSanity(int add)
	{
		if ((sanity + add) >= 100)
		{
			sanity = 100;
		}
		else if ((sanity + add) <= 0)
		{
			sanity = 0;
		}
		else
		{
			sanity += add;
		}
	}

	int getHealth()
	{
		return health;
	}

	int getSanity()
	{
		return sanity;
	}

	std::vector<std::string> getInventory()
	{
		return inventory;
	}

	void addInventory(std::vector<std::string> incoming)
	{
		for (int i = 0;i < incoming.size();i++)
		{
			inventory.push_back(incoming[i]);
		}
	}

	bool hasItem(std::string& item)
	{
		bool status = std::find(inventory.begin(), inventory.end(), item) != inventory.end();
		return status;
	}

	bool removeItem(std::string& item)
	{
		auto it = std::find(inventory.begin(), inventory.end(), item);
		if (it != inventory.end()) {
			inventory.erase(it);
			return true; 
		}
		return false; 
	}

private:
	int health;
	int sanity;
	std::vector<std::string> inventory;
};