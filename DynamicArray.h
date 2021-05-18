#ifndef LABORATORY2_DYNAMICARRAY_H
#define LABORATORY2_DYNAMICARRAY_H

#include <iostream>
using namespace std;

#include <stdexcept>

const string NEGATIVE_SIZE = "size is negative";
const string INDEX_OUT_OF_RANGE = "index out of range";

template <typename T>  class DynamicArray {

private:
    T* data;
    int size;

public:
    // Конструкторы
    DynamicArray(); // без инициализации.
    DynamicArray(int size); //Создать массив заданной длины
    DynamicArray(T* items, int size); //Копировать элементы из переданного массива
    DynamicArray(const DynamicArray<T> & array); //Копирующий конструктор

    //Декомпозиция
    T Get(int index) const; //Получить элемент по индексу.
    int GetSize() const; //Получить размер массива

    //Операции
    void Set(int index, T value); //Задать элемент по индексу
    void Resize(int newSize); //Изменить размер массива

    //Деструктор
    ~DynamicArray() {
        delete[] data;
    };
};


#endif //LABORATORY2_DYNAMICARRAY_H