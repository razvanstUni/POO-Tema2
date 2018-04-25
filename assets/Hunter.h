//
// Created by Razvan Statescu on 31/03/2018.
//

#ifndef POO_TEMA2_HUNTER_H
#define POO_TEMA2_HUNTER_H

#endif //POO_TEMA2_HUNTER_H

class Hunter {
protected:
    int x;
    int y;
    int score;
    bool active;
    void init();
    bool direction[5];
    enum directions {up=1, right, down, left};
    int radius;
public:
    Hunter();
    void setLocation(int, int);
    int getX();
    int getY();
    void addScore(int);
    int getScore();
    bool isActive();
    void setActiveStatus(bool);
    bool hunterCanMoveInDirection(int);
    virtual int checkForTreasureNear(int, int, int**, int, int) = 0;
};

class HunterTL : public Hunter {
public:
    HunterTL();
    int checkForTreasureNear(int, int, int**, int, int);
};

class HunterTR : public Hunter {
public:
    HunterTR();
    int checkForTreasureNear(int, int, int**, int, int);
};

class HunterBL : public Hunter {
public:
    HunterBL();
    int checkForTreasureNear(int, int, int**, int, int);
};

class HunterBR : public Hunter {
public:
    HunterBR();
    int checkForTreasureNear(int, int, int**, int, int);
};
