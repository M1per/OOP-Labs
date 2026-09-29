#include "Flight.h"
#include <iostream>

/**
 * @brief Главная функция программы.
 *
 * Выполняет тестирование класса Flight:
 * - создаёт объекты с использованием разных конструкторов;
 * - выводит начальное состояние объектов;
 * - выполняет корректные операции;
 * - проверяет некорректные операции;
 * - проверяет корректность состояния объекта;
 * - проверяет независимость объектов;
 * - проверяет количество существующих объектов.
 *
 * @return 0 при успешном завершении программы.
 */
int main()
{
    /**
     * @brief Создание трёх объектов Flight.
     *
     * Каждый объект создаётся с использованием
     * отдельного конструктора.
     */
    std::cout << "=== Создание объектов ===" << std::endl;

    Flight flight1;

    Flight flight2(101, "Москва", 180);

    Flight flight3(202, "Санкт-Петербург", 200, 50,
                   FlightStatus::Registration);

    std::cout << "Количество объектов: "
              << Flight::getObjectCount() << std::endl;

    /**
     * @brief Вывод начального состояния объектов.
     */
    std::cout << "\n=== Начальное состояние ===" << std::endl;

    flight1.printInfo();
    std::cout << std::endl;

    flight2.printInfo();
    std::cout << std::endl;

    flight3.printInfo();

    /**
     * @brief Проверка корректных операций.
     *
     * Для второго рейса добавляются пассажиры.
     * Для третьего рейса изменяется статус.
     */
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

    /**
     * @brief Проверка некорректных операций.
     *
     * Проверяется попытка удалить пассажира,
     * когда пассажиров нет, а также попытка добавить
     * пассажира в полностью заполненный самолёт.
     */
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

    /**
     * @brief Проверка корректности состояния объекта.
     *
     * Передаются некорректные значения:
     * отрицательный номер рейса, пустой пункт назначения,
     * отрицательная вместимость и слишком большое количество
     * пассажиров.
     *
     * Конструктор должен заменить некорректные значения
     * допустимыми значениями.
     */
    std::cout << "\n=== Проверка корректности объекта ==="
              << std::endl;

    Flight invalidFlight(-10, "", -50, 500,
                         FlightStatus::Scheduled);

    std::cout << "Попытка создать рейс с некорректными данными:"
              << std::endl;

    invalidFlight.printInfo();

    /**
     * @brief Проверка независимости объектов.
     *
     * Изменяется только второй объект.
     * После изменения проверяется состояние всех трёх
     * объектов, чтобы убедиться, что они не влияют друг
     * на друга.
     */
    std::cout << "\n=== Проверка независимости объектов ==="
              << std::endl;

    std::cout << "Изменяем только второй рейс..." << std::endl;

    flight2.addPassenger();

    std::cout << "\nПервый рейс:" << std::endl;
    flight1.printInfo();

    std::cout << "\nВторой рейс:" << std::endl;
    flight2.printInfo();

    std::cout << "\nТретий рейс:" << std::endl;
    flight3.printInfo();

    /**
     * @brief Проверка статического счётчика объектов.
     */
    std::cout << "\n=== Проверка количества объектов ==="
              << std::endl;

    std::cout << "Сейчас существует объектов Flight: "
              << Flight::getObjectCount() << std::endl;

    return 0;
}