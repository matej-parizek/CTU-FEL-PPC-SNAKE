#ifndef SNAKESFML_CSNAKE_H
#define SNAKESFML_CSNAKE_H


#include <vector>
#include "CApple.h"
#include "CTile.h"
#include "CMap.h"

//Snake 75, 60 white2.png
class CSnake {
    CMap *map;                                  //// mapa
    std::vector<CTile*> body;                   //// telo snake

public:
                                                //// construktor @param1 - zacatecni pozic
    explicit CSnake(CMap &map);                 //// @param2 - map s ostatnimi pozicemi pro telo snake     //// ziskat data z predni pozice snake
    int sizeBody=3;                             //// velikost snake pri snezeni jablka vzorste
    int score=0;                                //// skore  //// naraz do sebe sama
    void move(int x, int y );                   //// posun snake
    CTile *getHead();                           //// dlazdice, kde ma had hlavu (body.endl())
    int getScore();                             //// skore
};
bool operator ==(CSnake &snake,CTile & apple);          //// Snake sni jablko


#endif //SNAKESFML_CSNAKE_H
