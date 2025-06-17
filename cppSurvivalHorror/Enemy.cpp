#include <vector>
#include <string>

class Enemy
{
public:
	Enemy()
	{
		seesPlayer = false;
		isRunning = false;
		health = 100;
		isStunned = false;
	}

	bool getSeesPlayer()
	{
		return seesPlayer;
	}

	bool getRunningStatus()
	{
		return isRunning;
	}

	int getHealth()
	{
		return health;
	}

	bool getIsStunned()
	{
		return isStunned;
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

	void playerSpottedStatus(bool status)
	{
		seesPlayer = status;
	}

	void runningStatus(bool status)
	{
		isRunning = status;
	}

	void isStunnedStatus(bool status)
	{
		isStunned = status;
	}

private:
	bool seesPlayer;
	bool isRunning;
	int health;
	bool isStunned;

};
