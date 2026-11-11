
#ifndef WIND_INSTRUMENT_H
#define WIND_INSTRUMENT_H

#include "MusicalInstrument.h"
#include <string>

/**
 * @brief Промежуточный класс духового музыкального инструмента.
 *
 * Наследуется от MusicalInstrument.
 * Хранит размер диафрагмы и материал изготовления.
 *
 * От данного класса наследуется Flute.
 */
class WindInstrument : public MusicalInstrument {
protected:
    /** @brief Размер диафрагмы инструмента. */
    double diaphragm;

    /** @brief Материал изготовления инструмента. */
    std::string material;

public:
    /**
     * @brief Создаёт духовой инструмент.
     * @param diaphragmSize Размер диафрагмы.
     * @param instrumentMaterial Материал изготовления.
     * @throw std::invalid_argument Если параметры заданы некорректно.
     */
    WindInstrument(
        double diaphragmSize,
        const std::string& instrumentMaterial
    );

    /**
     * @brief Конструктор копирования.
     * @param other Копируемый духовой инструмент.
     */
    WindInstrument(const WindInstrument& other);

    /**
     * @brief Оператор присваивания.
     * @param other Инструмент, данные которого копируются.
     * @return Ссылка на текущий объект.
     */
    WindInstrument& operator=(const WindInstrument& other);

    /** @brief Виртуальный деструктор. */
    virtual ~WindInstrument();

    /**
     * @brief Настраивает духовой инструмент.
     *
     * Выводит размер диафрагмы и материал изготовления.
     */
    void tune() const override;

    /**
     * @brief Возвращает размер диафрагмы.
     * @return Размер диафрагмы.
     */
    double getDiaphragm() const;

    /**
     * @brief Возвращает материал изготовления.
     * @return Название материала.
     */
    std::string getMaterial() const;
};

#endif
