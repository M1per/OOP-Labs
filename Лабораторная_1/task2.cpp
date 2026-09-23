#include <iostream>

/**
 * @brief Обрабатывает динамический массив.
 *
 * Функция находит первый отрицательный элемент.
 * Если отрицательный элемент найден, создаёт новый динамический массив,
 * размер которого равен количеству элементов до первого отрицательного.
 * Элементы до отрицательного копируются в новый массив.
 * Старая память освобождается, а arr начинает указывать на новый массив.
 *
 * @param arr Ссылка на указатель на динамический массив.
 * @param size Размер исходного динамического массива.
 */
void process(int*& arr, int size)
{
    int firstNegative = -1; // Индекс первого отрицательного элемента

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] < 0)
        {
            firstNegative = i;
            break;
        }
    }

    // Если отрицательного элемента нет, массив не изменяем
    if (firstNegative == -1)
    {
        return;
    }

    int* newArr = new int[firstNegative]; // Новый массив только нужного размера

    for (int i = 0; i < firstNegative; ++i)
    {
        newArr[i] = arr[i]; // Копируем элементы до отрицательного
    }

    delete[] arr; // Освобождаем старый массив

    arr = newArr; // arr теперь указывает на новый массив
}

int main()
{
    int size;

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = new int[size]{}; // Выделяем динамический массив

    std::cout << "Введите " << size << " целых чисел: ";

    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    // Определяем количество элементов,
    // которые останутся после обработки
    int resultSize = size;

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] < 0)
        {
            resultSize = i;
            break;
        }
    }

    process(arr, size); // Передаём указатель по ссылке

    std::cout << "Результат: ";

    for (int i = 0; i < resultSize; ++i)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    delete[] arr; // Освобождаем память
    arr = nullptr; // Обнуляем указатель

    if (arr == nullptr)
    {
        std::cout << "Указатель обнулён, обращаться к памяти нельзя."
                  << std::endl;
    }

    return 0;
}