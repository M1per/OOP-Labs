
#ifndef MUSICAL_INSTRUMENT_H
#define MUSICAL_INSTRUMENT_H

#include <string>
#include <map>
#include <iosfwd>

class MusicalInstrument {
private:
    // Общее количество существующих инструментов.
    static int instrumentCount;

    // Количество вызовов play() для каждого типа.
    static std::map<std::string, int> playStatistics;

protected:
    // Увеличивает счётчик воспроизведений конкретного типа.
    void registerPlay(const std::string& type);

public:
    // Конструктор.
    MusicalInstrument();

    // Конструктор копирования.
    MusicalInstrument(const MusicalInstrument& other);

    // Оператор присваивания.
    MusicalInstrument& operator=(const MusicalInstrument& other);

    // Виртуальный деструктор.
    virtual ~MusicalInstrument();

    // Чисто виртуальные функции.
    virtual void play() = 0;
    virtual std::string getType() const = 0;

    // Виртуальная функция с реализацией по умолчанию.
    virtual void tune() const;

    // Статические функции.
    static int getInstrumentCount();
    static std::string getMostPlayedType();

    // Дружественная функция.
    friend std::ostream& operator<<(
        std::ostream& out,
        const MusicalInstrument& instrument
    );
};

#endif
