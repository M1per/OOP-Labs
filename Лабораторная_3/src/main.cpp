/**
 * @file main.cpp
 * @brief Консольная программа для управления расписанием на день.
 */

#include "Time.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <type_traits>
#include <vector>

// Проверка на этапе компиляции: int нельзя неявно преобразовать в Time.
static_assert(
    !std::is_convertible<int, Time>::value,
    "Time(int) должен запрещать неявное преобразование из int"
);

/**
 * @brief Событие расписания с названием и временем начала/окончания.
 */
struct Event {
    std::string name; ///< Название события.
    Time start;       ///< Время начала.
    Time end;         ///< Время окончания.

    /// Заполняет событие переданными значениями.
    Event(const std::string& eventName, const Time& eventStart, const Time& eventEnd)
        : name(eventName), start(eventStart), end(eventEnd) {}
};

// Строки для визуального оформления разделов консоли.
const std::string LINE(72, '=');
const std::string SEPARATOR(72, '-');

// Печатает заголовок раздела.
void printHeader(const std::string& title) {
    std::cout << '\n' << LINE << '\n'
              << "  " << title << '\n'
              << LINE << '\n';
}

// Печатает результат проверки в виде «Да» или «Нет».
void printResult(const std::string& description, bool result) {
    std::cout << "  " << std::left << std::setw(44) << description
              << (result ? "Да" : "Нет") << '\n';
}

// Читает целое число и повторяет ввод, пока значение не попадёт в диапазон.
int readInt(const std::string& prompt, int minValue, int maxValue) {
    int value;

    while (true) {
        std::cout << prompt;

        if (std::cin >> value && value >= minValue && value <= maxValue) {
            // Удаляем остаток строки после введённого числа.
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            return value;
        }

        std::cout << "  Ошибка: введите целое число от "
                  << minValue << " до " << maxValue << ".\n";

        // Сбрасываем состояние потока после ошибочного ввода.
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
    }
}

// Читает непустую строку, например название события.
std::string readText(const std::string& prompt) {
    std::string text;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, text);

        if (!text.empty()) {
            return text;
        }

        std::cout << "  Название не должно быть пустым.\n";
    }
}

// Запрашивает часы, минуты и секунды, затем создаёт объект Time.
Time readTime(const std::string& title) {
    printHeader(title);

    const int hours = readInt("  Часы    [0-23]: ", 0, 23);
    const int minutes = readInt("  Минуты  [0-59]: ", 0, 59);
    const int seconds = readInt("  Секунды [0-59]: ", 0, 59);

    return Time(hours, minutes, seconds);
}

// Показывает доступные действия программы.
void showMenu() {
    printHeader("ГЛАВНОЕ МЕНЮ");

    std::cout
        << "  1. Просмотреть расписание\n"
        << "  2. Добавить событие\n"
        << "  3. Изменить событие\n"
        << "  4. Сравнить два времени\n"
        << "  5. Демонстрация операторов класса Time\n"
        << "  6. Статистика объектов\n"
        << "  0. Выход\n"
        << SEPARATOR << '\n';
}

// Выводит все события таблицей; если список пуст, сообщает об этом.
void showSchedule(const std::vector<Event>& events) {
    printHeader("РАСПИСАНИЕ НА ДЕНЬ");

    if (events.empty()) {
        std::cout << "  Расписание пустое.\n";
        return;
    }

    // Печатаем заголовки столбцов таблицы.
    std::cout << "  " << std::left
              << std::setw(5) << "№"
              << std::setw(28) << "Событие"
              << std::setw(17) << "Начало"
              << "Окончание\n"
              << "  " << SEPARATOR << '\n';

    // Перебираем все события и выводим их в таблицу.
    for (std::size_t i = 0; i < events.size(); ++i) {
        std::string name = events[i].name;

        // Слишком длинное название сокращаем для аккуратного отображения.
        if (name.length() > 26) {
            name = name.substr(0, 23) + "...";
        }

        std::cout << "  "
                  << std::left << std::setw(5) << i + 1
                  << std::setw(28) << name
                  << std::setw(17) << events[i].start
                  << events[i].end << '\n';
    }

    std::cout << "  " << SEPARATOR << '\n'
              << "  Всего событий: " << events.size() << '\n';
}

