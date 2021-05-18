#ifndef LABORATORY2_SEQUENCE_H
#define LABORATORY2_SEQUENCE_H
#include "DynamicArray.h"
#include "LinkedList.h"
template <typename T> class Sequence { //базовый класс
public:
    //Декомпозиция
    virtual int GetLength() const = 0; //Получить длину списка
    virtual T Get(int index) const = 0; //Получить элемент по индексу
    virtual T GetLast() const = 0; //Получить последний элемент в списке
    virtual T GetFirst() const = 0; //Получить первый элемент в списке
    virtual Sequence<T>* GetSubSequence(int startIndex, int endIndex) = 0; //Получить список из всех элементов, начиная с startIndex и заканчивая endIndex.

    //Операции
    virtual void Set(int index, T item) = 0; //Задать элемент по индексу //не указано в условии
    virtual void Append(T item) = 0; //Добавляет элемент в конец списка
    virtual void Prepend(T item) = 0; //Добавляет элемент в начало списка
    virtual void InsertAt(T item, int index) = 0; //Вставляет элемент в заданную позицию
    virtual Sequence<T>* Concat(Sequence<T>* list) = 0; //Сцепляет два списка
};

#endif //LABORATORY2_SEQUENCE_H
