#include <iostream>

#define MAX_TREASURE 50 //Max score a treasure can have
#define HUNTERS 4 //Number of hunters on the map
#define TRASURES 3 //Number of treasures on the map

#include "assets/Hunter.cpp"
#include "assets/TreasureHunt.cpp";
using namespace std;

int main() {

    /*
     * Dummy example
     */

    int select,x,y;
    do {
        cout << "Pentru modul normal tastati 1, pentru modul cu obstacole tastati 2: "; cin >> select;
    }while( !(select == 1 || select == 2) );
    cout << "Introduceti dimensiunile hartii: ";
    cout << "\nx= "; cin >> x;
    cout << "\ny= "; cin >> y;

    if( select == 1) {
        TreasureHuntNormal t(x,y);
        cout << t;
        t.run();
        cout << t;
        for(int i=0; i<HUNTERS; i++)
            cout << "Hunter " << i << " - Treasure: " << (t.getHunterScore(i) ? "YES" : "NO") << endl;
    } else if( select == 2 ) {
        TreasureHuntObs t(x,y);
        cout << t;
        t.run();
        cout << t;
        for(int i=0; i<HUNTERS; i++)
            cout << "Hunter " << i << " - Treasure: " << (t.getHunterScore(i) ? "YES" : "NO") << endl;
    }


    return 0;
}