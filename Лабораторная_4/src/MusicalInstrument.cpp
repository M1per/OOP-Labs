
#include "MusicalInstrument.h"

#include <iostream>

// Инициализация статических переменных.
int MusicalInstrument::instrumentCount = 0;

std::map<std::string, int> MusicalInstrument::playStatistics;

// Конструктор.
MusicalInstrument::MusicalInstrument() {
    ++instrumentCount;
}

// Конструктор копирования.
MusicalInstrument::MusicalInstrument(const MusicalInstrument& other) {
    (void)other;
    ++instrumentCount;
}

// Оператор присваивания.
MusicalInstrument& MusicalInstrument::operator=(
    const MusicalInstrument& other
) {
    if (this != &other) {
        // В базовом классе нет динамических ресурсов для копирования.
    }

    return *this;
}

// Деструктор.
MusicalInstrument::~MusicalInstrument() {
    --instrumentCount;
}

// Регистрация вызова play().
void MusicalInstrument::registerPlay(const std::string& type) {
    ++playStatistics[type];
}

// Настройка по умолчанию.
void MusicalInstrument::tune() const {
    std::cout << getType() << ": выполняется стандартная настройка.\n";
}

// Получение количества существующих инструментов.
int MusicalInstrument::getInstrumentCount() {
    return instrumentCount;
}

// Получение наиболее часто воспроизводимого типа.
std::string MusicalInstrument::getMostPlayedType() {
    if (playStatistics.empty()) {
        return "Нет данных";
    }

    std::string mostPlayed;
    int maxCount = 0;

    for (const auto& item : playStatistics) {
        if (item.second > maxCount) {
            maxCount = item.second;
            mostPlayed = item.first;
        }
    }

    return mostPlayed;
}

// Дружественный оператор вывода.
std::ostream& operator<<(
    std::ostream& out,
    const MusicalInstrument& instrument
) {
    out << "Тип инструмента: " << instrument.getType();
    return out;
}
