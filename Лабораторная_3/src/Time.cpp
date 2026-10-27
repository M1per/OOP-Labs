#include "Time.h"

#include <iomanip>
#include <ostream>
#include <sstream>
#include <stdexcept>

/** Инициализация общего счётчика объектов. */
int Time::objectCount = 0;

/**
 * @brief Нормализует время в пределах одних суток.
 * @param seconds Исходное количество секунд.
 * @return Количество секунд в диапазоне [0, 86399].
 */
int Time::normalize(int seconds) {
    const int secondsPerDay = 24 * 60 * 60;
    seconds %= secondsPerDay;

    if (seconds < 0) {
        seconds += secondsPerDay;
    }

    return seconds;
}

/**
 * @brief Создаёт объект с нулевым временем.
 */
Time::Time()
    : totalSeconds(0), accessCount(0) {
    ++objectCount;
}

/**
 * @brief Создаёт объект по количеству секунд.
 * @param seconds Количество секунд.
 */
Time::Time(int seconds)
    : totalSeconds(normalize(seconds)), accessCount(0) {
    ++objectCount;
}

/**
 * @brief Создаёт объект по часам, минутам и секундам.
 * @param hours Часы.
 * @param minutes Минуты.
 * @param seconds Секунды.
 * @throws std::invalid_argument При некорректных значениях.
 */
Time::Time(int hours, int minutes, int seconds)
    : totalSeconds(normalize(hours * 3600 + minutes * 60 + seconds)),
      accessCount(0) {
    if (hours < 0 || hours >= 24 ||
        minutes < 0 || minutes >= 60 ||
        seconds < 0 || seconds >= 60) {
        throw std::invalid_argument("Некорректное значение времени");
    }

    ++objectCount;
}

/**
 * @brief Уничтожает объект и обновляет счётчик.
 */
Time::~Time() {
    --objectCount;
}

/**
 * @brief Возвращает часы и увеличивает счётчик обращений.
 * @return Часы.
 */
int Time::getHours() const {
    ++accessCount;
    return totalSeconds / 3600;
}

/**
 * @brief Возвращает минуты и увеличивает счётчик обращений.
 * @return Минуты.
 */
int Time::getMinutes() const {
    ++accessCount;
    return (totalSeconds % 3600) / 60;
}

/**
 * @brief Возвращает секунды и увеличивает счётчик обращений.
 * @return Секунды.
 */
int Time::getSeconds() const {
    ++accessCount;
    return totalSeconds % 60;
}

/**
 * @brief Возвращает общее количество секунд.
 * @return Количество секунд.
 */
int Time::getTotalSeconds() const {
    ++accessCount;
    return totalSeconds;
}

/**
 * @brief Возвращает количество обращений к объекту.
 * @return Счётчик обращений.
 */
unsigned int Time::getAccessCount() const {
    return accessCount;
}

/**
 * @brief Формирует строковое представление времени.
 * @return Строка HH:MM:SS.
 */
std::string Time::toString() const {
    ++accessCount;

    std::ostringstream out;
    out << std::setfill('0')
        << std::setw(2) << totalSeconds / 3600 << ':'
        << std::setw(2) << (totalSeconds % 3600) / 60 << ':'
        << std::setw(2) << totalSeconds % 60;

    return out.str();
}

/**
 * @brief Префиксный инкремент.
 * @return Ссылка на изменённый объект.
 */
Time& Time::operator++() {
    totalSeconds = normalize(totalSeconds + 1);
    return *this;
}

/**
 * @brief Постфиксный инкремент.
 * @param dummy Неиспользуемый параметр.
 * @return Предыдущее значение времени.
 */
Time Time::operator++(int) {
    Time previous(*this);
    ++(*this);
    return previous;
}

/**
 * @brief Префиксный декремент.
 * @return Ссылка на изменённый объект.
 */
