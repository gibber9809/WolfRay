#include "Map.h"
#include "Player.h"
#include <math.h>
#include <vector>

using namespace std;

vector<int> Map::scanColumns(Player player, double fov, int numColumns, int columnHeight) {
    vector<int> lineHeights;
    double distanceToCameraPlane = (double(numColumns) * sin(PI/2.0 - fov/2.0)) / (2.0 * sin(fov/2.0));
    for (int i = 0; i < numColumns; ++i) {
        double viewAngleOffset = atan((double(i) - double(numColumns)) / distanceToCameraPlane);
        double rayAngle = player.getViewAngle() + viewAngleOffset;
        double rayDirX = cos(rayAngle);
        double rayDirY = sin(rayAngle);
        
        double dist = scanLine(player.getXPos(), player.getYPos(), rayDirX, rayDirY);
        int lineHeight = int(columnHeight/(dist + 1.0));
        lineHeights.push_back(lineHeight);
    }

    return lineHeights;
}

int Map::scanLine(double rayPosX, double rayPosY, double rayDirX, double rayDirY) {
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
            } else {
                intersectDistX += hypDeltaX;
            }
        } else {
            mapY += stepY;
            if (map[mapY][mapX] > 0) {
                wallHit = true;
            } else {
                intersectDistY += hypDeltaY;
            }
        }
    }
}
