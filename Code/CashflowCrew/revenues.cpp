#include "expenses.h"
#include "revenues.h"

std::string categoriesRev[10];
double userRevenue[10];
int numRevCategories;
double sumRevenue = 0;
void revenues() {
    std::cout << "\033[2J\033[1;1H"; // Clears the screen

    std::ofstream outRevFile;
    std::ifstream inRevFile;

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


    // Input loop for entering the number of revenue categories
    do {
        std::cout << "Enter the number of revenue categories (max " << 10 << "): ";
        std::cin >> numRevCategories;

        if (numRevCategories > 10) {
            std::cout << "Exceeded maximum number of categories! Please enter a number less than or equal to " << 10 << "." << std::endl;
        }
    } while (numRevCategories > 10);

    // Input loop for entering category names and corresponding revenues
    for (int i = 0; i < numRevCategories; i++) {
        std::cout << "Enter the name of the category " << (i + 1) << ": ";
        std::cin >> categoriesRev[i];
        std::cout << "Enter the montly revenue for " << categoriesRev[i] << ": ";
        std::cin >> userRevenue[i];
        sumRevenue += userRevenue[i];
    }

    // Display the entered monthly revenues
    std::cout << "\nYour monthly revenues:" << std::endl;
    for (int i = 0; i < numRevCategories; i++) {
        std::cout << categoriesRev[i] << ": $" << userRevenue[i] << std::endl;
    }

    outRevFile.open("Revenues.txt", std::ios::out);  // Open file in write mode
    outRevFile << sumRevenue << std::endl;
    outRevFile.close();  // Close the file after writing

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