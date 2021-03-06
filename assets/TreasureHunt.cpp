//
// Created by Razvan Statescu on 31/03/2018.
//

#include "TreasureHunt.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void TreasureHunt::init() {
    this->hunterCount = 0;
    this->treasureCount = 0;
}

TreasureHunt::TreasureHunt() {
    this->init();
    this->map = 0;
}
/**
 *
 * @param rows int - map rows
 * @param columns int - map columns
 */
TreasureHunt::TreasureHunt(int rows, int columns) {
    this->init();
    this->createMap(rows, columns);
}

TreasureHunt::~TreasureHunt() {
    int i;
    for( int i = 0;  i < this->rows; i++ )
        delete [] this->map[i];
    delete [] this->map;
}
/**
 *
 * @param os ostream&
 * @param t TreasureHunt
 * @return ostream&
 */
ostream& operator<<(ostream& os, TreasureHunt& t)
{
    int i,j,activeHunters = 0;
    for(i=0;i<HUNTERS;i++)
        if(t.hunters[i]->isActive()) activeHunters++;

    os << "--- Active hunters: " << activeHunters << " - Treasures left: " << t.treasureCount << " ---\n";
    for(i=0;i<t.rows;i++) {
        for(j=0;j<t.columns;j++) {
            os << setw(3);
            if( t.map[i][j] == -2 ) os << "X";
            else os << t.map[i][j];
        }
        os << "\n";
    }
    return os;
}
/**
 *
 * @param min int
 * @param max int
 * @return int
 */
