
#ifndef STRING_INSTRUMENT_H
#define STRING_INSTRUMENT_H

#include "MusicalInstrument.h"

/**
 * @brief Промежуточный класс струнного музыкального инструмента.
 *
 * Наследуется от MusicalInstrument.
 * Содержит общие характеристики струнных инструментов:
 * количество струн и их натяжение.
 *
 * От данного класса наследуются Guitar и Violin.
 */
class StringInstrument : public MusicalInstrument {
protected:
    /** @brief Количество струн инструмента. */
    int stringCount;

    /** @brief Натяжение струн инструмента. */
    double tension;

public:
    /**
     * @brief Создаёт струнный инструмент.
     * @param strings Количество струн.
     * @param stringTension Натяжение струн.
     * @throw std::invalid_argument Если параметры неположительные.
     */
    StringInstrument(int strings, double stringTension);

    /**
     * @brief Конструктор копирования.
     * @param other Копируемый струнный инструмент.
     */
    StringInstrument(const StringInstrument& other);

    /**
     * @brief Оператор присваивания.
     * @param other Инструмент, данные которого копируются.
     * @return Ссылка на текущий объект.
     */
    StringInstrument& operator=(const StringInstrument& other);

    /** @brief Виртуальный деструктор. */
    virtual ~StringInstrument();

    /**
     * @brief Настраивает струнный инструмент.
     *
     * Выводит количество струн и их натяжение.
     */
    void tune() const override;

    /**
     * @brief Возвращает количество струн.
     * @return Количество струн.
     */
    int getStringCount() const;

    /**
     * @brief Возвращает натяжение струн.
     * @return Значение натяжения.
     */
    double getTension() const;
};

#endif
