#include <string>
#include <vector>
#include <iostream>

class Item {
public:
	Item(std::string name, std::string description, std::string purpose)
	{
		name = name;
		description = description;
		purpose = purpose;
	}

	void addInteractiontags(const std::string& interaction)
	{
		interactionTags.push_back(interaction);
	}

	std::string getName()
	{
		return name;
	}

	void getDescription()
	{
		std::cout << "You see " << description << std::endl;
	}

	std::string getPurpose()
	{
		return purpose;
	}

	bool canInteractWith(const std::string& tag) const {
		for (const auto& t : interactionTags) {
			if (t == tag) return true;
		}
		return false;
	}
private:
	std::string name;
	std::string description;
	std::string purpose;
	std::vector<std::string> interactionTags;
};