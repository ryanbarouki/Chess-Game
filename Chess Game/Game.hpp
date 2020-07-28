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
    sf::RenderWindow* window;
    Board* board;
    Pawn* pawn;
};
