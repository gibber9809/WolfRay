#ifndef MAP_H
#define MAP_H

#define PI 3.14159265

#include "Player.h"
#include <vector>

class Map{
    private:
        int map[12][12] = {
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0}};
        int mapWidth = 12, mapHeight = 12;
    public:
        std::vector<int> scanColumns(Player player, double fov, int numColumns, int columnHeight);
        int scanLine(double rayPosX, double rayPosY, double rayDirX, double rayDirY);
};
#endif