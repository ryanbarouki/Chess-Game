#include "Rook.hpp"
#define size 125

Rook::Rook(sf::Vector2f original_position, int rect_x, int rect_y, char clr): Piece(clr){
    piece.setPosition(original_position);
    piece.setTextureRect(sf::IntRect(rect_x*size,rect_y*size,size,size));
    type = "rook";
}

bool Rook::canMoveTo(int row, int col, int row_final, int col_final, Board &board){
    bool valid = false;
    // validation code
    
    if (row_final == row or col_final == col){
        if (board.getPiece(row_final,col_final) == nullptr || board.getPiece(row_final,col_final)->getColour()!= getColour()) {
            if (row_final == row) {
                int col_min = std::min(col, col_final);
                int col_max = std::max(col, col_final);
                valid = true;
                for (int c = col_min+1; c < col_max; c++){
                    if (board.getPiece(row,c) == nullptr){
                        valid = true;
                    } else {
                        valid = false;
                        break;
                    }
                }
            } else if (col_final == col) {
                int row_min = std::min(row, row_final);
                int row_max = std::max(row, row_final);
                valid = true;
                for (int r = row_min+1; r < row_max; r++){
                    if (board.getPiece(r,col) == nullptr){
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