Time& Time::operator--() {
    totalSeconds = normalize(totalSeconds - 1);
    return *this;
}

/**
 * @brief Постфиксный декремент.
 * @param dummy Неиспользуемый параметр.
 * @return Предыдущее значение времени.
 */
Time Time::operator--(int) {
    Time previous(*this);
    --(*this);
    return previous;
}

/**
 * @brief Составное сложение.
 * @param other Второе время.
 * @return Ссылка на изменённый объект.
 */
Time& Time::operator+=(const Time& other) {
    totalSeconds = normalize(totalSeconds + other.totalSeconds);
    return *this;
}

/**
 * @brief Составное вычитание.
 * @param other Второе время.
 * @return Ссылка на изменённый объект.
 */
Time& Time::operator-=(const Time& other) {
    totalSeconds = normalize(totalSeconds - other.totalSeconds);
    return *this;
}

/**
 * @brief Составное умножение.
 * @param other Второе время.
 * @return Ссылка на изменённый объект.
 */
Time& Time::operator*=(const Time& other) {
    totalSeconds = normalize(totalSeconds * other.totalSeconds);
    return *this;
}

/**
 * @brief Составное деление.
 * @param other Делитель.
 * @return Ссылка на изменённый объект.
 * @throws std::invalid_argument Если делитель равен нулю.
 */
Time& Time::operator/=(const Time& other) {
    if (other.totalSeconds == 0) {
        throw std::invalid_argument("Деление на нулевое время");
    }

    totalSeconds = normalize(totalSeconds / other.totalSeconds);
    return *this;
}

/**
 * @brief Оператор сложения.
 * @param lhs Первое время.
 * @param rhs Второе время.
 * @return Результат сложения.
 */
Time operator+(Time lhs, const Time& rhs) {
    lhs += rhs;
    return lhs;
}

/**
 * @brief Оператор вычитания.
 * @param lhs Первое время.
 * @param rhs Второе время.
 * @return Результат вычитания.
 */
Time operator-(Time lhs, const Time& rhs) {
    lhs -= rhs;
    return lhs;
}

/**
 * @brief Оператор умножения.
 * @param lhs Первое время.
 * @param rhs Второе время.
 * @return Результат умножения.
 */
Time operator*(Time lhs, const Time& rhs) {
    lhs *= rhs;
    return lhs;
}

/**
 * @brief Оператор деления.
 * @param lhs Делимое.
 * @param rhs Делитель.
 * @return Результат деления.
 */
Time operator/(Time lhs, const Time& rhs) {
    lhs /= rhs;
    return lhs;
}

/** @brief Сравнивает два времени на меньше. */
bool Time::operator<(const Time& other) const {
    return totalSeconds < other.totalSeconds;
}

/** @brief Сравнивает два времени на больше. */
bool Time::operator>(const Time& other) const {
    return totalSeconds > other.totalSeconds;
}

/** @brief Проверяет условие меньше или равно. */
bool Time::operator<=(const Time& other) const {
    return totalSeconds <= other.totalSeconds;
}

/** @brief Проверяет условие больше или равно. */
bool Time::operator>=(const Time& other) const {
    return totalSeconds >= other.totalSeconds;
}

/** @brief Проверяет равенство времён. */
bool Time::operator==(const Time& other) const {
    return totalSeconds == other.totalSeconds;
}

/** @brief Проверяет неравенство времён. */
bool Time::operator!=(const Time& other) const {
    return totalSeconds != other.totalSeconds;
}

/**
 * @brief Возвращает количество существующих объектов.
 * @return Значение статического счётчика.
 */
int Time::getObjectCount() {
    return objectCount;
}

/**
 * @brief Выводит время в формате HH:MM:SS.
 * @param out Поток вывода.
 * @param time Объект времени.
 * @return Ссылка на поток вывода.
 */
std::ostream& operator<<(std::ostream& out, const Time& time) {
    return out << time.toString();
}