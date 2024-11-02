#include <cstdlib> // using library only for exit() function
#include "expenses.h"

std::string categoriesRev[10];
double userRevenue[10];
int numRevCategories;
void revenues() {
    std::cout << "\033[2J\033[1;1H"; //clears the screen

    std::cout << R"(
---------------------------------------------------------------------------
  $$$$$$$\                                                                 
  $$  __$$\                                                                
  $$ |  $$ |$$$$$$\$$\    $$\ $$$$$$\ $$$$$$$\ $$\   $$\ $$$$$$\  $$$$$$$\ 
  $$$$$$$  $$  __$$\$$\  $$  $$  __$$\$$  __$$\$$ |  $$ $$  __$$\$$  _____|
  $$  __$$<$$$$$$$$ \$$\$$  /$$$$$$$$ $$ |  $$ $$ |  $$ $$$$$$$$ \$$$$$$\  
  $$ |  $$ $$   ____|\$$$  / $$   ____$$ |  $$ $$ |  $$ $$   ____|\____$$\ 
  $$ |  $$ \$$$$$$$\  \$  /  \$$$$$$$\$$ |  $$ \$$$$$$  \$$$$$$$\$$$$$$$  |
  \__|  \__|\_______|  \_/    \_______\__|  \__|\______/ \_______\_______/ 
---------------------------------------------------------------------------
                                                                           
    )" << "\n";



    do {
        std::cout << "Enter the number of revenue categories (max " << 10 << "): ";
        std::cin >> numRevCategories;

        if (numRevCategories > 10) {
            std::cout << "Exceeded maximum number of categories! Please enter a number less than or equal to " << 10 << "." << std::endl;
        }
    } while (numRevCategories > 10);

    for (int i = 0; i < numRevCategories; i++) {
        std::cout << "Enter the name of the category " << (i + 1) << ": ";
        std::cin >> categoriesRev[i];
        std::cout << "Enter the montly revenue for " << categoriesRev[i] << ": ";
        std::cin >> userRevenue[i];
    }

    std::cout << "\nYour monthly revenues:" << std::endl;
    for (int i = 0; i < numRevCategories; i++) {
        std::cout << categoriesRev[i] << ": $" << userRevenue[i] << std::endl;
    }
    std::cout << "\n";
    int choice;
    std::cout << "1.Continue\n2.Exit\n";
    std::cout << "Enter choice:";
    std::cin >> choice;
    if (choice == 1) {
        expenses();
    }
    else {
        std::cout << "Exiting...";
        exit(0);
    }
}