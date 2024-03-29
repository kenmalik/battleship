#ifndef BATTLESHIP_USER_H
#define BATTLESHIP_USER_H

#include "Board.h"

class User {
private:
  Board board;
  Board emptyBoard;

public:
  User();
  char checkHit(int x, int y);
  Board &getBoard();
  Board &getEmptyBoard();
};

#endif // BATTLESHIP_USER_H
