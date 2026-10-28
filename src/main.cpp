
#include "matrix.h"

#include <iostream>
#include <exception>

int main()
{
    try
    {
        Matrix a = create_matrix(2, 2);
        Matrix b = create_matrix(2, 2);

        a.data[0][0] = 1;
        a.data[0][1] = 2;
        a.data[1][0] = 3;
        a.data[1][1] = 4;

        b.data[0][0] = 5;
        b.data[0][1] = 6;
        b.data[1][0] = 7;
        b.data[1][1] = 8;

        std::cout << "Матрица A:\n";
        print_matrix(a);

        std::cout << "\nМатрица B:\n";
        print_matrix(b);

        Matrix sum = matrix_add(a, b);
        std::cout << "\nСумма матриц:\n";
        print_matrix(sum);

        Matrix product = matrix_multiply(a, b);
        std::cout << "\nПроизведение матриц:\n";
        print_matrix(product);

        std::cout << "\nМинимальный элемент матрицы A: "
                  << matrix_min(a) << '\n';

        free_matrix(a);
        free_matrix(b);
        free_matrix(sum);
        free_matrix(product);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
