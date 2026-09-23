#include <iostream>

/**
 * @brief Безопасный динамический массив.
 */
struct SafeArray
{
    int* data; // Указатель на динамический массив
    int size;  // Размер массива
};

/**
 * @brief Создаёт безопасный массив заданного размера.
 *
 * @param size Размер массива.
 * @return SafeArray Созданная структура с динамическим массивом.
 */
SafeArray createArray(int size)
{
    SafeArray arr;

    arr.data = new int[size]{};
    arr.size = size;

    return arr; // Возвращаем структуру по значению
}

/**
 * @brief Возвращает ссылку на элемент безопасного массива.
 *
 * @param arr Безопасный массив.
 * @param index Индекс элемента.
 * @return int& Ссылка на элемент массива или на переменную-заглушку.
 */
int& getElement(SafeArray& arr, int index)
{
    static int errorValue = 0; // Статическая переменная-заглушка

    if (index < 0 || index >= arr.size)
    {
        std::cout << "Ошибка: индекс выходит за границы массива."
                  << std::endl;

        return errorValue;
    }

    return arr.data[index]; // Возвращаем ссылку на настоящий элемент
}

int main()
{
    int size;

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    SafeArray myArr = createArray(size);

    std::cout << "Введите " << size << " элементов: ";

    for (int i = 0; i < myArr.size; ++i)
    {
        std::cin >> myArr.data[i];
    }

    std::cout << "Исходный массив: ";

    for (int i = 0; i < myArr.size; ++i)
    {
        std::cout << myArr.data[i] << " ";
    }

    std::cout << std::endl;

    getElement(myArr, 2) = 999; // Изменяем третий элемент через ссылку

    std::cout << "После изменения: ";

    for (int i = 0; i < myArr.size; ++i)
    {
        std::cout << myArr.data[i] << " ";
    }

    std::cout << std::endl;

    delete[] myArr.data;

    return 0;
}