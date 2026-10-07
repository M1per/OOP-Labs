#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <string>

/**
 * @brief Класс, представляющий самолёт.
 *
 * Класс хранит модель самолёта и его вместимость.
 */
class Aircraft
{
private:
    std::string model;     ///< Модель самолёта
    int capacity;          ///< Вместимость самолёта

public:
    /**
     * @brief Конструктор без параметров.
     *
     * Создаёт самолёт со стандартными значениями.
     */
    Aircraft();

    /**
     * @brief Параметризованный конструктор.
     *
     * @param model Модель самолёта.
     * @param capacity Вместимость самолёта.
     */
    Aircraft(const std::string& model, int capacity);

    /**
     * @brief Возвращает модель самолёта.
     *
     * @return Модель самолёта.
     */
    std::string getModel() const;

    /**
     * @brief Возвращает вместимость самолёта.
     *
     * @return Вместимость самолёта.
     */
    int getCapacity() const;
};

#endif