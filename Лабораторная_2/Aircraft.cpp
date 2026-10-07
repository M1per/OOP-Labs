#include "Aircraft.h"

/**
 * @brief Конструктор без параметров.
 */
Aircraft::Aircraft()
    : model("Не указано"),
      capacity(100)
{
}

/**
 * @brief Параметризованный конструктор.
 *
 * @param model Модель самолёта.
 * @param capacity Вместимость самолёта.
 */
Aircraft::Aircraft(const std::string& model, int capacity)
    : model(model.empty() ? "Не указано" : model),
      capacity(capacity > 0 ? capacity : 100)
{
}

/**
 * @brief Возвращает модель самолёта.
 *
 * @return Модель самолёта.
 */
std::string Aircraft::getModel() const
{
    return model;
}

/**
 * @brief Возвращает вместимость самолёта.
 *
 * @return Вместимость самолёта.
 */
int Aircraft::getCapacity() const
{
    return capacity;
}