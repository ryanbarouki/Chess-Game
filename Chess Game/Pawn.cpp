#include "Pawn.hpp"
#include <iostream>
#define size 125

Pawn::Pawn(sf::Vector2f original_position, int rect_x, int rect_y){
    //piece.setSize(sf::Vector2f(777.0f,250.0f));
    piece.setPosition(original_position);
    pieceTexture.loadFromFile("/Users/ryanbarouki/Documents/Coding Projects/Chess Game/Chess Game/images/pieces_s.png");
    piece.setTexture(pieceTexture);
    piece.setTextureRect(sf::IntRect(rect_x*size,rect_y*size,size,size));
}
 
