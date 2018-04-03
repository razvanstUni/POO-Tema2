#include <iostream>

#define MAX_TREASURE 50 //Max score a treasure can have
#define HUNTERS 4 //Number of hunters on the map
#define TRASURES 3 //Number of treasures on the map

#include "Hunter.cpp"
#include "TreasureHunt.cpp";
using namespace std;

int main() {
    TreasureHunt t;
    t.createMap(15,15);
    cout << t;
    t.run();
    cout << t;
    for(int i=0; i<HUNTERS; i++)
        cout << "Hunter " << i << " - Treasure: " << (t.getHunterScore(i) ? "YES" : "NO") << endl;
    return 0;
}