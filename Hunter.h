//
// Created by Razvan Statescu on 31/03/2018.
//

#ifndef POO_TEMA2_HUNTER_H
#define POO_TEMA2_HUNTER_H

#endif //POO_TEMA2_HUNTER_H

class Hunter {
    int x;
    int y;
    int score;
    bool active;
    void init();
public:
    Hunter();
    Hunter(int, int);
    void setLocation(int, int);
    int getX();
    int getY();
    void addScore(int);
    int getScore();
    bool isActive();
    void setActiveStatus(bool);
};
