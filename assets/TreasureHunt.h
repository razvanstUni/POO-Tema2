//
// Created by Razvan Statescu on 31/03/2018.
//

#ifndef POO_TEMA2_TREASUREHUNT_H
#define POO_TEMA2_TREASUREHUNT_H

#endif //POO_TEMA2_TREASUREHUNT_H

#include <random>
using namespace std;

class TreasureHunt {
protected:
    int **map;
    int rows, columns;
    Hunter hunters[4];
    int hunterCount;
    int treasureCount;
    enum directions {up=1, right, down, left};

    void init();
    int random(int, int);
    void addHunter(int, int);
    void addTreasure();
    int moveHunter(int);
    bool hunterCanMove(int);
    virtual void createMap(int, int) = 0;
    bool hunterCanMoveInDirection(int, int);
public:
    TreasureHunt();
    TreasureHunt(int, int);
    ~TreasureHunt();
    int getHunterScore(int);
    bool runOneRound();
    void run();
    friend ostream& operator<<(ostream&, TreasureHunt&);
};

class TreasureHuntNormal : public TreasureHunt {
public:
    TreasureHuntNormal(int, int);
    void createMap(int, int);
};

class TreasureHuntObs : public TreasureHunt {
public:
    TreasureHuntObs(int, int);
    void createMap(int, int);
};