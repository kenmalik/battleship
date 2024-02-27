#ifndef BATTLESHIP_USER_H
#define BATTLESHIP_USER_H

#include "Board.h"

class User {
private:
    Board board;

public:
    User();
    char launchMissile(int x , int y);
    bool isLoser();

};


#endif //BATTLESHIP_USER_H
