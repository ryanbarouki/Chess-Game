#pragma once
#include <SFML/Graphics.hpp>
#include "Board.hpp"

class Piece {
public:
    //constructor
    Piece(char clr);
    
    void Draw(sf::RenderWindow &window);
    
    sf::Sprite GetShape();
    
    bool wouldMoveCauseCheck(int origrow, int origcol, int finalrow, int finalcol, Board board);
    
    char getColour();
    
    virtual bool canMoveTo(int row, int col, int row_final, int col_final, Board &board){
        return true;
    }
    
    sf::Sprite piece;
    
    std::string type;
protected:
    sf::Texture pieceTexture;
    int location[2];
    char colour;

};
