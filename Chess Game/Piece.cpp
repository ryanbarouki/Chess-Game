#include "Piece.hpp"


Piece::Piece(){

}

void Piece::Draw(sf::RenderWindow &window){
    window.draw(piece);
}

sf::RectangleShape Piece::GetShape(){
    return piece;
}
