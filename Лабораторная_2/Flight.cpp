#include "Flight.h"
#include <iostream>

/**
 * @brief Статический счётчик существующих объектов Flight.
 */
int Flight::objectCount = 0;

/**
 * @brief Создаёт рейс со значениями по умолчанию.
 *
 * Создаётся рейс с номером 1, вместимостью 100 пассажиров
 * и статусом "Запланирован".
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
 * @brief Создаёт рейс с основными параметрами.
 *
 * @param number Номер рейса.
 * @param destination Пункт назначения.
 * @param capacity Вместимость самолёта.
 *
 * Если номер или вместимость некорректны, используются
 * безопасные значения по умолчанию.
 */
Flight::Flight(int number, const std::string& destination, int capacity)
    : flightNumber(number > 0 ? number : 1),
      destination(destination.empty() ? "Не указано" : destination),
      capacity(capacity > 0 ? capacity : 100),
      passengerCount(0),
      status(FlightStatus::Scheduled)
{
    objectCount++;
}

/**
 * @brief Создаёт рейс со всеми основными параметрами.
 *
 * @param number Номер рейса.
 * @param destination Пункт назначения.
 * @param capacity Вместимость самолёта.
 * @param passengers Количество пассажиров.
 * @param status Начальный статус рейса.
 *
 * Если количество пассажиров некорректно или превышает
 * вместимость самолёта, устанавливается 0 пассажиров.
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
 * @brief Уничтожает объект Flight.
 *
 * При уничтожении объекта уменьшается статический счётчик.
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
 * @return Максимальное количество пассажиров.
 */
int Flight::getCapacity() const
{
    return capacity;
}

/**
 * @brief Возвращает количество пассажиров.
 *
 * @return Текущее количество пассажиров.
 */
int Flight::getPassengerCount() const
{
    return passengerCount;
}

/**
 * @brief Возвращает текущий статус рейса.
 *
 * @return Статус рейса.
 */
FlightStatus Flight::getStatus() const
{
    return status;
}

/**
 * @brief Добавляет одного пассажира на рейс.
 *
 * Пассажир добавляется только в том случае, если самолёт
 * ещё не заполнен.
 *
 * @return true, если пассажир успешно добавлен.
 * @return false, если достигнута максимальная вместимость.
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
 * @brief Удаляет одного пассажира с рейса.
 *
 * @return true, если пассажир успешно удалён.
 * @return false, если пассажиров нет.
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
 *
 * На экран выводятся номер рейса, пункт назначения,
 * вместимость, количество пассажиров и текущий статус.
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
 * @brief Возвращает количество существующих объектов Flight.
 *
 * @return Количество объектов Flight.
 */
int Flight::getObjectCount()
{
    return objectCount;
}