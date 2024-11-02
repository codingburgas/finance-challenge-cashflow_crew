#include "User.h"
#include <iostream>

using namespace std;

User::User(const string& uname, const string& pass) 
    : username(uname), password(pass) {}

string User::getUsername() const {
    return username;
}

string User::getPassword() const {
    return password;
}

void User::addIncome(const FinancialRecord& record) {
    incomes.push_back(record);
}

void User::addExpense(const FinancialRecord& record) {
    expenses.push_back(record);
}

void User::generateReport() {
    cout << "Income and Expense Report:" << endl;
    for (const auto& income : incomes) {
        cout << "Income: " << income.getCategory() << " - " << income.getAmount() << " USD" << endl;
    }
    for (const auto& expense : expenses) {
        cout << "Expense: " << expense.getCategory() << " - " << expense.getAmount() << " USD" << endl;
    }
}