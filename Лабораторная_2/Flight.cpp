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
    : flightNumber(number),
      destination(destination),
      capacity(capacity),
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
    : flightNumber(number),
      destination(destination),
      capacity(capacity),
      passengerCount(passengers),
      status(status)
{
    objectCount++;
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