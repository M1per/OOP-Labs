#ifndef MONEY_H
#define MONEY_H

#include <cstdint>
#include <string>

/**
 * @brief Класс для представления денежных сумм в рублях и копейках.
 *
 * Хранит сумму в копейках и поддерживает арифметические операции,
 * сравнение, копирование и получение информации о количестве объектов.
 */
class Money {
private:
    /// @brief Денежная сумма, хранящаяся в копейках.
    std::int64_t kopecks_;

    /// @brief Счётчик обращений к объекту, изменяемый даже у const-объекта.
    mutable unsigned int accessCount_;

    /// @brief Количество существующих объектов Money.
    static unsigned int objectCount_;

public:
    /**
     * @brief Создаёт денежную сумму, равную нулю.
     */
    Money();

    /**
     * @brief Создаёт денежную сумму из копеек.
     * @param kopecks Количество копеек.
     */
    explicit Money(std::int64_t kopecks);

    /**
     * @brief Создаёт денежную сумму из рублей и копеек.
     * @param rubles Количество рублей.
     * @param kopecks Количество копеек.
     */
    Money(std::int64_t rubles, std::int64_t kopecks);

    /**
     * @brief Создаёт копию существующего денежного объекта.
     * @param other Объект для копирования.
     */
    Money(const Money& other);

    /**
     * @brief Присваивает объекту сумму другого объекта.
     * @param other Объект, из которого копируются данные.
     * @return Ссылка на текущий объект.
     */
    Money& operator=(const Money& other);

    /**
     * @brief Уничтожает объект и обновляет счётчик объектов.
     */
    ~Money();

    /**
     * @brief Возвращает денежную сумму в копейках.
     * @return Количество копеек.
     */
    std::int64_t getKopecks() const;

    /**
     * @brief Возвращает целое количество рублей.
     * @return Количество рублей.
     */
    std::int64_t getRubles() const;

    /**
     * @brief Возвращает остаток копеек после выделения рублей.
     * @return Количество копеек от 0 до 99.
     */
    std::int64_t getRemainderKopecks() const;

    /**
     * @brief Возвращает количество обращений к объекту.
     * @return Счётчик обращений.
     */
    unsigned int getAccessCount() const;

    /**
     * @brief Форматирует денежную сумму для вывода.
     * @return Строка с денежной суммой.
     */
    std::string toString() const;

    /**
     * @brief Увеличивает сумму на одну копейку.
     * @return Ссылка на изменённый объект.
     */
    Money& operator++();

    /**
     * @brief Увеличивает сумму на одну копейку и возвращает старое значение.
     * @param Не используется; отличает постфиксную форму оператора.
     * @return Копия суммы до увеличения.
     */
    Money operator++(int);

    /**
     * @brief Уменьшает сумму на одну копейку.
     * @return Ссылка на изменённый объект.
     */
    Money& operator--();

    /**
     * @brief Уменьшает сумму на одну копейку и возвращает старое значение.
     * @param Не используется; отличает постфиксную форму оператора.
     * @return Копия суммы до уменьшения.
     */
    Money operator--(int);

    /**
     * @brief Прибавляет денежную сумму другого объекта.
     * @param other Прибавляемая сумма.
     * @return Ссылка на текущий объект.
     */
    Money& operator+=(const Money& other);

    /**
     * @brief Вычитает денежную сумму другого объекта.
     * @param other Вычитаемая сумма.
     * @return Ссылка на текущий объект.
     */
    Money& operator-=(const Money& other);

    /**
     * @brief Умножает денежную сумму на целое число.
     * @param multiplier Множитель.
     * @return Ссылка на текущий объект.
     */
    Money& operator*=(std::int64_t multiplier);

    /**
     * @brief Делит денежную сумму на целое число.
     * @param divisor Делитель.
     * @return Ссылка на текущий объект.
     */
    Money& operator/=(std::int64_t divisor);

    /**
     * @brief Складывает две денежные суммы.
     * @param lhs Первая сумма.
     * @param rhs Вторая сумма.
     * @return Результат сложения.
     */
    friend Money operator+(Money lhs, const Money& rhs);

    /**
     * @brief Вычитает одну денежную сумму из другой.
     * @param lhs Уменьшаемая сумма.
     * @param rhs Вычитаемая сумма.
     * @return Результат вычитания.
     */
    friend Money operator-(Money lhs, const Money& rhs);

    /**
     * @brief Умножает денежную сумму на целое число.
     * @param lhs Денежная сумма.
     * @param multiplier Множитель.
     * @return Результат умножения.
     */
    friend Money operator*(Money lhs, std::int64_t multiplier);

    /**
     * @brief Умножает целое число на денежную сумму.
     * @param multiplier Множитель.
     * @param rhs Денежная сумма.
     * @return Результат умножения.
     */
    friend Money operator*(std::int64_t multiplier, Money rhs);

    /**
     * @brief Делит денежную сумму на целое число.
     * @param lhs Денежная сумма.
     * @param divisor Делитель.
     * @return Результат деления.
     */
    friend Money operator/(Money lhs, std::int64_t divisor);

    /**
     * @brief Проверяет, меньше ли текущая сумма другой суммы.
     * @param other Сравниваемая сумма.
     * @return true, если текущая сумма меньше.
     */
    bool operator<(const Money& other) const;

    /**
     * @brief Проверяет, больше ли текущая сумма другой суммы.
     * @param other Сравниваемая сумма.
     * @return true, если текущая сумма больше.
     */
    bool operator>(const Money& other) const;

    /**
     * @brief Проверяет, меньше ли или равна текущая сумма другой сумме.
     * @param other Сравниваемая сумма.
     * @return true, если условие выполняется.
     */
    bool operator<=(const Money& other) const;

    /**
     * @brief Проверяет, больше ли или равна текущая сумма другой сумме.
     * @param other Сравниваемая сумма.
     * @return true, если условие выполняется.
     */
    bool operator>=(const Money& other) const;

    /**
     * @brief Проверяет равенство денежных сумм.
     * @param other Сравниваемая сумма.
     * @return true, если суммы равны.
     */
    bool operator==(const Money& other) const;

    /**
     * @brief Проверяет неравенство денежных сумм.
     * @param other Сравниваемая сумма.
     * @return true, если суммы не равны.
     */
    bool operator!=(const Money& other) const;

    /**
     * @brief Возвращает количество существующих объектов Money.
     * @return Количество объектов.
     */
    static unsigned int getObjectCount();
};

#endif