#pragma once
#include <SFML/Graphics.hpp>

class Piece {
public:
    //constructor
    Piece();
    
    void Draw(sf::RenderWindow &window);
    
    sf::Sprite GetShape();

    void Move(sf::Event event, sf::RenderWindow &window);
    
protected:
    sf::Sprite piece;
    sf::Texture pieceTexture;
    
private:
    bool isMove = false;
    double dx = 0, dy = 0;
    sf::Vector2f oldPos, newPos;
};
