#include "ArraySequence.h"

#ifndef LABORATORY2_SQUAREMATRIX_H
#define LABORATORY2_SQUAREMATRIX_H

template <typename T> class SquareMatrix{
private:
    int size;
    ArraySequence<T> array_sequence;
public:

    //Constructor
    SquareMatrix(){
        array_sequence = new ArraySequence<T>;
    }

    SquareMatrix(T* array, int size_m){
        array_sequence = ArraySequence<T>(array, size_m * size_m);
        size = size_m;
    }

    SquareMatrix(const ArraySequence<T> arraySequence, int size_m){
        size = size_m;
        array_sequence = arraySequence;
    }

    //Destructor
    ~SquareMatrix() = default;


    //Decomposition
    int GetSize(){
        return size;
    }

    T GetElement(int row, int col){
        try{
            if (row < 0 || col < 0 || col >= this->GetSize() || row >= this->GetSize())
                throw "Index out of range!";
            return array_sequence.Get(row * size + col);
        }
        catch (const char* error){
            std::cerr<<"Error: "<<error;
        }
    }

    //Operations
    void Append(T item) {
        return array_sequence->Append(item);
    };

    void Set(T item, int row, int col) {
        try{
            if (row < 0 || col < 0 || col >= this->GetSize() || row >= this->GetSize())
                throw "Index out of range!";
            return array_sequence->Set(item, row);
        }
        catch (const char* error){
            std::cerr<<"Error: "<<error;
        }
    };

    U MatrixNorm() {
        U sum = this->GetElement(0, 0) * this->GetElement(0, 0);
        for (int i = 1; i < this->GetSize(); i++)
            sum += this->GetElement(i, i) * this->GetElement(i, i);
        return sqrt(sum);
    }

    SquareMatrix<T> *SumOfMatrix(SquareMatrix<T> matrix){
        if(size!=matrix.size){
            throw length_error("Different size!");
        }
        T *new_array = new T[size*size];
        for (int i = 0; i < size*size; i++) {
            new_array[i] = array_sequence.Get(i) + matrix.array_sequence->Get(i);
        }
        auto *newArray = new SquareMatrix<T>(new_array, size);
        return newArray;
    }

    SquareMatrix<T> *ScalarMultiplyMatrix(T scalar){
        T *new_array = new T[size*size];
        for (int i = 0; i < size*size; ++i) {
            new_array[i] = array_sequence.Get(i) * scalar;
        }
        auto *newArray = new SquareMatrix<T>(new_array, size);
        return newArray;
    }

    SquareMatrix<T> *MultiplyMatrix(SquareMatrix<T> matrix){
        if(size!=matrix.size)
            throw length_error("Different size!");
        T *a = new T[size*size];
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                a[i*size + j] = 0;
                for (int k = 0; k < size; ++k) {
                    a[i*size + j] = a[i*size + j] + array_sequence.Get(i * size + k) * matrix.array_sequence->Get(k * size + j);
                }
            }
        }
        auto *newArray = new SquareMatrix<T>(a, size);
        return newArray;
    }

    void MultiplyRow(SquareMatrix<T> *matrix, int row, T scalar) {
        if (row < 1 || row >= size)
            throw out_of_range("Index out of range!");
        for (int i = 0; i < size; i++) {
            matrix->Set(matrix->array_sequence->Get((row - 1) * size + i) * scalar, row - 1, i);
        }
    }

    void AddRowToRow(SquareMatrix<T> *matrix, int first, T second) {
        if (first < 1 || first >= size || second < 1 || second >= size)
            throw out_of_range("Index out of range!");
        for (int i = 0; i < size; ++i) {
            matrix->Set(matrix->array_sequence->Get((first - 1) * size + i) + matrix->array_sequence->Get((second - 1) * size + i), first-1, i);
        }
    }
    /*
    SquareMatrix<T> *MultiplyRow(int row, T scalar){
        if (row<1||row>size)
            throw out_of_range("Index out of range!");
        T *new_array = new T[size*size];
        for (int i = 0; i < size*size; ++i) {
            new_array[i] = array_sequence.Get(i) * scalar;
        }
        auto *newArray = new SquareMatrix<T>(new_array, size);
        return newArray;

        for (int i = 0; i < size; i++) {
            array_sequence.InsertAt(array_sequence.Get((row - 1) * size + i) * scalar, (row - 1) * size + i);
        }
    }

    SquareMatrix<T> *AddRowToRow(int first, int second){
        if (first<1||first>size||second<1||second>size)
            throw out_of_range("Index out of range!");
        for (int i = 0; i < size; ++i) {
            array_sequence.InsertAt(array_sequence.Get((first - 1) * size + i) + array_sequence.Get(second - 1 * size + i), first);
        }
    }  */
};

#endif //LABORATORY2_SQUAREMATRIX_H
