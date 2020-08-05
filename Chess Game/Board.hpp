#pragma once

#include <SFML/Graphics.hpp>


class Piece; // forward declaration of Piece before knowing the details (need to use pointers below because of this)

class Board {
public:
    Board(sf::Vector2f dim);
    
    void Draw(sf::RenderWindow &window);
    
    sf::RectangleShape GetShape();
    
    Piece pieceAt(int row, int col); // returns the chess piece at that position
    
    Piece* getPiece(int row, int col);
    
    void addPiece(Piece *piece, int row, int col);
    
    void updateBoard(int old_row, int old_col, int new_row, int new_col);
    
    sf::Vector2i white_king_position = {7,4};
    sf::Vector2i black_king_position = {0,4};
private:
    
    sf::RectangleShape board;
    sf::Texture boardTexture;
    Piece *board_array[8][8] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    // this will store an array of pieces i.e. the actual chess board
    
};
