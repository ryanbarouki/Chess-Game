#include "Game.hpp"


Game::Game(){
    window = new sf::RenderWindow (sf::VideoMode(1000, 1000), "Chess");
    board = new Board(sf::Vector2f(1000.0f, 1000.0f));
}

void Game::Loop(){
    while(window->isOpen()){
        
        sf::Event evnt;
        
        // allows us to close the window
        while (window->pollEvent(evnt)){
            // a switch statement for event types e.g close window, resize, input text etc.
            switch (evnt.type){
                    // close the window
                case sf::Event::Closed:
                    window->close();
                    break;
            }
            
        }
        window->clear();
        
        // draw things here
        board->Draw(*window);
        
        window->display();
    }
    
}
