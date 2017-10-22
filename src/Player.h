#ifndef PLAYER_H
#define PLAYER_H

//#include "GameMap.h"

class Player{
private:
    double xPos, yPos;
    double viewAngle;
public:
    Player();
    Player(double xPos_, double yPos_, double viewAngle_);
    double getXPos() const;
    double getYPos() const;
    double getViewAngle() const;

    void rotateViewAngle(double angle);
    void setViewAngle(double angle);
    void moveForwards(double delta);
    void moveSideways(double delta);
};
#endif