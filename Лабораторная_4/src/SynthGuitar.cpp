
#include "SynthGuitar.h"

#include <iostream>
#include <stdexcept>

// Конструктор.
SynthGuitar::SynthGuitar(int strings, double tension)
    : Guitar(strings, tension),
      poweredOn(false),
      currentPatch("Стандартный") {
}

// Конструктор копирования.
SynthGuitar::SynthGuitar(const SynthGuitar& other)
    : Guitar(other),
      poweredOn(other.poweredOn),
      currentPatch(other.currentPatch) {
}

// Оператор присваивания.
SynthGuitar& SynthGuitar::operator=(const SynthGuitar& other) {
    if (this != &other) {
        Guitar::operator=(other);

        poweredOn = other.poweredOn;
        currentPatch = other.currentPatch;
    }

    return *this;
}

// Деструктор.
SynthGuitar::~SynthGuitar() {
}

// Воспроизведение.
void SynthGuitar::play() {
    if (poweredOn) {
        std::cout << "Играет синтезаторная гитара. Эффект: "
                  << currentPatch << '\n';
    } else {
        std::cout << "Играет синтезаторная гитара в обычном режиме.\n";
    }

    registerPlay(getType());
}

// Получение типа.
std::string SynthGuitar::getType() const {
    return "Синтезаторная гитара";
}

// Настройка.
void SynthGuitar::tune() const {
    std::cout << "Настройка синтезаторной гитары.\n";
    Guitar::tune();
}

// Включение электронного устройства.
void SynthGuitar::powerOn() {
    poweredOn = true;
    std::cout << "Электронная часть гитары включена.\n";
}

// Выбор звукового эффекта.
void SynthGuitar::setPatch(const std::string& patch) {
    if (!poweredOn) {
        throw std::runtime_error(
            "Сначала необходимо включить электронную часть гитары"
        );
    }

    if (patch.empty()) {
        throw std::invalid_argument(
            "Название звукового эффекта не может быть пустым"
        );
    }

    currentPatch = patch;

    std::cout << "Выбран звуковой эффект: " << currentPatch << '\n';
}

// Проверка питания.
bool SynthGuitar::isPoweredOn() const {
    return poweredOn;
}

// Получение звукового эффекта.
std::string SynthGuitar::getCurrentPatch() const {
    return currentPatch;
}
