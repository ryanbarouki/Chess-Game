#pragma once
#include "Piece.hpp"

class Pawn: public Piece {
public:
    Pawn(sf::Vector2f original_position, int rect_x, int rect_y);
    
};
