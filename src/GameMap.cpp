#include "GameMap.h"
#include "Player.h"
#include <math.h>
#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>

using namespace std;

GameMap::GameMap() {return;}

vector<pair<int,sf::Color> > GameMap::scanColumns(Player player, double fov, int numColumns, int columnHeight) {
    vector<pair<int,sf::Color> > lineHeights;
    double distanceToCameraPlane = (double(numColumns) * sin(PI/2.0 - fov/2.0)) / (2.0 * sin(fov/2.0));
    
    for (int i = 0; i < numColumns; ++i) {
        double viewAngleOffset = atan((double(i) - double(numColumns)/2.0) / distanceToCameraPlane);
        double rayAngle = player.getViewAngle() + viewAngleOffset;
        double rayDirX = cos(rayAngle);
        double rayDirY = sin(rayAngle);
        
        pair<double,sf::Color> distAndColor = scanLine(player.getXPos(), player.getYPos(), rayDirX, rayDirY);
        int lineHeight = 0;
        if (distAndColor.first >= 0)
            lineHeight = int(columnHeight/(distAndColor.first + 1.0));
        lineHeights.push_back(pair<int,sf::Color>(lineHeight,distAndColor.second));
    }

    return lineHeights;
}

pair<double,sf::Color> GameMap::scanLine(double rayPosX, double rayPosY, double rayDirX, double rayDirY) {
    int mapX, mapY, stepX, stepY;
    double intersectDistX, intersectDistY, hypDeltaX, hypDeltaY;
    bool wallHit = false;
    mapX = int(rayPosX);
    mapY = int(rayPosY);
    hypDeltaX = sqrt(1.0 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
    hypDeltaY = sqrt(1.0 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

    if (rayDirX < 0) {
        stepX = -1;
        intersectDistX = (rayPosX - mapX) * hypDeltaX;
    } else {
        stepX = 1;
        intersectDistX = (mapX + 1.0 - rayPosX) * hypDeltaX;
    }
    if (rayDirY < 0) {
        stepY = -1;
        intersectDistY = (rayPosY - mapY) * hypDeltaY;
    } else {
        stepY = 1;
        intersectDistY = (mapY + 1.0 - rayPosY) * hypDeltaY;
    }

    while (!wallHit && mapX >= 0 && mapY >= 0 && mapX < mapWidth && mapY < mapHeight) {
        if (intersectDistX < intersectDistY) {
            mapX += stepX;
            if (map[mapY][mapX] > 0) {
                wallHit = true;
                return pair<double,sf::Color>(intersectDistX,sf::Color(0,255,0));
            } else {
                intersectDistX += hypDeltaX;
            }
        } else {
            mapY += stepY;
            if (map[mapY][mapX] > 0) {
                wallHit = true;
                return pair<double,sf::Color>(intersectDistY,sf::Color(0,127,0));
            } else {
                intersectDistY += hypDeltaY;
            }
        }
    }
    return pair<double,sf::Color>(-1,sf::Color(0,0,0));
}
