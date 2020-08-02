#include "Piece.hpp"
#include <iostream>
#include "Pawn.hpp"
#define size 125
Piece::Piece(char clr){
    pieceTexture.loadFromFile("images/pieces_s.png");
    piece.setTexture(pieceTexture);
    colour = clr;
}

void Piece::Draw(sf::RenderWindow &window){
    window.draw(piece);
}

sf::Sprite Piece::GetShape(){
    return piece;
}

char Piece::getColour(){
    return colour;
}
