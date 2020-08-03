#include "Queen.hpp"
#define size 125

Queen::Queen(sf::Vector2f original_position, int rect_x, int rect_y, char clr): Piece(clr){
    
    piece.setPosition(original_position);
    piece.setTextureRect(sf::IntRect(rect_x*size,rect_y*size,size,size));
}
 
bool Queen::canMoveTo(int row, int col, Board &board){
    bool valid = false;
    // validation code here
    int col_final = int((piece.getPosition().x)/size);
    int row_final = int((piece.getPosition().y)/size);
    if ((col==col_final) || (row==row_final) || (abs(row-row_final)==abs(col-col_final))) {
        if (board.getPiece(row_final,col_final) == nullptr || board.getPiece(row_final,col_final)->getColour()!= getColour()) {
            int col_min = std::min(col, col_final);
            int col_max = std::max(col, col_final);
            int row_min = std::min(row, row_final);
            int row_max = std::max(row, row_final);
            if (row_final == row) {
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
                valid = true;
                for (int r = row_min+1; r < row_max; r++){
                    if (board.getPiece(r,col) == nullptr){
                        valid = true;
                    } else {
                        valid = false;
                        break;
                    }
                }
            } else {
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
    }
    return valid;
}
