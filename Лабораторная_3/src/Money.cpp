#include "Money.h"

#include <iomanip>
#include <limits>
#include <sstream>
#include <stdexcept>

unsigned int Money::objectCount_ = 0;

Money::Money()
    : kopecks_(0), accessCount_(0) {
    ++objectCount_;
}

Money::Money(std::int64_t kopecks)
    : kopecks_(kopecks), accessCount_(0) {
    if (kopecks < 0) {
        throw std::invalid_argument("Сумма не может быть отрицательной");
    }

    ++objectCount_;
}

Money::Money(std::int64_t rubles, std::int64_t kopecks)
    : kopecks_(0), accessCount_(0) {
    if (rubles < 0 || kopecks < 0) {
        throw std::invalid_argument("Рубли и копейки не могут быть отрицательными");
    }

    if (rubles > (std::numeric_limits<std::int64_t>::max() - kopecks) / 100) {
        throw std::overflow_error("Переполнение денежной суммы");
    }

    kopecks_ = rubles * 100 + kopecks;
    ++objectCount_;
}

Money::Money(const Money& other)
    : kopecks_(other.kopecks_), accessCount_(0) {
    ++objectCount_;
}

Money::~Money() {
    if (objectCount_ > 0) {
        --objectCount_;
    }
}

std::int64_t Money::getKopecks() const {
    ++accessCount_;
    return kopecks_;
}

std::int64_t Money::getRubles() const {
    ++accessCount_;
    return kopecks_ / 100;
}

std::int64_t Money::getRemainderKopecks() const {
    ++accessCount_;
    return kopecks_ % 100;
}

unsigned int Money::getAccessCount() const {
    return accessCount_;
}

std::string Money::toString() const {
    ++accessCount_;

    std::ostringstream output;
    output << kopecks_ / 100 << ','
           << std::setw(2) << std::setfill('0')
           << kopecks_ % 100 << " руб.";

    return output.str();
}

Money& Money::operator++() {
    if (kopecks_ == std::numeric_limits<std::int64_t>::max()) {
        throw std::overflow_error("Переполнение денежной суммы");
    }

    ++kopecks_;
    return *this;
}

Money Money::operator++(int) {
    Money previous(*this);
    ++(*this);
    return previous;
}

Money& Money::operator--() {
    if (kopecks_ == 0) {
        throw std::underflow_error("Сумма не может быть отрицательной");
    }

    --kopecks_;
    return *this;
}

Money Money::operator--(int) {
    Money previous(*this);
    --(*this);
    return previous;
}

Money& Money::operator+=(const Money& other) {
    if (other.kopecks_ >
        std::numeric_limits<std::int64_t>::max() - kopecks_) {
        throw std::overflow_error("Переполнение денежной суммы");
    }

    kopecks_ += other.kopecks_;
    return *this;
}

Money& Money::operator-=(const Money& other) {
    if (kopecks_ < other.kopecks_) {
        throw std::underflow_error("Недостаточно средств");
    }

    kopecks_ -= other.kopecks_;
    return *this;
}

Money& Money::operator*=(std::int64_t multiplier) {
    if (multiplier < 0) {
        throw std::invalid_argument("Множитель не может быть отрицательным");
    }

    if (multiplier != 0 &&
        kopecks_ > std::numeric_limits<std::int64_t>::max() / multiplier) {
        throw std::overflow_error("Переполнение денежной суммы");
    }

    kopecks_ *= multiplier;
    return *this;
}

Money& Money::operator/=(std::int64_t divisor) {
    if (divisor <= 0) {
        throw std::invalid_argument("Делитель должен быть положительным");
    }

    kopecks_ /= divisor;
    return *this;
}

Money operator+(Money lhs, const Money& rhs) {
    lhs += rhs;
    return lhs;
}

Money operator-(Money lhs, const Money& rhs) {
    lhs -= rhs;
    return lhs;
}

Money operator*(Money lhs, std::int64_t multiplier) {
    lhs *= multiplier;
    return lhs;
}

Money operator*(std::int64_t multiplier, Money rhs) {
    rhs *= multiplier;
    return rhs;
}

Money operator/(Money lhs, std::int64_t divisor) {
    lhs /= divisor;
    return lhs;
}

bool Money::operator<(const Money& other) const {
    return kopecks_ < other.kopecks_;
}

bool Money::operator>(const Money& other) const {
    return kopecks_ > other.kopecks_;
}

bool Money::operator<=(const Money& other) const {
    return kopecks_ <= other.kopecks_;
}

bool Money::operator>=(const Money& other) const {
    return kopecks_ >= other.kopecks_;
}

bool Money::operator==(const Money& other) const {
    return kopecks_ == other.kopecks_;
}

bool Money::operator!=(const Money& other) const {
    return !(*this == other);
}

unsigned int Money::getObjectCount() {
    return objectCount_;
}