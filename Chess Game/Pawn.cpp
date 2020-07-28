#include "Pawn.hpp"

Pawn::Pawn(sf::Vector2f original_position){
    piece.setSize(sf::Vector2f(777.0f,250.0f));
    piece.setPosition(original_position);
    pieceTexture.loadFromFile("/Users/ryanbarouki/Documents/Coding Projects/Chess Game/Chess Game/images/pieces.png");
    piece.setTexture(&pieceTexture);
}
 
