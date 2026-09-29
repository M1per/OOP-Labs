#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

/**
 * @brief Статус авиарейса.
 */
enum class FlightStatus
{
    Scheduled,
    Registration,
    Departed,
    Completed,
    Cancelled
};

/**
 * @brief Класс, представляющий авиарейс.
 */
class Flight
{
private:
    int flightNumber;              ///< Номер рейса
    std::string destination;       ///< Пункт назначения
    int capacity;                  ///< Вместимость самолёта
    int passengerCount;            ///< Количество пассажиров
    FlightStatus status;           ///< Статус рейса

    static int objectCount;        ///< Количество существующих объектов

public:
    /**
     * @brief Конструктор без параметров.
     */
    Flight();

    /**
     * @brief Конструктор с номером, пунктом назначения и вместимостью.
     *
     * @param number Номер рейса.
     * @param destination Пункт назначения.
     * @param capacity Вместимость самолёта.
     */
    Flight(int number, const std::string& destination, int capacity);

    /**
     * @brief Конструктор со всеми основными параметрами.
     *
     * @param number Номер рейса.
     * @param destination Пункт назначения.
     * @param capacity Вместимость самолёта.
     * @param passengers Количество пассажиров.
     * @param status Статус рейса.
     */
    Flight(int number,
           const std::string& destination,
           int capacity,
           int passengers,
           FlightStatus status);

    /**
     * @brief Деструктор.
     */
    ~Flight();

    /**
     * @brief Возвращает номер рейса.
     * @return Номер рейса.
     */
    int getFlightNumber() const;

    /**
     * @brief Возвращает пункт назначения.
     * @return Пункт назначения.
     */
    std::string getDestination() const;

    /**
     * @brief Возвращает вместимость самолёта.
     * @return Вместимость.
     */
    int getCapacity() const;

    /**
     * @brief Возвращает количество пассажиров.
     * @return Количество пассажиров.
     */
    int getPassengerCount() const;

    /**
     * @brief Возвращает статус рейса.
     * @return Статус рейса.
     */
    FlightStatus getStatus() const;

    /**
     * @brief Регистрирует одного пассажира.
     * @return true, если пассажир успешно зарегистрирован.
     */
    bool addPassenger();

    /**
     * @brief Отменяет регистрацию одного пассажира.
     * @return true, если регистрация успешно отменена.
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
     * @brief Возвращает количество существующих объектов.
     * @return Количество объектов Flight.
     */
    static int getObjectCount();
};

#endif
