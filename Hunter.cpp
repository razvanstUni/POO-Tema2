//
// Created by Razvan Statescu on 31/03/2018.
//
#include "Hunter.h";
void Hunter::init() {
    this->score = 0;
    this->active = true;
}
Hunter::Hunter() {
    this->x = -1;
    this->y = -1;
    this->init();
}
Hunter::Hunter(int x, int y) {
    this->x = x;
    this->y = y;
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
