#pragma once
#include <SFML/Graphics.hpp>
#include "Board.hpp"

class Piece {
public:
    //constructor
    Piece(char clr);
    
    void Draw(sf::RenderWindow &window);
    
    sf::Sprite GetShape();
    
    bool wouldMoveCauseCheck(int finalrow, int finalcol, Board &board);
    
    char getColour();
    
    virtual bool canMoveTo(int row, int col, Board &board){
        return true;
    }
    
    sf::Sprite piece;
    
protected:
    sf::Texture pieceTexture;
    int location[2];
    char colour;

};
