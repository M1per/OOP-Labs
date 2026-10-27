#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include "Money.h"

#include <string>
#include <vector>

/**
 * @brief Класс банковского счёта.
 *
 * Хранит имя владельца, баланс и историю операций.
 * Поддерживает пополнение, снятие и перевод денежных средств.
 */
class BankAccount {
private:
    /// @brief Имя владельца счёта.
    std::string owner_;

    /// @brief Текущий баланс счёта.
    Money balance_;

    /// @brief История операций по счёту.
    std::vector<std::string> history_;

    /**
     * @brief Добавляет запись в историю операций.
     * @param operation Описание выполненной операции.
     */
    void addHistory(const std::string& operation);

public:
    /**
     * @brief Создаёт счёт с нулевым балансом.
     * @param owner Имя владельца счёта.
     */
    explicit BankAccount(const std::string& owner);

    /**
     * @brief Создаёт счёт с заданным начальным балансом.
     * @param owner Имя владельца счёта.
     * @param initialBalance Начальный баланс.
     */
    BankAccount(const std::string& owner, const Money& initialBalance);

    /**
     * @brief Возвращает имя владельца счёта.
     * @return Имя владельца.
     */
    const std::string& getOwner() const;

    /**
     * @brief Возвращает текущий баланс счёта.
     * @return Константная ссылка на баланс.
     */
    const Money& getBalance() const;

    /**
     * @brief Выводит историю операций счёта.
     */
    void showHistory() const;

    /**
     * @brief Пополняет банковский счёт.
     * @param amount Сумма пополнения.
     */
    void deposit(const Money& amount);

    /**
     * @brief Снимает деньги с банковского счёта.
     * @param amount Сумма снятия.
     */
    void withdraw(const Money& amount);

    /**
     * @brief Переводит деньги на другой банковский счёт.
     * @param recipient Счёт получателя.
     * @param amount Сумма перевода.
     */
    void transferTo(BankAccount& recipient, const Money& amount);
};

#endif