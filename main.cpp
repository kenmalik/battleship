#include <iostream>
#include "User.h"

int main() {
    std::srand(time(NULL));
    User user, user2;
    bool endGame = false;
    std::string winner;

    std::cout << "User 1's board\n\n";
    user.getBoard().print();
    std::cout << "\nUser 2's board\n\n";
    user2.getBoard().print();

    while (!endGame) {
        int x, y;
        std::cout << "\nUser 1\nPick a coordinate (format: 3 4 = (3, 4)): ";
        std::cin >> x >> y;

        char hitChar = user2.checkHit(x-1, y-1);
        user.getEmptyBoard().setCoordinate(x - 1, y - 1, hitChar);
        std::cout << "\nUser 2's board\n";
        user.getEmptyBoard().print();

        if (user2.isLoser()) {
            endGame = true;
            winner = "User 1 won!";
        }

        if (!endGame) {
            int x2, y2;
            std::cout << "User 2\nPick a coordinate (format: 3 4 = (3, 4)): ";
            std::cin >> x2 >> y2;

            char hitChar = user.checkHit(x-1, y-1);
            user2.getEmptyBoard().setCoordinate(x - 1, y - 1, hitChar);
            std::cout << "\nUser 1's board\n";
            user2.getEmptyBoard().print();

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
