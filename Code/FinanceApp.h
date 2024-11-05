#ifndef FINANCEAPP_H
#define FINANCEAPP_H

#include "User.h"
#include <vector>
#include <string>

class FinanceApp {
private:
    std::vector<User> users;
public:
    void registerUser(const std::string& username, const std::string& password);
    void loginUser(const std::string& username, const std::string& password);
    void addIncome(const std::string& date, const std::string& category, double amount);
    void addExpense(const std::string& date, const std::string& category, double amount);
    void generateReport();
};

#endif