
#ifndef STRING_INSTRUMENT_H
#define STRING_INSTRUMENT_H

#include "MusicalInstrument.h"

class StringInstrument : public MusicalInstrument {
protected:
    int stringCount;
    double tension;

public:
    // Конструктор.
    StringInstrument(int strings, double stringTension);

    // Конструктор копирования.
    StringInstrument(const StringInstrument& other);

    // Оператор присваивания.
    StringInstrument& operator=(const StringInstrument& other);

    // Виртуальный деструктор.
    virtual ~StringInstrument();

    // Переопределение настройки.
    void tune() const override;

    // Получение количества струн.
    int getStringCount() const;

    // Получение натяжения струн.
    double getTension() const;
};

#endif
