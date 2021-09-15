#include <iostream>
#include "stack.h" //.h wichtig, sonst STD-Implementierung!
#include "Queue.h"
#include "singlylinkedlist.h"
#include "doublylinkedlist.h"
#include <stdexcept>

using namespace std;

void printSeperator(){
    cout << "========================" << endl;
}

void stackTest(){
    cout << "Please enter the size of the stack: ";
    int l;
    cin >> l;
    Stack<int> test(l);

    bool loop = true;
    while (loop) {
        cout << "0. return to main menu" << endl;
        cout << "1. empty()" << endl;
        cout << "2. full()" << endl;
        cout << "3. push()" << endl;
        cout << "4. pop()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. getCapacity()" << endl;
        cout << "7. getSize()" << endl;
        cout << "Please choose: ";

        int input;
        cin >> input;

        switch (input) {
        case 0:
            loop = false;
            break;
        case 1:
            cout << "Stack is empty: " << test.empty() << endl;
            break;
        case 2:
            cout << "Stack is full: " << test.full() << endl;
            break;
        case 3:{
            cout << "Please input int-value: ";
            int* i = new int();
            cin >> *i;
            test.push(i);
            cout << "Added (" << *i << ") to stack" << endl;
            break;
        }
        case 4:{
            cout << "Removed (" << *test.peek() << ") from stack" << endl;
            test.pop();
            break;
        }
        case 5:{
            int i = *test.peek();
            cout << "Top of stack is (" << i << ")" << endl;
            break;
        }
        case 6:
            cout << "Stack maximum capacity is: " << test.getCapacity() << endl;
            break;
        case 7:
            cout << "Stack size is: " << test.getSize() << endl;
            break;
        default:
            cout << "Invalid input! Please try again" << endl;
            break;
        }
        printSeperator();
    }
}

void queueTest(){
    cout << "Please enter the size of the queue: ";
    int l;
    cin >> l;
    Queue<int> test(l);

    bool loop = true;
    while (loop) {
        cout << "0. return to main menu" << endl;
        cout << "1. empty()" << endl;
        cout << "2. full()" << endl;
        cout << "3. enqueue()" << endl;
        cout << "4. dequeue()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. getCapacity()" << endl;
        cout << "7. getSize()" << endl;
        cout << "Please choose: ";

        int input;
        cin >> input;

        switch (input) {
        case 0:
            //delete test;
            loop = false;
            break;
        case 1:
            cout << "Queue is empty: " << test.empty() << endl;
            break;
        case 2:
            cout << "Queue is full: " << test.full() << endl;
            break;
        case 3:{
            cout << "Please input int-value: ";
            int* i = new int();
            cin >> *i;
            test.enqueue(i);
            cout << "Added (" << *i << ") to queue" << endl;
            break;
        }
        case 4:{
            cout << "Removed (" << *test.peek() << ") from queue" << endl;
            test.dequeue();
            break;
        }
        case 5:{
            int i = *test.peek();
            cout << "At the beginning of queue is (" << i << ")" << endl;
            break;
        }
        case 6:
            cout << "Stack maximum capacity is: " << test.getCapacity() << endl;
            break;
        case 7:
            cout << "Queue size is: " << test.getSize() << endl;
            break;
        default:
            cout << "Invalid input! Please try again" << endl;
            break;
        }
        printSeperator();
    }
}

