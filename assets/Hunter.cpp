//
// Created by Razvan Statescu on 31/03/2018.
//
#include "Hunter.h";
void Hunter::init() {
    this->score = 0;
    this->active = true;
    int i;
    for(i=1;i<=4;i++)
        this->direction[i] = false;
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
}
/*
 * Hunter Top Right
 */
HunterTR::HunterTR() {
    this->direction[ left ] = true;
    this->direction[ down ] = true;
}

/*
 * Hunter Bottom Left
 */
HunterBL::HunterBL() {
    this->direction[ right ] = true;
    this->direction[ up ] = true;
}

/*
 * Hunter Bottom Right
 */
HunterBR::HunterBR() {
    this->direction[ left ] = true;
    this->direction[ up ] = true;
}
