
#ifndef VIOLIN_H
#define VIOLIN_H

#include "StringInstrument.h"

/**
 * @brief Класс скрипки.
 *
 * Наследуется от StringInstrument.
 * Представляет струнный смычковый музыкальный инструмент.
 */
class Violin : public StringInstrument {
public:
    /**
     * @brief Создаёт скрипку.
     * @param strings Количество струн.
     * @param tension Натяжение струн.
     */
    Violin(int strings = 4, double tension = 8.0);

    /**
     * @brief Конструктор копирования.
     * @param other Копируемая скрипка.
     */
    Violin(const Violin& other);

    /**
     * @brief Оператор присваивания.
     * @param other Скрипка, данные которой копируются.
     * @return Ссылка на текущий объект.
     */
    Violin& operator=(const Violin& other);

    /** @brief Деструктор скрипки. */
    ~Violin() override;

    /**
     * @brief Воспроизводит звук скрипки.
     *
     * Регистрирует воспроизведение в общей статистике.
     */
    void play() override;

    /**
     * @brief Возвращает название инструмента.
     * @return Строка «Скрипка».
     */
    std::string getType() const override;

    /** @brief Выполняет настройку скрипки. */
    void tune() const override;
};

#endif
