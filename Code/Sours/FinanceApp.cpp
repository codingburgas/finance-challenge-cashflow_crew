#include "FinanceApp.h"
#include <iostream>

using namespace std;

void FinanceApp::registerUser(const string& username, const string& password) {
    users.push_back(User(username, password));
}

void FinanceApp::loginUser(const string& username, const string& password) {
    for (auto& user : users) {
        if (user.getUsername() == username && user.getPassword() == password) {
            cout << "Login successful: " << username << endl;
            return;
        }
    }
    cout << "Invalid username or password." << endl;
}

void FinanceApp::addIncome(const string& date, const string& category, double amount) {
    users.back().addIncome(FinancialRecord(date, category, amount));
}

void FinanceApp::addExpense(const string& date, const string& category, double amount) {
    users.back().addExpense(FinancialRecord(date, category, amount));
}

void FinanceApp::generateReport() {
    users.back().generateReport();
}