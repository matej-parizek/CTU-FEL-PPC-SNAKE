#include "CTile.h"

CTile::CTile(int i, int j) { x=i; y=j; state=tileState::EMPTY;} //// konstruktor dlazdice, uchovava stav SANKE/EMPTY/APPLE a pozice

int CTile::getX() {     //// vraci pozici x
    return this->x;
}

int CTile::getY() {     //// vraci pozici y
    return this->y;
}

bool operator==(CTile t1, CTile &t2) {      //// polymorfismus porovnava yda jsou ve dlazdici stejne
    return t1.getX()==t2.getX() && t1.getY()==t2.getY();
}

