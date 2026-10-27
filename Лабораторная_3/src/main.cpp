#include "Time.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <type_traits>
#include <vector>

struct Event {
    std::string name;
    Time start;
    Time end;

    Event(const std::string& eventName, const Time& eventStart, const Time& eventEnd)
        : name(eventName), start(eventStart), end(eventEnd) {}
};

const std::string LINE(66, '=');
const std::string SEPARATOR(66, '-');

void printHeader(const std::string& title) {
    std::cout << '\n' << LINE << '\n'
              << "  " << title << '\n'
              << LINE << '\n';
}

void printResult(const std::string& description, bool result) {
    std::cout << "  " << std::left << std::setw(42) << description
              << (result ? "Да" : "Нет") << '\n';
}

int readInt(const std::string& prompt, int minValue, int maxValue) {
    int value;

    while (true) {
        std::cout << prompt;

        if (std::cin >> value && value >= minValue && value <= maxValue) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cout << "  Ошибка: введите целое число от "
                  << minValue << " до " << maxValue << ".\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

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

Time readTime(const std::string& title) {
    printHeader(title);

    int hours = readInt("  Часы    [0-23]: ", 0, 23);
    int minutes = readInt("  Минуты  [0-59]: ", 0, 59);
    int seconds = readInt("  Секунды [0-59]: ", 0, 59);

    return Time(hours, minutes, seconds);
}

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

void showSchedule(const std::vector<Event>& events) {
    printHeader("РАСПИСАНИЕ НА ДЕНЬ");

    if (events.empty()) {
        std::cout << "  Расписание пустое.\n";
        return;
    }

    std::cout << "  " << std::left
              << std::setw(5) << "№"
              << std::setw(25) << "Событие"
              << std::setw(17) << "Начало"
              << "Окончание\n"
              << "  " << SEPARATOR << '\n';

    for (std::size_t i = 0; i < events.size(); ++i) {
        std::string name = events[i].name;

        if (name.length() > 23) {
            name = name.substr(0, 20) + "...";
        }

        std::cout << "  "
                  << std::left << std::setw(5) << i + 1
                  << std::setw(25) << name
                  << std::setw(17) << events[i].start
                  << events[i].end << '\n';
    }

    std::cout << "  " << SEPARATOR << '\n'
              << "  Всего событий: " << events.size() << '\n';
}

void addEvent(std::vector<Event>& events) {
    printHeader("ДОБАВЛЕНИЕ СОБЫТИЯ");

    std::string name = readText("  Название события: ");

    for (const Event& event : events) {
        if (event.name == name) {
            std::cout << "\n  Ошибка: событие с названием \""
                      << name << "\" уже существует.\n";
            return;
        }
    }

    Time start = readTime("ВРЕМЯ НАЧАЛА");
    Time end = readTime("ВРЕМЯ ОКОНЧАНИЯ");

    if (end < start) {
        std::cout << "\n  Ошибка: время окончания раньше времени начала.\n"
                  << "  Событие не добавлено.\n";
        return;
    }

    events.emplace_back(name, start, end);
    std::cout << "\n  Событие добавлено.\n";
}

void changeEventTime(std::vector<Event>& events) {
    printHeader("ИЗМЕНЕНИЕ СОБЫТИЯ");

    if (events.empty()) {
        std::cout << "  Нет событий для изменения.\n";
        return;
    }

    showSchedule(events);

    int index = readInt(
        "\n  Номер события: ",
        1,
        static_cast<int>(events.size())
    );

    std::string newName = readText("  Новое название события: ");

    for (std::size_t i = 0; i < events.size(); ++i) {
        if (i != static_cast<std::size_t>(index - 1) &&
            events[i].name == newName) {
            std::cout << "\n  Ошибка: событие с названием \""
                      << newName << "\" уже существует.\n"
                      << "  Изменения не сохранены.\n";
            return;
        }
    }

    Time start = readTime("НОВОЕ ВРЕМЯ НАЧАЛА");
    Time end = readTime("НОВОЕ ВРЕМЯ ОКОНЧАНИЯ");

    if (end < start) {
        std::cout << "\n  Ошибка: время окончания раньше начала.\n"
                  << "  Изменения не сохранены.\n";
        return;
    }

    events[index - 1].name = newName;
    events[index - 1].start = start;
    events[index - 1].end = end;

    std::cout << "\n  Событие \"" << newName << "\" изменено.\n";
}

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
    printResult("Первое время меньше или равно:", first <= second);
    printResult("Первое время больше или равно:", first >= second);
    printResult("Время одинаковое:", first == second);
    printResult("Время различается:", first != second);
}

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

    if (second.getTotalSeconds() != 0) {
        std::cout << "  Деление (/):        " << first / second << '\n';
    } else {
        std::cout << "  Деление (/):        невозможно, делитель равен нулю\n";
    }

    printHeader("УНАРНЫЕ ОПЕРАТОРЫ");

    Time value = first;

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
              << "  Счётчик до вызовов: "
              << constantTime.getAccessCount() << '\n';

    constantTime.getHours();
    constantTime.getMinutes();
    constantTime.getSeconds();

    std::cout << "  Счётчик после вызовов: "
              << constantTime.getAccessCount() << '\n';

    printResult(
        "Неявное преобразование int в Time запрещено:",
        !std::is_convertible<int, Time>::value
    );

    std::cout << "  Явное создание Time(3600): "
              << Time(3600) << '\n';
}

void showStatistics() {
    printHeader("СТАТИСТИКА ОБЪЕКТОВ");

    int before = Time::getObjectCount();

    std::cout << "  Объектов до проверки: "
              << before << '\n';

    {
        Time temporary;

        std::cout << "  После создания объекта: "
                  << Time::getObjectCount() << '\n';
    }

    std::cout << "  После уничтожения объекта: "
              << Time::getObjectCount() << '\n';

    printResult(
        "Счётчик восстановился после деструктора:",
        Time::getObjectCount() == before
    );
}

int main() {
    std::vector<Event> events;

    while (true) {
        showMenu();

        int choice = readInt("  Выберите действие: ", 0, 6);

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