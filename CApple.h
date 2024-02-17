#ifndef SNAKESFML_CAPPLE_H
#define SNAKESFML_CAPPLE_H


#include "CTile.h"
#include "CMap.h"

class CApple {
    CMap *m;                                                //// mapa
    int x; int y;                                           //// souradnice
    bool control();                                         //// kontrola, jestli je pole prazdne
public:
    explicit CApple(CMap & map);                            //// construktor
    void newApple();
};
#endif //SNAKESFML_CAPPLE_H
