#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H

#include <vector>
#include <iostream>
#include "Ship.h"

class Board {
public:
    Board();
    const std::vector<std::vector<char>>& getBoard() const;
    friend std::ostream& operator<<(std::ostream&, const Board&);
    char getCoordinate(int x, int y) const; // returns whats at that coordinate (ship or nothing)
    void setCoordinate(int x, int y, char icon); //sets coordinate
    void setShip(int, int, Ship); //sets ships
    bool isGameOver();

private:
    std::vector<std::vector<char>> board;
};

#endif //BATTLESHIP_BOARD_H
