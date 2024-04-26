#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

class Board {
public:
    Board();
    void display();
    bool placeMark(int cell, char mark);
    char checkWinner();
    bool isBoardFull();

private:
    char board[3][3];
};

#endif // BOARD_HPP
