
#ifndef VIOLIN_H
#define VIOLIN_H

#include "StringInstrument.h"

#include <string>

class Violin : public StringInstrument {
public:
    // Конструктор.
    Violin(int strings = 4, double tension = 8.0);

    // Конструктор копирования.
    Violin(const Violin& other);

    // Оператор присваивания.
    Violin& operator=(const Violin& other);

    // Деструктор.
    ~Violin() override;

    // Реализация виртуальных функций.
    void play() override;
    std::string getType() const override;

    // Переопределение настройки.
    void tune() const override;
};

#endif
