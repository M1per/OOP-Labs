
#ifndef FLUTE_H
#define FLUTE_H

#include "WindInstrument.h"
#include <string>

/**
 * @brief Класс флейты.
 *
 * Наследуется от WindInstrument.
 * Представляет духовой музыкальный инструмент.
 */
class Flute : public WindInstrument {
public:
    /**
     * @brief Создаёт флейту.
     * @param diaphragmSize Размер диафрагмы.
     * @param instrumentMaterial Материал изготовления.
     */
    Flute(
        double diaphragmSize = 2.5,
        const std::string& instrumentMaterial = "Серебро"
    );

    /**
     * @brief Конструктор копирования.
     * @param other Копируемая флейта.
     */
    Flute(const Flute& other);

    /**
     * @brief Оператор присваивания.
     * @param other Флейта, данные которой копируются.
     * @return Ссылка на текущий объект.
     */
    Flute& operator=(const Flute& other);

    /** @brief Деструктор флейты. */
    ~Flute() override;

    /**
     * @brief Воспроизводит звук флейты.
     *
     * Регистрирует воспроизведение в общей статистике.
     */
    void play() override;

    /**
     * @brief Возвращает название инструмента.
     * @return Строка «Флейта».
     */
    std::string getType() const override;

    /** @brief Выполняет настройку флейты. */
    void tune() const override;
};

#endif
