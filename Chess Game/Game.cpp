#include "Game.hpp"
#define board_size 1000
#define size 125
// rect_x: 0= , 1= , 2= , 3= , 4= , 5=pawn
// rect_y: 0=white, 1=black

Game::Game(){
    
    window = new sf::RenderWindow (sf::VideoMode(1000, 1000), "Chess");
    board = new Board(sf::Vector2f(board_size, board_size));
    
    // initialise all the pawns in a loop
    for (int i = 0; i < 16; i++) {
        if(i < 8){
            // white pawns
            pawns[i] = new Pawn(sf::Vector2f(size*i,size),5,0);
        } else {
            // black pawns
            pawns[i] = new Pawn(sf::Vector2f(size*(i-8),size*6),5,1);
        }
    }
    
}

void Game::Loop(){
    while(window->isOpen()){
        sf::Event evnt;
        
        // allows us to close the window
        while (window->pollEvent(evnt)){
            // a switch statement for event types e.g close window, resize, input text etc.
            if (evnt.type == evnt.Closed){
                    // close the window
                    window->close();
            }
            for (int i = 0; i < 16; i++) pawns[i]->Move(evnt, *window);
            
        }
        window->clear();
        
        // draw things here
        board->Draw(*window);
        // draw all pawns in a loop
        for(int i = 0; i < 16; i++) pawns[i]->Draw(*window);
        
        
        
        window->display();
    }
    
}
