#pragma once

#include <SFML/Graphics.hpp>
#include "Piece.hpp"
#include "Pawn.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Rook.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "Board.hpp"

class Game {
public:
    Game();
    
    void Loop();
    

    
private:
    //declare all pointers to pieces etc
    sf::RenderWindow* window;
    Board* board;
    Pawn* pawns[16];
    Rook* rooks[4];
    Knight* knights[4];
    Bishop* bishops[4];
    Queen* queens[2];
    King* kings[2];
    
};
