/*****************************************************************************************************************
** Author: Anish Reddy
** Date: 10/13/19
** Description: This is the main function. It calls the menu function to see if the user wants to run the simulation
** If the user doesn't want to run it quits. If not, it goes through a while loop for the user to enter a bunch of info
** This is where the simulation actually runs.
******************************************************************************************************************/

#include "ant.hpp"
#include "menu.hpp"


using std::string;

int main(){
    int menuchoice = menu();

    int row;
    int col;
    int steps;
    int antX;
    int antY;
    int direction = 0;
    char **myboard = NULL;
	char white = ' ';

    //checks to see that the user input 1 to play
    while(menuchoice == 1){
        std::cout << "Please enter the number of rows you would like from 1 to 100: " << std::endl;
        std::cin >> row;
        while(row < 1 || row > 100 || std::cin.fail()){
            std::cout << "You have entered a wrong input. Please enter the amount of rows you would like from 1 to 100: " << std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cin >> row;
        }
        
        std::cout << "Please enter the number of columns you would like from 1 to 100: " << std::endl;
        std::cin >> col;
        while(col < 1 || col > 100 || std::cin.fail()){
            std::cout << "You have entered a wrong number. Please enter the amount of columns you would like from 1 to 100: " << std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cin >> col;
        }

        std::cout << "Please enter the number of steps you would like the ant to take from 1 to 20000: " << std::endl;
        std::cin >> steps;
        while(steps < 1 || steps > 20000 || std::cin.fail()){
            std::cout << "You have entered a wrong number. Please enter the amount of steps you would like the ant to take from 1 to 20000: " << std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cin >> steps;
        }

        std::cout << "Please enter the starting x-coordinate position of the ant from 1 to " << col << ": " << std::endl;
        std::cin >> antX;
        while(antX < 1 || antX > row || std::cin.fail()){
            std::cout << "You have entered a wrong number. Please enter the starting x-coordinate position of the ant from 1 to " << row << ":" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cin >> antX;
        }

        std::cout << "Please enter the starting y-coordinate position of the ant from 1 to " << row << ": " << std::endl;
        std::cin >> antY;
        while(antY < 1 || antY > col || std::cin.fail()){
            std::cout << "You have entered a wrong number. Please enter the starting y-coordinate position of the ant from 1 to " << col << ":" <<  std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cin >> antY;
        }

        std::cout << "Please enter a starting direction for the ant. 0 = North, 1 = East, 2 = South, 3 = West." << std::endl;
        std::cin >> direction;
        while(direction < 1 || direction > 4 || std::cin.fail()){
            std::cout << "You have entered a wrong integer. Please enter a starting directionection for the ant. 0 = North, 1 = East, 2 = South, 3 = West." << std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cin >> direction;
        }

        //dynamically allocates memory for a 2D array called myboard
        char **myboard = new char*[row];
        for(int i = 0; i < row; i++){
            myboard[i]= new char[col];
        }
        
        //fills the board with blank spaces representing the color white. 
        //Also adds the outside border to the array.
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i == 0 || i == (row - 1)){
                   myboard[i][j] = '-';
                }
                else if(j == 0 || j == (col - 1)){
                    myboard[i][j] = '|';
                }
                else{
                    myboard[i][j] = ' ';
                }
            }
        }

        //creates the ant instance of the Ant class using all the variables created in main
        Ant ant(row, col, antX, antY, direction, steps, myboard);
        //sets the current ant position to white or ' ', so that antDirection can run
		ant.setCurrentColor(white);
        int count = 0;
        //loops through the antDirection and printBoard functions from ant until the
        //counter is greater than steps.
        while(count < steps){
             ant.antDirection();
			 ant.printBoard();
             count++;
         }

        //deallocates the memory created for myboard
        for(int i = 0; i < row; i++){
            delete[] myboard[i];
        }
        delete[] myboard;

        //calls the menu again to see if the user would like to play or would like to quit
        menuchoice = menu();

    }
    //quits the program when the user hits 2 from the main menu.
    while(menuchoice == 2){
        return 0;
    }



}