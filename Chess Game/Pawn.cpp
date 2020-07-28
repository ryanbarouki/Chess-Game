#include "Pawn.hpp"

Pawn::Pawn(sf::Vector2f original_position,sf::Vector2f scale, int rect_x, int rect_y){
    //piece.setSize(sf::Vector2f(777.0f,250.0f));
    piece.setScale(scale);
    piece.setPosition(original_position);
    pieceTexture.loadFromFile("/Users/ryanbarouki/Documents/Coding Projects/Chess Game/Chess Game/images/pieces.png");
    piece.setTexture(pieceTexture);
    piece.setTextureRect(sf::IntRect(rect_x*180,rect_y*180,180,180));
}
 
void Pawn::Move(sf::Event event, sf::RenderWindow &window){
    
    bool isMove = false;
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    if (event.key.code == sf::Mouse::Left){
        for(int i = 0; i < 16; i++) {
            if (piece.getGlobalBounds().contains(pos.x,pos.y)){
                isMove = true;
                
                
            }
        }
    }
}
