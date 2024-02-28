#include "User.h"

User::User() {
}

char User::launchMissile(int x, int y) {
    if (board.getCoordinate(x, y) == 'o') {
        board.setCoordinate(x, y, 'x');
        return 'x';
    } else {
        board.setCoordinate(x,y, '-');
        return '-';
    }
}

bool User::isLoser() {
    return board.isGameOver();
}
