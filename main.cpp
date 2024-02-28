#include <iostream>
#include "User.h"

bool promptUser(bool, User*, User*);

int main() {
    std::srand(time(NULL));
    User user, user2;
    bool endGame = false;
    std::string winner;

    Ship debugShip(1, 'o', true);
    user.getBoard().setShip(0, 0, debugShip);
    user2.getBoard().setShip(0, 2, debugShip);
    std::cout << "User 1's board\n\n" << user.getBoard();
    std::cout << "\nUser 2's board\n\n" << user2.getBoard();

    bool player1Turn = true;
    while (!endGame) {
        endGame = promptUser(player1Turn, &user, &user2);
        player1Turn = !player1Turn;
    } 

    if (player1Turn) {
        winner = "Player 2 won!";
    } else {
        winner = "Player 1 won!";
    }
    std::cout << "\n================================\n\n" 
        << winner << std::endl;

    return 0;
}

bool promptUser(bool player1Turn, User* player1, User* player2) {
    std::string playerLabel;
    User* currentPlayer;
    User* enemyPlayer;

    if (player1Turn) {
        playerLabel = "Player 1";
        currentPlayer = player1;
        enemyPlayer = player2;
    } else {
        playerLabel = "Player 2";
        currentPlayer = player2;
        enemyPlayer = player1;
    }

    int x, y;
    std::cout << "\n================================\n\n" 
        << playerLabel << "'s turn\n" 
        << "Pick a coordinate (format: 3 4 = (3, 4)): ";
    std::cin >> x >> y;

    char hitChar = enemyPlayer->checkHit(x-1, y-1);
    currentPlayer->getEmptyBoard().setCoordinate(x - 1, y - 1, hitChar);
    std::cout << "\nYour hits\n" << currentPlayer ->getEmptyBoard();

    if (enemyPlayer->getBoard().isGameOver()) {
        return true;
    }
    return false;
}
