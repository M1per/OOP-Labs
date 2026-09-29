#include "Flight.h"
#include <iostream>

/**
 * @mainpage Лабораторная работа №2
 *
 * @section description Описание
 *
 * Лабораторная работа посвящена разработке класса Flight,
 * представляющего авиарейс.
 *
 * Класс содержит информацию о номере рейса,
 * пункте назначения, вместимости самолёта,
 * количестве пассажиров и статусе рейса.
 *
 * @section tests Выполненные проверки
 *
 * В программе выполняются проверки:
 * - создания объектов;
 * - работы конструкторов;
 * - добавления пассажиров;
 * - удаления пассажиров;
 * - изменения статуса рейса;
 * - обработки некорректных операций;
 * - проверки корректности входных данных;
 * - независимости объектов;
 * - подсчёта количества существующих объектов.
 *
 * @image html Flight.png "UML-диаграмма класса Flight"
 */

/**
 * @brief Главная функция программы.
 *
 * Создаёт несколько объектов Flight и выполняет
 * проверку основных возможностей класса.
 *
 * @return 0 при успешном завершении программы.
 */
int main()
{
    std::cout << "=== Создание объектов ===" << std::endl;

    Flight flight1;

    Flight flight2(101, "Москва", 180);

    Flight flight3(202, "Санкт-Петербург", 200, 50,
                   FlightStatus::Registration);

    std::cout << "Количество объектов: "
              << Flight::getObjectCount() << std::endl;

    std::cout << "\n=== Начальное состояние ===" << std::endl;

    flight1.printInfo();
    std::cout << std::endl;

    flight2.printInfo();
    std::cout << std::endl;

    flight3.printInfo();

    std::cout << "\n=== Корректные операции ===" << std::endl;

    flight2.addPassenger();
    flight2.addPassenger();
    flight2.addPassenger();

    flight3.changeStatus(FlightStatus::Departed);

    std::cout << "\nРейс 101 после добавления пассажиров:"
              << std::endl;

    flight2.printInfo();

    std::cout << "\nРейс 202 после изменения статуса:"
              << std::endl;

    flight3.printInfo();

    std::cout << "\n=== Некорректные операции ===" << std::endl;

    bool removed = flight1.removePassenger();

    if (!removed)
    {
        std::cout << "Ошибка: невозможно удалить пассажира, "
                     "так как пассажиров нет."
                  << std::endl;
    }

    Flight testFlight(303, "Уфа", 2);

    testFlight.addPassenger();
    testFlight.addPassenger();

    bool added = testFlight.addPassenger();

    if (!added)
    {
        std::cout << "Ошибка: невозможно добавить пассажира, "
                     "так как самолёт заполнен."
                  << std::endl;
    }

    std::cout << "\nСостояние тестового рейса:" << std::endl;

    testFlight.printInfo();

    std::cout << "\n=== Проверка корректности объекта ==="
              << std::endl;

    Flight invalidFlight(-10, "", -50, 500,
                         FlightStatus::Scheduled);

    std::cout << "Попытка создать рейс с некорректными данными:"
              << std::endl;

    invalidFlight.printInfo();

    std::cout << "\n=== Проверка независимости объектов ==="
              << std::endl;

    std::cout << "Изменяем только второй рейс..."
              << std::endl;

    flight2.addPassenger();

    std::cout << "\nПервый рейс:" << std::endl;
    flight1.printInfo();

    std::cout << "\nВторой рейс:" << std::endl;
    flight2.printInfo();

    std::cout << "\nТретий рейс:" << std::endl;
    flight3.printInfo();

    std::cout << "\n=== Проверка количества объектов ==="
              << std::endl;

    std::cout << "Сейчас существует объектов Flight: "
              << Flight::getObjectCount()
              << std::endl;

    return 0;
}