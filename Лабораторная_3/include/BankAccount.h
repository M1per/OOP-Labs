#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include "Money.h"

#include <string>
#include <vector>

class BankAccount {
private:
    std::string owner_;
    Money balance_;
    std::vector<std::string> history_;

    void addHistory(const std::string& operation);

public:
    explicit BankAccount(const std::string& owner);
    BankAccount(const std::string& owner, const Money& initialBalance);

    const std::string& getOwner() const;
    const Money& getBalance() const;

    void showHistory() const;

    void deposit(const Money& amount);
    void withdraw(const Money& amount);
    void transferTo(BankAccount& recipient, const Money& amount);
};

#endif