#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class BinarySearchTree {
public:
    struct Node {
        T* data;
        int key;
        Node* parent;
        Node* left;
        Node* right;

        Node () {
            data = nullptr;
            key = 0;
            parent = nullptr;
            left = nullptr;
            right = nullptr;
        }

        Node (T* _data, int _key) {
            data = _data;
            key = _key;
            parent = nullptr;
            left = nullptr;
            right = nullptr;
        }
    };

    enum PrintModes {
        preOrder,
        inOrder,
        postOrder
    };

    enum RotateMode{
        left,
        right
    };

    Node* root;
    Node* current;
    int length;

    BinarySearchTree () {
        root = nullptr;
        current = nullptr;
        length = 0;
    }

    ~BinarySearchTree(){
        clear(root);
    }

    bool empty(){
        return (root == nullptr);
    }

    Node* getRoot(){
        if (root != nullptr) {
            return root;
        } else {
            throw std::underflow_error("Root is not set");
        }
    }

    Node* getCurrent(){
        if (current != nullptr) {
            return current;
        } else {
            throw std::out_of_range("Current is not set");
        }
    }

    int getLength(){
        return length;
    }

    void insert(T* _data, int _key){
        if (empty()) {
            //Tree is empty insert at root
            root = new Node(_data, _key);
            current = root;
        } else {
            insert(root, _data, _key);
        }
        length++;
    }

    void print(PrintModes _mode){
        if (empty()) {
            throw underflow_error("Tree is empty");
        }

        switch (_mode) {
            case preOrder:
                printPreOrder(root);
                break;

            case inOrder:
                printInOrder(root);
                break;

            case postOrder:
                printPostOrder(root);
                break;
            default:
                throw invalid_argument("Not valid print mode chosen");
                break;
        }
        cout << endl;
    }

    int getLayers(){
        if (empty()) {
            throw underflow_error("Tree is empty");
        } else {
            return getLayers(root);
        }
    }

    Node* searchNode(const int _key){
        if (empty()) {
            throw underflow_error("Tree is empty");
        } else {
            return searchNode(root, _key);
        }
    }

    void destroy(const int _key){
        if (empty()) {
            throw underflow_error("Tree is empty");
        } else {
            //Need to find node before it can be deleted
            Node* result = searchNode(_key);

            if (result == nullptr) {
                throw std::invalid_argument("Key does not exist");
            } else {
                destroy(result);
                length--;
            }
        }
    }

    void rotate(const int _key, RotateMode _mode){
        if (empty()) {
            throw underflow_error("Tree is empty");
        } else {
            //Need to find node before it can be rotatet around it
            Node* result = searchNode(_key);

            if (result == nullptr) {
                throw std::invalid_argument("Key does not exist");
            }

            switch (_mode) {
                case left:
                    if (result->right == nullptr) {
                        throw std::invalid_argument("Cannot rotate with empty right subtree");
                    }
                    rotateLeft(result);
                    break;

                case right:
                    if (result->left == nullptr) {
                        throw std::invalid_argument("Cannot rotate with empty left subtree");
                    }
                    rotateRight(result);
                    break;
                default:
                    throw invalid_argument("Not valid rotate mode chosen");
                    break;
            }
        }
    }

    void balance(){
        if (empty() || (root->left == nullptr && root->right == nullptr)) {
            throw length_error("Theres nothing to be balanced");
        }
        balance(root);
        std::cout << "INFO: Tree now balanced" << std::endl;
    }

    void setData(T* _data, int _key){
        if (empty()) {
            throw underflow_error("Tree is empty");
        } else {
            //Need to find node before it can be altered
            Node* result = searchNode(_key);

            if (result == nullptr) {
                throw std::invalid_argument("Key does not exist");
            }

            if (result->data == _data) {
                cout << "INFO: No data changed" << endl;
            } else {
                result->data = _data;
            }
        }
    }

    void clear(){
        if (empty()) {
            throw underflow_error("Tree is empty");
        } else {
            clear(root);
            current = nullptr;
            root = nullptr;
        }
    }

    void printPretty() {
        printPretty("", root, false);
    }

