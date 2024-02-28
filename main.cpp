#include <iostream>
#include "User.h"

void promptUser(bool, User*, User*);

int main() {
    std::srand(time(NULL));
    User user, user2;
    bool endGame = false;
    std::string winner;

    Ship debugShip(5, 'o', true);
    user.getBoard().setShip(0, 0, debugShip);
    user2.getBoard().setShip(0, 2, debugShip);
    std::cout << "User 1's board\n\n";
    user.getBoard().print();
    std::cout << "\nUser 2's board\n\n";
    user2.getBoard().print();

    bool player1Turn = true;
    while (!endGame) {
        promptUser(player1Turn, &user, &user2);
        player1Turn = !player1Turn;

        if (user2.isLoser()) {
            endGame = true;
            winner = "User 1 won!";
        }

        if (!endGame) {
            promptUser(player1Turn, &user, &user2);
            player1Turn = !player1Turn;

            if (user.isLoser()) {
                endGame = true;
                winner = "User 2 won!";
            }
        }
    } 
    std::cout << std::endl << winner << std::endl;

    return 0;
}

void promptUser(bool player1Turn, User* player1, User* player2) {
    std::string player;
    User* currentPlayer;
    User* enemyPlayer;

    if (player1Turn) {
        player = "User 1";
        currentPlayer = player1;
        enemyPlayer = player2;
    } else {
        player = "User 2";
        currentPlayer = player2;
        enemyPlayer = player1;
    }

    int x, y;
    std::cout << "\n" << player << "\nPick a coordinate (format: 3 4 = (3, 4)): ";
    std::cin >> x >> y;

    char hitChar = enemyPlayer->checkHit(x-1, y-1);
    currentPlayer->getEmptyBoard().setCoordinate(x - 1, y - 1, hitChar);
    std::cout << "\nUser 2's board\n";
    currentPlayer->getEmptyBoard().print();
}
