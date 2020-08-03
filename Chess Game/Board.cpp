#include "Board.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Rook.hpp"
#include "Queen.hpp"
#include "King.hpp"
#define size 125

Board::Board(sf::Vector2f dim){
    board.setSize(dim);
    board.setPosition(0.0f, 0.0f);
    boardTexture.loadFromFile("images/board2.png");
    // set the image as the texture of board by reference
    board.setTexture(&boardTexture);
    
    
    // INITIALISE ALL PIECES IN THE CONSTRUCTOR
    for (int i = 0; i < 8; i++) {
            board_array[1][i] = new Pawn(sf::Vector2f(size*i+size/2,size+size/2),5,1,'b');
            board_array[6][i] = new Pawn(sf::Vector2f(size*i+size/2,size*6 + size/2),5,0,'w');
        }
    
    board_array[7][0] = new Rook(sf::Vector2f(size/2,size*7+size/2),4,0,'w');
    board_array[7][1] = new Knight(sf::Vector2f(size+size/2,size*7+size/2),3,0,'w');
    board_array[7][2] = new Bishop(sf::Vector2f(size*2+size/2,size*7+size/2),2,0,'w');
    board_array[7][7] = new Rook(sf::Vector2f(size*7+size/2,size*7+size/2),4,0,'w');
    board_array[7][6] = new Knight(sf::Vector2f(size*6+size/2,size*7+size/2),3,0,'w');
    board_array[7][5] = new Bishop(sf::Vector2f(size*5+size/2,size*7+size/2),2,0,'w');
    board_array[7][3] = new Queen(sf::Vector2f(size*3+size/2,size*7+size/2),1,0,'w');
    board_array[7][4] = new King(sf::Vector2f(size*4+size/2,size*7+size/2),0,0,'w');
    
    board_array[0][0] = new Rook(sf::Vector2f(size/2,size/2),4,1,'b');
    board_array[0][1] = new Knight(sf::Vector2f(size+size/2,size/2),3,1,'b');
    board_array[0][2] = new Bishop(sf::Vector2f(size*2+size/2,size/2),2,1,'b');
    board_array[0][7] = new Rook(sf::Vector2f(size*7+size/2,size/2),4,1,'b');
    board_array[0][6] = new Knight(sf::Vector2f(size*6+size/2,size/2),3,1,'b');
    board_array[0][5] = new Bishop(sf::Vector2f(size*5+size/2,size/2),2,1,'b');
    board_array[0][3] = new Queen(sf::Vector2f(size*3+size/2,size/2),1,1,'b');
    board_array[0][4] = new King(sf::Vector2f(size*4+size/2,size/2),0,1,'b');
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