private:
    void insert(Node* _node, T* _data, int _key){
        if (_key <= _node->key) {
            if (_node->left == nullptr) {
                Node* child = new Node(_data, _key);
                child->parent = _node;
                _node->left = child;
                current = child;
            } else {
                insert(_node->left, _data, _key);
            }
        } else {
            if (_node->right == nullptr) {
                Node* child = new Node(_data, _key);
                child->parent = _node;
                _node->right = child;
                current = child;
            } else {
                insert(_node->right, _data, _key);
            }
        }
    }

    void printPreOrder(Node* _node){
        cout << *_node->data << " ";

        if (_node->left != nullptr) {
            printPreOrder(_node->left);
        }
        if (_node->right != nullptr) {
            printPreOrder(_node->right);
        }
    }

    void printInOrder(Node* _node){

        if (_node->left != nullptr) {
            printInOrder(_node->left);
        }

        cout << *_node->data << " ";

        if (_node->right != nullptr) {
            printInOrder(_node->right);
        }
    }

    void printPostOrder(Node* _node){
        if (_node->left != nullptr) {
            printPostOrder(_node->left);
        }
        if (_node->right != nullptr) {
            printPostOrder(_node->right);
        }

        cout << *_node->data << " ";
    }

    int getLayers(Node* _node, int height = 0){
        if (_node == nullptr) {
            return 0;
        }

        int heightLeft = 0, heightRight = 0;
        height++;

        if (_node->left == nullptr && _node->right == nullptr) {
            return height;
        }

        if (_node->left != nullptr) {
            heightLeft = getLayers(_node->left, height);
        }

        if (_node->right != nullptr) {
            heightRight = getLayers(_node->right, height);
        }

        return (heightLeft > heightRight) ? heightLeft : heightRight;
    }

    Node* searchNode(Node* _node, const int _key){
        if (_node->key == _key) {
            return _node;
        }

        Node* resultLeft = nullptr;
        Node* resultRight = nullptr;

        if (_node->left != nullptr) {
            resultLeft = searchNode(_node->left, _key);
        }
        if (_node->right != nullptr) {
            resultRight = searchNode(_node->right, _key);
        }

        if (resultLeft != nullptr) {
            return resultLeft;

        } else if (resultRight != nullptr) {
            return resultRight;

        } else {
            return nullptr;
        }
    }

    void destroy(Node* _node){
        if (_node->left == nullptr && _node->right == nullptr) {
            if (_node->parent->left == _node) {
                _node->parent->left = nullptr;
            }
            if (_node->parent->right == _node) {
                _node->parent->right = nullptr;
            }

        } else if (_node->right != nullptr) {
            _node->right->parent = _node->parent;
            _node->parent->right = _node->right;

        } else if (_node->left != nullptr) {
            _node->left->parent = _node->parent;
            _node->parent->left = _node->left;

        } else {
            if (_node->key == root->key) {
                _node->left->parent = nullptr;
                root = _node->left;
            } else {
                _node->parent->right = _node->left;
                _node->left->parent = _node->parent;
            }

            Node* toDelete = _node;
            Node* tmp = _node->right;
            _node = _node->left;

            while (_node->right != nullptr) {
                _node = _node->right;
            }
            _node->right = tmp;
            tmp->parent = _node->right;
            _node = toDelete;
        }
        delete _node;
    }

    //From https://github.com/Bibeknam/algorithmtutorprograms/blob/master/data-structures/red-black-trees/RedBlackTree.cpp
    void rotateLeft(Node* x){
        Node* y = x->right;
        x->right = y->left;

        if (y->left != nullptr) {
            y->left->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }

    //From https://github.com/Bibeknam/algorithmtutorprograms/blob/master/data-structures/red-black-trees/RedBlackTree.cpp
    void rotateRight(Node* x){
        Node* y = x->left;
        x->left = y->right;

        if (y->right != nullptr) {
            y->right->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }

        y->right = x;
        x->parent = y;
    }

    void balance(Node* _node) {
        int d = getLayers(root->left) - getLayers(root->right);

        if (d > 1) {
            rotateRight(_node);
            balance(_node->parent);
        } else if(d < -1) {
            rotateLeft(_node);
            balance(_node->parent);
        }
    }

    void clear(Node* _node){
        if (_node != nullptr) {
            //Delete tree recursively
            if (_node->left != nullptr) {
                clear(_node->left);
            }
            if (_node->right != nullptr) {
                clear(_node->right);
            }

            delete _node;
            length--;
        }
    }

    //Adapted from https://stackoverflow.com/a/51730733/7184809
    void printPretty(string _prefix, Node* _node, bool _isLeft){
        if (_node != nullptr) {
            cout << _prefix;
            cout << (_isLeft ? "|--" : "+--" );
            cout << (_isLeft ? ">L: " : ">R: " );
            cout << "(" << _node->key << ") " << endl;

            printPretty( _prefix + (_isLeft ? "|   " : "   "), _node->left, true);
            printPretty( _prefix + (_isLeft ? "|   " : "   "), _node->right, false);
        }
    }
};

#endif // BINARYSEARCHTREE_H
