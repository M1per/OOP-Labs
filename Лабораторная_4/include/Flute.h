
#ifndef FLUTE_H
#define FLUTE_H

#include "WindInstrument.h"

#include <string>

class Flute : public WindInstrument {
public:
    // Конструктор.
    Flute(double diaphragmSize = 2.5,
          const std::string& instrumentMaterial = "Серебро");

    // Конструктор копирования.
    Flute(const Flute& other);

    // Оператор присваивания.
    Flute& operator=(const Flute& other);

    // Деструктор.
    ~Flute() override;

    // Реализация виртуальных функций.
    void play() override;
    std::string getType() const override;

    // Переопределение настройки.
    void tune() const override;
};

#endif
