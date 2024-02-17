#include "CMap.h"

//// konstruktor vytvori hraci plochu o zadanych velikostech
CMap::CMap(int w, int h) {
    height=h; width=w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            CTile *buffer=new CTile(j,i);
            map.push_back(buffer);
        }
    }
}

//// vraci dlazdici hraci plochy
CTile& CMap::getTile(int x, int y) {
    return *map.at(x+y*width);
}

//// zabali velikost hraci desky do vektoru
std::vector<int> CMap::getHeightWidth() {
    std::vector<int> tmp;
    tmp.push_back(width); tmp.push_back(height);
    return tmp;
}

//// vraci hraci desky
std::vector<CTile*> &CMap::viewMap() {
    return map;
}

//// tisk do cmd kontrola
std::ostream &operator<<(std::ostream &out, const CMap &map){
    for (int i = 0; i < map.height ; ++i) {
        for (int j = 0; j < map.width; ++j) {
            out<<map.map.at(i*map.width+j)->state<<" ";
        }
        out <<std::endl;
    };
    return out;
}

