#pragma once

#include <SFML/Graphics.hpp>


class Piece; // forward declaration of Piece before knowing the details (need to use pointers below because of this)

class Board {
public:
    Board(sf::Vector2f dim);
    
    void Draw(sf::RenderWindow &window);
    
    sf::RectangleShape GetShape();
    
    Piece pieceAt(int row, int col); // returns the chess piece at that position
    
    void addPiece(Piece *piece); // adds a piece to the board
    
    void removePiece(int row, int col); // removes a piece from the board
    
    Piece *board_array[8][8]; // this will store an array of pieces i.e. the actual chess board
private:
    
    sf::RectangleShape board;
    sf::Texture boardTexture;
    
};
