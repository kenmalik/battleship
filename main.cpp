#include <iostream>
#include "User.h"

int main() {
    std::srand(time(NULL));
    Board blankUser, blankUser2;
    User user, user2;
    bool endGame = false;
    std::string winner;

    std::cout << "User 1's board\n\n";
    blankUser.print();
    std::cout << "\nUser 2's board\n\n";
    blankUser2.print();


    while (!endGame) {
        int x, y;
        std::cout << "\nUser 1\nPick a coordinate (format: 3 4 = (3, 4)): ";
        std::cin >> x >> y;

        char hitIcon = user2.checkHit(x-1, y-1);
        blankUser2.setCoordinate(x-1, y-1, hitIcon);
        std::cout << "\nUser 2's board\n";
        blankUser2.print();

        if (user2.isLoser()) {
            endGame = true;
            winner = "User 1 won!";
        }

        if (!endGame) {
            int x2, y2;
            std::cout << "User 2\nPick a coordinate (format: 3 4 = (3, 4)): ";
            std::cin >> x2 >> y2;

            char hitIcon2 = user.checkHit(x2-1, y2-1);
            blankUser.setCoordinate(x2-1, y2-1,hitIcon2);
            std::cout << "\nUser 1's board\n";
            blankUser.print();

            if (user.isLoser()) {
                endGame = true;
                winner = "User 2 won!";
            }
        }
    } 
    std::cout << std::endl << winner << std::endl;

    return 0;
}

void promptUser(bool player1Turn, User& player1, User& player2) {

}
