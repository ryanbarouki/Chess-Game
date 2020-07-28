#pragma once
#include "Piece.hpp"

class Queen: public Piece {
public:
    Queen(sf::Vector2f original_position, sf::Vector2f scale, int rect_x, int rect_y);
    
    void Move(sf::Event event);
};
