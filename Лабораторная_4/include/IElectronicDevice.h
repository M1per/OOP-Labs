
#ifndef I_ELECTRONIC_DEVICE_H
#define I_ELECTRONIC_DEVICE_H

#include <string>

/**
 * @brief Интерфейс электронного музыкального устройства.
 *
 * Определяет обязательные операции для электронных устройств:
 * включение питания и выбор звукового эффекта.
 *
 * Используется классом SynthGuitar при множественном наследовании.
 */
class IElectronicDevice {
public:
    /** @brief Виртуальный деструктор интерфейса. */
    virtual ~IElectronicDevice();

    /**
     * @brief Включает электронное устройство.
     */
    virtual void powerOn() = 0;

    /**
     * @brief Выбирает звуковой эффект.
     * @param patch Название звукового эффекта.
     */
    virtual void setPatch(const std::string& patch) = 0;
};

#endif
