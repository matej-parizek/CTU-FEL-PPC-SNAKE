#ifndef SNAKESFML_CMAP_H
#define SNAKESFML_CMAP_H


#include <vector>
#include "CTile.h"
#include <iostream>

class CMap {
    std::vector<CTile*> map;                        //// dlazdice hraci plochy
    int height; int width;                          //// velikost hraci plochy
public:
    CMap(int w, int h);                             //// vytvoreni hraci plochy
    CTile &getTile(int x, int y);                   //// vybrat danou plochu
    std::vector<int> getHeightWidth();              //// vector s hodnotami velikosti hraci plochy
    std::vector<CTile*> & viewMap();                //// vraci všechny dlaždíce mapy
    friend std::ostream & operator << (std::ostream &out, const CMap &map);     //// vypise mapu do prikazove radky
};


#endif //SNAKESFML_CMAP_H
