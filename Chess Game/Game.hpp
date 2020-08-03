#pragma once

#include <SFML/Graphics.hpp>
#include "Piece.hpp"
#include "Board.hpp"

class Game {
public:
    Game();
    
    void Loop();
    

    
private:
    //declare all pointers to pieces etc
    sf::RenderWindow* window;
    Board* board;
    int turn = 0;
    bool isMove = false;
    double dx = 0, dy = 0;
    sf::Vector2f newPos, oldPos;
    int I = -1;
    int J = -1;
    
};
