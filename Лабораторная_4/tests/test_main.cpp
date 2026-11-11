
#include "MusicalInstrument.h"
#include "Guitar.h"
#include "Violin.h"
#include "Flute.h"
#include "SynthGuitar.h"
#include "IElectronicDevice.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

// Максимальное количество инструментов.
const int MAX_INSTRUMENTS = 20;

// Загрузка инструментов из файла.
int loadInstruments(
    const std::string& filename,
    MusicalInstrument* instruments[],
    int capacity
) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error(
            "Не удалось открыть файл с инструментами"
        );
    }

    std::string line;
    int count = 0;

    while (std::getline(file, line) && count < capacity) {
        if (line.empty()) {
            continue;
        }

        std::stringstream stream(line);

        std::string type;
        std::string firstParameter;
        std::string secondParameter;

        std::getline(stream, type, ';');
        std::getline(stream, firstParameter, ';');
        std::getline(stream, secondParameter, ';');

        try {
            if (type == "Guitar") {
                instruments[count] = new Guitar(
                    std::stoi(firstParameter),
                    std::stod(secondParameter)
                );
                ++count;
            }
            else if (type == "Violin") {
                instruments[count] = new Violin(
                    std::stoi(firstParameter),
                    std::stod(secondParameter)
                );
                ++count;
            }
            else if (type == "Flute") {
                instruments[count] = new Flute(
                    std::stod(firstParameter),
                    secondParameter
                );
                ++count;
            }
            else if (type == "SynthGuitar") {
                instruments[count] = new SynthGuitar(
                    std::stoi(firstParameter),
                    std::stod(secondParameter)
                );
                ++count;
            }
            else {
                std::cerr << "Неизвестный тип инструмента: "
                          << type << '\n';
            }
        }
        catch (const std::exception& error) {
            std::cerr << "Ошибка загрузки строки: "
                      << line << '\n';
            std::cerr << "Причина: "
                      << error.what() << '\n';
        }
    }

    return count;
}

// Демонстрация полиморфизма.
void testPolymorphism(
    MusicalInstrument* instruments[],
    int count
) {
    std::cout << "\n========== ПОЛИМОРФИЗМ ==========\n";

    for (int i = 0; i < count; ++i) {
        std::cout << "\nИнструмент: "
                  << *instruments[i] << '\n';

        instruments[i]->play();
        instruments[i]->tune();
    }
}

// Проверка электронных возможностей.
void testElectronicDevices(
    MusicalInstrument* instruments[],
    int count
) {
    std::cout << "\n========== ЭЛЕКТРОННЫЕ УСТРОЙСТВА ==========\n";

    for (int i = 0; i < count; ++i) {
        IElectronicDevice* device =
            dynamic_cast<IElectronicDevice*>(instruments[i]);

        if (device != nullptr) {
            std::cout << "\nНайдена синтезаторная гитара.\n";

            device->powerOn();
            device->setPatch("Рок");

            instruments[i]->play();
        }
    }
}

// Проверка глубокого копирования и присваивания.
void testCopying() {
    std::cout << "\n========== КОПИРОВАНИЕ ==========\n";

    Guitar original(6, 10.0);

    original.setStringName(0, "Ми");

    // Создаём копию.
    Guitar copied(original);

    // Изменяем оригинал.
    original.setStringName(0, "Ля");

    std::cout << "Оригинал: "
              << original.getStringName(0) << '\n';

    std::cout << "Копия: "
              << copied.getStringName(0) << '\n';

    if (copied.getStringName(0) == "Ми") {
        std::cout << "Глубокое копирование работает правильно.\n";
    }
    else {
        std::cout << "Ошибка глубокого копирования.\n";
    }

    // Проверка оператора присваивания.
    Guitar assigned;

    assigned = original;

    original.setStringName(0, "Соль");

    std::cout << "\nПосле присваивания:\n";

    std::cout << "Оригинал: "
              << original.getStringName(0) << '\n';

    std::cout << "Присвоенный объект: "
              << assigned.getStringName(0) << '\n';

    // Проверка самоприсваивания.
    assigned = assigned;

    std::cout << "Самоприсваивание выполнено.\n";
}

// Проверка обработки исключений.
void testExceptions() {
    std::cout << "\n========== ИСКЛЮЧЕНИЯ ==========\n";

    // Некорректное количество струн.
    try {
        Guitar invalidGuitar(0, 10.0);
    }
    catch (const std::exception& error) {
        std::cout << "Перехвачено исключение: "
                  << error.what() << '\n';
    }

    // Попытка выбрать эффект без включения устройства.
    try {
        SynthGuitar synth;

        synth.setPatch("Рок");
    }
    catch (const std::exception& error) {
        std::cout << "Перехвачено исключение: "
                  << error.what() << '\n';
    }

    // Проверка неправильного номера струны.
    try {
        Guitar guitar;

        guitar.setStringName(100, "Ми");
    }
    catch (const std::exception& error) {
        std::cout << "Перехвачено исключение: "
                  << error.what() << '\n';
    }
}

// Вывод общей статистики.
void showStatistics() {
    std::cout << "\n========== СТАТИСТИКА ==========\n";

    std::cout << "Количество существующих инструментов: "
              << MusicalInstrument::getInstrumentCount()
              << '\n';

    std::cout << "Самый часто воспроизводимый тип: "
              << MusicalInstrument::getMostPlayedType()
              << '\n';
}

int main() {
    MusicalInstrument* orchestra[MAX_INSTRUMENTS] = {};

    int count = 0;

    try {
        std::cout << "====================================\n";
        std::cout << "       МУЗЫКАЛЬНЫЙ ОРКЕСТР\n";
        std::cout << "====================================\n";

        // Загрузка данных.
        std::cout << "\nЗагрузка инструментов из файла...\n";

        count = loadInstruments(
            "data/instruments.txt",
            orchestra,
            MAX_INSTRUMENTS
        );

        std::cout << "Успешно загружено инструментов: "
                  << count << '\n';

        // Список инструментов.
        std::cout << "\n========== СПИСОК ИНСТРУМЕНТОВ ==========\n";

        for (int i = 0; i < count; ++i) {
            std::cout << i + 1 << ". "
                      << *orchestra[i] << '\n';
        }

        // Полиморфизм.
        testPolymorphism(orchestra, count);

        // Электронные устройства.
        testElectronicDevices(orchestra, count);

        // Копирование.
        testCopying();

        // Исключения.
        testExceptions();

        // Статистика.
        showStatistics();
    }
    catch (const std::exception& error) {
        std::cerr << "\nКритическая ошибка: "
                  << error.what() << '\n';
    }

    // Освобождение памяти.
    std::cout << "\n========== ЗАВЕРШЕНИЕ ==========\n";

    for (int i = 0; i < count; ++i) {
        delete orchestra[i];
        orchestra[i] = nullptr;
    }

    std::cout << "Все инструменты удалены.\n";

    std::cout << "Оставшееся количество объектов: "
              << MusicalInstrument::getInstrumentCount()
              << '\n';

    return 0;
}
