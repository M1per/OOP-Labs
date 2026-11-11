
#ifndef MUSICAL_INSTRUMENT_H
#define MUSICAL_INSTRUMENT_H

#include <string>
#include <map>
#include <iosfwd>

/**
 * @brief Абстрактный базовый класс музыкального инструмента.
 *
 * Определяет общий интерфейс всех музыкальных инструментов.
 * Содержит виртуальные методы воспроизведения и настройки,
 * а также общую статистику созданных и используемых инструментов.
 *
 * От данного класса наследуются StringInstrument и WindInstrument.
 */
class MusicalInstrument {
private:
    /**
     * @brief Общее количество существующих инструментов.
     *
     * Статическая переменная, общая для всех объектов класса
     * и его наследников.
     */
    static int instrumentCount;

    /**
     * @brief Статистика воспроизведения инструментов.
     *
     * Ключ — название типа инструмента,
     * значение — количество воспроизведений.
     */
    static std::map<std::string, int> playStatistics;

protected:
    /**
     * @brief Регистрирует воспроизведение инструмента.
     * @param type Название типа инструмента.
     */
    void registerPlay(const std::string& type);

public:
    /**
     * @brief Конструктор по умолчанию.
     *
     * Увеличивает общий счётчик созданных объектов.
     */
    MusicalInstrument();

    /**
     * @brief Конструктор копирования.
     * @param other Объект, данные которого копируются.
     */
    MusicalInstrument(const MusicalInstrument& other);

    /**
     * @brief Оператор присваивания.
     * @param other Объект, данные которого присваиваются.
     * @return Ссылка на текущий объект.
     */
    MusicalInstrument& operator=(const MusicalInstrument& other);

    /**
     * @brief Виртуальный деструктор.
     *
     * Уменьшает общий счётчик объектов.
     */
    virtual ~MusicalInstrument();

    /**
     * @brief Воспроизводит звук инструмента.
     *
     * Чисто виртуальный метод, реализуемый производными классами.
     */
    virtual void play() = 0;

    /**
     * @brief Возвращает название типа инструмента.
     * @return Строка с названием инструмента.
     */
    virtual std::string getType() const = 0;

    /**
     * @brief Выполняет стандартную настройку инструмента.
     *
     * Виртуальный метод имеет реализацию по умолчанию.
     * Производные классы могут переопределять его.
     */
    virtual void tune() const;

    /**
     * @brief Возвращает количество существующих инструментов.
     * @return Текущее количество объектов.
     */
    static int getInstrumentCount();

    /**
     * @brief Определяет наиболее часто воспроизводимый тип.
     * @return Название наиболее часто воспроизводимого инструмента.
     */
    static std::string getMostPlayedType();

    /**
     * @brief Выводит информацию об инструменте в поток.
     * @param out Поток вывода.
     * @param instrument Объект музыкального инструмента.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(
        std::ostream& out,
        const MusicalInstrument& instrument
    );
};

#endif
