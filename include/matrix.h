
#ifndef MATRIX_H
#define MATRIX_H

/**
 * @brief Структура для хранения матрицы.
 */
struct Matrix
{
    double** data;
    int rows;
    int cols;
};

/**
 * @brief Создаёт матрицу заданного размера.
 */
Matrix create_matrix(int rows, int cols);

/**
 * @brief Освобождает память, занятую матрицей.
 */
void free_matrix(Matrix& m);

/**
 * @brief Складывает две матрицы.
 */
Matrix matrix_add(const Matrix& a, const Matrix& b);

/**
 * @brief Умножает две матрицы.
 */
Matrix matrix_multiply(const Matrix& a, const Matrix& b);

/**
 * @brief Выводит матрицу на экран.
 */
void print_matrix(const Matrix& m);

/**
 * @brief Создаёт матрицу из двумерного массива.
 */
Matrix matrix_from_array(const double* const* arr, int rows, int cols);

/**
 * @brief Находит минимальный элемент матрицы.
 */
double matrix_min(const Matrix& m);

#endif
