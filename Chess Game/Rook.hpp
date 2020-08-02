#pragma once
#include "Piece.hpp"

class Rook: public Piece {
public:
    Rook(sf::Vector2f original_position, int rect_x, int rect_y, char clr);
    
    bool canMoveTo(int row, int col, Board &board);
};
