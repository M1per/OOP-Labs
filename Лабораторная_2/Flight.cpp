#include "Flight.h"
#include <iostream>

/**
 * @brief Инициализация статического счётчика объектов.
 */
int Flight::objectCount = 0;

/**
 * @brief Конструктор без параметров.
 *
 * Создаёт рейс со стандартными значениями.
 */
Flight::Flight()
    : flightNumber(1),
      destination("Не указано"),
      capacity(100),
      passengerCount(0),
      status(FlightStatus::Scheduled)
{
    objectCount++;
}

/**
 * @brief Конструктор с основными параметрами.
 *
 * @param number Номер рейса.
 * @param destination Пункт назначения.
 * @param capacity Вместимость самолёта.
 */
Flight::Flight(int number,
               const std::string& destination,
               int capacity)
    : flightNumber(number > 0 ? number : 1),
      destination(destination.empty() ? "Не указано" : destination),
      capacity(capacity > 0 ? capacity : 100),
      passengerCount(0),
      status(FlightStatus::Scheduled)
{
    objectCount++;
}

/**
 * @brief Конструктор со всеми параметрами.
 *
 * @param number Номер рейса.
 * @param destination Пункт назначения.
 * @param capacity Вместимость самолёта.
 * @param passengers Количество пассажиров.
 * @param status Статус рейса.
 */
Flight::Flight(int number,
               const std::string& destination,
               int capacity,
               int passengers,
               FlightStatus status)
    : flightNumber(number > 0 ? number : 1),
      destination(destination.empty() ? "Не указано" : destination),
      capacity(capacity > 0 ? capacity : 100),
      passengerCount(0),
      status(status)
{
    if (passengers >= 0 && passengers <= this->capacity)
    {
        passengerCount = passengers;
    }
    else
    {
        passengerCount = 0;
    }

    objectCount++;
}

/**
 * @brief Деструктор объекта Flight.
 */
Flight::~Flight()
{
    objectCount--;
}

/**
 * @brief Возвращает номер рейса.
 *
 * @return Номер рейса.
 */
int Flight::getFlightNumber() const
{
    return flightNumber;
}

/**
 * @brief Возвращает пункт назначения.
 *
 * @return Пункт назначения.
 */
std::string Flight::getDestination() const
{
    return destination;
}

/**
 * @brief Возвращает вместимость самолёта.
 *
 * @return Вместимость самолёта.
 */
int Flight::getCapacity() const
{
    return capacity;
}

/**
 * @brief Возвращает количество пассажиров.
 *
 * @return Количество пассажиров.
 */
int Flight::getPassengerCount() const
{
    return passengerCount;
}

/**
 * @brief Возвращает статус рейса.
 *
 * @return Текущий статус.
 */
FlightStatus Flight::getStatus() const
{
    return status;
}

/**
 * @brief Добавляет одного пассажира.
 *
 * @return true, если пассажир добавлен;
 * false, если самолёт заполнен.
 */
bool Flight::addPassenger()
{
    if (passengerCount >= capacity)
    {
        return false;
    }

    passengerCount++;
    return true;
}

/**
 * @brief Удаляет одного пассажира.
 *
 * @return true, если пассажир удалён;
 * false, если пассажиров нет.
 */
bool Flight::removePassenger()
{
    if (passengerCount <= 0)
    {
        return false;
    }

    passengerCount--;
    return true;
}

/**
 * @brief Изменяет статус рейса.
 *
 * @param newStatus Новый статус рейса.
 */
void Flight::changeStatus(FlightStatus newStatus)
{
    status = newStatus;
}

/**
 * @brief Выводит информацию о рейсе.
 */
void Flight::printInfo() const
{
    std::cout << "Рейс №" << flightNumber << std::endl;
    std::cout << "Пункт назначения: " << destination << std::endl;
    std::cout << "Вместимость: " << capacity << std::endl;
    std::cout << "Пассажиров: " << passengerCount << std::endl;

    std::cout << "Статус: ";

    switch (status)
    {
        case FlightStatus::Scheduled:
            std::cout << "Запланирован";
            break;

        case FlightStatus::Registration:
            std::cout << "Регистрация";
            break;

        case FlightStatus::Departed:
            std::cout << "Вылетел";
            break;

        case FlightStatus::Completed:
            std::cout << "Завершён";
            break;

        case FlightStatus::Cancelled:
            std::cout << "Отменён";
            break;
    }

    std::cout << std::endl;
}

/**
 * @brief Возвращает количество существующих объектов.
 *
 * @return Количество объектов Flight.
 */
int Flight::getObjectCount()
{
    return objectCount;
}