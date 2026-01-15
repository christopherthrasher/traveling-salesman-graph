// ArrayQueue Class

#ifndef ARRAY_QUEUE_CPP
#define ARRAY_QUEUE_CPP

#include "arrayqueue.h"

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() {
    front = 0;
    back = DEFAULT_CAPACITY - 1;
    itemCount = 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry) {
    if (itemCount == DEFAULT_CAPACITY) {
        return false;
    }

    back = (back + 1) % DEFAULT_CAPACITY;
    queue[back] = newEntry;
    itemCount++;
    return true;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue() {
    if (isEmpty()) {
        return false;
    }

    front = (front + 1) % DEFAULT_CAPACITY;
    itemCount--;
    return true;
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const {
    if (isEmpty()) {
        throw "Queue is empty";
    }
    return queue[front];
}

#endif
