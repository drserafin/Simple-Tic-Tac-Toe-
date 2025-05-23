#include <iostream>
#include <algorithm>
#include "game.h"

void Game::startGame(){
    while (true) {
        board.drawBoard();
        playerMove();

        int result = evaluateBoard();
        if (result == 10) {
            board.drawBoard();
            std::cout << "Computer wins!\n";
            break;
        } else if (result == -10) {
            board.drawBoard();
            std::cout << "You win!\n";
            break;
        }

        // Check if there are any moves left after player move
        bool movesLeft = false;
        for (int i = 0; i < 9; i++) {
            if (board.getSpaces(i) != 'X' && board.getSpaces(i) != 'O') {
                movesLeft = true;
                break;
            }
        }
        if (!movesLeft) {
            board.drawBoard();
            std::cout << "It's a draw!\n";
            break;
        }

        computerMove();

        result = evaluateBoard();
        if (result == 10) {
            board.drawBoard();
            std::cout << "Computer wins!\n";
            break;
        } else if (result == -10) {
            board.drawBoard();
            std::cout << "You win!\n";
            break;
        }

        // Check if there are any moves left after computer move
        movesLeft = false;
        for (int i = 0; i < 9; i++) {
            if (board.getSpaces(i) != 'X' && board.getSpaces(i) != 'O') {
                movesLeft = true;
                break;
            }
        }
        if (!movesLeft) {
            board.drawBoard();
            std::cout << "It's a draw!\n";
            break;
        }
    }
}

void Game::playerMove(){
    int move;
    while(true){
        std::cout << "Please enter a position (1-9) you want to place your symbol: ";
        if (!(std::cin >> move)){
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << "Invalid input, please try again\n";
            continue;
        }
        move = move - 1; 
        if (move >= 0 && move < 9 && board.getSpaces(move) != 'X' && board.getSpaces(move) != 'O') {
            board.setSpace(move, player);
            break;
        } else {
            std::cout << "Invalid move! Try again.\n";
        }
    }
}

int Game::evaluateBoard() {
    const int winPatterns[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, // rows
        {0,3,6}, {1,4,7}, {2,5,8}, // columns
        {0,4,8}, {2,4,6}           // diagonals
    };
    for (auto& pattern : winPatterns) {
        char a = board.getSpaces(pattern[0]);
        char b = board.getSpaces(pattern[1]);
        char c = board.getSpaces(pattern[2]);
        if (a == b && b == c) {
            if (a == computer) return +10;
            if (a == player) return -10;
        }
    }
    return 0;
}

int Game::minimax(bool isMaximizing) { //true when its computer's turn otherwise false
    int score = evaluateBoard();
    if (score == 10 || score == -10) return score; // no winner -> skip if statement

    bool movesLeft = false; // no more moves
    for (int i = 0; i < 9; i++) {
        if (board.getSpaces(i) != 'X' && board.getSpaces(i) != 'O') {
            movesLeft = true; // there are moves left -> exit for loop
            break;
        }
    }
    if (!movesLeft) return 0; // if movesLeft is false -> return 0

    if (isMaximizing) { // 
        int best = -1000; 
        for (int i = 0; i < 9; i++) {
            if (board.getSpaces(i) != 'X' && board.getSpaces(i) != 'O') {
                char original = board.getSpaces(i);
                board.setSpace(i, computer);
                best = std::max(best, minimax(false)); // minimax(false) returns a value
                board.setSpace(i, original);
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 9; i++) {
            if (board.getSpaces(i) != 'X' && board.getSpaces(i) != 'O') {
                char original = board.getSpaces(i);
                board.setSpace(i, player);
                best = std::min(best, minimax(true));
                board.setSpace(i, original);
            }
        }
        return best;
    }
}

void Game::computerMove() {
    int bestVal = -1000;
    int bestMove = -1;

    for (int i = 0; i < 9; i++) {
        if (board.getSpaces(i) != 'X' && board.getSpaces(i) != 'O') {
            char original = board.getSpaces(i);
            board.setSpace(i, computer);
            int moveVal = minimax(false);
            board.setSpace(i, original); // not playing the move , just simulating it

            if (moveVal > bestVal) { // (10 > -10)
                bestMove = i;// 2
                bestVal = moveVal; // 10
            }
        }
    }

    board.setSpace(bestMove, computer);
    std::cout << "Computer placed at position " << bestMove + 1 << "\n";
}




