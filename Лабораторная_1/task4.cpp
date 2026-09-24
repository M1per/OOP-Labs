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

int main()
{
    int rows = 3;
    int cols = 4;

    int** matrix = allocateMatrix(rows, cols);

    std::cout << "Матрица успешно выделена: "
              << rows << " x " << cols << std::endl;

    return 0;
}