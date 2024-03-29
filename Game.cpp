#include "Game.h"
#include "User.h"
#include <tuple>

/**
 * Starts the game.
 */
void Game::play() {
  std::srand(time(0));
  User user, user2;
  bool endGame = false;

  Game::setRandomShips(user);
  Game::setRandomShips(user2);
  std::cout << "Player 1's board\n\n" << user.getBoard();
  std::cout << "\nPlayer 2's board\n\n" << user2.getBoard();

  if (!Game::inputToStart()) {
    return;
  }

  bool player1Turn = true;
  while (!endGame) {
    endGame = promptAction(player1Turn, &user, &user2);
    player1Turn = !player1Turn;
  }

  Game::announceWinner(player1Turn);
}

/**
 * Prompts a user with an action.
 *
 * @param player1Turn Whether it is player 1's turn.
 * @param *player1 User pointer to player 1.
 * @param *player2 User pointer to player 2.
 * @return Boolean whether the game is over.
 */
bool Game::promptAction(bool player1Turn, User *player1, User *player2) {
  std::string playerLabel;
  User *currentPlayer;
  User *enemyPlayer;

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
            << playerLabel << "'s turn\n"
            << "\nYour hits\n"
            << currentPlayer->getEmptyBoard() << "\nYour board\n"
            << currentPlayer->getBoard() << std::endl;

  auto [x, y] = getCoordinateInput(*currentPlayer);

  std::string hitMessage;
  char hitChar = enemyPlayer->checkHit(x - 1, y - 1);
  if (hitChar == 'X') {
    hitMessage = "Hit!";
  } else {
    hitMessage = "Miss";
  }
  currentPlayer->getEmptyBoard().setCoordinate(x - 1, y - 1, hitChar);
  std::cout << "\n" << hitMessage << "\n" << currentPlayer->getEmptyBoard();

  if (enemyPlayer->getBoard().isGameOver()) {
    return true;
  }
  return false;
}

/**
 * Gets a valid coordinate input (it must exist on the board and cannot have
 * been previously selected).
 *
 * @param &currentPlayer User reference to the player whose turn it is.
 * @return The inputted coordinates.
 */
std::tuple<int, int> Game::getCoordinateInput(User &currentPlayer) {
  int x, y;
  bool validInput = false;
  while (!validInput) {
    std::cout << "Pick a coordinate (format: 3 4 = (3, 4)): ";
    std::cin >> x >> y;
    validInput =
        (x <= 10 && x >= 1 && y <= 10 && y >= 1) &&
        (currentPlayer.getEmptyBoard().getCoordinate(x - 1, y - 1) == '.');
    if (!validInput) {
      std::cout << "Invalid selection\n";
    }
  }
  return std::tuple<int, int>(x, y);
}

/**
 * Randomly places ships on a user's board.
 *
 * @param &player User reference to the player whose board the ships will be
 * set on.
 */
void Game::setRandomShips(User &player) {
  constexpr int kMaxShips = 5;
  constexpr int kMaxShipSize = 6;
  const size_t kBoardSize = player.getBoard().getBoard().size();
  int n = 0;
  int shipSize = 1;

  while (n < kMaxShips && shipSize < kMaxShipSize) {
    int x(rand() % kBoardSize);
    int y(rand() % kBoardSize);
    bool horizontal(rand() % 2);

    if ((horizontal && x + shipSize > kBoardSize) ||
        (!horizontal && y + shipSize > kBoardSize)) {
      continue;
    }

    if (player.getBoard().getCoordinate(x, y) != 'o') {
      player.getBoard().setShip(x, y, Ship(shipSize, 'o', horizontal));
      n++;
      shipSize++;
    }
  }
}

/**
 * Gets initial input to start game.
 */
bool Game::inputToStart() {
  std::cout << "\nInput a character to start (q to quit): ";
  std::string input;
  std::getline(std::cin, input);

  if (input == "q" || input == "Q") {
    return false;
  }
  return true;
}

/**
 * Announces the winner of the game.
 *
 * @param player1Turn Boolean whether the game ended on player 1's turn.
 */
void Game::announceWinner(bool player1Turn) {
  std::string winner;
  if (player1Turn) {
    winner = "Player 2 won!";
  } else {
    winner = "Player 1 won!";
  }
  std::cout << "\n================================\n\n" << winner << std::endl;
}
