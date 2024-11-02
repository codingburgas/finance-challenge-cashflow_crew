#include "FinancialRecord.h"

FinancialRecord::FinancialRecord(const std::string& d, const std::string& cat, double amt) 
    : date(d), category(cat), amount(amt) {}

std::string FinancialRecord::getCategory() const {
    return category;
}

double FinancialRecord::getAmount() const {
    return amount;
}