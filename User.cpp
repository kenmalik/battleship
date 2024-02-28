#include "User.h"

User::User(){
    ships[0] = Ship(1,'o', rand() % 2);
    ships[1] = Ship(2,'o', rand() % 2);
    ships[2] = Ship(3,'o', rand() % 2);
    ships[3] = Ship(4,'o', rand() % 2);
    ships[4] = Ship(5,'o', rand() % 2);
    placeShips();
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

void User::placeShips() {
    for (int i = 0; i < 5; i++) {
        if (ships[i].getIsHorizontal()) {
            placeVertically(ships[i]);
        } else {
            placeHorizontally(ships[i]);
        }
    }
}

void User::placeVertically(Ship ship) {
    bool valid = false;

    while (!valid) {
        int r = (rand() % 10);
        int c = (rand() % 10);
        int counter = 0;

        if (r + ship.getLength() < 10) {
            for (int i = 0; i < ship.getLength(); i++) {
                if (board.getCoordinate(r+i ,c) == '.') {
                    counter++;
                }
            }

            if (counter == ship.getLength()) {
                valid = true;
            }
            board.setShip(r, c, ship);
        }
    }
}

void User::placeHorizontally(Ship ship) {
    bool valid = false;

    while (!valid) {
        int r = rand() % 10;
        int c = rand() % 10;
        int counter = 0;

        if (c + ship.getLength() < 10) {
            for (int i = 0; i < ship.getLength(); i++) {
                if (board.getCoordinate(r ,c+i) == '.') {
                    counter++;
                }
            }

            if (counter == ship.getLength()) {
                valid = true;
            }
            board.setShip(r, c, ship);
        }
    }
}

void User::print() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << board.getCoordinate(i,j) << " ";
        }
        std::cout << std::endl;
    }
}
