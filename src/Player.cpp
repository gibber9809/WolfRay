#include "Player.h"
#include "GameMap.h"
#include <math.h>
#include <utility>
//#include <SFML/Graphics.hpp>

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

void Player::moveForwards(double delta) {//, const GameMap & gameMap) {
    double deltaX, deltaY;
    deltaX = delta * cos(viewAngle);
    deltaY = delta * sin(viewAngle);

    /*if (gameMap.isWall(int(xPos + deltaX), int(yPos + deltaY))) {
        pair<double,sf::Color> dist = gameMap.scanLine(xPos,yPos,deltaX,deltaY);
        xPos = trunc(xPos + dist.first * cos(viewAngle));
        yPos = trunc(yPos + dist.first * sin(viewAngle));
    } else {*/
        xPos += deltaX;
        yPos += deltaY;
    //}
}

void Player::moveSideways(double delta) {
    xPos += delta * cos(viewAngle + PI/2);
    yPos += delta * sin(viewAngle + PI/2);
}