// Добавляет событие, проверяя уникальность названия и порядок времени.
void addEvent(std::vector<Event>& events) {
    printHeader("ДОБАВЛЕНИЕ СОБЫТИЯ");

    const std::string name = readText("  Название события: ");

    // Запрещаем повторяющиеся названия событий.
    for (const Event& event : events) {
        if (event.name == name) {
            std::cout << "\n  Ошибка: событие с таким названием уже существует.\n";
            return;
        }
    }

    // Получаем время начала и окончания.
    Time start = readTime("ВРЕМЯ НАЧАЛА");
    Time end = readTime("ВРЕМЯ ОКОНЧАНИЯ");

    // Событие не добавляется, если окончание раньше начала.
    if (end < start) {
        std::cout << "\n  Ошибка: время окончания раньше времени начала.\n"
                  << "  Событие не добавлено.\n";
        return;
    }

    // Добавляем новое событие в конец списка.
    events.emplace_back(name, start, end);

    std::cout << "\n  Событие добавлено.\n";
}

// Изменяет выбранное событие после проверок названия и времени.
void changeEventTime(std::vector<Event>& events) {
    printHeader("ИЗМЕНЕНИЕ СОБЫТИЯ");

    if (events.empty()) {
        std::cout << "  Нет событий для изменения.\n";
        return;
    }

    // Показываем список, чтобы пользователь выбрал нужный номер.
    showSchedule(events);

    const int index = readInt(
        "\n  Номер события: ",
        1,
        static_cast<int>(events.size())
    );

    const std::string newName = readText("  Новое название события: ");

    // Проверяем уникальность нового названия, кроме изменяемого события.
    for (std::size_t i = 0; i < events.size(); ++i) {
        if (i != static_cast<std::size_t>(index - 1) &&
            events[i].name == newName) {
            std::cout << "\n  Ошибка: событие с таким названием уже существует.\n"
                      << "  Изменения не сохранены.\n";
            return;
        }
    }

    // Получаем новое время.
    Time start = readTime("НОВОЕ ВРЕМЯ НАЧАЛА");
    Time end = readTime("НОВОЕ ВРЕМЯ ОКОНЧАНИЯ");

    if (end < start) {
        std::cout << "\n  Ошибка: время окончания раньше времени начала.\n"
                  << "  Изменения не сохранены.\n";
        return;
    }

    // Сохраняем новые данные в выбранном элементе списка.
    Event& event = events[static_cast<std::size_t>(index - 1)];
    event.name = newName;
    event.start = start;
    event.end = end;

    std::cout << "\n  Событие изменено.\n";
}

// Демонстрирует все шесть операторов сравнения для двух введённых времён.
void compareTimes() {
    printHeader("СРАВНЕНИЕ ВРЕМЕНИ");

    Time first = readTime("ПЕРВОЕ ВРЕМЯ");
    Time second = readTime("ВТОРОЕ ВРЕМЯ");

    std::cout << '\n' << SEPARATOR << '\n'
              << "  Первое время:  " << first << '\n'
              << "  Второе время:  " << second << '\n'
              << SEPARATOR << '\n';

    printResult("Первое время меньше второго:", first < second);
    printResult("Первое время больше второго:", first > second);
    printResult("Первое меньше или равно второму:", first <= second);
    printResult("Первое больше или равно второму:", first >= second);
    printResult("Время одинаковое:", first == second);
    printResult("Время различается:", first != second);
}

