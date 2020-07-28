#pragma once
#include <SFML/Graphics.hpp>

class Piece {
public:
    //constructor
    Piece();
    
    void Draw(sf::RenderWindow &window);
    
    sf::RectangleShape GetShape();
    
protected:
    sf::RectangleShape piece;
    sf::Texture pieceTexture;
};
