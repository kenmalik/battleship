#ifndef GAME_H
#define GAME_H

#include "User.h"

class Game {
public:
  static bool promptAction(bool, User *, User *);
  static void setRandomShips(User &);
  static void play();
  static bool inputToStart();
  static void announceWinner(bool);
  static std::tuple<int, int> getCoordinateInput(User &);
};

#endif
