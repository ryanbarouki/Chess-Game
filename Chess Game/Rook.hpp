#pragma once
#include "Piece.hpp"

class Rook: public Piece {
public:
    Rook(sf::Vector2f original_position, sf::Vector2f scale, int rect_x, int rect_y);
    
    void Move(sf::Event event);
};
