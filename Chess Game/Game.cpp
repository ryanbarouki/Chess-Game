#include "Game.hpp"
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
            pawns[i] = new Pawn(sf::Vector2f(size*(i-8)+size/2,size*6 + size/2),5,0);}
        else { // black
            pawns[i] = new Pawn(sf::Vector2f(size*i+size/2,size+size/2),5,1);}}
    //rooks
    for (int i=0; i<4; i++) {
        if (i>=2) {//white
            rooks[i] = new Rook(sf::Vector2f(size*7*(i-2)+size/2,size*7+size/2),4,0);}
        else { //black
            rooks[i] = new Rook(sf::Vector2f(size*7*i+size/2,size/2),4,1);}}
    //knights
    for (int i=0; i<4; i++) {
        if (i>=2) {//white
            knights[i] = new Knight(sf::Vector2f(size*((5*(i-2))+1)+size/2,size*7+size/2),3,0);}
        else { //black
            knights[i] = new Knight(sf::Vector2f(size*((5*i)+1)+size/2,size/2),3,1);}}
    //bishops
    for (int i=0; i<4; i++) {
        if (i>=2) {//white
            bishops[i] = new Bishop(sf::Vector2f(size*((3*(i-2))+2)+size/2,size*7+size/2),2,0);}
        else { //black
            bishops[i] = new Bishop(sf::Vector2f(size*((3*i)+2)+size/2,size/2),2,1);}}
    //queens
    queens[1] = new Queen(sf::Vector2f(size*3+size/2,size*7+size/2),1,0);
    queens[0] = new Queen(sf::Vector2f(size*3+size/2,size/2),1,1);
    
    //kings
    kings[1] = new King(sf::Vector2f(size*4+size/2,size*7+size/2),0,0);
    kings[0] = new King(sf::Vector2f(size*4+size/2,size/2),0,1);
    
}

void Game::Loop(){
    while(window->isOpen()){
        sf::Event evnt;
        
        // allows us to close the window
        while (window->pollEvent(evnt)){
            // an if statement for event types e.g close window, resize, input text etc.
            if (evnt.type == evnt.Closed){
                    // close the window
                    window->close();
            }
            // allows pieces to move (click n drag)
            for (int i = 0; i < 16; i++) pawns[i]->Move(evnt, *window);
            for (int i = 0; i < 4; i++) {
                rooks[i]->Move(evnt, *window);
                knights[i]->Move(evnt, *window);
                bishops[i]->Move(evnt, *window);}
            for (int i=0; i<2; i++) {
                queens[i]->Move(evnt, *window);
                kings[i]->Move(evnt, *window);
                }
        }
        window->clear();
        
        // DRAW THINGS HERE
        board->Draw(*window);
        // DRAW PIECES
        for(int i = 0; i < 16; i++) pawns[i]->Draw(*window);
        for(int i = 0; i < 4; i++) rooks[i]->Draw(*window);
        for(int i = 0; i < 4; i++) knights[i]->Draw(*window);
        for(int i = 0; i < 4; i++) bishops[i]->Draw(*window);
        for(int i = 0; i < 2; i++) queens[i]->Draw(*window);
        for(int i = 0; i < 2; i++) kings[i]->Draw(*window);
        
        
        
        window->display();
    }
    
}
