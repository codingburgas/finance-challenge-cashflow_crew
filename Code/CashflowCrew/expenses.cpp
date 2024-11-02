#include <cstdlib> // using library only for exit() function
#include "expenses.h"

std::string categoriesExp[10];
double userExpense[10];
int numExpCategories;

void expenses() {
    std::cout << "\033[2J\033[1;1H"; //clears the screen

    std::cout << R"(
  _____                                     
 | ____|_  ___ __   ___ _ __  ___  ___  ___ 
 |  _| \ \/ / '_ \ / _ \ '_ \/ __|/ _ \/ __|
 | |___ >  <| |_) |  __/ | | \__ \  __/\__ \
 |_____/_/\_\ .__/ \___|_| |_|___/\___||___/
            |_|                                                 
    )" << "\n";



    do {
        std::cout << "Enter the number of expense categories (max " << 10 << "): ";
        std::cin >> numExpCategories;

        if (numExpCategories > 10) {
            std::cout << "Exceeded maximum number of categories! Please enter a number less than or equal to " << 10 << "." << std::endl;
        }
    } while (numExpCategories > 10);

    for (int i = 0; i < numExpCategories; i++) {
        std::cout << "Enter the name of the category " << (i + 1) << ": ";
        std::cin >> categoriesExp[i];
        std::cout << "Enter the montly revenue for " << categoriesExp[i] << ": ";
        std::cin >> userExpense[i];
    }

    std::cout << "\nYour monthly expenses:" << std::endl;
    for (int i = 0; i < numExpCategories; i++) {
        std::cout << categoriesExp[i] << ": $" << userExpense[i] << std::endl;
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