#include "Player.h"

Player::Player() {
    xPos = 0;
    yPos = 0;
    viewAngle = 0;
}

Player::Player(double xPos_, double yPos_, double viewAngle_) {
    xPos = xPos_;
    yPos = yPos_;
    viewAngle = viewAngle_;
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