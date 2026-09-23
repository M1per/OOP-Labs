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

/**
 * @brief Выводит элементы безопасного массива.
 *
 * Функция не изменяет массив, поэтому используется const-ссылка.
 *
 * @param arr Безопасный массив для вывода.
 */
void printSafe(const SafeArray& arr)
{
    for (int i = 0; i < arr.size; ++i)
    {
        std::cout << arr.data[i] << " ";
    }

    std::cout << std::endl;
}

/**
 * @brief Изменяет размер безопасного массива.
 *
 * При уменьшении размера выводит элементы,
 * которые будут удалены.
 * При увеличении новые элементы получают значение 0.
 *
 * @param arr Безопасный массив.
 * @param newSize Новый размер массива.
 */
void reSizeArray(SafeArray& arr, int newSize)
{
    int* newData = new int[newSize]{};

    int copySize = arr.size;

    if (newSize < copySize)
    {
        copySize = newSize;

        std::cout << "Удаляемые элементы: ";

        for (int i = newSize; i < arr.size; ++i)
        {
            std::cout << arr.data[i] << " ";
        }

        std::cout << std::endl;
    }

    for (int i = 0; i < copySize; ++i)
    {
        newData[i] = arr.data[i];
    }

    delete[] arr.data;

    arr.data = newData;
    arr.size = newSize;
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
    printSafe(myArr);

    getElement(myArr, 2) = 999; // Изменяем третий элемент через ссылку
    getElement(myArr, 10) = 500; // Проверяем выход за границы

    std::cout << "После изменения: ";
    printSafe(myArr);

    reSizeArray(myArr, 3); // Уменьшаем массив до 3 элементов

    std::cout << "После уменьшения: ";
    printSafe(myArr);

    reSizeArray(myArr, 5); // Увеличиваем массив до 5 элементов

    std::cout << "После увеличения: ";
    printSafe(myArr);

    delete[] myArr.data;
    myArr.data = nullptr;

    return 0;
}