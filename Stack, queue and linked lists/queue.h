#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>

template <class T>
class Queue {

    int head = 0, tail = -1, size = 0, capacity;
    T** data;

public:
    Queue(int _capacity){
        data = new T*[_capacity];
        capacity = _capacity;
    }

    ~Queue(){
        delete [] data;
    }

    bool empty(){
        //return (head == tail);
        return size == 0;
    }

    bool full(){
        return (size == capacity);
    }

    void enqueue(T* _element){
        if (full()) {
            throw std::overflow_error("Queue is full");
        } else {
            //tail = (tail % size) + 1;
            tail = (tail+1) % capacity;
            data[tail] = _element;
            size++;
        }
    }

    void dequeue(){
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        } else {
            delete data[head]; //maybe? seems to make sense
            //head = (head % size) + 1;
            head = (head+1) % capacity;
            size--;
        }
    }

    T* peek(){
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        } else {
            return data[head];
        }
    }

    int getCapacity(){
        return capacity;
    }

    int getSize(){
        return size;
    }
};

#endif // QUEUE_H
