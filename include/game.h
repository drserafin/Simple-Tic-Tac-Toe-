#ifndef GAME_H
#define GAME_H
#include "board.h"

class Game { 
private:
    DrawBoard board;
    char player = 'X';
    char computer = 'O';
    void playerMove();  
    void computerMove();
    int evaluateBoard();
    int minimax(bool isMaxmizing); 
    bool checkWinner(); 
    bool checkTie();
public:
    void startGame();       
};

#endif