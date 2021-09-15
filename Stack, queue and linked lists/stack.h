#ifndef STACK_H
#define STACK_H
#include <stdexcept>

template <class T>
//template <class T, int _size> => Alternativ, _size dann aber static
class Stack {

    int size = 0, capacity;
    T** data;

public:
    Stack(int _capacity){
        data = new T*[_capacity];
        capacity = _capacity;
    }

    ~Stack(){
        delete [] data;
    }

    bool empty(){
        return (size == 0);
    }

    bool full(){
        return (size == capacity);
    }

    void push(T* _element){
        if (full()) {
            throw std::overflow_error("Stack is full");
        } else {
            data[++size] = _element;
        }
    }

    void pop(){
        if (empty()) {
            throw std::underflow_error("Stack is empty");
        } else {
            /* As long as a pointer is used, either the value can be returned and
             * the location in the stack can be overwritten OR the location in the
             * stack (i.e. the pointer) can be deleted, but nothing can be returned.
             */
            delete data[size--];
        }
    }

    T* peek(){
        if (empty()) {
            throw std::underflow_error("Stack is empty");
        } else {
            return data[size];
        }
    }

    int getCapacity(){
        return capacity;
    }

    int getSize(){
        return size;
    }
};

#endif // STACK_H
