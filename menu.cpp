/**********************************************************************************
** Author: Anish Reddy
** Date: 10/13/19
** Description: This is a basic menu to see if the user wants to play or quit. It 
** can be called multiple times, hence why I put it in a separate file.
**********************************************************************************/

#include "menu.hpp"

int menu(){

    int choice;
    
    std::cout << "Please choose from the following options below:" << std::endl;
    std::cout << "1. Start Langton's Ant Simulation" << std::endl;
    std::cout << "2. Quit" << std::endl;
    std::cin >> choice;

    //checks to see if the integer the user entered was actually an integer, and if it was if
    //it was either 1 or 2.
    if(choice <= 0 || choice > 3 || std::cin.fail()){
        std::cout <<"You have entered an incorrect value. Please select 1 or 2 from the menu again." << std::endl;
        std::cout << "Please choose from the following options below:" << std::endl;
        std::cout << "1. Start Langton's Ant Simulation" << std::endl;
        std::cout << "2. Quit" << std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cin >> choice;
    }

    return choice;
}