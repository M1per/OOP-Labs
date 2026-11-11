
#include "StringInstrument.h"

#include <iostream>
#include <stdexcept>

// Конструктор.
StringInstrument::StringInstrument(int strings, double stringTension)
    : MusicalInstrument(),
      stringCount(strings),
      tension(stringTension) {

    if (strings <= 0 || stringTension <= 0) {
        throw std::invalid_argument(
            "Количество струн и натяжение должны быть положительными"
        );
    }
}

// Конструктор копирования.
StringInstrument::StringInstrument(const StringInstrument& other)
    : MusicalInstrument(other),
      stringCount(other.stringCount),
      tension(other.tension) {
}

// Оператор присваивания.
StringInstrument& StringInstrument::operator=(
    const StringInstrument& other
) {
    if (this != &other) {
        MusicalInstrument::operator=(other);

        stringCount = other.stringCount;
        tension = other.tension;
    }

    return *this;
}

// Деструктор.
StringInstrument::~StringInstrument() {
}

// Настройка струнного инструмента.
void StringInstrument::tune() const {
    std::cout << "Настройка струнного инструмента.\n";
    std::cout << "Количество струн: " << stringCount << '\n';
    std::cout << "Натяжение струн: " << tension << '\n';
}

// Получение количества струн.
int StringInstrument::getStringCount() const {
    return stringCount;
}

// Получение натяжения струн.
double StringInstrument::getTension() const {
    return tension;
}