void singlyLinkedListTest(){
    SinglyLinkedList<int> test;

    bool loop = true;
    while (loop) {
        cout << "0. return to main menu" << endl;
        cout << "1. empty()" << endl;
        cout << "2. start()" << endl;
        cout << "3. end()" << endl;
        cout << "4. advance()" << endl;
        cout << "5. reset()" << endl;
        cout << "6. insert()" << endl;
        cout << "7. get()" << endl;
        cout << "8. destroy()" << endl;
        cout << "9. getSize()" << endl;
        cout << "10. print()" << endl;
        cout << "Please choose: ";

        int input;
        cin >> input;

        switch (input) {
        case 0:
            loop = false;
            break;
        case 1:
            cout << "Singly linked list is empty: " << test.empty() << endl;
            break;
        case 2:
            cout << "Singly linked list points currently at the beginning: " << test.start() << endl;
            break;
        case 3:
            cout << "Singly linked list points currently at the end: " << test.end() << endl;
            break;
        case 4:
            test.advance();
            cout << "Position pointer advanced to (" << *test.get() << ")" << endl;
            break;
        case 5:
            cout << "Reseted singly linked list to the beginning" << endl;
            test.reset();
            break;
        case 6:{
            cout << "Please input int-value: ";
            int* i = new int();
            cin >> *i;
            test.insert(i);
            cout << "Added (" << *i << ") to singly linked list" << endl;
            break;
        }
        case 7:{
            int i = *test.get();
            cout << "Got (" << i << ") from singly linked list" << endl;
            break;
        }
        case 8:
            cout << "Deleted (" << *test.get() << ") from singly linked list" << endl;
            test.destroy();
            break;
        case 9:
            cout << "Singly linked list size is: " << test.getSize() << endl;
            test.destroy();
            break;
        case 10:
            cout << "Print singly linked list:" << endl;
            test.print();
            break;
        default:
            cout << "Invalid input! Please try again" << endl;
            break;
        }
        printSeperator();
    }
}

void doublyLinkedListTest(){
    DoublyLinkedList<int> test;

    bool loop = true;
    while (loop) {
        cout << "0. return to main menu" << endl;
        cout << "1. empty()" << endl;
        cout << "2. start()" << endl;
        cout << "3. end()" << endl;
        cout << "4. advance()" << endl;
        cout << "5. reset()" << endl;
        cout << "6. insertBefore()" << endl;
        cout << "7. insertAfter()" << endl;
        cout << "8. get()" << endl;
        cout << "9. destroy()" << endl;
        cout << "10. getSize()" << endl;
        cout << "11. print()" << endl;
        cout << "Please choose: ";

        int input;
        cin >> input;

        switch (input) {
        case 0:
            loop = false;
            break;
        case 1:
            cout << "Doubly linked list is empty: " << test.empty() << endl;
            break;
        case 2:
            cout << "Doubly linked list points currently at the beginning: " << test.start() << endl;
            break;
        case 3:
            cout << "Doubly linked list points currently at the end: " << test.end() << endl;
            break;
        case 4:
            test.advance();
            cout << "Position pointer advanced to (" << *test.get() << ")" << endl;
            break;
        case 5:
            cout << "Reseted doubly linked list to the beginning" << endl;
            test.reset();
            break;
        case 6:{
            cout << "Please input int-value: ";
            int* i = new int();
            cin >> *i;
            test.insertBefore(i);
            cout << "Added (" << *i << ") to doubly linked list" << endl;
            break;
        }
        case 7:{
            cout << "Please input int-value: ";
            int* i = new int();
            cin >> *i;
            test.insertAfter(i);
            cout << "Added (" << *i << ") to doubly linked list" << endl;
            break;
        }
        case 8:{
            int i = *test.get();
            cout << "Got (" << i << ") from doubly linked list" << endl;
            break;
        }
        case 9:
            cout << "Deleted (" << *test.get() << ") from doubly linked list" << endl;
            test.destroy();
            break;
        case 10:
            cout << "Doubly linked list size is: " << test.getSize() << endl;
            test.destroy();
            break;
        case 11:
            cout << "Print doubly linked list:" << endl;
            test.print();
            break;
        default:
            cout << "Invalid input! Please try again" << endl;
            break;
        }
        printSeperator();
    }
}

int main() {
    bool loop = true;
    while (loop) {
        cout << "0. exit" << endl;
        cout << "1. stack" << endl;
        cout << "2. queue" << endl;
        cout << "3. singly linked list" << endl;
        cout << "4. doubly linked list" << endl;
        cout << "Please choose: ";

        int input;
        cin >> input;

        printSeperator();

        switch (input) {
        case 0:
            loop = false;
            break;
        case 1:
            stackTest();
            break;
        case 2:
            queueTest();
            break;
        case 3:
            singlyLinkedListTest();
            break;
        case 4:
            doublyLinkedListTest();
            break;
        default:
            cout << "Invalid input! Please try again" << endl;
            break;
        }
    }
    return 0;
}
