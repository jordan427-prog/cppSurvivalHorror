#pragma once

class Enemy {
public:
    Enemy();

    bool getSeesPlayer();
    bool getRunningStatus();
    int getHealth();
    bool getIsStunned();

    void changeHealth(int add);
    void playerSpottedStatus(bool status);
    void runningStatus(bool status);
    void isStunnedStatus(bool status);

private:
    bool seesPlayer;
    bool isRunning;
    int health;
    bool isStunned;
};