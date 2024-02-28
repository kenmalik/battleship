#include <iostream>
#include "User.h"

int main() {
    std::srand(std::time(NULL));
    Board blankUser, blankUser2;
    User user, user2;
    bool endGame = false;
    std::string winner;

    std::cout << "User 1's board\n\n";
    blankUser.print();
    std::cout << "\nUser 2's board\n\n";
    blankUser2.print();

    do {
        int x, y;
        std::cout << "\nUser 1\nPick a coordinate (format: 3 4 = (3, 4)): ";
        std::cin >> x >> y;

<<<<<<< HEAD
        char hitIcon = user.launchMissile(x, y);
        blankUser2.setCoordinate(x, y, hitIcon);
        std::cout << "\nUser 2's board\n\n";
=======
        char hitIcon = user2.launchMissile(x-1, y-1);
        blankUser2.setCoordinate(x-1, y-1, hitIcon);
        std::cout << "User 2's board\n";
>>>>>>> 48691c83c13bb4bdb950aa2a45503b59c04a71c8
        blankUser2.print();

        if (user2.isLoser()) {
            endGame = true;
            winner = "User 1 won!";
        }

        if (!endGame) {
            int x2, y2;
            std::cout << "User 2\nPick a coordinate (format: 3 4 = (3, 4)): ";
            std::cin >> x2 >> y2;

            char hitIcon2 = user.launchMissile(x2-1, y2-1);
            blankUser.setCoordinate(x2-1, y2-1,hitIcon2);
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
