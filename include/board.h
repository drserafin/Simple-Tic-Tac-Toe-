#ifndef BOARD_H
#define BOARD_H

class DrawBoard {
private:
    char spaces[9]; // array of characters
public:
    DrawBoard(); // constructor
    void drawBoard() const; // just prints, dosen't modify
    char getSpaces(int index) const; 
    void setSpace(int index, char symbol); 
};

#endif