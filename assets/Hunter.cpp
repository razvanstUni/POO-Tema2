//
// Created by Razvan Statescu on 31/03/2018.
//
#include "Hunter.h"
void Hunter::init() {
    this->score = 0;
    this->active = true;
    int i;
    for(i=1;i<=4;i++)
        this->direction[i] = false;
    this->radius = 1;
}
Hunter::Hunter() {
    this->x = -1;
    this->y = -1;
    this->init();
}
/**
 *
 * @param x - x location on the map
 * @param y - y location on the map
 */
void Hunter::setLocation(int x, int y) {
    this->x = x;
    this->y = y;
}
/**
 *
 * @return int - x location on the map
 */
int Hunter::getX() {
    return this->x;
}
/**
 *
 * @return int - y location on the map
 */
int Hunter::getY() {
    return this->y;
}
/**
 *
 * @param value int
 */
void Hunter::addScore(int value) {
    this->score+=value;
}
/**
 *
 * @return int
 */
int Hunter::getScore() {
    return this->score;
}
/**
 *
 * @return bool
 */
bool Hunter::isActive() {
    return this->active;
}
/**
 *
 * @param status bool
 */
void Hunter::setActiveStatus(bool status) {
    this->active = status;
}
/**
 *
 * @param dir int
 * @return bool
 */
bool Hunter::hunterCanMoveInDirection(int dir) {
    return this->direction[ dir ];
}
/*
 * Hunter Top Left
 */
HunterTL::HunterTL() {
    this->direction[ right ] = true;
    this->direction[ down ] = true;
    this->direction[ up ] = true;
    this->radius = 4;
}
/**
 *
 * @param x int - x position on the map
 * @param y int - y position on the map
 * @param map int**
 * @param rows int - number of rows for the map
 * @param columns int - number of columns for the map
 * @return int - direction
 */
int HunterTL::checkForTreasureNear(int x, int y, int** map, int rows, int columns) {
    int i;
    for(i = x; i >= x-radius && i > 0; i--) if( map[i][y] > 0 ) return up;
    for(i = y; i <= y+radius && i < columns; i++) if( map[x][i] > 0 ) return right;
    for(i = x; i <= x+radius && i < rows; i++) if( map[i][y] > 0 ) return down;
    return -1;
}
/*
 * Hunter Top Right
 */
HunterTR::HunterTR() {
    this->direction[ left ] = true;
    this->direction[ down ] = true;
    this->direction[ right ] = true;
    this->radius = 5;
}
/**
 *
 * @param x int - x position on the map
 * @param y int - y position on the map
 * @param map int**
 * @param rows int - number of rows for the map
 * @param columns int - number of columns for the map
 * @return int - direction
 */
int HunterTR::checkForTreasureNear(int x, int y, int** map, int rows, int columns) {
    int i;
    for(i = y; i <= y+radius && i < columns; i++) if( map[x][i] > 0 ) return right;
    for(i = x; i <= x+radius && i < rows; i++) if( map[i][y] > 0 ) return down;
    for(i = y; i >= y-radius && i > 0; i--) if( map[x][i] > 0 ) return left;
    return -1;
}

/*
 * Hunter Bottom Left
 */
HunterBL::HunterBL() {
    this->direction[ right ] = true;
    this->direction[ up ] = true;
    this->direction[ left ] = true;
    this->radius = 5;
}
/**
 *
 * @param x int - x position on the map
 * @param y int - y position on the map
 * @param map int**
 * @param rows int - number of rows for the map
 * @param columns int - number of columns for the map
 * @return int - direction
 */
int HunterBL::checkForTreasureNear(int x, int y, int** map, int rows, int columns) {
    int i;
    for(i = x; i >= x-radius && i > 0; i--) if( map[i][y] > 0 ) return up;
    for(i = y; i <= y+radius && i < columns; i++) if( map[x][i] > 0 ) return right;
    for(i = y; i >= y-radius && i > 0; i--) if( map[x][i] > 0 ) return left;
    return -1;
}

/*
 * Hunter Bottom Right
 */
HunterBR::HunterBR() {
    this->direction[ left ] = true;
    this->direction[ up ] = true;
    this->direction[ down ] = true;
    this->radius = 4;
}
/**
 *
 * @param x int - x position on the map
 * @param y int - y position on the map
 * @param map int**
 * @param rows int - number of rows for the map
 * @param columns int - number of columns for the map
 * @return int - direction
 */
int HunterBR::checkForTreasureNear(int x, int y, int** map, int rows, int columns) {
    int i;
    for(i = x; i >= x-radius && i > 0; i--) if( map[i][y] > 0 ) return up;
    for(i = x; i <= x+radius && i < rows; i++) if( map[i][y] > 0 ) return down;
    for(i = y; i >= y-radius && i > 0; i--) if( map[x][i] > 0 ) return left;
    return -1;
}
