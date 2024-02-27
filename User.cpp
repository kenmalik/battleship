#include "User.h"

User::User(){

}

char User::launchMissile(int x, int y) {
    if (board.getCoordinate(x, y) == '-') {
        board.setCoordinate(x, y, 'x');
        return 'x';
    } else {
        board.setCoordinate(x,y, 'o');
        return '-';
    }
}
bool User::isLoser() {


}