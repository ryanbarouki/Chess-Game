#include "Pawn.hpp"
#include <iostream>
#define size 125

Pawn::Pawn(sf::Vector2f original_position, int rect_x, int rect_y, char clr): Piece(clr){

    piece.setPosition(original_position);
    piece.setTextureRect(sf::IntRect(rect_x*size,rect_y*size,size,size));
    
}

bool Pawn::canMoveTo(int row, int col, Board &board){
    bool valid = false;
    int col_final = int((piece.getPosition().x)/size);
    int row_final = int((piece.getPosition().y)/size);
    
    // validation code here
    if(getColour() == 'w'){
        if(col_final == col && board.getPiece(row_final, col_final) == nullptr){
            if(row_final - row == -2 && row == 6) valid = true; // first move
            else if(row_final - row == -1) valid = true;
        } else if (abs(col_final - col) == 1 && row_final - row == -1) {
            if (board.getPiece(row_final, col_final) != nullptr) valid = true;
        }
        
    } else if (getColour() == 'b'){
        if (col_final == col && board.getPiece(row_final, col_final) == nullptr) {
            if(row_final - row == 2 && row == 1) valid = true; // first move
            else if(row_final - row == 1 ) valid = true;
        } else if (abs(col_final - col) == 1 && row_final - row == 1) {
            if (board.getPiece(row_final, col_final) != nullptr) valid = true;
        }
    }
    
    return valid;
}


 
