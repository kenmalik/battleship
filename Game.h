#include "User.h"

class Game {
    public:
        static bool promptAction(bool, User*, User*);
        static void setRandomShips(User&);
        static void play();
};

