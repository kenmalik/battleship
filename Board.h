#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H

#include "Ship.h"
#include <iostream>
#include <vector>

class Board {
public:
  static constexpr int kBoardSize = 10;
  Board();
  const std::vector<std::vector<char>> &getBoard() const;
  friend std::ostream &operator<<(std::ostream &, const Board &);
  char getCoordinate(int x, int y) const;
  void setCoordinate(int x, int y, char icon);
  void setShip(int, int, Ship);
  bool isGameOver() const;

private:
  std::vector<std::vector<char>> board;
};

#endif // BATTLESHIP_BOARD_H
