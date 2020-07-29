#include "Pawn.hpp"
#include <iostream>

Pawn::Pawn(sf::Vector2f original_position,sf::Vector2f scale, int rect_x, int rect_y){
    //piece.setSize(sf::Vector2f(777.0f,250.0f));
    piece.setScale(scale);
    piece.setPosition(original_position);
    pieceTexture.loadFromFile("/Users/ryanbarouki/Documents/Coding Projects/Chess Game/Chess Game/images/pieces.png");
    piece.setTexture(pieceTexture);
    piece.setTextureRect(sf::IntRect(rect_x*180,rect_y*180,180,180));
}
 
void Pawn::Move(sf::Event event, sf::RenderWindow &window){
    
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    //std::cout << pos.x << " " << pos.y << "\n";
    
    if (event.type == sf::Event::MouseButtonPressed) {
        
        if (event.key.code == sf::Mouse::Left){
            for(int i = 0; i < 16; i++) {
                if (piece.getGlobalBounds().contains(pos.x,pos.y)){
                    isMove = true;
                    dx = pos.x - piece.getPosition().x;
                    dy = pos.y - piece.getPosition().y;
                    //oldPos = piece.getPosition();
                    //piece.setPosition(pos.x-dx,pos.y-dy);
                    
                }
            }
        }
    }
    if (event.type == sf::Event::MouseButtonReleased){
        if (event.key.code == sf::Mouse::Left) {
            isMove = false;
            sf::Vector2f p = piece.getPosition() + sf::Vector2f(180/2,180/2);
            newPos = sf::Vector2f(180*int(p.x/180), 180*int(p.y/180));
            //piece.setPosition(pos.x-dx,pos.y-dy);
        }
    }
    if(isMove) piece.setPosition(pos.x-dx,pos.y-dy);
}
