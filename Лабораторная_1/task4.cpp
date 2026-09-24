#include <iostream>
#include <string>

/**
 * @brief Выделяет память под двумерный динамический массив.
 *
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return int** Указатель на двумерный массив.
 */
int** allocateMatrix(int rows, int cols)
{
    int** matrix = new int*[rows];

    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols]{};
    }

    return matrix;
}

/**
 * @brief Заполняет двумерный массив значениями пользователя.
 *
 * @param matrix Двумерный динамический массив.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 */
void fillMatrix(int** matrix, int rows, int cols)
{
    std::cout << "Введите элементы матрицы:" << std::endl;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
}

/**
 * @brief Красиво выводит двумерный массив.
 *
 * @param matrix Двумерный динамический массив.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @param showBorders Показывать ли рамку.
 * @param title Заголовок матрицы.
 */
void printMatrix(
    int** matrix,
    int rows,
    int cols,
    bool showBorders = true,
    std::string title = "Matrix")
{
    std::cout << title << std::endl;

    if (showBorders)
    {
        std::cout << "--------------------" << std::endl;
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }

    if (showBorders)
    {
        std::cout << "--------------------" << std::endl;
    }
}

int main()
{
    int rows = 3;
    int cols = 4;

    int** matrix = allocateMatrix(rows, cols);

    std::cout << "Матрица успешно выделена: "
              << rows << " x " << cols << std::endl;

    fillMatrix(matrix, rows, cols);

    printMatrix(matrix, rows, cols);

    return 0;
}