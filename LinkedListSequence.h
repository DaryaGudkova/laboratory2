#ifndef LABORATORY2_LINKEDLISTSEQUENCE_H
#define LABORATORY2_LINKEDLISTSEQUENCE_H

#include "ArraySequence.h"
#include "LinkedList.h"


template <class T>
class ListSequence : public Sequence<T>{ //производный класс

private:
    LinkedList<T>* linked_list;

public:
    // Конструкторы

    ListSequence()  { // Создать пустой список
        this->linked_list = new LinkedList<T>();
    }
    ListSequence(T* item, int size)  {  //Копировать элементы из переданного массива
        this->linked_list = new LinkedList<T>(item, size);
    }
    ListSequence(LinkedList<T>* list) {
        this->linked_list = list;
    }
    ListSequence(const ListSequence<T>& seq) { //Копирующий конструктор
        this->linked_list = new LinkedList<T>(*seq.linked_list);
    }

    //Декомпозиция
    int GetLength() const override{
        return this->linked_list->GetLength();
    }

    T Get(int index) const override{
        if (index < 0)
            throw out_of_range(INDEX_OUT_OF_RANGE);
        return this->linked_list->Get(index);
    }

    T GetFirst() const override {
        if (this->GetSize() == 0)
            throw out_of_range(INDEX_OUT_OF_RANGE);
        return this->linked_list->GetFirst();
    }

    T GetLast() const override {
        if (this->GetSize() == 0)
            throw out_of_range(INDEX_OUT_OF_RANGE);
        return this->linked_list->GetLast();
    }

    ListSequence<T>* GetSubSequence(int startIndex, int endIndex) override {
        if (startIndex < 0 || startIndex >= this->GetSize() || endIndex<0 || endIndex >= this->GetSize() || endIndex < startIndex)
            throw out_of_range(INDEX_OUT_OF_RANGE);
        auto* list = new LinkedList<T>();
        list = this->linked_list->GetSubList(startIndex, endIndex);
        auto* listSequence = new ListSequence<T>(list);
        return listSequence;
    }

    //Операции

    void Prepend(T item) override { //++
        this->linked_list->Prepend(item);
    }

    void Append(T item) override { //++
        this->linked_list->Append(item);
    }

    void InsertAt(T item, int index) override {
        this->linked_list->InsertAt(item, index);
    }

    ListSequence<T>* Concat(Sequence<T>* list) override {
        auto* newLinkedList = new ListSequence<T>;
        for (int i = 0; i < this->GetLength(); i++)
            newLinkedList->Append(this->Get(i));
        for (int i = 0; i < list->GetLength(); i++)
            newLinkedList->Append(list->Get(i));
        return newLinkedList;
    }

//DESTRUCTOR
    ~ListSequence() = default;
};

#endif //LABORATORY2_LINKEDLISTSEQUENCE_H
