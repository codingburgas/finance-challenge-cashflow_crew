#include "budget.h"
#include "report.h"

void budget() {
	std::cout << "\033[2J\033[1;1H"; //clears the screen
	std::cout << R"(
-------------------------------------------------------------
$$$$$$$\                  $$\                      $$\     
$$  __$$\                 $$ |                     $$ |    
$$ |  $$ |$$\   $$\  $$$$$$$ | $$$$$$\   $$$$$$\ $$$$$$\   
$$$$$$$\ |$$ |  $$ |$$  __$$ |$$  __$$\ $$  __$$\\_$$  _|  
$$  __$$\ $$ |  $$ |$$ /  $$ |$$ /  $$ |$$$$$$$$ | $$ |    
$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |$$   ____| $$ |$$\ 
$$$$$$$  |\$$$$$$  |\$$$$$$$ |\$$$$$$$ |\$$$$$$$\  \$$$$  |
\_______/  \______/  \_______| \____$$ | \_______|  \____/ 
                              $$\   $$ |                   
                              \$$$$$$  |                   
                               \______/                    
-------------------------------------------------------------

  
    )" << "\n";
	int days;
	double budget, dailyExpense;
	std::cout << "Enter the number of days for which you want to save money:" << "\n";
	std::cin >> days;
	std::cout << "Enter the budget amount: " << "\n";
	std::cin >> budget;
	dailyExpense = budget / days;
	std::cout << "You would need to spend no more than: " << dailyExpense << "$ a day" << "\n" << "\n";
	double sumExp, sumRev;
	std::ifstream inputRevFile("Revenues.txt");
	inputRevFile >> sumRev; // Read the number from the file
	inputRevFile.close();   // Close the file
	std::ifstream inputExpFile("Expenses.txt");
	inputExpFile >> sumExp; // Read the number from the file
	inputExpFile.close();   // Close the file
	if (sumRev < sumExp) {
		std::cout << "You are spending more than your income." << "\n";
		std::cout << "Try to spend less money, or find a way to increase your income." << "\n";
	}
	else {
		std::cout << "You can spend " << (sumRev/days) - dailyExpense << " a day freely." << "\n";
	}
	std::cout << "\n";
	int choice;
	std::cout << "1.Continue\n2.Exit\n";
	std::cout << "Enter choice:";
	std::cin >> choice;
	if (choice == 1) {
		report();
	}
	else {
		std::cout << "Exiting...";
		exit(0);
	}
}