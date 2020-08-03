#include "Knight.hpp"
#define size 125

Knight::Knight(sf::Vector2f original_position, int rect_x, int rect_y, char clr): Piece(clr){
    piece.setPosition(original_position);
    piece.setTextureRect(sf::IntRect(rect_x*size,rect_y*size,size,size));
}
 
bool Knight::canMoveTo(int row, int col, Board &board){
    bool valid = false;
    // validation code
    int col_final = int((piece.getPosition().x)/size);
    int row_final = int((piece.getPosition().y)/size);
    if ((abs(row-row_final)==1 && abs(col-col_final)==2) || (abs(row-row_final)==2 && abs(col-col_final)==1)) {
        if(board.getPiece(row_final,col_final) == nullptr){
            valid = true;
        } else {
            if(board.getPiece(row_final,col_final)->getColour()!= getColour()){
                valid = true;
            }
        }
    }
    return valid;
}