// Показывает работу арифметических, унарных и составных операторов Time.
void demonstrateOperators() {
    printHeader("ДЕМОНСТРАЦИЯ ОПЕРАТОРОВ");

    Time first = readTime("ПЕРВОЕ ВРЕМЯ");
    Time second = readTime("ВТОРОЕ ВРЕМЯ");

    printHeader("АРИФМЕТИЧЕСКИЕ ОПЕРАТОРЫ");

    std::cout << "  Первое время:       " << first << '\n'
              << "  Второе время:       " << second << '\n'
              << "  Сложение (+):       " << first + second << '\n'
              << "  Вычитание (-):      " << first - second << '\n'
              << "  Умножение (*):      " << first * second << '\n';

    // Перед делением проверяем, что второе время не равно нулю.
    if (second.getTotalSeconds() != 0) {
        std::cout << "  Деление (/):        " << first / second << '\n';
    } else {
        std::cout << "  Деление (/):        невозможно, делитель равен нулю\n";
    }

    printHeader("УНАРНЫЕ ОПЕРАТОРЫ");

    Time value = first;

    // Префиксные операторы сначала меняют значение, постфиксные возвращают старое.
    std::cout << "  Исходное значение:     " << value << '\n';
    std::cout << "  Префиксный ++:         " << ++value << '\n';
    std::cout << "  Постфиксный ++:        " << value++ << '\n';
    std::cout << "  После постфиксного ++: " << value << '\n';
    std::cout << "  Префиксный --:         " << --value << '\n';
    std::cout << "  Постфиксный --:        " << value-- << '\n';
    std::cout << "  После постфиксного --: " << value << '\n';

    printHeader("СОСТАВНЫЕ ОПЕРАТОРЫ");

    value = first;
    value += second;
    std::cout << "  После +=: " << value << '\n';

    value = first;
    value -= second;
    std::cout << "  После -=: " << value << '\n';

    value = first;
    value *= second;
    std::cout << "  После *=: " << value << '\n';

    if (second.getTotalSeconds() != 0) {
        value = first;
        value /= second;
        std::cout << "  После /=: " << value << '\n';
    } else {
        std::cout << "  После /=: деление на ноль невозможно\n";
    }

    printHeader("CONST, MUTABLE И EXPLICIT");

    const Time constantTime(12, 30, 0);

    std::cout << "  Константный объект: " << constantTime << '\n'
              << "  Счётчик до вызовов: " << constantTime.getAccessCount() << '\n';

    // Методы чтения увеличивают mutable-счётчик даже у const-объекта.
    constantTime.getHours();
    constantTime.getMinutes();
    constantTime.getSeconds();

    std::cout << "  Счётчик после вызовов: "
              << constantTime.getAccessCount() << '\n';

    std::cout << "  Проверка explicit: static_assert успешно скомпилирован.\n"
              << "  Неявное преобразование int в Time запрещено.\n";

    // Создаём объект явно из количества секунд.
    Time explicitTime(3600);

    std::cout << "  Явное создание Time(3600): " << explicitTime << '\n';

    printHeader("КОНСТРУКТОРЫ");

    // Демонстрируем разные способы создания объекта Time.
    Time defaultTime;
    Time secondsTime(3661);
    Time hmsTime(1, 1, 1);

    std::cout << "  Конструктор по умолчанию: " << defaultTime << '\n'
              << "  Конструктор Time(int):    " << secondsTime << '\n'
              << "  Конструктор Time(h,m,s):  " << hmsTime << '\n';
}

// Показывает число объектов Time, которые существуют в данный момент.
void showStatistics() {
    printHeader("СТАТИСТИКА ОБЪЕКТОВ");

    std::cout << "  Количество существующих объектов Time: "
              << Time::getObjectCount() << '\n';
}

/**
 * @brief Точка входа в программу.
 * @return 0 при штатном завершении.
 *
 * Хранит список событий и вызывает функцию согласно выбранному пункту меню.
 */
int main() {
    std::vector<Event> events;

    // Главное меню повторяется, пока пользователь не выберет выход.
    while (true) {
        showMenu();

        const int choice = readInt("  Выберите действие: ", 0, 6);

        // Вызываем обработчик выбранного пункта меню.
        switch (choice) {
            case 1:
                showSchedule(events);
                break;

            case 2:
                addEvent(events);
                break;

            case 3:
                changeEventTime(events);
                break;

            case 4:
                compareTimes();
                break;

            case 5:
                demonstrateOperators();
                break;

            case 6:
                showStatistics();
                break;

            case 0:
                return 0;
        }
    }
}