#pragma once
#include "Piece.hpp"

class Bishop: public Piece {
public:
    Bishop(sf::Vector2f original_position, int rect_x, int rect_y, char clr);
    
    bool canMoveTo(int row, int col, int row_final, int col_final, Board &board);

};
