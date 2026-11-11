
#include "WindInstrument.h"

#include <iostream>
#include <stdexcept>

// Конструктор.
WindInstrument::WindInstrument(
    double diaphragmSize,
    const std::string& instrumentMaterial
)
    : MusicalInstrument(),
      diaphragm(diaphragmSize),
      material(instrumentMaterial) {

    if (diaphragmSize <= 0 || instrumentMaterial.empty()) {
        throw std::invalid_argument(
            "Размер диафрагмы и материал должны быть заданы корректно"
        );
    }
}

// Конструктор копирования.
WindInstrument::WindInstrument(const WindInstrument& other)
    : MusicalInstrument(other),
      diaphragm(other.diaphragm),
      material(other.material) {
}

// Оператор присваивания.
WindInstrument& WindInstrument::operator=(
    const WindInstrument& other
) {
    if (this != &other) {
        MusicalInstrument::operator=(other);

        diaphragm = other.diaphragm;
        material = other.material;
    }

    return *this;
}

// Деструктор.
WindInstrument::~WindInstrument() {
}

// Настройка духового инструмента.
void WindInstrument::tune() const {
    std::cout << "Настройка духового инструмента.\n";
    std::cout << "Размер диафрагмы: " << diaphragm << '\n';
    std::cout << "Материал: " << material << '\n';
}

// Получение размера диафрагмы.
double WindInstrument::getDiaphragm() const {
    return diaphragm;
}

// Получение материала.
std::string WindInstrument::getMaterial() const {
    return material;
}
