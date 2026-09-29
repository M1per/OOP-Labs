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
