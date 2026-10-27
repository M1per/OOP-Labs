#ifndef TIME_H
#define TIME_H

#include <iosfwd>
#include <string>

/**
 * @brief Класс для хранения и обработки времени суток.
 *
 * Время хранится в секундах от начала суток.
 * Значение автоматически нормализуется в диапазоне
 * от 00:00:00 до 23:59:59.
 *
 * Класс поддерживает арифметические операции, сравнение,
 * инкремент, декремент и подсчёт количества обращений
 * к некоторым методам.
 */
class Time {
private:
    /** Общее количество секунд от начала суток. */
    int totalSeconds;

    /**
     * @brief Счётчик обращений к объекту.
     *
     * Ключевое слово mutable позволяет изменять счётчик
     * даже внутри константных методов.
     */
    mutable unsigned int accessCount;

    /** Количество существующих объектов класса Time. */
    static int objectCount;

    /**
     * @brief Приводит количество секунд к диапазону одних суток.
     * @param seconds Исходное количество секунд.
     * @return Нормализованное количество секунд.
     */
    static int normalize(int seconds);

public:
    /**
     * @brief Создаёт объект со временем 00:00:00.
     */
    Time();

    /**
     * @brief Создаёт время по общему количеству секунд.
     * @param seconds Количество секунд.
     *
     * Отрицательные значения и значения больше суток
     * автоматически нормализуются.
     */
    explicit Time(int seconds);

    /**
     * @brief Создаёт время по часам, минутам и секундам.
     * @param hours Часы от 0 до 23.
     * @param minutes Минуты от 0 до 59.
     * @param seconds Секунды от 0 до 59.
     * @throws std::invalid_argument При некорректных значениях.
     */
    Time(int hours, int minutes, int seconds);

    /**
     * @brief Уничтожает объект времени.
     *
     * Уменьшает общий счётчик существующих объектов.
     */
    ~Time();

    /**
     * @brief Возвращает часы.
     * @return Часы от 0 до 23.
     */
    int getHours() const;

    /**
     * @brief Возвращает минуты.
     * @return Минуты от 0 до 59.
     */
    int getMinutes() const;

    /**
     * @brief Возвращает секунды.
     * @return Секунды от 0 до 59.
     */
    int getSeconds() const;

    /**
     * @brief Возвращает общее количество секунд.
     * @return Количество секунд от начала суток.
     */
    int getTotalSeconds() const;

    /**
     * @brief Возвращает количество обращений к объекту.
     * @return Значение счётчика обращений.
     */
    unsigned int getAccessCount() const;

    /**
     * @brief Преобразует время в строку.
     * @return Строка в формате HH:MM:SS.
     */
    std::string toString() const;

    /**
     * @brief Увеличивает время на одну секунду.
     * @return Ссылка на текущий объект.
     */
    Time& operator++();

    /**
     * @brief Постфиксно увеличивает время на одну секунду.
     * @param dummy Неиспользуемый параметр, отличающий постфиксную форму.
     * @return Копия времени до увеличения.
     */
    Time operator++(int);

    /**
     * @brief Уменьшает время на одну секунду.
     * @return Ссылка на текущий объект.
     */
    Time& operator--();

    /**
     * @brief Постфиксно уменьшает время на одну секунду.
     * @param dummy Неиспользуемый параметр, отличающий постфиксную форму.
     * @return Копия времени до уменьшения.
     */
    Time operator--(int);

    /**
     * @brief Прибавляет другое время к текущему.
     * @param other Второе время.
     * @return Ссылка на текущий объект.
     */
    Time& operator+=(const Time& other);

    /**
     * @brief Вычитает другое время из текущего.
     * @param other Второе время.
     * @return Ссылка на текущий объект.
     */
    Time& operator-=(const Time& other);

    /**
     * @brief Умножает текущее время на другое время.
     * @param other Второе время.
     * @return Ссылка на текущий объект.
     */
    Time& operator*=(const Time& other);

    /**
     * @brief Делит текущее время на другое время.
     * @param other Делитель.
     * @return Ссылка на текущий объект.
     * @throws std::invalid_argument Если делитель равен нулю.
     */
    Time& operator/=(const Time& other);

    /**
     * @brief Оператор сложения.
     * @param lhs Первое время.
     * @param rhs Второе время.
     * @return Результат сложения.
     */
    friend Time operator+(Time lhs, const Time& rhs);

    /**
     * @brief Оператор вычитания.
     * @param lhs Первое время.
     * @param rhs Второе время.
     * @return Результат вычитания.
     */
    friend Time operator-(Time lhs, const Time& rhs);

    /**
     * @brief Оператор умножения.
     * @param lhs Первое время.
     * @param rhs Второе время.
     * @return Результат умножения.
     */
    friend Time operator*(Time lhs, const Time& rhs);

    /**
     * @brief Оператор деления.
     * @param lhs Делимое.
     * @param rhs Делитель.
     * @return Результат деления.
     */
    friend Time operator/(Time lhs, const Time& rhs);

    /**
     * @brief Проверяет, меньше ли текущее время другого.
     * @param other Второе время.
     * @return true, если текущее время меньше.
     */
    bool operator<(const Time& other) const;

    /**
     * @brief Проверяет, больше ли текущее время другого.
     * @param other Второе время.
     * @return true, если текущее время больше.
     */
    bool operator>(const Time& other) const;

    /**
     * @brief Проверяет, меньше ли время или равно другому.
     * @param other Второе время.
     * @return true, если условие выполняется.
     */
    bool operator<=(const Time& other) const;

    /**
     * @brief Проверяет, больше ли время или равно другому.
     * @param other Второе время.
     * @return true, если условие выполняется.
     */
    bool operator>=(const Time& other) const;

    /**
     * @brief Проверяет равенство двух времён.
     * @param other Второе время.
     * @return true, если времена равны.
     */
    bool operator==(const Time& other) const;

    /**
     * @brief Проверяет неравенство двух времён.
     * @param other Второе время.
     * @return true, если времена различаются.
     */
    bool operator!=(const Time& other) const;

    /**
     * @brief Возвращает количество существующих объектов.
     * @return Текущее значение общего счётчика.
     */
    static int getObjectCount();

    /**
     * @brief Выводит время в поток.
     * @param out Поток вывода.
     * @param time Объект времени.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& out, const Time& time);
};

#endif