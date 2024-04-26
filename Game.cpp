#include "Game.hpp"

Game::Game() : player1('X'), player2('O'), currentPlayerMark('X'), gameOver(false) {}

void Game::start() {
    while (!gameOver) {
        board.display();
        int cell = (currentPlayerMark == 'X') ? player1.makeMove() : player2.makeMove();
        if (board.placeMark(cell, currentPlayerMark)) {
            char winner = board.checkWinner();
            if (winner != ' ') {
                board.display();
                if (winner == 'X')
                    std::cout << "Player one wins!\n";
                else
                    std::cout << "Player two wins!\n";
                gameOver = true;
            } else if (board.isBoardFull()) {
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
    currentPlayerMark = (currentPlayerMark == 'X') ? 'O' : 'X';
}
