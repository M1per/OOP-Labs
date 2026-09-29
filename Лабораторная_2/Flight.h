#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

/**
 * @brief Статус авиарейса.
 */
enum class FlightStatus
{
    Scheduled,   ///< Рейс запланирован
    Registration,///< Идёт регистрация пассажиров
    Departed,    ///< Рейс вылетел
    Completed,   ///< Рейс завершён
    Cancelled    ///< Рейс отменён
};

/**
 * @brief Класс, представляющий авиарейс.
 *
 * Класс хранит основную информацию о рейсе:
 * номер, пункт назначения, вместимость самолёта,
 * количество пассажиров и текущий статус.
 */
class Flight
{
private:
    int flightNumber;              ///< Номер рейса
    std::string destination;       ///< Пункт назначения
    int capacity;                  ///< Вместимость самолёта
    int passengerCount;            ///< Количество пассажиров
    FlightStatus status;           ///< Статус рейса

    static int objectCount;        ///< Количество существующих объектов Flight

public:
    /**
     * @brief Конструктор без параметров.
     *
     * Создаёт рейс со стандартными значениями:
     * номер 1, пункт назначения "Не указано",
     * вместимость 100 и без пассажиров.
     */
    Flight();

    /**
     * @brief Конструктор с основными параметрами.
     *
     * @param number Номер рейса.
     * @param destination Пункт назначения.
     * @param capacity Вместимость самолёта.
     *
     * Если переданы некорректные значения,
     * используются значения по умолчанию.
     */
    Flight(int number,
           const std::string& destination,
           int capacity);

    /**
     * @brief Конструктор со всеми параметрами.
     *
     * @param number Номер рейса.
     * @param destination Пункт назначения.
     * @param capacity Вместимость самолёта.
     * @param passengers Количество пассажиров.
     * @param status Статус рейса.
     *
     * Если количество пассажиров выходит за допустимые
     * пределы, устанавливается значение 0.
     */
    Flight(int number,
           const std::string& destination,
           int capacity,
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
     * Пассажир добавляется только в том случае,
     * если самолёт ещё не заполнен.
     *
     * @return true, если пассажир успешно добавлен;
     * false, если самолёт заполнен.
     */
    bool addPassenger();

    /**
     * @brief Удаляет одного пассажира.
     *
     * Пассажир удаляется только при наличии
     * хотя бы одного пассажира.
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
     *
     * Выводит номер, пункт назначения,
     * вместимость, количество пассажиров и статус.
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