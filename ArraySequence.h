#ifndef LABORATORY2_ARRAYSEQUENCE_H
#define LABORATORY2_ARRAYSEQUENCE_H

#include "Sequence.h"
#pragma once
#include "DynamicArray.h"

template<typename T>
class ArraySequence : public Sequence<T> //производный класс
{
private:
    DynamicArray<T>* dynamic_array;

public:
    //Конструкторы

    ArraySequence(){// Создать пустой список
        this->dynamic_array = new DynamicArray<T>();
    };
    ArraySequence(int size){//Создать массив заданной длины
        this->dynamic_array = new DynamicArray<T>(size);
    };
    ArraySequence(const ArraySequence<T> & array) { //Копирующий конструктор
        this->dynamic_array = new DynamicArray<T>(*array.dynamic_array);
    };
    ArraySequence(T* items, int size)  { //Копировать элементы из переданного массива
        this->dynamic_array = new DynamicArray<T>(items, size);
    };

    //Декомпозиция

    T GetFirst() const override { //override для корректного переопределения
        if (this->GetLength() == 0)
            throw out_of_range(INDEX_OUT_OF_RANGE);
        return dynamic_array->Get(0);
    };

    T GetLast() const override{
        if (this->GetLength() == 0)
            throw out_of_range(INDEX_OUT_OF_RANGE);
        return dynamic_array->Get(dynamic_array->GetSize()-1);
    };

    T Get(int index) const override  { //++
        if (index < 0 || index >= this->GetLength())
            throw out_of_range(INDEX_OUT_OF_RANGE);
        return dynamic_array->Get(index);
    };
    ArraySequence<T>* GetSubSequence(int startIndex, int endIndex) override{
        if (startIndex < 0 || endIndex < 0 || startIndex >= this->GetLength() || endIndex >= this->GetLength() || endIndex < startIndex)
            throw out_of_range(INDEX_OUT_OF_RANGE);
        ArraySequence<T>* newArray = new ArraySequence<T>();
        for (int i = startIndex; i <= endIndex; i++)
            newArray->Append(this->Get(i));
        return newArray;
    }

    int GetLength () const override {
        return this->dynamic_array->GetSize();
    };

    //Операции

    void Set(int index, T item) override {
        if (index < 0 || index >= this->dynamic_array->GetSize())
            throw out_of_range(INDEX_OUT_OF_RANGE);
        return this->dynamic_array->Set(index, item);
    };

    void Append(T item) override { //IMPROVED
        auto* newArray = new DynamicArray<T>(this->GetLength() + 1);
        newArray->Set(this->GetSize(), item);
        for (int i = 0; i < this->GetLength(); i++)
            newArray->Set(i, this->Get(i));
        this->dynamic_array = newArray;
    };

    void Prepend(T item) override  {
        auto* newArray = new DynamicArray<T>(this->GetLength() + 1);
        newArray->Set(0, item);
        for (int i = 0; i < this->GetLength(); i++)
            newArray->Set(i + 1, this->Get(i));
        this->dynamic_array = newArray;
    };

    void InsertAt(T item, int index) override {
        if (index < 0 || index >= this->GetLength())
            throw out_of_range(INDEX_OUT_OF_RANGE);
        int newSize = this->GetLength() + 1;
        auto* newArray = new DynamicArray<T>(newSize);
        for (int i = 0; i < newSize; i++) {
            if (i == index) {
                newArray->Set(i, item);
                continue;
            }
            newArray->Set(i, this->Get(i));
        }
        dynamic_array = newArray;
    };

    ArraySequence<T>* Concat(Sequence<T> *arr) override {
        auto* newSequence = new ArraySequence<T>;
        for (int i = 0; i < this->GetLength(); i++) {
            newSequence->Append(this->Get(i));}
        for (int i = 0; i < arr->GetLength(); i++){
            newSequence->Append(arr->Get(i));
        }
        return newSequence;
    };

    //Операторы
    T operator[](const int index) override { //++
        return dynamic_array->Get(index);
    }

    //Деструктор
    ~ArraySequence() = default;

};

#endif //LABORATORY2_ARRAYSEQUENCE_H