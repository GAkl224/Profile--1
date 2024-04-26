// game.cpp
#include "Game.hpp"

Game::Game() : board(), player1("Player one", 'X'), player2("Player two", 'O'), currentPlayer(&player1), gameOver(false) {}

void Game::start() {
    int move;
    while (!gameOver) {
        board.display();
        move = currentPlayer->makeMove();
        if (board.placeMarker(move, currentPlayer->getMarker())) {
            if (board.checkWin(currentPlayer->getMarker())) {
                board.display();
                std::cout << currentPlayer->getName() << " wins!\n";
                gameOver = true;
            } else if (board.checkDraw()) {
                board.display();
                std::cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        } else {
            std::cout << "That move is invalid!\n";
        }
    }
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
}
