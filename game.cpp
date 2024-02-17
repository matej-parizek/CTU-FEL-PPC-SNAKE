#include "resultwindow.h"
#include "Game.h"
#include "CMap.h"
#include "CSnake.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include "CApple.h"

Game::Game() {
    map=new CMap(x,y);
    snake=new CSnake(*map);
    apple= new CApple(*map);
}

int Game::run() {
    srand((unsigned) time(NULL) );                                          //// Zapocet casu pro vypocet nahodneho cisla
    sf::RenderWindow window(sf::VideoMode(wWindow,hWindow),
                            "Snake");                                       //// Otevreni okna
    sf::Texture texture;                                                    //// Nacteni obrazku
    texture.loadFromFile("../Snake/Images/white1.png");

    sf::Sprite sprite(texture);                                             //// Zmena obrazku do formy pro vykresleni

    sf::Clock clock;                                                        //// Nastaveni casu
    float timer=0, delay=0.1;
    int countAP=1;                                                          //// Pocita kolik je jablek v poli
    while (window.isOpen()){                                                //// Loop pro hrani

        if(countAP<applesCount){
            if(snake->getScore()==100){delay=0.085; applesCount--;}         ////obtiznost
            if(snake->getScore()==200){delay=0.07;  applesCount--;}
            if(snake->getScore()==300){delay=0.06;  applesCount--;}
            if(snake->getScore()==400){delay=0.05;  applesCount--;}
        }

        for (int i = countAP; i < applesCount; ++i) {                       //// Generovani jablek
            apple->newApple();
        }
        countAP=0;                                                          //// vynulovani poctu

        float time = clock.getElapsedTime().asSeconds();                    //// Zacatek casu pro rendrovani
        clock.restart();                                                    //// restart hodin
        timer+=time;

        sf::Event e;                                                        //// Vyjimka pro zavreni okna
        while (window.pollEvent(e))                                         //// Zavreni okna
            if(e.type==sf::Event::Closed)
                window.close();

        if(dir==1) {                                                        //// Nacteni klaves a urceni smeru
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) dir = 1;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) dir = 3;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) dir = 4;
        }
        if(dir==2){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) dir = 2;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) dir = 3;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) dir = 4;
        }
        if(dir==3){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) dir = 2;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) dir = 3;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) dir = 1;
        }
        if(dir==4){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) dir = 2;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) dir = 4;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) dir = 1;
        }

        window.clear();                                                     //// vycisteni okna

        if(timer>delay){                                                    //// pohyb
            timer=0;
            if(!moving()){

                window.close();
                return snake->getScore();
            }
        }
        int coutEmpty=0;
        for (CTile *temp: map->viewMap()) {                                 //// vykresleni
            if(temp->state!=EMPTY) {                                        //// pokud to pole neni prazdne, vykresli obrazek
                sprite.setPosition(temp->getX() * size, temp->getY() * size);
                window.draw(sprite);
            }
            //// countAP -> slouzi pro kontrolu poctu jablek
            if(temp->state==APPLE) {
                countAP++;
            }
            //// kontroluje prazdne mista, kdyy neni prazdne misto hra konci
            if(temp->state==EMPTY)
                coutEmpty++;
        }
        //// ukonci hru, pokud had nabyva velikosti celeho pole
        if(coutEmpty==map->getHeightWidth().at(0)*map->getHeightWidth().at(1))
            return snake->getScore();
        window.display();
    }
    return 0;
}

Game::~Game() {     //// destruktor
    delete apple;
    delete snake;
    delete map;
}

bool Game::moving() {                               //// pohyb
    if(dir==1){
        int x=snake->getHead()->getX()-1;
        if(x<0)
            x=map->getHeightWidth().at(0)-1;
        int y=snake->getHead()->getY();
        if((*snake==map->getTile(x,y)))
            return false;
        snake->move(x,y);
    }
    if(dir==2){
        int x=snake->getHead()->getX()+1;
        if(x>map->getHeightWidth().at(0)-1)
            x=0;
        int y=snake->getHead()->getY();
        if((*snake==map->getTile(x,y)))
            return false;
        snake->move(x,y);
    }
    if(dir==3){
        int y=snake->getHead()->getY()-1;
        if(y<0)
            y=map->getHeightWidth().at(1)-1;
        int x= snake->getHead()->getX();
        if((*snake==map->getTile(x,y)))
            return false;
        snake->move(x,y);
    }
    if(dir==4){
        int y=snake->getHead()->getY()+1;
        if(y>map->getHeightWidth().at(1)-1)
            y=0;
        int x= snake->getHead()->getX();
        if((*snake==map->getTile(x,y)))
            return false;
        snake->move(x,y);
    }
    return true;
}
