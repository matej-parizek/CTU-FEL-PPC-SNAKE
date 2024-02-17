#include "CSnake.h"
#include "CMap.h"

//// konstruktor vytvori zacatecni pozice
CSnake::CSnake(CMap &m) {
    map=&m;
    int x=m.getHeightWidth().at(0)/2; int y=m.getHeightWidth().at(1)/2;
    /*Vytori zacatecni telo o velikosti 3(v nasem pripade)*/
    for (int i = 0; i < sizeBody; ++i) {
        m.getTile(x-i,y).state=(tileState::SNAKE);
        body.push_back(&m.getTile(x-i,y));
    }
}

//// vraci hlavu (prvni kosticku hada)
CTile * CSnake::getHead(){
    return body.at(body.size()-1);
}

//// pohyb hada
void CSnake::move(int x, int y) {
    map->getTile(x,y).state=tileState::SNAKE;               //// nastaveni nove dlazdice
    body.push_back(&map->getTile(x,y));                     //// pridani dlazdice do tela hada
    if(sizeBody<body.size()){  body.at(0)->state=EMPTY;body.erase(body.begin());}       //// kontrola max poctu prvku v hadovy
}                                                                                       //// a pripadne odstaneni prvniho pridaneho prvku (FIFO)

//// skore
int CSnake::getScore() {
    return score;
}

//// kontrola kam se posune had a pripadne zvysi pocet kosticek v tele
bool operator ==(CSnake &snake,CTile &apple){     //// jednoduchy polymorfismus
    if(apple.state==APPLE){                       //// pokud je na dlazdici na kterou jsme vstoupili jablko -> pricte skore a zvysi telo o jedno
        snake.sizeBody++; snake.score+=10;
        return false;                             //// odejde z funkce
    } else if(apple.state==EMPTY) return false;   //// neprovede zadanou akci odejde z funkce
    return true;                                  //// pokud vrati true, tak had narazil do sebe
}
