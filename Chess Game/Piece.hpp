#pragma once
#include <SFML/Graphics.hpp>
#include "Board.hpp"

class Piece {
public:
    //constructor
    Piece(char clr);
    
    void Draw(sf::RenderWindow &window);
    
    sf::Sprite GetShape();

    void Move(sf::Event event, sf::RenderWindow &window);
    
    bool wouldMoveCauseCheck(int finalrow, int finalcol, Board board);
    
    char getColour();
    
protected:
    sf::Sprite piece;
    sf::Texture pieceTexture;
    int location[2];
    char colour;
    
private:
    bool isMove = false;
    double dx = 0, dy = 0;
    sf::Vector2f oldPos, newPos;
};
