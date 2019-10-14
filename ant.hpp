#ifndef ANT_HPP
#define ANT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Ant {
    private:
        int col;
        int row;
        int antX;
        int antY;
        int direction;
        int steps;
        char** myboard;
		char color;
    public:
        Ant(int, int, int, int, int, int, char**);
        void antDirection();
        void printBoard();
		void setCurrentColor(char color);
		char getCurrentColor();
};
#endif