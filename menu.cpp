#include "menu.hpp"

int menu(){
    string userInput;
    int choice;
    

    std::cout << "Please choose from the following options below:" << std::endl;
    std::cout << "1. Start Langton's Ant Simulation" << std::endl;
    std::cout << "2. Quit" << std::endl;
    std::cin >> userInput;

    choice = stoi(userInput);

    if(choice <= 0 || choice > 3){
        std::cout <<"You have entered an incorrect integer. Please select 1 or 2 from the menu again." << std::endl;
        getline(std::cin, userInput);
        choice = stoi(userInput);
    }

    return choice;
}