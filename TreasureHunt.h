//
// Created by Razvan Statescu on 31/03/2018.
//

#ifndef POO_TEMA2_TREASUREHUNT_H
#define POO_TEMA2_TREASUREHUNT_H

#endif //POO_TEMA2_TREASUREHUNT_H

#include <random>
using namespace std;

class TreasureHunt {
    public:int **map;
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
public:
    void createMap(int, int);
    TreasureHunt();
    TreasureHunt(int, int);
    ~TreasureHunt();
    int getHunterScore(int);
    bool runOneRound();
    void run();
    friend ostream& operator<<(ostream&, const TreasureHunt&);
};
