#include "Piece.hpp"


Piece::Piece(sf::Vector2f original_position){
    piece.setPosition(original_position);
    pieceTexture.loadFromFile("/Users/ryanbarouki/Documents/Coding Projects/Chess Game/Chess Game/images/pieces.svg");

}

void Piece::Draw(sf::RenderWindow &window){
    window.draw(piece);
}

sf::RectangleShape Piece::GetShape(){
    return piece;
}
