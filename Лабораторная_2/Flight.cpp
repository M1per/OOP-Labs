#include "Flight.h"
#include <iostream>

int Flight::objectCount = 0;

Flight::Flight()
    : flightNumber(1),
      destination("Не указано"),
      capacity(100),
      passengerCount(0),
      status(FlightStatus::Scheduled)
{
    objectCount++;
}

Flight::Flight(int number, const std::string& destination, int capacity)
    : flightNumber(number > 0 ? number : 1),
      destination(destination.empty() ? "Не указано" : destination),
      capacity(capacity > 0 ? capacity : 100),
      passengerCount(0),
      status(FlightStatus::Scheduled)
{
    objectCount++;
}

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

Flight::~Flight()
{
    objectCount--;
}

int Flight::getFlightNumber() const
{
    return flightNumber;
}

std::string Flight::getDestination() const
{
    return destination;
}

int Flight::getCapacity() const
{
    return capacity;
}

int Flight::getPassengerCount() const
{
    return passengerCount;
}

FlightStatus Flight::getStatus() const
{
    return status;
}

bool Flight::addPassenger()
{
    if (passengerCount >= capacity)
    {
        return false;
    }

    passengerCount++;
    return true;
}

bool Flight::removePassenger()
{
    if (passengerCount <= 0)
    {
        return false;
    }

    passengerCount--;
    return true;
}

void Flight::changeStatus(FlightStatus newStatus)
{
    status = newStatus;
}

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

int Flight::getObjectCount()
{
    return objectCount;
}