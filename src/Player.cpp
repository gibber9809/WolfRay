#include "Player.h"

Player::Player() {
    xPos = 0;
    yPos = 0;
    viewAngle = 0;
}

Player::Player(double xPos, double yPos, double viewAngle) {
    xPos = xPos;
    yPos = yPos;
    viewAngle = viewAngle;
}

double Player::getViewAngle() const {
    return viewAngle;
}

double Player::getXPos() const {
    return xPos;
}

double Player::getYPos() const {
    return yPos;
}

void Player::rotateViewAngle(double angle) {
    viewAngle += angle;
}

void Player::setViewAngle(double angle) {
    viewAngle = angle;  
}