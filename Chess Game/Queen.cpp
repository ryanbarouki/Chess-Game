#include "Queen.hpp"
#define size 125

Queen::Queen(sf::Vector2f original_position, int rect_x, int rect_y, char clr): Piece(clr){
    
    piece.setPosition(original_position);
    piece.setTextureRect(sf::IntRect(rect_x*size,rect_y*size,size,size));
}
 
