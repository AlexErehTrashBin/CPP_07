#pragma once

#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

using std::vector, std::sort;

namespace Task07 {
    template<class T>
    class Matrix {
        T** data;
        int rows;
        int cols;
    public:
        // Конструктор по умолчанию
        Matrix(): data(nullptr), rows(0), cols(0) {
        }

        // Конструктор с указанием размеров
        Matrix(int rows, int cols);

        // Конструктор копирования
        Matrix(const Matrix&other);

        // C++ 11 - initializer list
        Matrix(std::initializer_list<std::initializer_list<T>> list);

        // Деструктор
        ~Matrix();

        // Метод для получения количества строк
        [[nodiscard]] int getRows() const;

        // Метод для получения количества столбцов
        [[nodiscard]] int getCols() const;

        // Метод для доступа к элементу матрицы
        T& operator()(int row, int col) const;

        // Метод для транспонирования матрицы
        [[nodiscard]] Matrix transpose() const;

        // Метод для сравнения матриц
        bool operator==(const Matrix&other) const;

        // Метод для сортировки элементов по строкам
        void sortByRows() const;

        // Метод для сортировки элементов по столбцам
        void sortByCols() const;

        static void bubbleSort(T* arr, int size);

        template <typename E>
        friend std::ostream& operator<< (std::ostream& ostream, const Matrix<E>& matrix);
    };

    template<typename E>
    std::ostream& operator<< (std::ostream& ostream, const Matrix<E>& matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                ostream << matrix.data[i][j] << " ";
            }
            ostream << std::endl;
        }
        return ostream;
    }

    template class Matrix<int>;
    template class Matrix<double>;


}