#include "Rook.hpp"
#define size 125

Rook::Rook(sf::Vector2f original_position, int rect_x, int rect_y, char clr): Piece(clr){
    piece.setPosition(original_position);
    piece.setTextureRect(sf::IntRect(rect_x*size,rect_y*size,size,size));
}

bool Rook::canMoveTo(int row, int col, Board &board){
    bool valid = false;
    // validation code
    int col_orig = int((piece.getPosition().x-(size/2))/size);
    int row_orig = int((piece.getPosition().y-(size/2))/size);
    if (row_orig==row or col_orig==col){
        if (board.getPiece(row,col)==nullptr or board.getPiece(row,col)->getColour()!= getColour()) {
            if (row_orig==row) {
                for (int c=col_orig; c<=col; c++){
                    if (board.getPiece(row,c)==nullptr){
                        valid = true;
                    } else {
                        valid = false;
                        break;
                    }
                }
            } else if (col_orig==col) {
                for (int r=row_orig; r<=row; r++){
                    if (board.getPiece(r,col)==nullptr){
                        valid = true;
                    } else {
                        valid = false;
                        break;
                    }
                }
            }
        }
    }
    return valid;
}
