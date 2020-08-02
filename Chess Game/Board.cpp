#include "Board.hpp"
#include "Piece.hpp"

#define size 125

Board::Board(sf::Vector2f dim){
    board.setSize(dim);
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


Piece Board::pieceAt(int row, int col){
    
    return *board_array[row][col];
}
   
void Board::addPiece(Piece *piece){
    // use the fact that a Piece knows its location in order to figure out where it will go.
    double x = piece->GetShape().getPosition().x;
    double y = piece->GetShape().getPosition().y;
    
    int row = int((y - size/2)/size);
    int col = int((x - size/2)/size);
    
    board_array[row][col] =  new Piece(piece->getColour()); // this is needed for heapy stacky reasons
    board_array[row][col] = piece;
}
   
void Board::removePiece(int row, int col){
    delete board_array[row][col]; //clears the memory
    board_array[row][col] = nullptr; // makes it null basically
}

Piece* Board::getPiece(int row, int col){
    return board_array[row][col];
}

void Board::updateBoard(int old_row, int old_col, int new_row, int new_col){
    
    board_array[new_row][new_col] = board_array[old_row][old_col];
    //delete board_array[old_row][old_col];
    board_array[old_row][old_col] = nullptr;
}
