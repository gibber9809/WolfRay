#ifndef PLAYER_H
#define PLAYER_H

class Player{
private:
    double xPos, yPos;
    double viewAngle;
public:
    Player();
    Player(double xPos, double yPos, double viewAngle);
    double getXPos() const;
    double getYPos() const;
    double getViewAngle() const;

    void rotateViewAngle(double angle);
    void setViewAngle(double angle);
};
#endif