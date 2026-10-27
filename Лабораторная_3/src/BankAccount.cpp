#include "BankAccount.h"

#include <iostream>
#include <stdexcept>

BankAccount::BankAccount(const std::string& owner)
    : owner_(owner), balance_() {
    if (owner_.empty()) {
        throw std::invalid_argument(
            "Имя владельца не может быть пустым"
        );
    }

    addHistory("Счёт открыт");
}

BankAccount::BankAccount(
    const std::string& owner,
    const Money& initialBalance
)
    : owner_(owner), balance_(initialBalance) {
    if (owner_.empty()) {
        throw std::invalid_argument(
            "Имя владельца не может быть пустым"
        );
    }

    addHistory(
        "Счёт открыт. Начальный баланс: " + balance_.toString()
    );
}

const std::string& BankAccount::getOwner() const {
    return owner_;
}

const Money& BankAccount::getBalance() const {
    return balance_;
}

void BankAccount::addHistory(const std::string& operation) {
    history_.push_back(operation);
}

void BankAccount::showHistory() const {
    std::cout << "\nИстория операций счёта " << owner_ << ":\n";

    if (history_.empty()) {
        std::cout << "Операций пока нет.\n";
        return;
    }

    for (std::size_t i = 0; i < history_.size(); ++i) {
        std::cout << i + 1 << ". " << history_[i] << '\n';
    }
}

void BankAccount::deposit(const Money& amount) {
    if (amount.getKopecks() <= 0) {
        throw std::invalid_argument(
            "Зачисляемая сумма должна быть положительной"
        );
    }

    Money newBalance = balance_ + amount;
    balance_ = newBalance;

    addHistory("Зачислено: " + amount.toString());
}

void BankAccount::withdraw(const Money& amount) {
    if (amount.getKopecks() <= 0) {
        throw std::invalid_argument(
            "Сумма расхода должна быть положительной"
        );
    }

    Money newBalance = balance_ - amount;
    balance_ = newBalance;

    addHistory("Снято: " + amount.toString());
}

void BankAccount::transferTo(
    BankAccount& recipient,
    const Money& amount
) {
    if (this == &recipient) {
        throw std::invalid_argument(
            "Нельзя перевести деньги на тот же счёт"
        );
    }

    if (amount.getKopecks() <= 0) {
        throw std::invalid_argument(
            "Сумма перевода должна быть положительной"
        );
    }

    Money newSenderBalance = balance_ - amount;
    Money newRecipientBalance = recipient.balance_ + amount;

    balance_ = newSenderBalance;
    recipient.balance_ = newRecipientBalance;

    addHistory(
        "Перевод на счёт " + recipient.owner_ + ": " + amount.toString()
    );

    recipient.addHistory(
        "Получен перевод от " + owner_ + ": " + amount.toString()
    );
}