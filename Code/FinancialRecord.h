#ifndef FINANCIALRECORD_H
#define FINANCIALRECORD_H

#include <string>

class FinancialRecord {
private:
    std::string date;
    std::string category;
    double amount;
public:
    FinancialRecord(const std::string& d, const std::string& cat, double amt);
    std::string getCategory() const;
    double getAmount() const;
};

#endif