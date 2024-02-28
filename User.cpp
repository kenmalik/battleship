#include "User.h"

User::User() {
}

char User::checkHit(int x, int y) {
    if (board.getCoordinate(x, y) == 'o') {
        board.setCoordinate(x, y, 'x');
        return 'x';
    } else {
        board.setCoordinate(x,y, '-');
        return '-';
    }
}

Board& User::getBoard() {
    return board;
}

Board& User::getEmptyBoard() {
    return emptyBoard;
}
