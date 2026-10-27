#include "Time.h"

#include <iomanip>
#include <ostream>
#include <sstream>
#include <stdexcept>

int Time::objectCount = 0;

int Time::normalize(long long seconds) {
    const long long secondsPerDay = 24LL * 60LL * 60LL;

    seconds %= secondsPerDay;

    if (seconds < 0) {
        seconds += secondsPerDay;
    }

    return static_cast<int>(seconds);
}

int Time::checkedSeconds(int hours, int minutes, int seconds) {
    if (hours < 0 || hours >= 24 ||
        minutes < 0 || minutes >= 60 ||
        seconds < 0 || seconds >= 60) {
        throw std::invalid_argument("Некорректное значение времени");
    }

    return hours * 3600 + minutes * 60 + seconds;
}

Time::Time()
    : totalSeconds(0), accessCount(0) {
    ++objectCount;
}

Time::Time(int seconds)
    : totalSeconds(normalize(seconds)), accessCount(0) {
    ++objectCount;
}

Time::Time(const Time& other)
    : totalSeconds(other.totalSeconds), accessCount(0) {
    ++objectCount;
}

Time& Time::operator=(const Time& other) {
    if (this != &other) {
        totalSeconds = other.totalSeconds;
        accessCount = 0;
    }

    return *this;
}

Time::~Time() {
    --objectCount;
}

Time Time::fromHMS(int hours, int minutes, int seconds) {
    return Time(checkedSeconds(hours, minutes, seconds));
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
    totalSeconds = normalize(
        static_cast<long long>(totalSeconds) + 1
    );

    return *this;
}

Time Time::operator++(int) {
    Time previous(*this);
    ++(*this);
    return previous;
}

Time& Time::operator--() {
    totalSeconds = normalize(
        static_cast<long long>(totalSeconds) - 1
    );

    return *this;
}

Time Time::operator--(int) {
    Time previous(*this);
    --(*this);
    return previous;
}

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