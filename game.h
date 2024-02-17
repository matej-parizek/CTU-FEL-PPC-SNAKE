#ifndef SNAKESFML_GAME_H
#define SNAKESFML_GAME_H


#include "CMap.h"
#include "CSnake.h"

class Game {
    const int x=60;                 //// delka pro osu x
    const int y=40;                 //// delka pro osu y
    int applesCount=5;              //// pocet jakble pri startu hry
    CMap *map;                      //// mapa
    CSnake *snake;                  //// had
    CApple *apple;                  //// jablko
    const int size=20;              //// velikost ctverce
    const int hWindow=y*size;       //// pocet pixelu sloupce (vyska okna)
    const int wWindow=x*size;       //// pocet pixelu radku (sirka okna)
    int dir=1;                      //// zacatek pohybu hada
    bool moving();                  //// pohyb hada
public:
    Game();                         //// konstruktor
    int run();                      //// beh hry
    virtual ~Game();                //// destruktor
};


#endif //SNAKESFML_GAME_H
