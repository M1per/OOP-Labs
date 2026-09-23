#include <iostream>

/**
 * @brief Заполняет статический массив целыми числами.
 *
 * Функция получает массив из 10 элементов по ссылке
 * и заполняет его значениями, введёнными пользователем.
 *
 * @param arr Массив из 10 целых чисел.
 */
void fillArray(int (&arr)[10])
{
    std::cout << "Введите 10 целых чисел: ";

    for (int i = 0; i < 10; ++i)
    {
        std::cin >> arr[i];
    }
}

int main()
{
    int arr[10]{};

    fillArray(arr);

    return 0;
}
