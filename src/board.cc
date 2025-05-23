#include<iostream>
#include "board.h"

// Constructor: initialize the board spaces
DrawBoard::DrawBoard() {
    for (int i = 0; i < 9; i++) {
        spaces[i] = ' '; 
        //spaces[i] = '1' + i;
    }
}

// drawBoard prints the board nicely
void DrawBoard::drawBoard() const {
    for (int i = 0; i < 9; i += 3) {
        std::cout << "     |     |     \n";
        
        for (int j = 0; j < 3; j++) { 
            std::cout << "  " << spaces[i + j] << "  ";
            if (j < 2) {             
                std::cout << "|";
            }
        }

        if (i < 6) {
            std::cout << "\n_____|_____|_____\n";
        } else {
            std::cout << "\n     |     |     \n";
        }
    }
}

char DrawBoard::getSpaces(int index) const {
    return spaces[index];
}

void DrawBoard::setSpace(int index, char symbol){
    spaces[index] = symbol;
}