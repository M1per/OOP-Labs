#ifndef TIME_H
#define TIME_H

#include <iosfwd>
#include <string>

class Time {
private:
    int totalSeconds;
    mutable unsigned int accessCount;
    static int objectCount;

    static int normalize(int seconds);

public:
    Time();
    explicit Time(int seconds);
    Time(int hours, int minutes, int seconds);
    ~Time();

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    int getTotalSeconds() const;
    unsigned int getAccessCount() const;

    std::string toString() const;

    Time& operator++();
    Time operator++(int);
    Time& operator--();
    Time operator--(int);

    Time& operator+=(const Time& other);
    Time& operator-=(const Time& other);
    Time& operator*=(const Time& other);
    Time& operator/=(const Time& other);

    friend Time operator+(Time lhs, const Time& rhs);
    friend Time operator-(Time lhs, const Time& rhs);
    friend Time operator*(Time lhs, const Time& rhs);
    friend Time operator/(Time lhs, const Time& rhs);

    bool operator<(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator<=(const Time& other) const;
    bool operator>=(const Time& other) const;
    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;

    static int getObjectCount();

    friend std::ostream& operator<<(std::ostream& out, const Time& time);
};

#endif
