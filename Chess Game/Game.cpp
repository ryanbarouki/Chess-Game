#include "Game.hpp"
#include <iostream>
#define board_size 1132
#define size 125
// rect_x: 0= , 1= , 2= , 3=knight , 4=rook , 5=pawn
// rect_y: 0=white, 1=black

Game::Game(){
    
    window = new sf::RenderWindow (sf::VideoMode(board_size, board_size), "Chess");
    board = new Board(sf::Vector2f(board_size, board_size));
    
}

void Game::Loop(){
    while(window->isOpen()){
        sf::Event evnt;
        sf::Vector2i pos = sf::Mouse::getPosition(*window);
        // allows us to close the window
        while (window->pollEvent(evnt)){
            // an if statement for event types e.g close window, resize, input text etc.
            if (evnt.type == evnt.Closed){
                    // close the window
                    window->close();
            }
            // allows pieces to move (click n drag)
                
            if (evnt.type == sf::Event::MouseButtonPressed) {
                if (evnt.key.code == sf::Mouse::Left){
                    for( int i = 0; i < 8; i++)
                        for( int j = 0; j < 8; j++)
                            if (board->getPiece(i, j) != nullptr)
                                if (board->getPiece(i, j)->piece.getGlobalBounds().contains(pos.x,pos.y)){
                                    isMove = true;
                                    I = i;
                                    J = j;
                                    dx = pos.x - board->getPiece(i, j)->piece.getPosition().x;
                                    dy = pos.y - board->getPiece(i, j)->piece.getPosition().y;
                                    oldPos = board->getPiece(i, j)->piece.getPosition();
                                }
                }
            }
            
            if (evnt.type == sf::Event::MouseButtonReleased){
                if (evnt.key.code == sf::Mouse::Left) {
                    if (I != -1 && J != -1){ // needed to fix the bug
                        if (board->getPiece(I, J) != nullptr){
                                isMove = false;
                                sf::Vector2f p = board->getPiece(I, J)->piece.getPosition();
                                //snaps to grid
                                newPos = sf::Vector2f(size*int(p.x/size) + size/2, size*int(p.y/size) + size/2);
                                int new_row = int(newPos.y/size);
                                int new_col = int(newPos.x/size);
                                
                                // is the move valid and will it put you in check?
                                if(board->getPiece(I, J)->canMoveTo(I,J, new_row, new_col, *board) && newPos != oldPos && !board->getPiece(I, J)->wouldMoveCauseCheck(I,J, new_row, new_col, *board)){
                                    //takes care of who's turn it is.
                                    if((board->getPiece(I, J)->getColour() == 'w' && turn % 2 == 0) || (board->getPiece(I, J)->getColour() == 'b' && turn % 2 == 1)){
                                        turn++;
                                        board->getPiece(I, J)->piece.setPosition(newPos);
                                        board->updateBoard(I, J, new_row, new_col);
                                    } else board->getPiece(I, J)->piece.setPosition(oldPos);
                                } else board->getPiece(I, J)->piece.setPosition(oldPos);
                        }
                    }
                }
            }
            //updates the position continuously when dragging a piece
            if(isMove) board->getPiece(I, J)->piece.setPosition(pos.x-dx,pos.y-dy);
        }
        
        window->clear();
        
        // DRAW THINGS HERE
        board->Draw(*window);
        
        // DRAW PIECES
        for( int i = 0; i < 8; i++)
            for( int j = 0; j < 8; j++)
                if (board->getPiece(i, j) != nullptr) {
                    board->getPiece(i, j)->Draw(*window);
                }
        window->display();
    }
    
}
