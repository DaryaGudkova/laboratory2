#ifndef LABORATORY2_LINKEDLIST_H
#define LABORATORY2_LINKEDLIST_H

#include <iostream>
using namespace std;

#include <cassert>

template <typename T> class Item
{
public:
    T data;	// Любые данные
    Item<T>* next;	//Указатель на следующиий элемент в цепочке
    Item<T>* previous; // Указатель на предыдущий элемент в цепочке
};

template <typename T> class LinkedList
{
private:
    Item<T>* head;	// Голова списка
    Item<T>* tail;
    int length;	// Длина списка
public:
// Конструкторы
    LinkedList();// Создать пустой список
    LinkedList(T* items, int count); //	Копировать элементы из переданного массива
    // TODO: Сделать реализацию LinkedList
    LinkedList(LinkedList <T>& list);  // Копирующий конструктор

// Декомпозиция
    T GetFirst(); // Получить первый элемент в списке. Может выбрасывать исключения : − IndexOutOfRange(если список пуст)
    T GetLast(); // Получить последний элемент в списке. Может выбрасывать исключения : − IndexOutOfRange(если список пуст)

    T Get(int index); // Получить элемент по индексу. Может выбрасывать исключения :− IndexOutOfRange(если индекс отрицательный или больше / равен числу элементов)
    // Получить список из всех элементов, начиная с startIndex и заканчивая endIndex.
    // Может выбрасывать исключения :− IndexOutOfRange(если хотя бы один из
    // индексов отрицательный или больше / равен числу элементов)

    LinkedList<T>* GetSubList(int startIndex, int endIndex); //Получить список из всех элементов, начиная с startIndex и заканчивая endIndex.

    int GetLength();	// Получить длину списка

// Операции
    void Append(T item);// Добавляет элемент в конец списка
    void Prepend(T item); // Добавляет элемент в начало списка
    void InsertAt(T item, int index);   // Вставляет элемент в заданную позицию.
                                        // Может выбрасывать исключения : − IndexOutOfRange(если индекс отрицательный или больше / равен числу элементов)
    LinkedList<T>* Concat(LinkedList<T>* list);//Сцепляет два списка
};

#endif //LABORATORY2_LINKEDLIST_H
