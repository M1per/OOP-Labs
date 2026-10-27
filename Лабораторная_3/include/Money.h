#ifndef MONEY_H
#define MONEY_H

#include <cstdint>
#include <string>

class Money {
private:
    std::int64_t kopecks_;
    mutable unsigned int accessCount_;
    static unsigned int objectCount_;

public:
    Money();
    explicit Money(std::int64_t kopecks);
    Money(std::int64_t rubles, std::int64_t kopecks);

    Money(const Money& other);
    ~Money();

    std::int64_t getKopecks() const;
    std::int64_t getRubles() const;
    std::int64_t getRemainderKopecks() const;
    unsigned int getAccessCount() const;

    std::string toString() const;

    Money& operator++();
    Money operator++(int);
    Money& operator--();
    Money operator--(int);

    Money& operator+=(const Money& other);
    Money& operator-=(const Money& other);
    Money& operator*=(std::int64_t multiplier);
    Money& operator/=(std::int64_t divisor);

    friend Money operator+(Money lhs, const Money& rhs);
    friend Money operator-(Money lhs, const Money& rhs);
    friend Money operator*(Money lhs, std::int64_t multiplier);
    friend Money operator*(std::int64_t multiplier, Money rhs);
    friend Money operator/(Money lhs, std::int64_t divisor);

    bool operator<(const Money& other) const;
    bool operator>(const Money& other) const;
    bool operator<=(const Money& other) const;
    bool operator>=(const Money& other) const;
    bool operator==(const Money& other) const;
    bool operator!=(const Money& other) const;

    static unsigned int getObjectCount();
};

#endif