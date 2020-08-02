#include "Knight.hpp"
#define size 125

Knight::Knight(sf::Vector2f original_position, int rect_x, int rect_y, char clr): Piece(clr){
    piece.setPosition(original_position);
    piece.setTextureRect(sf::IntRect(rect_x*size,rect_y*size,size,size));
}
 
bool Knight::canMoveTo(int row, int col, Board &board){
    bool valid = false;
    // validation code
    int col_orig = int((piece.getPosition().x-(size/2))/size);
    int row_orig = int((piece.getPosition().y-(size/2))/size);
    if (abs(row-row_orig)==1 && abs(col-col_orig)==2 && board.getPiece(row,col)==nullptr) {
        valid = true;
    } else if (abs(row-row_orig)==2 && abs(col-col_orig)==1 && board.getPiece(row,col)==nullptr) {
        valid = true;
    } else if (abs(row-row_orig)==1 && abs(col-col_orig)==2 && board.getPiece(row,col)!=nullptr) {
        if (board.getPiece(row,col)->getColour()!= getColour()) {
            valid = true;
        }
    }
    return valid;
}

