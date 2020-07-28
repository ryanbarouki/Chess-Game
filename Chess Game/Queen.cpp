#include "Queen.hpp"

Queen::Queen(sf::Vector2f original_position,sf::Vector2f scale, int rect_x, int rect_y){
    //piece.setSize(sf::Vector2f(777.0f,250.0f));
    piece.setScale(scale);
    piece.setPosition(original_position);
    pieceTexture.loadFromFile("/Users/ryanbarouki/Documents/Coding Projects/Chess Game/Chess Game/images/pieces.png");
    piece.setTexture(pieceTexture);
    piece.setTextureRect(sf::IntRect(rect_x*180,rect_y*180,180,180));
}
 
void Queen::Move(sf::Event event){
    
}
