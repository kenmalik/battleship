#ifndef BATTLESHIP_USER_H
#define BATTLESHIP_USER_H

#include "Board.h"

class User {
private:
    Board board;
    Ship ships[5];

public:
    User();
    char launchMissile(int x , int y);
    bool isLoser();
    void placeShips();
    void placeHorizontally(Ship ship);
    void placeVertically(Ship ship);
    void print();

};


#endif //BATTLESHIP_USER_H
