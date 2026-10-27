#include "Time.h"

#include <iomanip>
#include <ostream>
#include <sstream>
#include <stdexcept>

int Time::objectCount = 0;

int Time::normalize(int seconds) {
    const int secondsPerDay = 24 * 60 * 60;
    seconds %= secondsPerDay;

    if (seconds < 0) {
        seconds += secondsPerDay;
    }

    return seconds;
}

Time::Time()
    : totalSeconds(0), accessCount(0) {
    ++objectCount;
}

Time::Time(int seconds)
    : totalSeconds(normalize(seconds)), accessCount(0) {
    ++objectCount;
}

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

Time::~Time() {
    --objectCount;
}

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

unsigned int Time::getAccessCount() const {
    return accessCount;
}

std::string Time::toString() const {
    ++accessCount;

    std::ostringstream out;
    out << std::setfill('0')
        << std::setw(2) << totalSeconds / 3600 << ':'
        << std::setw(2) << (totalSeconds % 3600) / 60 << ':'
        << std::setw(2) << totalSeconds % 60;

    return out.str();
}

Time& Time::operator++() {
    totalSeconds = normalize(totalSeconds + 1);
    return *this;
}

Time Time::operator++(int) {
    Time previous(*this);
    ++(*this);
    return previous;
}

Time& Time::operator--() {
    totalSeconds = normalize(totalSeconds - 1);
    return *this;
}

Time Time::operator--(int) {
    Time previous(*this);
    --(*this);
    return previous;
}

Time& Time::operator+=(const Time& other) {
    totalSeconds = normalize(totalSeconds + other.totalSeconds);
    return *this;
}

Time& Time::operator-=(const Time& other) {
    totalSeconds = normalize(totalSeconds - other.totalSeconds);
    return *this;
}

Time& Time::operator*=(const Time& other) {
    totalSeconds = normalize(totalSeconds * other.totalSeconds);
    return *this;
}

Time& Time::operator/=(const Time& other) {
    if (other.totalSeconds == 0) {
        throw std::invalid_argument("Деление на нулевое время");
    }

    totalSeconds = normalize(totalSeconds / other.totalSeconds);
    return *this;
}

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

int Time::getObjectCount() {
    return objectCount;
}

std::ostream& operator<<(std::ostream& out, const Time& time) {
    return out << time.toString();
}
