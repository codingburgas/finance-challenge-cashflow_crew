#ifndef USER_H
#define USER_H

#include "FinancialRecord.h"
#include <vector>
#include <string>

class User {
private:
    std::string username;
    std::string password;
    std::vector<FinancialRecord> incomes;
    std::vector<FinancialRecord> expenses;
public:
    User(const std::string& uname, const std::string& pass);
    std::string getUsername() const;
    std::string getPassword() const;
    void addIncome(const FinancialRecord& record);
    void addExpense(const FinancialRecord& record);
    void generateReport();
};

#endif