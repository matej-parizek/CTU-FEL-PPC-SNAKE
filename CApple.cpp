#include "CApple.h"

//// konstruktor
CApple::CApple(CMap &map) {
    m=&map;
    this->newApple();
}

//// kontrola zda je deska praydna nebo ne
bool CApple::control() {
    if(m->getTile(x,y).state!=EMPTY)
            return false;                                 //// false = zabrana
    return true;                                          //// true = prazdna
}

//// generovani nove pozice jablka
void CApple::newApple() {
    x=rand()%m->getHeightWidth().at(0);                   ////Generovani random x hodnoty
    y=rand()%m->getHeightWidth().at(1);                   ////Generovani random y hodnoty
    while (!control())                                    ////Controluje zda se jablko objevi na prazdnem koli
    { x=rand()%m->getHeightWidth().at(0); y=rand()%m->getHeightWidth().at(1);}
    m->getTile(x,y).state=APPLE;
}

