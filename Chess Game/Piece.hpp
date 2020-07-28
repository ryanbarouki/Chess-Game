#pragma once
#include <SFML/Graphics.hpp>

class Piece {
public:
    //constructor
    Piece(sf::Vector2f original_position);
    
    void Draw(sf::RenderWindow &window);
    
    sf::RectangleShape GetShape();
    
private:
    sf::RectangleShape piece;
    sf::Texture pieceTexture;
};
