#pragma once
#include "Piece.hpp"

class Pawn: public Piece {
public:
    Pawn(sf::Vector2f original_position, sf::Vector2f scale, int rect_x, int rect_y);
    
    void Move(sf::Event event, sf::RenderWindow &window);
    
private:
    bool isMove = false;
    double dx = 0, dy = 0;
    sf::Vector2f oldPos, newPos;
};
