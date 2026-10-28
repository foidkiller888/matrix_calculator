
#include "matrix.h"

#include <iostream>
#include <stdexcept>

// Создание матрицы
Matrix create_matrix(int rows, int cols)
{
    if (rows <= 0 || cols <= 0)
    {
        throw std::invalid_argument("Размеры матрицы должны быть положительными");
    }

    Matrix m{};
    m.rows = rows;
    m.cols = cols;
    m.data = new double*[rows];

    for (int i = 0; i < rows; ++i)
    {
        m.data[i] = new double[cols]{};
    }

    return m;
}

// Освобождение памяти
void free_matrix(Matrix& m)
{
    if (m.data != nullptr)
    {
        for (int i = 0; i < m.rows; ++i)
        {
            delete[] m.data[i];
        }

        delete[] m.data;
    }

    m.data = nullptr;
    m.rows = 0;
    m.cols = 0;
}

// Сложение матриц
Matrix matrix_add(const Matrix& a, const Matrix& b)
{
    if (a.rows != b.rows || a.cols != b.cols)
    {
        throw std::invalid_argument("Размеры матриц для сложения не совпадают");
    }

    Matrix result = create_matrix(a.rows, a.cols);

    for (int i = 0; i < a.rows; ++i)
    {
        for (int j = 0; j < a.cols; ++j)
        {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }

    return result;
}

// Умножение матриц
Matrix matrix_multiply(const Matrix& a, const Matrix& b)
{
    if (a.cols != b.rows)
    {
        throw std::invalid_argument("Количество столбцов первой матрицы должно совпадать с количеством строк второй");
    }

    Matrix result = create_matrix(a.rows, b.cols);

    for (int i = 0; i < a.rows; ++i)
    {
        for (int k = 0; k < a.cols; ++k)
        {
            for (int j = 0; j < b.cols; ++j)
            {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }

    return result;
}

// Вывод матрицы
void print_matrix(const Matrix& m)
{
    for (int i = 0; i < m.rows; ++i)
    {
        for (int j = 0; j < m.cols; ++j)
        {
            std::cout << m.data[i][j] << '\t';
        }

        std::cout << '\n';
    }
}

// Создание матрицы из двумерного массива
Matrix matrix_from_array(const double* const* arr, int rows, int cols)
{
    Matrix m = create_matrix(rows, cols);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            m.data[i][j] = arr[i][j];
        }
    }

    return m;
}

// Индивидуальное задание, вариант 7
double matrix_min(const Matrix& m)
{
    if (m.rows <= 0 || m.cols <= 0 || m.data == nullptr)
    {
        throw std::invalid_argument("Матрица пуста");
    }

    double minimum = m.data[0][0];

    for (int i = 0; i < m.rows; ++i)
    {
        for (int j = 0; j < m.cols; ++j)
        {
            if (m.data[i][j] < minimum)
            {
                minimum = m.data[i][j];
            }
        }
    }

    return minimum;
}
