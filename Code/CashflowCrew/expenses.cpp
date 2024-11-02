#include <cstdlib> // Using library only for exit() function
#include "expenses.h"

std::string categoriesExp[10];
double userExpense[10];
int numExpCategories;

// Function to handle the expense input and display
void expenses() {
    std::cout << "\033[2J\033[1;1H"; // Clears the screen

    std::cout << R"(
-------------------------------------------------------------------------------
  $$$$$$$$\                                                                    
  $$  _____|                                                                   
  $$ |     $$\   $$\ $$$$$$\  $$$$$$\ $$$$$$\$$$$\  $$$$$$$\ $$$$$$\  $$$$$$$\ 
  $$$$$\   \$$\ $$  $$  __$$\$$  __$$\$$  _$$  _$$\$$  _____$$  __$$\$$  _____|
  $$  __|   \$$$$  /$$ /  $$ $$$$$$$$ $$ / $$ / $$ \$$$$$$\ $$$$$$$$ \$$$$$$\  
  $$ |      $$  $$< $$ |  $$ $$   ____$$ | $$ | $$ |\____$$\$$   ____|\____$$\ 
  $$$$$$$$\$$  /\$$\$$$$$$$  \$$$$$$$\$$ | $$ | $$ $$$$$$$  \$$$$$$$\$$$$$$$  |
  \________\__/  \__$$  ____/ \_______\__| \__| \__\_______/ \_______\_______/ 
                    $$ |                                                       
                    $$ |                                                       
                    \__|  
-------------------------------------------------------------------------------                                                                                                  
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

    // Display the entered monthly expenses
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