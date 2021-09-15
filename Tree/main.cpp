#include <iostream>
#include <string>
#include <time.h>
#include <random>
#include "BinarySearchTree.h"

using namespace std;

int main() {
    srand((unsigned) time(NULL));

    try {
        BinarySearchTree<int> tree;

        bool loop = true;
        while (loop) {
            cout << "0. exit" << endl;
            cout << "1. empty()" << endl;
            cout << "2. getRoot()" << endl;
            cout << "3. getCurrent()" << endl;
            cout << "4. getLength()" << endl;
            cout << "5. insert(data, key)" << endl;
            cout << "6. print(mode)" << endl;
            cout << "7. getLayers()" << endl;
            cout << "8. searchNode(key)" << endl;
            cout << "9. destroy(key)" << endl;
            cout << "10. balance()" << endl;
            cout << "11. setData(data, key)" << endl;
            cout << "12. clear()" << endl;
            cout << "13. printPretty()" << endl;
            cout << "14. Fill with 10 random values" << endl;
            cout << "Please choose: ";

            int input;
            cin >> input;
            cout << "***" << endl;

            switch (input) {
            case 0:
                loop = false;
                break;

            case 1:
                cout << "Tree is empty: " << tree.empty() << endl;
                break;

            case 2:
                cout << "Root is currently: (" << tree.getRoot()->key << ") " << *tree.getRoot()->data << endl;
                break;

            case 3:
                cout << "Current is currently: (" << tree.getCurrent()->key << ") " << *tree.getCurrent()->data << endl;
                break;

            case 4:
                cout << "Currently the tree has " << tree.getLength() << " nodes" << endl;
                break;

            case 5:{
                cout << "Please enter key (int): ";
                int k;
                cin >> k;

                cout << "Please enter number (int) to store: ";
                int* d = new int;
                cin >> *d;

                tree.insert(d, k);
                cout << "Node added" << endl;
                break;
            }

            case 6:{
                cout << "1: Pre-Order" << endl;
                cout << "2: In-Order" << endl;
                cout << "3: Post-Order" << endl;
                cout << "Please choose print mode: ";

                int input;
                cin >> input;

                tree.print(static_cast<BinarySearchTree<int>::PrintModes>(input-1));
                //tree.print(BinarySearchTree<int>::preOrder);
                break;
            }

            case 7:
                cout << "Currently maximum height is " << tree.getLayers() << endl;
                break;

            case 8:{
                cout << "Please enter key (int): ";
                int k;
                cin >> k;

                BinarySearchTree<int>::Node* node = tree.searchNode(k);
                cout << "Node found is: (" << node->key << ") " << *node->data << endl;
                break;
            }

            case 9:{
                cout << "Please enter key (int): ";
                int k;
                cin >> k;

                tree.destroy(k);
                cout << "Node with key (" << k << ") got destroyd " << endl;
                break;
            }

            case 10:
                tree.balance();
                break;

            case 11:{
                cout << "Please enter key(int): ";
                int k;
                cin >> k;

                cout << "Please enter updated message (string) to store: ";
                int* d = new int;
                cin >> *d;

                tree.setData(d, k);
                cout << "Node updated" << endl;
                break;
            }

            case 12:
                tree.clear();
                cout << "Tree got cleaned" << endl;
                break;

            case 13:
                tree.printPretty();
                break;

            case 14:{
                for (int i = 0; i < 10; ++i) {
                    int* value = new int(rand() % 100);
                    tree.insert(value, *value);
                    cout << "Node (" << *value << ") added" << endl;
                }
                break;
              }
            }

            cout << "========================" << endl;
        }
    } catch (const char* m) {
        cout << m << endl;
        main();
    }
    return 0;
}
