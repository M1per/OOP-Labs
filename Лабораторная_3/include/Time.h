/**
 * @file Time.h
 * @brief Объявление класса времени Time.
 *
 * Время хранится в секундах от начала суток и выводится в формате HH:MM:SS.
 */
#ifndef TIME_H
#define TIME_H

#include <iosfwd>
#include <string>

/**
 * @brief Класс для хранения и обработки времени суток.
 *
 * Поддерживает конструкторы, получение компонентов времени,
 * арифметические и сравнительные операторы.
 */
class Time {
private:
    int totalSeconds;                  ///< Количество секунд от начала суток.
    mutable unsigned int accessCount; ///< Счётчик вызовов методов чтения.
    static int objectCount;            ///< Количество существующих объектов.

    /**
     * @brief Приводит количество секунд к диапазону одних суток.
     * @param seconds Исходное количество секунд.
     * @return Значение в диапазоне от 0 до 86399.
     */
    static int normalize(long long seconds);

    /**
     * @brief Проверяет часы, минуты и секунды и переводит их в секунды.
     * @param hours Часы.
     * @param minutes Минуты.
     * @param seconds Секунды.
     * @return Количество секунд от начала суток.
     * @throws std::invalid_argument Если компоненты времени вне допустимого диапазона.
     */
    static int checkedSeconds(int hours, int minutes, int seconds);

public:
    /// Создаёт время 00:00:00.
    Time();

    /**
     * @brief Создаёт время из общего количества секунд.
     * @param seconds Количество секунд от начала суток.
     *
     * explicit запрещает неявное преобразование int в Time.
     */
    explicit Time(int seconds);

    /// Создаёт время из часов, минут и секунд.
    Time(int hours, int minutes, int seconds);

    /// Создаёт копию другого объекта Time.
    Time(const Time& other);

    /// Копирует значение времени из другого объекта.
    Time& operator=(const Time& other);

    /// Уменьшает счётчик существующих объектов.
    ~Time();

    /// Возвращает часы (0–23).
    int getHours() const;

    /// Возвращает минуты (0–59).
    int getMinutes() const;

    /// Возвращает секунды (0–59).
    int getSeconds() const;

    /// Возвращает полное количество секунд от начала суток.
    int getTotalSeconds() const;

    /// Возвращает количество обращений к методам чтения.
    unsigned int getAccessCount() const;

    /// Возвращает строку времени в формате HH:MM:SS.
    std::string toString() const;

    /// Префиксный инкремент: увеличивает время на одну секунду.
    Time& operator++();

    /// Постфиксный инкремент: возвращает старое значение и увеличивает время.
    Time operator++(int);

    /// Префиксный декремент: уменьшает время на одну секунду.
    Time& operator--();

    /// Постфиксный декремент: возвращает старое значение и уменьшает время.
    Time operator--(int);

    /// Сложение с изменением текущего объекта.
    Time& operator+=(const Time& other);

    /// Вычитание с изменением текущего объекта.
    Time& operator-=(const Time& other);

    /// Умножение с изменением текущего объекта.
    Time& operator*=(const Time& other);

    /// Деление с изменением текущего объекта; деление на ноль запрещено.
    Time& operator/=(const Time& other);

    /// Свободный оператор сложения.
    friend Time operator+(Time lhs, const Time& rhs);

    /// Свободный оператор вычитания.
    friend Time operator-(Time lhs, const Time& rhs);

    /// Свободный оператор умножения.
    friend Time operator*(Time lhs, const Time& rhs);

    /// Свободный оператор деления.
    friend Time operator/(Time lhs, const Time& rhs);

    /// Сравнивает времена по количеству секунд.
    bool operator<(const Time& other) const;

    /// Сравнивает времена по количеству секунд.
    bool operator>(const Time& other) const;

    /// Проверяет, меньше ли время или равно другому.
    bool operator<=(const Time& other) const;

    /// Проверяет, больше ли время или равно другому.
    bool operator>=(const Time& other) const;

    /// Проверяет равенство времени.
    bool operator==(const Time& other) const;

    /// Проверяет неравенство времени.
    bool operator!=(const Time& other) const;

    /// Возвращает количество существующих объектов Time.
    static int getObjectCount();

    /// Выводит время в поток в формате HH:MM:SS.
    friend std::ostream& operator<<(std::ostream& out, const Time& time);
};

#endif