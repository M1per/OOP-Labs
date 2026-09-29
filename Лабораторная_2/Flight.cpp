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