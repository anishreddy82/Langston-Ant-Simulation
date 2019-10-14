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

        std::cout << "Please enter the starting x-coordinate position of the ant: " << std::endl;
        std::cin >> antX;
        while(antX < 1 || antX > row || std::cin.fail()){
            std::cout << "You have entered a wrong number. Please enter the starting x-coordinate position of the ant from 1 to " << row << ":" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cin >> antX;
        }

        std::cout << "Please enter the starting y-coordinate position of the ant: " << std::endl;
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

         char **myboard = new char*[row];
         for(int i = 0; i < row; i++){
              myboard[i]= new char[col];
         }
        
         

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

        Ant ant(row, col, antX, antY, direction, steps, myboard);
		ant.setCurrentColor(white);
        int count = 0;
        while(count < steps){
             ant.antDirection();
			 ant.printBoard();
             count++;
         }

        for(int i = 0; i < row; i++){
            delete[] myboard[i];
        }
        delete[] myboard;

        menuchoice = menu();

    }
    while(menuchoice == 2){
        return 0;
    }



}