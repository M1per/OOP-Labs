
#include "Guitar.h"

#include <iostream>
#include <stdexcept>

// Конструктор.
Guitar::Guitar(int strings, double tension)
    : StringInstrument(strings, tension),
      stringNames(new std::string[strings]) {

    for (int i = 0; i < strings; ++i) {
        stringNames[i] = "Струна " + std::to_string(i + 1);
    }
}

// Конструктор копирования с глубоким копированием.
Guitar::Guitar(const Guitar& other)
    : StringInstrument(other),
      stringNames(new std::string[other.stringCount]) {

    for (int i = 0; i < stringCount; ++i) {
        stringNames[i] = other.stringNames[i];
    }
}

// Оператор присваивания.
Guitar& Guitar::operator=(const Guitar& other) {
    if (this != &other) {
        StringInstrument::operator=(other);

        std::string* newNames = new std::string[other.stringCount];

        for (int i = 0; i < other.stringCount; ++i) {
            newNames[i] = other.stringNames[i];
        }

        delete[] stringNames;

        stringNames = newNames;
    }

    return *this;
}

// Деструктор.
Guitar::~Guitar() {
    delete[] stringNames;
}

// Воспроизведение.
void Guitar::play() {
    std::cout << "Играет гитара: звучат струны.\n";
    registerPlay(getType());
}

// Получение типа.
std::string Guitar::getType() const {
    return "Гитара";
}

// Настройка.
void Guitar::tune() const {
    StringInstrument::tune();

    std::cout << "Названия струн:\n";

    for (int i = 0; i < stringCount; ++i) {
        std::cout << "  " << stringNames[i] << '\n';
    }
}

// Изменение названия струны.
void Guitar::setStringName(int index, const std::string& name) {
    if (index < 0 || index >= stringCount) {
        throw std::out_of_range("Неверный номер струны");
    }

    if (name.empty()) {
        throw std::invalid_argument("Название струны не может быть пустым");
    }

    stringNames[index] = name;
}

// Получение названия струны.
std::string Guitar::getStringName(int index) const {
    if (index < 0 || index >= stringCount) {
        throw std::out_of_range("Неверный номер струны");
    }

    return stringNames[index];
}
