#include <iostream>
#include "User.h"

bool promptAction(bool, User*, User*);
void setRandomShips(User&);

int main() {
    srand(time(NULL));
    User user, user2;
    bool endGame = false;

    setRandomShips(user);
    setRandomShips(user2);

    std::cout << "User 1's board\n\n" << user.getBoard();
    std::cout << "\nUser 2's board\n\n" << user2.getBoard();

    bool player1Turn = true;
    while (!endGame) {
        endGame = promptAction(player1Turn, &user, &user2);
        player1Turn = !player1Turn;
    } 

    std::string winner;
    if (player1Turn) {
        winner = "Player 2 won!";
    } else {
        winner = "Player 1 won!";
    }
    std::cout << "\n================================\n\n" 
        << winner << std::endl;

    return 0;
}

bool promptAction(bool player1Turn, User* player1, User* player2) {
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

    std::cout << "\n================================\n\n" 
        << playerLabel << "'s turn\n";

    int x, y;
    bool validInput = false;
    while (!validInput) {
        std::cout << "Pick a coordinate (format: 3 4 = (3, 4)): ";
        std::cin >> x >> y;
        validInput = (x <= 10 && x >= 1 && y <= 10 && y >= 1)
            && (currentPlayer->getEmptyBoard().getCoordinate(x - 1, y - 1) == '.');
        if (!validInput) {
            std::cout << "Invalid selection\n";
        }
    }

    char hitChar = enemyPlayer->checkHit(x - 1, y - 1);
    currentPlayer->getEmptyBoard().setCoordinate(x - 1, y - 1, hitChar);
    std::cout << "\nYour hits\n" << currentPlayer ->getEmptyBoard();

    if (enemyPlayer->getBoard().isGameOver()) {
        return true;
    }
    return false;
}

void setRandomShips(User& player) {
    int n = 0, maxShips = 5, shipSize = 1;

    while (n < maxShips && shipSize < 6)
    {
        int x(rand() % 10); //randomizing x and y coordinates
        int y(rand() % 10);

        if (x + shipSize > 10 || y + shipSize > 10) {
            continue;
        }

        int horOrVert(rand() % 2);
        if (player.getBoard().getCoordinate(x, y) != 'o') { //if the space doesn't have a ship piece
            player.getBoard().setShip(x, y, Ship(shipSize, 'o', horOrVert));
            n++;
            shipSize++;
        }
    }

}
