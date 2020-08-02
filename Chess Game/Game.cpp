#include "Game.hpp"
#include <iostream>
#define board_size 1132
#define size 125
// rect_x: 0= , 1= , 2= , 3=knight , 4=rook , 5=pawn
// rect_y: 0=white, 1=black

Game::Game(){
    
    window = new sf::RenderWindow (sf::VideoMode(board_size, board_size), "Chess");
    board = new Board(sf::Vector2f(board_size, board_size));
    
    // INITIALISE ALL PIECES ONTO THE BOARD
    //pawns
    for (int i = 0; i < 16; i++) {
        if(i >= 8){ //white
            pawns[i] = new Pawn(sf::Vector2f(size*(i-8)+size/2,size*6 + size/2),5,0,'w');
            board->addPiece(pawns[i]);
        }
        else { // black
            pawns[i] = new Pawn(sf::Vector2f(size*i+size/2,size+size/2),5,1,'b');
            board->addPiece(pawns[i]);
        }
    }
    //rooks
    for (int i=0; i<4; i++) {
        if (i>=2) {//white
            rooks[i] = new Rook(sf::Vector2f(size*7*(i-2)+size/2,size*7+size/2),4,0,'w');
            knights[i] = new Knight(sf::Vector2f(size*((5*(i-2))+1)+size/2,size*7+size/2),3,0,'w');
            bishops[i] = new Bishop(sf::Vector2f(size*((3*(i-2))+2)+size/2,size*7+size/2),2,0,'w');
            board->addPiece(rooks[i]);
            board->addPiece(knights[i]);
            board->addPiece(bishops[i]);
        }
        else { //black
            rooks[i] = new Rook(sf::Vector2f(size*7*i+size/2,size/2),4,1,'b');
            knights[i] = new Knight(sf::Vector2f(size*((5*i)+1)+size/2,size/2),3,1,'b');
            bishops[i] = new Bishop(sf::Vector2f(size*((3*i)+2)+size/2,size/2),2,1,'b');
            board->addPiece(rooks[i]);
            board->addPiece(knights[i]);
            board->addPiece(bishops[i]);
        }
    }
    
    //queens
    queens[1] = new Queen(sf::Vector2f(size*3+size/2,size*7+size/2),1,0,'w');
    queens[0] = new Queen(sf::Vector2f(size*3+size/2,size/2),1,1,'b');
    board->addPiece(queens[0]);
    board->addPiece(queens[1]);
    
    //kings
    kings[1] = new King(sf::Vector2f(size*4+size/2,size*7+size/2),0,0,'w');
    kings[0] = new King(sf::Vector2f(size*4+size/2,size/2),0,1,'b');
    board->addPiece(kings[0]);
    board->addPiece(kings[1]);
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
                    isMove = false;
                    sf::Vector2f p = board->getPiece(I, J)->piece.getPosition();
                    //snaps to grid
                    newPos = sf::Vector2f(size*int(p.x/size) + size/2, size*int(p.y/size) + size/2);
                    if(board->getPiece(I, J)->canMoveTo(I,J,*board)){
                        board->getPiece(I, J)->piece.setPosition(newPos);
                    } else {
                        board->getPiece(I, J)->piece.setPosition(oldPos);
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
                if (board->getPiece(i, j) != nullptr) board->getPiece(i, j)->Draw(*window);
        window->display();
    }
    
}
