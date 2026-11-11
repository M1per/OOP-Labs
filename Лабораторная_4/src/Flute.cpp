
#include "Flute.h"

#include <iostream>

// Конструктор.
Flute::Flute(
    double diaphragmSize,
    const std::string& instrumentMaterial
)
    : WindInstrument(diaphragmSize, instrumentMaterial) {
}

// Конструктор копирования.
Flute::Flute(const Flute& other)
    : WindInstrument(other) {
}

// Оператор присваивания.
Flute& Flute::operator=(const Flute& other) {
    if (this != &other) {
        WindInstrument::operator=(other);
    }

    return *this;
}

// Деструктор.
Flute::~Flute() {
}

// Воспроизведение.
void Flute::play() {
    std::cout << "Играет флейта: звучит поток воздуха.\n";
    registerPlay(getType());
}

// Получение типа.
std::string Flute::getType() const {
    return "Флейта";
}

// Настройка.
void Flute::tune() const {
    std::cout << "Настройка флейты.\n";
    WindInstrument::tune();
}
