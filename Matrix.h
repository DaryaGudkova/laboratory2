#include "ArraySequence.h"

#ifndef LABORATORY2_MATRIX_H
#define LABORATORY2_MATRIX_H

template <typename T> class DiagonaleMatrix {
private:
    ArraySequence<T> *matrix;
public:

    //Constructor
    DiagonaleMatrix() {
        matrix = new ArraySequence<T>;
    };

    DiagonaleMatrix(T *items, int count) {
        matrix = new ArraySequence<T>(items, count);
    }

    DiagonaleMatrix(ArraySequence<T> *new_matrix) {
        matrix = new_matrix;
    }

    DiagonaleMatrix(DiagonaleMatrix<T> *new_matrix) {
        matrix = new_matrix->matrix;
    }

    //Destructor
    ~DiagonaleMatrix() = default;


    //Decomposition
    T GetElement(int row, int col) {
        try{
            if (row < 0 || col < 0 || col >= this->GetSize() || row >= this->GetSize())
                throw "Index out of range!";
            if (row == col)
                return matrix->Get(row);
            else
                return (T) 0;
        }
        catch (const char* error){
            std::cerr<<"Error: "<<error;
        }
    }

    int GetSize() {
        return matrix->GetSize();
    }

    //Operations
    void Append(T item) {
        return matrix->Append(item);
    };

    void Set(T item, int row, int col) {
        try{
            if (row < 0 || col < 0 || col >= this->GetSize() || row >= this->GetSize())
                throw "Index out of range!";
            if (row == col)
                return matrix->Set(item, row);
            else
                throw "Wrong position!";
        }
        catch (const char* error){
            std::cerr<<"Error: "<<error;
        }
    };

    template<typename U>
    U MatrixNorm() {
        U sum = this->GetElement(0, 0) * this->GetElement(0, 0);
        for (int i = 1; i < this->GetSize(); i++)
            sum += this->GetElement(i, i) * this->GetElement(i, i);
        return sqrt(sum);
    }

    DiagonaleMatrix<T> *MultiplyOnScalar(T scalar) {
        T item;
        DiagonaleMatrix<T> *new_Matrix = new DiagonaleMatrix<T>(matrix);
        for (int i = 0; i < this->GetSize(); i++) {
            item = this->GetElement(i, i) * scalar;
            new_Matrix->matrix->Set(item, i);
        }
        return new_Matrix;
    };

    DiagonaleMatrix<T> *SumOfMatrix(DiagonaleMatrix<T> *matrix1) {
        try{
            if (this->GetSize() != matrix1->GetSize())
                throw "Different size!";
            DiagonaleMatrix<T> *new_Matrix = new DiagonaleMatrix<T>();
            T item;
            for (int i = 0; i < this->GetDim(); i++) {
                item = this->GetElement(i, i) + matrix1->GetElement(i, i);
                new_Matrix->Append(item);
            }
            return new_Matrix;
        }
        catch (const char* error){
            std::cerr<<"Error: "<<error;
        }
    };
};
#endif //LABORATORY2_MATRIX_H
