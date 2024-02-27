#ifndef BATTLESHIP_SHIP_H
#define BATTLESHIP_SHIP_H


class Ship {
private:
    int length;
    char icon;
    bool isHorizontal;

public:
    Ship();
    Ship(int length, char icon, bool isHorizontal);
    int getLength();
    char getIcon();
    bool getIsHorizontal();

};


#endif //BATTLESHIP_SHIP_H