int TreasureHunt::random(int min, int max) {
    static bool first = true;
    if (first)
    {
        srand( time(NULL) ); //seeding for the first time only!
        first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}
/**
 *
 * @param x int - x position on the map
 * @param y int - y position on the map
 */
void TreasureHunt::addHunter(int x, int y, int type) {
    if(!map || this->hunterCount >= HUNTERS) return;

    switch(type) {
        case 1:
            this->hunters[this->hunterCount] = new HunterTL;
            break;
        case 2:
            this->hunters[this->hunterCount] = new HunterTR;
            break;
        case 3:
            this->hunters[this->hunterCount] = new HunterBL;
            break;
        case 4:
            this->hunters[this->hunterCount] = new HunterBR;
            break;
    }

    this->hunters[ this->hunterCount ]->setLocation(x, y);
    this->hunterCount++;
    this->map[x][y] = -1;
}

void TreasureHunt::addTreasure() {
    if(!map) return;
    int x,y;
    do {
        x = this->random(0, this->rows-1);
        y = this->random(0, this->columns-1);
    }while( this->map[x][y] == -1 &&  this->map[x][y] > 1);
    this->map[x][y] = this->random(1, MAX_TREASURE);
    this->treasureCount++;
}
/**
 *
 * @param i - Hunter ID
 * @return bool - true if Hunter can move or false if Hunter can't
 */
bool TreasureHunt::hunterCanMove(const int i) {
    int x,y;
    x = this->hunters[i]->getX();
    y = this->hunters[i]->getY();
    if(x > 0 && this->map[x-1][y] >= 0 && this->hunters[i]->hunterCanMoveInDirection(up) )
        return true;
    else if(x < this->rows-1 && this->map[x+1][y] >= 0 && this->hunters[i]->hunterCanMoveInDirection(down) )
        return true;
    else if(y > 0 && this->map[x][y-1] >= 0 && this->hunters[i]->hunterCanMoveInDirection(left) )
        return true;
    else if(y < this->columns-1 && this->map[x][y+1] >= 0 && this->hunters[i]->hunterCanMoveInDirection(right) )
        return true;
    return false;
}
/**
 *
 * @param hunterID - Hunter ID
 * @return int - < 0 if error, 0 if no error and no treasure found, > 0 if no error and treasure found
 */
int TreasureHunt::moveHunter(const int hunterID) {
    if(!this->hunterCanMove(hunterID) || !this->hunters[ hunterID ]->isActive()) return -1;
    int x,y,xx,yy, direction; bool forceDirection = false;
    xx = x = this->hunters[ hunterID ]->getX();
    yy = y = this->hunters[ hunterID ]->getY();
    direction = this->hunters[ hunterID ]->checkForTreasureNear(x, y, this->map, this->rows, this->columns);
    if( direction > 0 ) forceDirection = true;
        do {
            if( !forceDirection ) {
                do { direction = random(1, 5); } while (!this->hunters[hunterID]->hunterCanMoveInDirection(direction));
            }
            if(direction == up && x>0)
                x--;
            else if(direction == right && y<this->columns-1)
                y++;
            else if(direction == down && x<this->rows-1)
                x++;
            else if(direction == left && y>0)
                y--;
            if(this->map[x][y] < 0) { x = xx; y = yy;}
        }while(x == xx && y == yy);
    this->map[xx][yy] = -1;
    this->hunters[ hunterID ]->setLocation(x, y);
    if(this->map[x][y] > 0) {
        this->hunters[ hunterID ]->addScore( this->map[x][y] );
        this->treasureCount--;
        this->map[ x ][ y ] = -1;
        this->hunters[ hunterID ]->setActiveStatus(false);
        return 5;
    } else {
        this->map[ x ][ y ] = -2;
        return 0;
    }
}
/**
 *
 * @param hunterID - Hunter ID
 * @return int
 */
int TreasureHunt::getHunterScore(const int hunterID) {
    return this->hunters[ hunterID ]->getScore();
}
/**
 *
 * @return bool - true if at the end of a round there are Hunters left on the map or false if there aren't any Hunters left
 */
bool TreasureHunt::runOneRound() {
    int i, status;
    bool huntersLeft = false;
    for(i=0; i<HUNTERS; i++) {
        if( this->moveHunter(i) == 0) huntersLeft = true;
    }
    return huntersLeft;
}

void TreasureHunt::run() {
    bool status;
    ofstream log("log.txt");
    do {
        log << *this << "\n";
        status = this->runOneRound();
    }while(this->treasureCount && status);
    log.close();
}

/*
 * Treasure Hunt Normal
 */

/**
 *
 * @param rows int map rows
 * @param columns int map columns
 */
TreasureHuntNormal::TreasureHuntNormal(int rows, int columns) {
    this->init();
    this->createMap(rows, columns);
}
/**
 *
 * @param rows int map rows
 * @param columns int map columns
 */
void TreasureHuntNormal::createMap(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    this->map = new int* [rows];
    int i,j;
    for(i=0; i<rows; i++) {
        this->map[i] = new int [columns];
    }
    for(i=0;i<rows;i++)
        for(j=0;j<columns;j++)
            this->map[i][j] = 0;
    this->addHunter(0, 0, this->TR);
    this->addHunter(0, columns-1, this->TL);
    this->addHunter(rows-1, 0, this->BL);
    this->addHunter(rows-1, columns-1, this->BR);
    for(i=1;i<=TRASURES;i++)
        this->addTreasure();
}

/*
 * Treasure Hunt Obstacles
 */

/**
 *
 * @param rows int map rows
 * @param columns int map columns
 */
TreasureHuntObs::TreasureHuntObs(int rows, int columns) {
    this->init();
    this->createMap(rows, columns);
}
/**
 *
 * @param rows int map rows
 * @param columns int map columns
 */
void TreasureHuntObs::createMap(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    this->map = new int* [rows];
    int i,j;
    for(i=0; i<rows; i++) {
        this->map[i] = new int [columns];
    }
    for(i=0;i<rows;i++)
        for(j=0;j<columns;j++)
            this->map[i][j] = 0;

    //Add obstacles
    i = this->random(1, (rows+columns)/10 + 2 );
    for(j = 1; j <= i; j++) {
        int x,y;
        x = this->random(0, rows-1);
        y = this->random(0, columns-1);
        this->map[x][y] = -1;
    }

    this->addHunter(0, 0, this->TR);
    this->addHunter(0, columns-1, this->TL);
    this->addHunter(rows-1, 0, this->BL);
    this->addHunter(rows-1, columns-1, this->BR);
    for(i=1;i<=TRASURES;i++)
        this->addTreasure();
}