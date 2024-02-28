#include "Board.h"

Board::Board() {
    constexpr int kBoardSize = 10;
    for (int i = 0; i < kBoardSize; ++i) {
        board.push_back(std::vector<char>(10, '.'));
    }
}

void Board::print() {
    for (std::vector<char>& row : board) {
        for (char space : row) {
            std::cout << space << " ";
        }
        std::cout << std::endl;
    }
}

char Board::getCoordinate(int x, int y){
    return board.at(x).at(y);
}

void Board::setCoordinate(int x, int y, char icon) {
    board.at(x).at(y) = icon;
}

void Board::setShip(int x, int y, Ship ship) {
    if (ship.getIsHorizontal()) {
        for (int i = 0; i < ship.getLength(); i++) {
            board.at(y).at(x + i) = ship.getIcon();
        }
    } else {
        for (int i = 0; i < ship.getLength(); i++) {
            board.at(y + i).at(x) = ship.getIcon();
        }
    }
}

bool Board::isGameOver() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board.at(i).at(j) == 'o') {
                return false;
            }
        }
    }
    return true;
}

