//
//  main.cpp
//  Chess Game
//
//  Created by Ryan Barouki on 24/07/2020.
//  Copyright © 2020 Ryan Barouki. All rights reserved.
//

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window( sf::VideoMode(1000, 1000), "Chess");
    // create a board rectangle
    sf::RectangleShape board(sf::Vector2f(1000.0f, 1000.0f));
    // center the position of the board
    board.setPosition(0.0f, 0.0f);
    
    // create a texture so we can load an image of a chess board
    sf::Texture boardTexture;
    // load image of chess board
    boardTexture.loadFromFile("/Users/ryanbarouki/Documents/Coding Projects/Chess Game/Chess Game/images/board.png");
    // set the image as the texture of board by reference
    board.setTexture(&boardTexture);
    
    
    while(window.isOpen()){
        
        sf::Event evnt;
        
        // allows us to close the window
        while (window.pollEvent(evnt)){
            // a switch statement for event types e.g close window, resize, input text etc.
            switch (evnt.type){
                    // close the window
                case sf::Event::Closed:
                    window.close();
                    break;
            }
            
        }
        window.clear();
        // draw the board here
        window.draw(board);
        window.display();
    }
    
    return 0;
}
