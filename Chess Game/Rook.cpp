#include "Rook.hpp"
#define size 125

Rook::Rook(sf::Vector2f original_position, int rect_x, int rect_y, char clr): Piece(clr){
    piece.setPosition(original_position);
    piece.setTextureRect(sf::IntRect(rect_x*size,rect_y*size,size,size));
}

bool Rook::canMoveTo(int row, int col, Board &board){
    bool valid = false;
    // validation code here
    return valid;
}
