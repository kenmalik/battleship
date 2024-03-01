#include "User.h"

User::User() {}

char User::checkHit(int x, int y) {
  if (board.getCoordinate(x, y) == 'o') {
    board.setCoordinate(x, y, 'X');
    return 'X';
  } else {
    board.setCoordinate(x, y, '#');
    return '#';
  }
}

Board &User::getBoard() { return board; }

Board &User::getEmptyBoard() { return emptyBoard; }
