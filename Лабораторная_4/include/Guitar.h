
#ifndef GUITAR_H
#define GUITAR_H

#include "StringInstrument.h"

#include <string>

class Guitar : public StringInstrument {
private:
    // Динамический массив названий струн.
    std::string* stringNames;

public:
    // Конструктор.
    Guitar(int strings = 6, double tension = 10.0);

    // Конструктор копирования.
    Guitar(const Guitar& other);

    // Оператор присваивания.
    Guitar& operator=(const Guitar& other);

    // Деструктор.
    ~Guitar() override;

    // Реализация виртуальных функций.
    void play() override;
    std::string getType() const override;

    // Переопределение настройки.
    void tune() const override;

    // Изменение названия струны.
    void setStringName(int index, const std::string& name);

    // Получение названия струны.
    std::string getStringName(int index) const;
};

#endif
