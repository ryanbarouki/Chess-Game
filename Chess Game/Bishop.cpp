#include "Bishop.hpp"
#define size 125

Bishop::Bishop(sf::Vector2f original_position, int rect_x, int rect_y, char clr): Piece(clr){

    piece.setPosition(original_position);
    piece.setTextureRect(sf::IntRect(rect_x*size,rect_y*size,size,size));
}
 
bool Bishop::canMoveTo(int row, int col, Board &board){
    bool valid = false;
    // validation code
    int col_final = int((piece.getPosition().x)/size);
    int row_final = int((piece.getPosition().y)/size);
    
    if(abs(col_final - col) == abs(row_final - row)){
        if(board.getPiece(row_final, col_final) == nullptr || board.getPiece(row_final,col_final)->getColour()!= getColour()){
            int col_min = std::min(col, col_final);
            int col_max = std::max(col, col_final);
            int row_min = std::min(row, row_final);
            int row_max = std::max(row, row_final);

            valid = true;
            if((row_final == row_max && col_final == col_max) || (row_final == row_min && col_final == col_min)){
                for (int c = col_min+1; c < col_max; c++){
                        int r = (c - col_min) + row_min;
                        if (board.getPiece(r, c) == nullptr){
                            valid = true;
                        } else {
                            valid = false;
                            break;
                    }
                }
            } else {
                for (int c = col_min+1; c < col_max; c++){
                        int r = (col_min - c) + row_max;
                        if (board.getPiece(r, c) == nullptr){
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
