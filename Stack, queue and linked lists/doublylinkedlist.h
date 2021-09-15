#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include <stdexcept>

template <class T>
class DoublyLinkedList {    
    struct Item {
        Item(T* _data) {
            data = _data;

            next = nullptr;
            previous = nullptr;
        }

        T* data;
        Item* next;
        Item* previous;
    };

    Item* head;
    Item* current;
    int size;

public:
    DoublyLinkedList(){
        head = nullptr;
        current = nullptr;
        size = 0;
    }

    T* get() {
        if (!empty()) {
            return current->data;
        } else {
            throw std::out_of_range("No data reachable");
        }
    }

    bool empty() {
        return (head == nullptr);
    }

    bool end() {
        if (empty()) {
            return true;
        }
        return (current->next == nullptr);
    }

    bool start(){
        return (current == head);
    }

    void advance() {
        if (!end()) {
            current = current->next;
        } else {
            //For circular linked list:
            //reset();

            //For finitely linked list:
            throw std::overflow_error("Already reached end of singly linked list");
        }
    }

    void reset() {
        if (head != nullptr) {
            current = head;
        }
    }

    void insertBefore(T* _element) {
        std::cout << "before" << std::endl;

        //Create new item
        Item* newItem = new Item(_element);

        if (empty()) {
            current = newItem;
            head = newItem;
        } else {
            //Set pointers
            newItem->previous = current->previous;
            current->previous = newItem;
            newItem->next = current;

            //Pay attention to the first item
            if (newItem->previous != nullptr) {
                newItem->previous->next = newItem;
            } else {
                //Set head new
                head = newItem;
            }
        }
        size++;
    }

    void insertAfter(T* _element) {

        std::cout << "after" << std::endl;


        //Erstelle neues Element
        Item* newItem = new Item(_element);

        if (empty()) {
            current = newItem;
            head = newItem;
        } else {
            //Biege Zeiger um
            newItem->next = current->next;
            current->next = newItem;
            newItem->previous = current;

            //Passe auf letztes Item auf
            if (newItem->next != nullptr) {
                newItem->next->previous = newItem;
            }
            current = newItem;
        }
        size++;
    }

    void destroy() {
        if (!empty()) {

            //Das erste Element soll gelöscht werden
            if (start()) {
                head = current->next;
            }

            //Ändere das nächste Item
            if (!end()) {
                current->next->previous = current->previous;
            }

            //Ändere das vorherige Item
            if (current->previous != nullptr) {
                current->previous->next = current->next;
            }

            Item* tmp = current;
            if (current->next != nullptr) {
                current = current->next;
            } else {
                current = current->previous;
            }
            delete tmp;
            size--;
        }
    }    

    int getLength(){
        return size;
    }

    void print() {
        Item* t = head;

        while (t != nullptr) {
            std::cout << *t->data << std::endl;
            t = t->next;
        }
    }
};

#endif // DOUBLYLINKEDLIST_H
