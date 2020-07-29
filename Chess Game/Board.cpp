#include "Board.hpp"

Board::Board(sf::Vector2f size){
    board.setSize(size);
    board.setPosition(0.0f, 0.0f);
    boardTexture.loadFromFile("images/board2.png");
    // set the image as the texture of board by reference
    board.setTexture(&boardTexture);
}

void Board::Draw(sf::RenderWindow &window){
    window.draw(board);
}

sf::RectangleShape Board::GetShape(){
    return board;
}
