
#include "Violin.h"

#include <iostream>

// Конструктор.
Violin::Violin(int strings, double tension)
    : StringInstrument(strings, tension) {
}

// Конструктор копирования.
Violin::Violin(const Violin& other)
    : StringInstrument(other) {
}

// Оператор присваивания.
Violin& Violin::operator=(const Violin& other) {
    if (this != &other) {
        StringInstrument::operator=(other);
    }

    return *this;
}

// Деструктор.
Violin::~Violin() {
}

// Воспроизведение.
void Violin::play() {
    std::cout << "Играет скрипка: звучит смычок.\n";
    registerPlay(getType());
}

// Получение типа.
std::string Violin::getType() const {
    return "Скрипка";
}

// Настройка.
void Violin::tune() const {
    std::cout << "Настройка скрипки.\n";
    StringInstrument::tune();
}
