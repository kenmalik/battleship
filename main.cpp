#include <iostream>
#include "User.h"

int main() {
    std::srand(std::time(0));
    Board blankUser, blankUser2;
    User user, user2;
    bool endGame = false;
    std::string winner;

    blankUser.setShip(1, 1, Ship(5,'o', false));

    std::cout << "User 1's board\n";
    blankUser.print();
    std::cout << "\nUser 2's board\n";
    blankUser2.print();

    do {
        int x, y;
        std::cout << "\nUser 1\nPick a coordinate (format: 3 4 = (3, 4)): ";
        std::cin >> x >> y;

        char hitIcon = user.launchMissile(x, y);
        blankUser2.setCoordinate(x, y, hitIcon);
        std::cout << "User 2's board\n";
        blankUser2.print();

        if (user2.isLoser()) {
            endGame = true;
            winner = "User 1 won!";
        }

        if (!endGame) {
            int x2, y2;
            std::cout << "User 2\nPick a coordinate (format: 3 4 = (3, 4)): ";
            std::cin >> x2 >> y2;

            char hitIcon2 = user2.launchMissile(x2, y2);
            blankUser.setCoordinate(x, y, hitIcon2);
            std::cout << "User 1's board\n";
            blankUser.print();

            if (user.isLoser()) {
                endGame = true;
                winner = "User 2 won!";
            }
        }
    } while (!endGame);
    std::cout << winner;

    return 0;
}
