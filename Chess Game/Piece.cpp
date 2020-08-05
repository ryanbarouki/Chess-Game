#include "Piece.hpp"
#include <iostream>
#include "Pawn.hpp"
#define size 125
Piece::Piece(char clr){
    pieceTexture.loadFromFile("images/pieces_s.png");
    piece.setTexture(pieceTexture);
    colour = clr;
}

void Piece::Draw(sf::RenderWindow &window){
    window.draw(piece);
}

sf::Sprite Piece::GetShape(){
    return piece;
}

char Piece::getColour(){
    return colour;
}

bool Piece::wouldMoveCauseCheck(int origrow, int origcol, int finalrow, int finalcol, Board board){
    bool causesCheck = false;
    
    //update the board
    board.updateBoard(origrow, origcol, finalrow, finalcol);
    //check if any piece of the opposite colour can move to the square of the king.
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (board.getPiece(i, j) != nullptr){
                if(board.getPiece(i, j)->getColour() != colour && colour == 'w'){
                    if (board.getPiece(i, j)->canMoveTo(i, j, board.white_king_position.x, board.white_king_position.y, board)){
                        causesCheck = true;
                        std::cout << "YOU WOULD BE IN CHECK!" << "\n";
                    }
                } else if (board.getPiece(i, j)->getColour() != colour && colour == 'b'){
                    if (board.getPiece(i, j)->canMoveTo(i, j, board.black_king_position.x, board.black_king_position.y, board)){
                        causesCheck = true;
                        std::cout << "YOU WOULD BE IN CHECK!" << "\n";
                    }
                }
            }
    return causesCheck;
}
