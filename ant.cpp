#include "ant.hpp"


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

void Ant::setCurrentColor(char white){
	color = white;
}

char Ant::getCurrentColor() {
	return color;
}


void Ant::antDirection(){
     //0 = North, 1 = East, 2 = South, 3 = West
     
        if(color == ' '){
            myboard[antX][antY] = '#';
            if(direction == 0){
                direction = 1;
                if((antX + 1) >= (col - 1)){
                    direction = 3;
                }
                else{
                    antX++;
                }
            }
            else if(direction == 1){
                direction = 2;
                if((antY + 1) > (row - 1)){
                    direction = 0;
                }
                else{
                    antY++;
                }
            }
            else if(direction == 2){
                direction = 3;
                if((antX - 1) < 1){
                    direction = 1;
                }
                else{
                    antX--;
                }
            }

            else if(direction == 3){
                direction = 0;
                if((antY - 1) < 1){
                        direction = 2;
                }
                else{
                    antY--;
                }
            }
        }
        else if(color == '#'){
            myboard[antX][antY] = ' ';
            if(direction == 0){
                direction = 3;
                if((antX - 1) < 1){
                    direction = 1;
                }
                else{
                    antX--;
                }
            }
            else if(direction == 1){
                direction = 0;
                if((antY -1) < 1){
                    direction = 2;
                }
                else{
                    antY--;
                }
            }
            else if(direction == 2){
                direction = 1;
                if((antX + 1) >= (col - 1)){
                    direction = 3;
                }
                else{
                    antX++;
                }
            }
            else if(direction == 3){
                direction = 2;
                if((antY + 1) >= (row -1)){
                    direction = 0;
                }
                else{
                    antY++;
                }
            }
    }

		

    
}

void Ant::printBoard() {
	if (myboard[antX][antY] == ' ') {
		color = ' ';
	}
	else {
		color = '#';
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			myboard[antX][antY] = '*';
			std::cout << myboard[i][j];
			
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}










