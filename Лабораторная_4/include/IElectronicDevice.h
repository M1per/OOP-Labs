
#ifndef I_ELECTRONIC_DEVICE_H
#define I_ELECTRONIC_DEVICE_H

#include <string>

// Интерфейс электронного устройства.
class IElectronicDevice {
public:
    // Виртуальный деструктор.
    virtual ~IElectronicDevice();

    // Включение электронного устройства.
    virtual void powerOn() = 0;

    // Выбор звукового эффекта.
    virtual void setPatch(const std::string& patch) = 0;
};

#endif
