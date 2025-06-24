#include "Enemy.h"

Enemy::Enemy() {
    seesPlayer = false;
    isRunning = false;
    health = 100;
    isStunned = false;
}

bool Enemy::getSeesPlayer() {
    return seesPlayer;
}

bool Enemy::getRunningStatus() {
    return isRunning;
}

int Enemy::getHealth() {
    return health;
}

bool Enemy::getIsStunned() {
    return isStunned;
}

void Enemy::changeHealth(int add) {
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

void Enemy::playerSpottedStatus(bool status) {
    seesPlayer = status;
}

void Enemy::runningStatus(bool status) {
    isRunning = status;
}

void Enemy::isStunnedStatus(bool status) {
    isStunned = status;
}