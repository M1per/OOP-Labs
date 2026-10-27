/**
 * @file main.cpp
 * @brief Демонстрация работы класса Money и банковских счетов.
 *
 * Показывает работу конструкторов, арифметических операторов,
 * операторов сравнения, банковских операций и обработки ошибок.
 */

#include "Money.h"
#include "BankAccount.h"

#include <iostream>
#include <stdexcept>
#include <type_traits>

/**
 * @brief Главная функция программы.
 * @return 0 при успешном завершении, 1 при критической ошибке.
 */
int main() {
    try {
        std::cout << "====================================\n";
        std::cout << " Лабораторная работа № 3 по ООП\n";
        std::cout << " Вариант № 2 — Счёт в банке\n";
        std::cout << "====================================\n\n";

        std::cout << "1. Конструкторы класса Money\n";

        Money zero;
        Money amount(15000);
        Money amount2(75, 50);
        Money copiedAmount(amount2);

        std::cout << "Конструктор по умолчанию: "
                  << zero.toString() << '\n';

        std::cout << "Конструктор из копеек: "
                  << amount.toString() << '\n';

        std::cout << "Конструктор из рублей и копеек: "
                  << amount2.toString() << '\n';

        std::cout << "Копирующий конструктор: "
                  << copiedAmount.toString() << "\n\n";

        std::cout << "2. Бинарные арифметические операторы\n";

        Money a(100, 50);
        Money b(20, 25);

        std::cout << a.toString() << " + " << b.toString()
                  << " = " << (a + b).toString() << '\n';

        std::cout << a.toString() << " - " << b.toString()
                  << " = " << (a - b).toString() << '\n';

        std::cout << b.toString() << " * 3 = "
                  << (b * 3).toString() << '\n';

        std::cout << "3 * " << b.toString() << " = "
                  << (3 * b).toString() << '\n';

        std::cout << a.toString() << " / 2 = "
                  << (a / 2).toString() << "\n\n";

        std::cout << "3. Операторы составного присваивания\n";

        Money arithmetic(10000);

        arithmetic += Money(500);
        std::cout << "После += 500 копеек: "
                  << arithmetic.toString() << '\n';

        arithmetic -= Money(200);
        std::cout << "После -= 200 копеек: "
                  << arithmetic.toString() << '\n';

        arithmetic *= 2;
        std::cout << "После *= 2: "
                  << arithmetic.toString() << '\n';

        arithmetic /= 4;
        std::cout << "После /= 4: "
                  << arithmetic.toString() << "\n\n";

        std::cout << "4. Префиксные и постфиксные операторы\n";

        Money unary(1, 0);

        std::cout << "Начальная сумма: "
                  << unary.toString() << '\n';

        std::cout << "Префиксный ++: "
                  << (++unary).toString() << '\n';

        std::cout << "Постфиксный ++ (старое значение): "
                  << (unary++).toString() << '\n';

        std::cout << "После постфиксного ++: "
                  << unary.toString() << '\n';

        std::cout << "Префиксный --: "
                  << (--unary).toString() << '\n';

        std::cout << "Постфиксный -- (старое значение): "
                  << (unary--).toString() << '\n';

        std::cout << "После постфиксного --: "
                  << unary.toString() << "\n\n";

        std::cout << "5. Операторы сравнения\n";
        std::cout << std::boolalpha;

        std::cout << "a < b: " << (a < b) << '\n';
        std::cout << "a > b: " << (a > b) << '\n';
        std::cout << "a <= b: " << (a <= b) << '\n';
        std::cout << "a >= b: " << (a >= b) << '\n';
        std::cout << "a == b: " << (a == b) << '\n';
        std::cout << "a != b: " << (a != b) << "\n\n";

        std::cout << "6. Демонстрация explicit\n";

        Money explicitMoney(500);

        std::cout << "Явное создание Money(500): "
                  << explicitMoney.toString() << '\n';

        std::cout << "Можно ли неявно преобразовать int в Money? "
                  << std::is_convertible<int, Money>::value << '\n';

        std::cout
            << "Неявное преобразование запрещено конструктором explicit.\n\n";

        std::cout << "7. Демонстрация mutable\n";

        const Money constantMoney(25, 30);

        std::cout << "Константный объект: "
                  << constantMoney.toString() << '\n';

        std::cout << "Обращений после toString(): "
                  << constantMoney.getAccessCount() << '\n';

        std::cout << "Сумма в копейках: "
                  << constantMoney.getKopecks() << '\n';

        std::cout << "Обращений после чтения: "
                  << constantMoney.getAccessCount() << "\n\n";

        std::cout << "8. Статический счётчик объектов\n";

        std::cout << "Живых объектов Money: "
                  << Money::getObjectCount() << "\n\n";

        std::cout << "9. Банковские операции\n";

        BankAccount account1("Арсений", Money(10000));
        BankAccount account2("Дмитрий", Money(5000));

        std::cout << "Начальный баланс Арсения: "
                  << account1.getBalance().toString() << '\n';

        std::cout << "Начальный баланс Дмитрия: "
                  << account2.getBalance().toString() << '\n';

        account1.deposit(Money(25, 50));

        std::cout << "\nПосле зачисления 25,50 руб. Арсению: "
                  << account1.getBalance().toString() << '\n';

        account1.withdraw(Money(10, 25));

        std::cout << "После снятия 10,25 руб.: "
                  << account1.getBalance().toString() << '\n';

        account1.transferTo(account2, Money(20, 0));

        std::cout << "\nПосле перевода 20 руб.:\n";

        std::cout << "Баланс Арсения: "
                  << account1.getBalance().toString() << '\n';

        std::cout << "Баланс Дмитрия: "
                  << account2.getBalance().toString() << '\n';

        account1.showHistory();
        account2.showHistory();

        std::cout << "\n10. Проверка обработки ошибок\n";

        try {
            Money insufficient(500);
            insufficient -= Money(1000);
        } catch (const std::exception& error) {
            std::cout << "Ошибка вычитания: "
                      << error.what() << '\n';
        }

        try {
            Money divisor(1000);
            divisor /= 0;
        } catch (const std::exception& error) {
            std::cout << "Ошибка деления: "
                      << error.what() << '\n';
        }

        try {
            BankAccount account3("Елена", Money(100));
            account3.withdraw(Money(500));
        } catch (const std::exception& error) {
            std::cout << "Ошибка банковской операции: "
                      << error.what() << '\n';
        }

        std::cout << "\nПрограмма завершила работу.\n";
    } catch (const std::exception& error) {
        std::cerr << "Критическая ошибка: "
                  << error.what() << '\n';

        return 1;
    }

    return 0;
}