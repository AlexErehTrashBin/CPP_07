#include <iostream>

#include "matrix.hpp"

using namespace Task07;

int main() {
    const Matrix<double> matrix1{{1.2, 4.2, 3}, {6, 2, 5}, {8, 7, 9}};

    // Вывод исходной матрицы
    std::cout << "Исходная матрица:" << std::endl;
    std::cout << matrix1 << std::endl;

    // Транспонирование матрицы
    const Matrix transposed = matrix1.transpose();
    std::cout << "Транспонированная матрица:" << std::endl;
    std::cout << transposed << std::endl;



    const Matrix<double> matrix2{{1.2, 4.2, 3}, {6, 2, 5}, {8, 7, 9}};

    // Сравнение матриц
    if (matrix2 == matrix1) {
        std::cout << "Матрицы равны." << std::endl;
    } else {
        std::cout << "1";
    }

    // Сортировка элементов по строкам
    matrix1.sortByRows();
    std::cout << "Матрица после сортировки элементов по строкам:" << std::endl;
    std::cout << matrix1 << std::endl;

    // Сортировка элементов по столбцам
    matrix1.sortByCols();
    std::cout << "Матрица после сортировки элементов по столбцам:" << std::endl;
    std::cout << matrix1 << std::endl;
    return 0;
}
