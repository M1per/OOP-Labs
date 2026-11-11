
#ifndef SYNTH_GUITAR_H
#define SYNTH_GUITAR_H

#include "Guitar.h"
#include "IElectronicDevice.h"
#include <string>

/**
 * @brief Класс синтезаторной гитары.
 *
 * Наследуется одновременно от Guitar и IElectronicDevice.
 *
 * Демонстрирует множественное наследование:
 * Guitar предоставляет функциональность обычной гитары,
 * IElectronicDevice определяет интерфейс электронного устройства.
 *
 * Поддерживает включение электронной части и выбор звуковых эффектов.
 */
class SynthGuitar : public Guitar, public IElectronicDevice {
private:
    /** @brief Состояние питания электронной части гитары. */
    bool poweredOn;

    /** @brief Название текущего звукового эффекта. */
    std::string currentPatch;

public:
    /**
     * @brief Создаёт синтезаторную гитару.
     * @param strings Количество струн.
     * @param tension Натяжение струн.
     */
    SynthGuitar(int strings = 6, double tension = 10.0);

    /**
     * @brief Конструктор копирования.
     * @param other Копируемая синтезаторная гитара.
     */
    SynthGuitar(const SynthGuitar& other);

    /**
     * @brief Оператор присваивания.
     * @param other Гитара, данные которой копируются.
     * @return Ссылка на текущий объект.
     */
    SynthGuitar& operator=(const SynthGuitar& other);

    /** @brief Деструктор синтезаторной гитары. */
    ~SynthGuitar() override;

    /**
     * @brief Воспроизводит звук синтезаторной гитары.
     *
     * Если электронная часть включена, используется выбранный эффект.
     * В противном случае воспроизведение происходит в обычном режиме.
     */
    void play() override;

    /**
     * @brief Возвращает название инструмента.
     * @return Строка «Синтезаторная гитара».
     */
    std::string getType() const override;

    /** @brief Выполняет настройку синтезаторной гитары. */
    void tune() const override;

    /**
     * @brief Включает электронную часть гитары.
     *
     * Реализация метода интерфейса IElectronicDevice.
     */
    void powerOn() override;

    /**
     * @brief Устанавливает звуковой эффект.
     * @param patch Название звукового эффекта.
     * @throw std::runtime_error Если электронная часть выключена.
     * @throw std::invalid_argument Если название эффекта пустое.
     */
    void setPatch(const std::string& patch) override;

    /**
     * @brief Проверяет состояние электронной части.
     * @return true, если питание включено, иначе false.
     */
    bool isPoweredOn() const;

    /**
     * @brief Возвращает текущий звуковой эффект.
     * @return Название выбранного эффекта.
     */
    std::string getCurrentPatch() const;
};

#endif
