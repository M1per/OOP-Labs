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

    std::cout << "Массив: ";

    for (int i = 0; i < myArr.size; ++i)
    {
        std::cout << myArr.data[i] << " ";
    }

    std::cout << std::endl;

    delete[] myArr.data;

    return 0;
}