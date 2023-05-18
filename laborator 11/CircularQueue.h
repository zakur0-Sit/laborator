#pragma once
#include <iostream>
#include <stdexcept>

template <class T>
class CircularQueue {
    int size;
    T* buffer;
    int frontIndex;
    int backIndex;
    int currentSize;
    int maxCapacity;

public:
    CircularQueue(int capacity);
    ~CircularQueue();

    void push(const T& element);
    void pop();
    T& front();
    T& back();
    int getSize();
    bool empty();
};

template<class T>
CircularQueue<T>::CircularQueue(int capacity)
{
    this->size = capacity;
    this->buffer = new T [capacity];
    this->frontIndex = 0;
    this->backIndex = 0;
    this->currentSize = 0;
    this->maxCapacity = capacity;

}
template<class T>
CircularQueue<T>::~CircularQueue()
{
    delete[] buffer;
}

template<class T>
void CircularQueue<T>::push(const T& element)
{
    if (currentSize == maxCapacity)
    {
        buffer[backIndex] = element;
        frontIndex = (frontIndex + 1) % maxCapacity;
        backIndex = (backIndex + 1) % maxCapacity;
    }
    else {
        buffer[backIndex] = element;
        backIndex = (backIndex + 1) % maxCapacity;
        currentSize++;
    }
}

template<class T>
void CircularQueue<T>::pop()
{
    if (empty())
    {
        throw std::runtime_error("Randul este gol");
    }
    frontIndex = (frontIndex + 1) % maxCapacity;
    currentSize--;
}

template<class T>
T& CircularQueue<T>::front()
{
    if (empty())
    {
        throw std::runtime_error("Randul este gol");
    }
    return buffer[frontIndex];
}

template<class T>
T& CircularQueue<T>::back()
{
    if (empty())
    {
        throw std::runtime_error("Randul este gol");
    }
    return buffer[(backIndex + maxCapacity - 1) % maxCapacity];
}

template <class T>
int CircularQueue<T>::getSize() {
    return currentSize;
}

template <class T>
bool CircularQueue<T>::empty() {
    return currentSize == 0;
}
