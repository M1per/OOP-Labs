
#ifndef SYNTH_GUITAR_H
#define SYNTH_GUITAR_H

#include "Guitar.h"
#include "IElectronicDevice.h"

#include <string>

class SynthGuitar : public Guitar, public IElectronicDevice {
private:
    bool poweredOn;
    std::string currentPatch;

public:
    // Конструктор.
    SynthGuitar(
        int strings = 6,
        double tension = 10.0
    );

    // Конструктор копирования.
    SynthGuitar(const SynthGuitar& other);

    // Оператор присваивания.
    SynthGuitar& operator=(const SynthGuitar& other);

    // Деструктор.
    ~SynthGuitar() override;

    // Реализация функций музыкального инструмента.
    void play() override;
    std::string getType() const override;
    void tune() const override;

    // Реализация функций электронного устройства.
    void powerOn() override;
    void setPatch(const std::string& patch) override;

    // Получение состояния питания.
    bool isPoweredOn() const;

    // Получение текущего звукового эффекта.
    std::string getCurrentPatch() const;
};

#endif
