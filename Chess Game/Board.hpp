#pragma once

#include <SFML/Graphics.hpp>

class Board {
public:
    Board(sf::Vector2f size);
    
    void Draw(sf::RenderWindow &window);
    
    sf::RectangleShape GetShape();
    
private:
    sf::RectangleShape board;
    sf::Texture boardTexture;
    
};
