//
//  main.cpp
//  Chess Game
//
//  Created by Ryan Barouki on 24/07/2020.
//  Copyright © 2020 Ryan Barouki. All rights reserved.
//

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window( sf::VideoMode(640, 480), "Chess");
    
    while( window.isOpen()){
        sf::Event event;
        
        while (window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    
                    break;
            }
        }
        
        window.clear();
        // draw objects here
        window.display();
    }
    
}
