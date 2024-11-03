#include "budget.h"
#include "expenses.h"

std::string categoriesExp[10];
double userExpense[10];
int numExpCategories;
double sumExpenses = 0;

// Function to handle the expense input and display
void expenses() {
    std::cout << "\033[2J\033[1;1H"; // Clears the screen

    std::ofstream outExpFile;
    std::ifstream inExpFile;

    std::cout << R"(
---------------------------------------------------------------------------------
$$$$$$$$\                                                                       
$$  _____|                                                                      
$$ |      $$\   $$\  $$$$$$\   $$$$$$\  $$$$$$$\   $$$$$$$\  $$$$$$\   $$$$$$$\ 
$$$$$\    \$$\ $$  |$$  __$$\ $$  __$$\ $$  __$$\ $$  _____|$$  __$$\ $$  _____|
$$  __|    \$$$$  / $$ /  $$ |$$$$$$$$ |$$ |  $$ |\$$$$$$\  $$$$$$$$ |\$$$$$$\  
$$ |       $$  $$<  $$ |  $$ |$$   ____|$$ |  $$ | \____$$\ $$   ____| \____$$\ 
$$$$$$$$\ $$  /\$$\ $$$$$$$  |\$$$$$$$\ $$ |  $$ |$$$$$$$  |\$$$$$$$\ $$$$$$$  |
\________|\__/  \__|$$  ____/  \_______|\__|  \__|\_______/  \_______|\_______/ 
                    $$ |                                                        
                    $$ |                                                        
                    \__|                                                        
---------------------------------------------------------------------------------                                                                                                     
    )" << "\n";



    do {
        std::cout << "Enter the number of expense categories (max " << 10 << "): ";
        std::cin >> numExpCategories;

        if (numExpCategories > 10) {
            std::cout << "Exceeded maximum number of categories! Please enter a number less than or equal to " << 10 << "." << std::endl;
        }
    } while (numExpCategories > 10);

    std::ofstream expDataFile;
    expDataFile.open("Expenses.txt", std::ios::out);  // Open file in write mode
    expDataFile << numExpCategories << "\n";
    for (int i = 0; i < numExpCategories; i++) {
        std::cout << "Enter the name of the category " << (i + 1) << ": ";
        std::cin >> categoriesExp[i];
        expDataFile << categoriesExp[i] << " ";
        std::cout << "Enter the montly revenue for " << categoriesExp[i] << ": ";
        std::cin >> userExpense[i];
        expDataFile << userExpense[i] << "\n";
        sumExpenses += userExpense[i];
    }
    expDataFile.close();  // Close the file after writing

    // Display the entered monthly expenses
    std::cout << "\nYour monthly expenses:" << std::endl;
    for (int i = 0; i < numExpCategories; i++) {
        std::cout << categoriesExp[i] << ": $" << userExpense[i] << std::endl;
    }
    std::cout << "\n";

    outExpFile.open("ExpensesNum.txt", std::ios::out);  // Open file in write mode
        outExpFile  << sumExpenses << std::endl;
        outExpFile.close();  // Close the file after writing
    
    int choice;
    std::cout << "1.Continue\n2.Exit\n";
    std::cout << "Enter choice:";
    std::cin >> choice;
    if (choice == 1) {
        budget();
    }
    else {
        std::cout << "Exiting...";
        exit(0);
    }
}