#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Player.hpp"

class Game {
public:
    Game();
    void start();

private:
    Board board;
    Player player1;
    Player player2;
    char currentPlayerMark;
    bool gameOver;

    void switchPlayer();
};

#endif // GAME_HPP
