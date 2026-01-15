// ArrayQueue Class

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include "queue.h"

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType> {
private:
    static const int DEFAULT_CAPACITY = 100;
    ItemType queue[DEFAULT_CAPACITY];
    int front;
    int back;
    int itemCount;

public:
    ArrayQueue();
    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;
};

#include "arrayqueue.cpp"
#endif
