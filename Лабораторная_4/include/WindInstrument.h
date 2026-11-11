
#ifndef WIND_INSTRUMENT_H
#define WIND_INSTRUMENT_H

#include "MusicalInstrument.h"

#include <string>

class WindInstrument : public MusicalInstrument {
protected:
    double diaphragm;
    std::string material;

public:
    // Конструктор.
    WindInstrument(double diaphragmSize, const std::string& instrumentMaterial);

    // Конструктор копирования.
    WindInstrument(const WindInstrument& other);

    // Оператор присваивания.
    WindInstrument& operator=(const WindInstrument& other);

    // Виртуальный деструктор.
    virtual ~WindInstrument();

    // Переопределение настройки.
    void tune() const override;

    // Получение размера диафрагмы.
    double getDiaphragm() const;

    // Получение материала.
    std::string getMaterial() const;
};

#endif
