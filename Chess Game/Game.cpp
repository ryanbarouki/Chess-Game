#include "Game.hpp"


Game::Game(){
    
    window = new sf::RenderWindow (sf::VideoMode(1000, 1000), "Chess");
    board = new Board(sf::Vector2f(1000.0f, 1000.0f));
    
    // initialise all the pawns in a loop
    for (int i = 0; i < 16; i++) {
        if(i < 8){
            // white pawns
            pawns[i] = new Pawn(sf::Vector2f(125.0f*i-25.0f,120.0f),sf::Vector2f(0.7f,0.7f),5,0);
        } else {
            // black pawns
            pawns[i] = new Pawn(sf::Vector2f(125.0f*(i-8)-25.0f,740.0f),sf::Vector2f(0.7f,0.7f),5,1);
        }
    }
    
}

void Game::Loop(){
    while(window->isOpen()){
        sf::Vector2i pos = sf::Mouse::getPosition(*window);
        sf::Event evnt;
        
        // allows us to close the window
        while (window->pollEvent(evnt)){
            // a switch statement for event types e.g close window, resize, input text etc.
            if (evnt.type == evnt.Closed){
                    // close the window
                    window->close();
            }
            
            if (evnt.type == sf::Event::MouseButtonPressed){
                
            }
            
        }
        window->clear();
        
        // draw things here
        board->Draw(*window);
        // draw all pawns in a loop
        for(int i = 0; i < 16; i++) pawns[i]->Draw(*window);
        
        
        
        window->display();
    }
    
}
