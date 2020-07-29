#include "King.hpp"

King::King(sf::Vector2f original_position, int rect_x, int rect_y){
    Piece();
    piece.setPosition(original_position);
    piece.setTextureRect(sf::IntRect(rect_x*180,rect_y*180,180,180));
}
 
