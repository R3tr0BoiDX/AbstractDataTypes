#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include <iostream>
#include <stdexcept>

template <class T>
class SinglyLinkedList {
    struct Item {
        Item(T* _data, Item* _next) {
            data = _data;
            next = _next;
        }

        T* data;
        Item* next;
    };

    Item* current;
    Item* previous;
    Item* head;
    int size;

public:
    SinglyLinkedList() {
        current = nullptr;
        previous = nullptr;
        head = nullptr;
        size = 0;
    }

    bool end(){
        return (current == nullptr);
    }

    bool start(){
        return (previous == nullptr);
    }

    bool empty(){
        return (head == nullptr);
    }

    void advance(){
        if (!end()) {
            previous = current;
            current = current->next;
        } else {
            //For circular linked list:
            //reset();

            //For finitely linked list:
            throw std::overflow_error("Already reached end of singly linked list");
        }
    }

    void reset(){
        current = head;
        previous = nullptr;
    }

    T* get(){
        if (!end()) {
            return current->data;
        } else {
            throw std::out_of_range("No data reachable");
        }
    }

    void insert(T* _data){
        Item* t = new Item(_data, current);

        if (empty()) {
            head = t;
        }

        if (!start()) {
            previous->next = t;
        } else {
            head = t;
        }
        current = t;
        size++;
    }

    void destroy(){
        if (!end()) {
            if (!start()) {
                previous->next = current->next;
            } else {
                head = current->next;
            }

            delete current;

            if (!start()) {
                current=previous->next;
            } else {
                current = head;
            }
            size--;
        }
    }

    int getSize(){
        return size;
    }

    void print(){
        Item* t = head;

        while (t != nullptr) {
            std::cout << *t->data << std::endl;
            t = t->next;
        }
    }
};
#endif // SINGLYLINKEDLIST_H
