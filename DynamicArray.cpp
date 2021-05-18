#include "DynamicArray.h"

//Конструкторы
template<typename T> DynamicArray<T>::DynamicArray(): size(0) {
    this->size = 0;
}

template<typename T> DynamicArray<T>::DynamicArray(int size) : size(size){
    if (size<0) {
        throw length_error(NEGATIVE_SIZE);
    }
    this->size = size;
    this->data = new T[this->size];
}

template<typename T> DynamicArray<T>::DynamicArray(T* items, int size) : size(size), DynamicArray(size) { //DynamicArray(size)
    if (size < 0) {
        throw length_error(NEGATIVE_SIZE);
    }
    this->size = size;
    for (int i = 0; i < size; i++) {
        this->data[i] = items[i];
    }
}

template<typename T> DynamicArray<T>::DynamicArray(const DynamicArray<T> & array) : size(array->size), DynamicArray(array->size) { //DynamicArray(array.size)
    if (size < 0) {
        throw out_of_range(INDEX_OUT_OF_RANGE);
    }
    this->size = size;
    for (int i = 0; i < array->size; i++)
        this->data[i] = *array[i];
}

//Декомпозиция

template<typename T> T DynamicArray<T>::Get(int index) const {
    if (index < 0 || index >= this->size) {
        throw out_of_range(INDEX_OUT_OF_RANGE);
    }
    return this->data[index];
}

template<typename T> int DynamicArray<T>::GetSize() const {
    return this->size;
}

//Операции

template<typename T> void DynamicArray<T>::Set(int index, T value) {
    if (index<0 || index >=this->size) {
        throw out_of_range(INDEX_OUT_OF_RANGE);
    }
    this->data[index] = value;
}

template<typename T> void DynamicArray<T>::Resize(int newSize) {
    if (newSize < 0) {
        throw length_error(NEGATIVE_SIZE);
    }
    T* newData = new T[newSize];
    for (int i = 0; i < (this->size > newSize ? newSize : this->size); i++) {
        newData[i] = data[i];
    }
    delete[] data;
    this->data = newData;
    this->size = newSize;
}