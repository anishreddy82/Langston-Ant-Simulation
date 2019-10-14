/********************************************************************************
** Author: Anish Reddy
** Date: 10/13/19
** Description: This is the main file that moves the ant. This file changes the 
** color of the space the ant is currently on, changes the direction of the ant,
** moves the ant, and prints the board out.
********************************************************************************/

#include "ant.hpp"

//This is the constructor, where I set everything equal to what it is in my main function.
//These variables will now be accessible by any of the member functions below
Ant::Ant(int xrow, int ycol, int antX_row, int antY_col, int dir, int step, char** board){
    row = xrow;
    col = ycol;
    antX = antX_row;
    antY = antY_col;
    direction = dir;
    myboard = board;
    steps = step;
    char color;
}

//This sets the current color of the ant. This is for the first move of the ant. By setting
//the color to white, which was set to ' ' in my main function, we are allow the ant to 
//make its first move with the current position of the ant being white.
void Ant::setCurrentColor(char white){
	color = white;
}

//This just returns the color of the ant to be used later, if necessary
char Ant::getCurrentColor() {
	return color;
}

//This function gets the direction, and moves the ant depending on the color of the current
//position. This function has multiple if statements that all do the same thing. The 
//comments I made on the first block of if statements is similar for all other if statements
//in the same block.
void Ant::antDirection(){
     //0 = North, 1 = East, 2 = South, 3 = West
        //checks to see if the color the ant is on is white.
        if(color == ' '){
            //changes the color the ant is on to black
            myboard[antX][antY] = '#';
            //checks the direction and changes the direction depending on color
            if(direction == 0){
                direction = 1;
                //checks the edge, and if it is an edge, makes ant go to other side of board
                if((antX + 1) >= (col - 1)){
                    antX = 1;
                }
                //if not an edge, then it moves the ant
                else{
                    antX++;
                }
            }
            else if(direction == 1){
                direction = 2;
                if((antY + 1) >= (row - 1)){
                    antY = 1;
                }
                else{
                    antY++;
                }
            }
            else if(direction == 2){
                direction = 3;
                if((antX - 1) < 1){
                    antX = (col - 2);
                }
                else{
                    antX--;
                }
            }
            else if(direction == 3){
                direction = 0;
                if((antY - 1) < 1){
                    antY = (row - 2);
                }
                else{
                    antY--;
                }
            }
        }
        //checks to see if the color the ant is on is black.
        else if(color == '#'){
            myboard[antX][antY] = ' ';
            if(direction == 0){
                direction = 3;
                if((antX - 1) < 1){
                    antX = (col - 2);
                }
                else{
                    antX--;
                }
            }
            else if(direction == 1){
                direction = 0;
                if((antY -1) < 1){
                    antY = (row - 2);
                }
                else{
                    antY--;
                }
            }
            else if(direction == 2){
                direction = 1;
                if((antX + 1) >= (col - 1)){
                    antX = 1;
                }
                else{
                    antX++;
                }
            }
            else if(direction == 3){
                direction = 2;
                if((antY + 1) >= (row -1)){
                    antY = 1;
                }
                else{
                    antY++;
                }
            }
    }

		

    
}

//This prints the board after the ant has made a move
void Ant::printBoard() {
    //checks to see if the ants next position is white, and then stores
    //that color in the color variable to be used in the antDirection function
	if (myboard[antX][antY] == ' ') {
		color = ' ';
	}
    //Checks to see if the ants next position is black, and then stores 
    //that color in the color variable.
	else {
		color = '#';
	}

    //prints out the board, putting the ant in the location that the ant had just
    //moved to according to antDirection
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			myboard[antX][antY] = '*';
			std::cout << myboard[i][j];
			
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}










