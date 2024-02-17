#include "matrix.hpp"

using namespace Task07;

namespace Task07 {
    template<class T >
    Matrix<T>::Matrix(const int rows, const int cols) {
        this->rows = rows;
        this->cols = cols;
        this->data = new T *[rows];
        for (int i = 0; i < rows; ++i) {
            this->data[i] = new T[cols];
        }
    }

    template<class T>
    Matrix<T>::Matrix(const Matrix&other) {
        rows = other.rows;
        cols = other.cols;
        data = new T *[rows];
        for (int i = 0; i < rows; ++i) {
            this->data[i] = new T[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other(i, j);
            }
        }
    }

    // C++ 11 - initializer list
    template<class T>
    Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> list) {
        const size_t rows = list.size();
        size_t cols = 0;

        // C++ 11 - Range based for loop
        for (auto i : *list.begin()) {
            cols++;
        }

        this->rows = rows;
        this->cols = cols;
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            this->data[i] = new T[cols];
            auto row = list.begin();
            row += i;

            for (int j = 0; j < cols; ++j) {
                auto col_value = row->begin();
                col_value += j;
                data[i][j] = *col_value;
            }
        }
    }

    template<class T>
    Matrix<T>::~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
        rows = 0;
        cols = 0;
    }

    template<class T>
    int Matrix<T>::getRows() const {
        return rows;
    }

    template<class T>
    int Matrix<T>::getCols() const {
        if (rows == 0) {
            return 0;
        }
        return cols;
    }

    template<class T>
    T& Matrix<T>::operator()(const int row, const int col) const {
        if (row < 0 || row >= getRows() || col < 0 || col >= getCols()) {
            throw std::out_of_range("Invalid matrix index!");
        }
        return data[row][col];
    }

    template<class T>
    Matrix<T> Matrix<T>::transpose() const {
        Matrix transposed(getCols(), getRows());
        for (int i = 0; i < getRows(); i++) {
            for (int j = 0; j < getCols(); j++) {
                transposed.data[j][i] = data[i][j];
            }
        }
        return transposed;
    }

    template<class T>
    bool Matrix<T>::operator==(const Matrix&other) const {
        if (rows != other.rows) return false;
        if (cols != other.cols) return false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                const T thisElement = data[i][j];
                const T otherElement = other.data[i][j];
                if (thisElement != otherElement) return false;
            }
        }
        return true;
    }

    template<class T>
    void Matrix<T>::sortByRows() const {
        for (int i = 0; i < getRows(); i++) {
            T* row = new T[cols];
            for (int j = 0; j < cols; ++j) {
                row[j] = data[i][j];
            }
            bubbleSort(row, cols);
            for (int j = 0; j < cols; ++j) {
                data[i][j] = row[j];
            }
            delete[] row;
        }
    }

    template<class T>
    void Matrix<T>::sortByCols() const {
        for (int j = 0; j < getCols(); j++) {
            T* column = new T[rows];

            for (int i = 0; i < getRows(); i++) {
                column[i] = data[i][j];
            }
            bubbleSort(column, rows);
            for (int i = 0; i < getRows(); i++) {
                data[i][j] = column[i];
            }
            delete[] column;
        }
    }

    template<class T>
    void Matrix<T>::bubbleSort(T* arr, const int size) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Swapping elements
                    const int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}
