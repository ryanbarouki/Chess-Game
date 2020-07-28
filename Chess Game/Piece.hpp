#pragma once
#include <SFML/Graphics.hpp>

class Piece {
public:
    //constructor
    Piece();
    
    void Draw(sf::RenderWindow &window);
    
    sf::Sprite GetShape();

    
protected:
    sf::Sprite piece;
    sf::Texture pieceTexture;
};
