#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include "Aircraft.h"

/**
 * @brief Статус авиарейса.
 */
enum class FlightStatus
{
    Scheduled,    ///< Рейс запланирован
    Registration, ///< Идёт регистрация пассажиров
    Departed,     ///< Рейс вылетел
    Completed,    ///< Рейс завершён
    Cancelled     ///< Рейс отменён
};

/**
 * @brief Класс, представляющий авиарейс.
 *
 * Класс хранит основную информацию о рейсе:
 * номер, пункт назначения, самолёт,
 * количество пассажиров и текущий статус.
 */
class Flight
{
private:
    int flightNumber;              ///< Номер рейса
    std::string destination;       ///< Пункт назначения
    Aircraft aircraft;             ///< Самолёт рейса
    int passengerCount;            ///< Количество пассажиров
    FlightStatus status;           ///< Статус рейса

    static int objectCount;        ///< Количество существующих объектов Flight

public:
    /**
     * @brief Конструктор без параметров.
     *
     * Создаёт рейс со стандартными значениями.
     */
    Flight();

    /**
     * @brief Конструктор с основными параметрами.
     *
     * @param number Номер рейса.
     * @param destination Пункт назначения.
     * @param aircraft Самолёт рейса.
     */
    Flight(int number,
           const std::string& destination,
           const Aircraft& aircraft);

    /**
     * @brief Конструктор со всеми параметрами.
     *
     * @param number Номер рейса.
     * @param destination Пункт назначения.
     * @param aircraft Самолёт рейса.
     * @param passengers Количество пассажиров.
     * @param status Статус рейса.
     */
    Flight(int number,
           const std::string& destination,
           const Aircraft& aircraft,
           int passengers,
           FlightStatus status);

    /**
     * @brief Деструктор.
     *
     * Уменьшает счётчик существующих объектов.
     */
    ~Flight();

    /**
     * @brief Возвращает номер рейса.
     *
     * @return Номер рейса.
     */
    int getFlightNumber() const;

    /**
     * @brief Возвращает пункт назначения.
     *
     * @return Пункт назначения.
     */
    std::string getDestination() const;

    /**
     * @brief Возвращает самолёт рейса.
     *
     * @return Самолёт.
     */
    Aircraft getAircraft() const;

    /**
     * @brief Возвращает вместимость самолёта.
     *
     * @return Вместимость самолёта.
     */
    int getCapacity() const;

    /**
     * @brief Возвращает количество пассажиров.
     *
     * @return Количество пассажиров.
     */
    int getPassengerCount() const;

    /**
     * @brief Возвращает текущий статус рейса.
     *
     * @return Статус рейса.
     */
    FlightStatus getStatus() const;

    /**
     * @brief Добавляет одного пассажира.
     *
     * @return true, если пассажир успешно добавлен;
     * false, если самолёт заполнен.
     */
    bool addPassenger();

    /**
     * @brief Удаляет одного пассажира.
     *
     * @return true, если пассажир успешно удалён;
     * false, если пассажиров нет.
     */
    bool removePassenger();

    /**
     * @brief Изменяет статус рейса.
     *
     * @param newStatus Новый статус рейса.
     */
    void changeStatus(FlightStatus newStatus);

    /**
     * @brief Выводит информацию о рейсе.
     */
    void printInfo() const;

    /**
     * @brief Возвращает количество существующих объектов Flight.
     *
     * @return Количество существующих объектов.
     */
    static int getObjectCount();
};

#endif