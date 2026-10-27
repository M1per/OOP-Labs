/**
 * @file Time.cpp
 * @brief Реализация методов класса Time и перегруженных операторов.
 */

#include "Time.h"

#include <iomanip>
#include <ostream>
#include <sstream>
#include <stdexcept>

// Статический счётчик общий для всех объектов класса.
int Time::objectCount = 0;

// Приводит секунды к одному дню; отрицательные значения тоже нормализуются.
int Time::normalize(long long seconds) {
    const long long secondsPerDay = 24LL * 60LL * 60LL;

    seconds %= secondsPerDay;

    if (seconds < 0) {
        seconds += secondsPerDay;
    }

    return static_cast<int>(seconds);
}

// Проверяет компоненты времени и переводит их в секунды от начала суток.
int Time::checkedSeconds(int hours, int minutes, int seconds) {
    if (hours < 0 || hours >= 24 ||
        minutes < 0 || minutes >= 60 ||
        seconds < 0 || seconds >= 60) {
        throw std::invalid_argument("Некорректное значение времени");
    }

    return hours * 3600 + minutes * 60 + seconds;
}

// Конструктор по умолчанию создаёт 00:00:00.
Time::Time()
    : totalSeconds(0), accessCount(0) {
    ++objectCount;
}

// Конструктор из общего количества секунд.
Time::Time(int seconds)
    : totalSeconds(normalize(seconds)), accessCount(0) {
    ++objectCount;
}

// Конструктор из часов, минут и секунд с проверкой диапазонов.
Time::Time(int hours, int minutes, int seconds)
    : totalSeconds(checkedSeconds(hours, minutes, seconds)), accessCount(0) {
    ++objectCount;
}

// Конструктор копирования переносит время, но начинает новый счётчик обращений.
Time::Time(const Time& other)
    : totalSeconds(other.totalSeconds), accessCount(0) {
    ++objectCount;
}

// Оператор присваивания копирует значение и защищается от присваивания самому себе.
Time& Time::operator=(const Time& other) {
    if (this != &other) {
        totalSeconds = other.totalSeconds;
        accessCount = 0;
    }

    return *this;
}

// При уничтожении объекта уменьшаем общий счётчик.
Time::~Time() {
    --objectCount;
}

// Методы чтения возвращают часть времени и увеличивают счётчик обращений.
int Time::getHours() const {
    ++accessCount;
    return totalSeconds / 3600;
}

int Time::getMinutes() const {
    ++accessCount;
    return (totalSeconds % 3600) / 60;
}

int Time::getSeconds() const {
    ++accessCount;
    return totalSeconds % 60;
}

int Time::getTotalSeconds() const {
    ++accessCount;
    return totalSeconds;
}

// Возвращает счётчик без дополнительного увеличения.
unsigned int Time::getAccessCount() const {
    return accessCount;
}

// Формирует строку времени с ведущими нулями: HH:MM:SS.
std::string Time::toString() const {
    ++accessCount;

    std::ostringstream out;

    out << std::setfill('0')
        << std::setw(2) << totalSeconds / 3600 << ':'
        << std::setw(2) << (totalSeconds % 3600) / 60 << ':'
        << std::setw(2) << totalSeconds % 60;

    return out.str();
}

// Префиксный ++ меняет объект и возвращает ссылку на него.
Time& Time::operator++() {
    totalSeconds = normalize(static_cast<long long>(totalSeconds) + 1);
    return *this;
}

// Постфиксный ++ сохраняет старое значение, затем увеличивает текущее.
Time Time::operator++(int) {
    Time previous(*this);
    ++(*this);
    return previous;
}

// Префиксный -- уменьшает время на секунду.
Time& Time::operator--() {
    totalSeconds = normalize(static_cast<long long>(totalSeconds) - 1);
    return *this;
}

// Постфиксный -- возвращает старое значение до уменьшения.
Time Time::operator--(int) {
    Time previous(*this);
    --(*this);
    return previous;
}

// Составные арифметические операторы меняют текущий объект.
Time& Time::operator+=(const Time& other) {
    totalSeconds = normalize(
        static_cast<long long>(totalSeconds) + other.totalSeconds
    );

    return *this;
}

Time& Time::operator-=(const Time& other) {
    totalSeconds = normalize(
        static_cast<long long>(totalSeconds) - other.totalSeconds
    );

    return *this;
}

Time& Time::operator*=(const Time& other) {
    totalSeconds = normalize(
        static_cast<long long>(totalSeconds) * other.totalSeconds
    );

    return *this;
}

// При делении проверяем, что делитель не равен нулю.
Time& Time::operator/=(const Time& other) {
    if (other.totalSeconds == 0) {
        throw std::invalid_argument("Деление на нулевое время");
    }

    totalSeconds = normalize(totalSeconds / other.totalSeconds);
    return *this;
}

// Свободные бинарные операторы используют составные операторы.
Time operator+(Time lhs, const Time& rhs) {
    lhs += rhs;
    return lhs;
}

Time operator-(Time lhs, const Time& rhs) {
    lhs -= rhs;
    return lhs;
}

Time operator*(Time lhs, const Time& rhs) {
    lhs *= rhs;
    return lhs;
}

Time operator/(Time lhs, const Time& rhs) {
    lhs /= rhs;
    return lhs;
}

// Операторы сравнения сопоставляют внутренние значения секунд.
bool Time::operator<(const Time& other) const {
    return totalSeconds < other.totalSeconds;
}

bool Time::operator>(const Time& other) const {
    return totalSeconds > other.totalSeconds;
}

bool Time::operator<=(const Time& other) const {
    return totalSeconds <= other.totalSeconds;
}

bool Time::operator>=(const Time& other) const {
    return totalSeconds >= other.totalSeconds;
}

bool Time::operator==(const Time& other) const {
    return totalSeconds == other.totalSeconds;
}

bool Time::operator!=(const Time& other) const {
    return totalSeconds != other.totalSeconds;
}

// Возвращает количество живых объектов Time.
int Time::getObjectCount() {
    return objectCount;
}

// Вывод через << делегируется методу toString().
std::ostream& operator<<(std::ostream& out, const Time& time) {
    return out << time.toString();
}