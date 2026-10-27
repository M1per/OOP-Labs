#include "Time.h"

#include <iomanip>
#include <ostream>
#include <sstream>
#include <stdexcept>

/**
 * @brief Количество существующих объектов класса Time.
 */
int Time::objectCount = 0;

/**
 * @brief Нормализует время в пределах одних суток.
 * @param seconds Исходное количество секунд.
 * @return Количество секунд в диапазоне от 0 до 86399.
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
 * @throws std::invalid_argument При некорректных значениях времени.
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
 * @return Количество часов.
 */
int Time::getHours() const {
    ++accessCount;
    return totalSeconds / 3600;
}

/**
 * @brief Возвращает минуты и увеличивает счётчик обращений.
 * @return Количество минут.
 */
int Time::getMinutes() const {
    ++accessCount;
    return (totalSeconds % 3600) / 60;
}

/**
 * @brief Возвращает секунды и увеличивает счётчик обращений.
 * @return Количество секунд.
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
 * @return Строка в формате HH:MM:SS.
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
 * @brief Выполняет префиксный инкремент времени.
 * @return Ссылка на изменённый объект.
 */
Time& Time::operator++() {
    totalSeconds = normalize(totalSeconds + 1);
    return *this;
}

/**
 * @brief Выполняет постфиксный инкремент времени.
 * @return Копия времени до изменения.
 */
Time Time::operator++(int) {
    Time previous(*this);
    ++(*this);
    return previous;
}

/**
 * @brief Выполняет префиксный декремент времени.
 * @return Ссылка на изменённый объект.
 */
Time& Time::operator--() {
    totalSeconds = normalize(totalSeconds - 1);
    return *this;
}

/**
 * @brief Выполняет постфиксный декремент времени.
 * @return Копия времени до изменения.
 */
Time Time::operator--(int) {
    Time previous(*this);
    --(*this);
    return previous;
}

/**
 * @brief Прибавляет другое время к текущему.
 * @param other Второе время.
 * @return Ссылка на изменённый объект.
 */
Time& Time::operator+=(const Time& other) {
    totalSeconds = normalize(totalSeconds + other.totalSeconds);
    return *this;
}

/**
 * @brief Вычитает другое время из текущего.
 * @param other Вычитаемое время.
 * @return Ссылка на изменённый объект.
 */
Time& Time::operator-=(const Time& other) {
    totalSeconds = normalize(totalSeconds - other.totalSeconds);
    return *this;
}

/**
 * @brief Умножает текущее время на другое.
 * @param other Второе время.
 * @return Ссылка на изменённый объект.
 */
Time& Time::operator*=(const Time& other) {
    totalSeconds = normalize(totalSeconds * other.totalSeconds);
    return *this;
}

/**
 * @brief Делит текущее время на другое.
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
 * @brief Складывает два значения времени.
 * @param lhs Первое время.
 * @param rhs Второе время.
 * @return Результат сложения.
 */
Time operator+(Time lhs, const Time& rhs) {
    lhs += rhs;
    return lhs;
}

/**
 * @brief Вычитает второе время из первого.
 * @param lhs Первое время.
 * @param rhs Второе время.
 * @return Результат вычитания.
 */
Time operator-(Time lhs, const Time& rhs) {
    lhs -= rhs;
    return lhs;
}

/**
 * @brief Умножает два значения времени.
 * @param lhs Первое время.
 * @param rhs Второе время.
 * @return Результат умножения.
 */
Time operator*(Time lhs, const Time& rhs) {
    lhs *= rhs;
    return lhs;
}

/**
 * @brief Делит первое время на второе.
 * @param lhs Делимое.
 * @param rhs Делитель.
 * @return Результат деления.
 * @throws std::invalid_argument Если делитель равен нулю.
 */
Time operator/(Time lhs, const Time& rhs) {
    lhs /= rhs;
    return lhs;
}

/**
 * @brief Проверяет, меньше ли текущее время указанного.
 * @param other Время для сравнения.
 * @return true, если текущее время меньше.
 */
bool Time::operator<(const Time& other) const {
    return totalSeconds < other.totalSeconds;
}

/**
 * @brief Проверяет, больше ли текущее время указанного.
 * @param other Время для сравнения.
 * @return true, если текущее время больше.
 */
bool Time::operator>(const Time& other) const {
    return totalSeconds > other.totalSeconds;
}

/**
 * @brief Проверяет, меньше ли текущее время указанного или равно ему.
 * @param other Время для сравнения.
 * @return true, если текущее время меньше или равно.
 */
bool Time::operator<=(const Time& other) const {
    return totalSeconds <= other.totalSeconds;
}

/**
 * @brief Проверяет, больше ли текущее время указанного или равно ему.
 * @param other Время для сравнения.
 * @return true, если текущее время больше или равно.
 */
bool Time::operator>=(const Time& other) const {
    return totalSeconds >= other.totalSeconds;
}

/**
 * @brief Проверяет равенство двух значений времени.
 * @param other Время для сравнения.
 * @return true, если времена равны.
 */
bool Time::operator==(const Time& other) const {
    return totalSeconds == other.totalSeconds;
}

/**
 * @brief Проверяет неравенство двух значений времени.
 * @param other Время для сравнения.
 * @return true, если времена не равны.
 */
bool Time::operator!=(const Time& other) const {
    return totalSeconds != other.totalSeconds;
}

/**
 * @brief Возвращает количество существующих объектов Time.
 * @return Количество объектов.
 */
int Time::getObjectCount() {
    return objectCount;
}

/**
 * @brief Выводит время в поток.
 * @param out Поток вывода.
 * @param time Выводимое время.
 * @return Ссылка на поток вывода.
 */
std::ostream& operator<<(std::ostream& out, const Time& time) {
    out << std::setfill('0')
        << std::setw(2) << time.totalSeconds / 3600 << ':'
        << std::setw(2) << (time.totalSeconds % 3600) / 60 << ':'
        << std::setw(2) << time.totalSeconds % 60;

    return out;
}