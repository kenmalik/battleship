#include "Board.h"
#include <iomanip>
#include <vector>

Board::Board() {
    constexpr int kBoardSize = 10;
    for (int i = 0; i < kBoardSize; ++i) {
        board.push_back(std::vector<char>(10, '.'));
    }
}

std::vector<std::vector<char>>& Board::getBoard() {
    return board;
}

std::ostream& operator<<(std::ostream& os, Board& board)  {
    std::cout << "   ";
    for (int i = 1; i <= board.getBoard().size(); ++i) {
        std::cout << std::setw(2) << i << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < board.getBoard().size(); ++i) {
        std::cout << std::setw(2) << i + 1 << " ";
        for (char space : board.getBoard().at(i)) {
            std::cout << std::setw(2) << space << " ";
        }
        std::cout << std::endl;
    }
    return os;
}

char Board::getCoordinate(int x, int y){
    return board.at(y).at(x);
}

void Board::setCoordinate(int x, int y, char icon) {
    board.at(y).at(x) = icon;
}

void Board::setShip(int x, int y, Ship ship) {
    if (ship.getIsHorizontal()) {
        for (int i = 0; i < ship.getLength(); i++) {
            board.at(y).at(x + i) = 'o';
        }
    } else {
        for (int i = 0; i < ship.getLength(); i++) {
            board.at(y + i).at(x) = 'o';
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

