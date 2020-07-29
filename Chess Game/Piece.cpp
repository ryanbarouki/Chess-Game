#include "Piece.hpp"
#include <iostream>

#define size 125
Piece::Piece(){
    pieceTexture.loadFromFile("/Users/ryanbarouki/Documents/Coding Projects/Chess Game/Chess Game/images/pieces_s.png");
    piece.setTexture(pieceTexture);
}

void Piece::Draw(sf::RenderWindow &window){
    window.draw(piece);
}

sf::Sprite Piece::GetShape(){
    return piece;
}

void Piece::Move(sf::Event event, sf::RenderWindow &window){
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
            sf::Vector2f p = piece.getPosition();
            //snaps to grid
            newPos = sf::Vector2f(size*int(p.x/size) + size/2, size*int(p.y/size) + size/2);
            piece.setPosition(newPos);
        }
    }
    //updates the position continuously when dragging a piece
    if(isMove) piece.setPosition(pos.x-dx,pos.y-dy);
}

