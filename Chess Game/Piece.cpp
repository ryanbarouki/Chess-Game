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

bool Piece::wouldMoveCauseCheck(int finalrow, int finalcol, Board &board){
    bool causesCheck = false;
    //check if any piece of the opposite colour can move to the square of the king.
    return causesCheck;
}
