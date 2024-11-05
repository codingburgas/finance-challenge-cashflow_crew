#include "FinanceApp.h"

using namespace std;

int main() {
    FinanceApp app;
    app.registerUser("john_doe", "password123");
    app.loginUser("john_doe", "password123");

    app.addIncome("2024-10-27", "Salary", 2000.00);
    app.addExpense("2024-10-28", "Food", 50.00);

    app.generateReport();

    return 0;
}