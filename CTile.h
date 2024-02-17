#ifndef SNAKESFML_CTILE_H
#define SNAKESFML_CTILE_H

//// Stav jaky muzou nabyvat dlazdice(pixely) hraci plochy


//// Dlazdice hraci plochy

enum tileState{EMPTY,SNAKE,APPLE};
class CTile {
    int x,y;                                                            //// souradnice
public:
    CTile(int i, int j);                                                //// constructor
    int getX();                                                         //// vraci hodnotu x
    int getY();                                                         //// vraci hodnotu y
    tileState state;                                                    //// stav Snake/APPLE/EMPTY
};
bool operator==(CTile t1, CTile &t2);                                   //// stejne pozice

#endif //SNAKESFML_CTILE_H
