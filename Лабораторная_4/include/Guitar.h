
#ifndef GUITAR_H
#define GUITAR_H

#include "StringInstrument.h"
#include <string>

/**
 * @brief Класс обычной гитары.
 *
 * Наследуется от StringInstrument.
 * Хранит названия отдельных струн в динамическом массиве.
 * Реализует воспроизведение звука и настройку гитары.
 */
class Guitar : public StringInstrument {
private:
    /**
     * @brief Динамический массив названий струн.
     *
     * Память выделяется в конструкторе и освобождается
     * в деструкторе.
     */
    std::string* stringNames;

public:
    /**
     * @brief Создаёт гитару.
     * @param strings Количество струн.
     * @param tension Натяжение струн.
     */
    Guitar(int strings = 6, double tension = 10.0);

    /**
     * @brief Конструктор глубокого копирования.
     * @param other Копируемая гитара.
     */
    Guitar(const Guitar& other);

    /**
     * @brief Оператор присваивания.
     * @param other Гитара, данные которой копируются.
     * @return Ссылка на текущий объект.
     */
    Guitar& operator=(const Guitar& other);

    /** @brief Освобождает динамическую память. */
    ~Guitar() override;

    /**
     * @brief Воспроизводит звук гитары.
     *
     * Увеличивает статистику воспроизведения.
     */
    void play() override;

    /**
     * @brief Возвращает название инструмента.
     * @return Строка «Гитара».
     */
    std::string getType() const override;

    /** @brief Настраивает гитару и выводит названия струн. */
    void tune() const override;

    /**
     * @brief Изменяет название указанной струны.
     * @param index Индекс струны, начиная с нуля.
     * @param name Новое название струны.
     * @throw std::out_of_range Если индекс выходит за границы массива.
     * @throw std::invalid_argument Если название пустое.
     */
    void setStringName(int index, const std::string& name);

    /**
     * @brief Возвращает название указанной струны.
     * @param index Индекс струны, начиная с нуля.
     * @return Название струны.
     * @throw std::out_of_range Если индекс выходит за границы массива.
     */
    std::string getStringName(int index) const;
};

#endif
