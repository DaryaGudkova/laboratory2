#include "LinkedList.h"

// Конструкторы
template<typename T> LinkedList<T>::LinkedList() : length(0) {
    head = NULL;
    tail = NULL;
    length = 0;
}

template<typename T> LinkedList<T>::LinkedList(T* items, int count): length(count), head(NULL), tail(NULL){
    if (count<0)
        throw length_error(NEGATIVE_SIZE);
    for (int i = 0; i < count; i++)
        this->Append(items[i]);
}

template<typename T> LinkedList<T>::LinkedList(LinkedList <T>& list): length(list.GetLength()), head(NULL), tail(NULL) {
        for (int i = 0; i < length; i++)
            Append(list.Get(i));
}

// Декомпозиция
template<typename T> T LinkedList<T>:: GetFirst(){
    if (this->GetLength()==0)
        throw out_of_range(INDEX_OUT_OF_RANGE);
    return head->data;
}

template<typename T> T LinkedList<T>:: GetLast() {
    if (this->GetLength()==0)
        throw out_of_range(INDEX_OUT_OF_RANGE);
    return tail->data;
}

template<typename T> T LinkedList<T>:: Get(int index){
    assert(!(index == 0 && length == 0));
    //cout << "test - " << "index = " << index << endl;
    if (index < 0 || index >= this->length)
        throw out_of_range(INDEX_OUT_OF_RANGE);
    Item<T>* buf = head;
    //cout << "test - " << "length = " << length << endl;
    //cout <<"test - "<<"head->data = "<< head->data<<endl;
    for (int i = 0; i < index; i++)
        buf = buf->next;
    return buf->data;
}

template<typename T> LinkedList<T>* LinkedList<T>:: GetSubList(int startIndex, int endIndex) {
    if (index < 0 || index >= this->length)
        throw out_of_range(INDEX_OUT_OF_RANGE);
    auto* buf = new LinkedList<T>();
    for (int i = startIndex; i <= endIndex; i++)
        buf->Append(Get(i));
    return buf;
}

template<typename T> int LinkedList<T>::GetLength()	{
    return length;
}

// Операции

template<typename T> void LinkedList<T>::Append(T item){
    length++;	//Увеличиваем число элементов на единицу
    auto* buf = new Item<T>;
    buf->next = NULL;
    buf->data = item;
    if (head == NULL) {
        head = buf;
        head->previous = NULL;
        tail = head;
    }
    else
    {
        tail->next = buf;
        buf->previous = tail;
        tail = buf; // Смещаем хвост
    }
}
template<typename T> void LinkedList<T>::Prepend(T item) {
    length++;	//Увеличиваем число элементов на единицу
    auto* buf = new Item<T>;
    buf->next = NULL;
    buf->data = item;
    if (head == NULL) {
        head = buf;
        head->previous = NULL;
        tail = head;
    }
    else {
        head->previous = buf;
        buf->next = head;
        head = buf; // Смещаем голову
    }
}
template<typename T> void LinkedList<T>:: InsertAt(T item, int index) {
    assert(index >= 0);
    assert(index < length);
    Item<T>* itemBefore = (*this)[index];

    if (itemBefore == NULL)
        Append(item);
    else
    {
        auto* buf = new Item<T>;
        buf->data = item;
        buf->previous = itemBefore;
        buf->next = itemBefore->next;
        itemBefore->next->previous = buf;
        itemBefore->next = buf;
        length++;
    }
}

template<typename T> LinkedList<T>* LinkedList<T>::Concat(LinkedList<T>* list) {
    auto* newLinkedList = new LinkedList<T>;
    for (int i = 0; i < this->GetLength(); i++) {
        newLinkedList->Append(this->Get(i));}
    for (int i = 0; i < list->GetLength(); i++){
        newLinkedList->Append(list->Get(i));
    }
    return newLinkedList;
}