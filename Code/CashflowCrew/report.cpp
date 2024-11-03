#include "report.h"
#include "budget.h"

void report() {
    std::cout << "\033[2J\033[1;1H"; // Clears the screen

    std::cout << R"(
------------------------------------------------------------
$$$$$$$\                                           $$\     
$$  __$$\                                          $$ |    
$$ |  $$ | $$$$$$\   $$$$$$\   $$$$$$\   $$$$$$\ $$$$$$\   
$$$$$$$  |$$  __$$\ $$  __$$\ $$  __$$\ $$  __$$\\_$$  _|  
$$  __$$< $$$$$$$$ |$$ /  $$ |$$ /  $$ |$$ |  \__| $$ |    
$$ |  $$ |$$   ____|$$ |  $$ |$$ |  $$ |$$ |       $$ |$$\ 
$$ |  $$ |\$$$$$$$\ $$$$$$$  |\$$$$$$  |$$ |       \$$$$  |
\__|  \__| \_______|$$  ____/  \______/ \__|        \____/ 
                    $$ |                                   
                    $$ |                                   
                    \__|                                   
------------------------------------------------------------
                                                                                                  
    )" << "\n";

    std::cout << "Your revenues:" << "\n";

    std::string revenue;
    double revnum;
    int num;

    std::ofstream revDataFile;
    std::ifstream inputRevFile("Revenues.txt");
    inputRevFile >> num;
    for(int i=0; i<num; i++){
        inputRevFile >> revenue;
        inputRevFile >> revnum;
        std::cout << revenue << " " << revnum << "\n";
    }
    inputRevFile.close();   // Close the file

    


    std::cout << "\nYour expenses:" << "\n";

    std::string expense;
    double expnum;

    std::ofstream expDataFile;
    std::ifstream inputExpFile("Expenses.txt");
    inputExpFile >> num;
    for (int i = 0; i < num; i++) {
        inputExpFile >> expense;
        inputExpFile >> expnum;
        std::cout << expense << " " << expnum << "\n";
    }
    inputExpFile.close();   // Close the file

    
    exit(0);
}